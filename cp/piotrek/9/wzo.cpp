//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e18, K = 30;

struct star{
	int x, y, c;
	void read(){
		cin >> x >> y >> c;
	}
};

struct TreeMax{
	vector<pair<int, int>>tab;
	int size = 1;

	TreeMax(int n){
		while (size < n) size*=2;
		tab.assign(2*size, {-oo, -oo});
	}

	void update(int x, pair<int, int> v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		pair<int, int>ans = {-oo, -oo};
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans.second;
	}
};

struct TreeSum{
	vector<int>tab;
	int size = 1;

	TreeSum(int n){
		while (size < n) size*=2;
		tab.resize(2*size);
	}

	void update(int x, int v){
		x += size;
		tab[x] += v;
		while (x){
			x/=2;
			tab[x] = tab[2*x] + tab[2*x+1];
		}
	}

	int query(int l, int r){
		int ans = 0;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];

	int m; cin >> m;
	vector<star>b(m);
	int s = 0;
	for (auto &x: b) {
		x.read();
		s += x.c;
	}
	sort(b.begin(), b.end(), [](auto x, auto y){return x.x < y.x;});
	vector<vector<int>>g(n+1);
	vector<vector<int>>paths(n+1);
	int c = 0;
	TreeMax smax(n+1);
	for (int i = 1; i<=n; i++) smax.update(i, {a[i], i});
	TreeMax gw(m+1);
	for (int i = 0; i<m; i++) gw.update(i, {b[i].y, i});
	vector<int>kon(n+1);

	function<void(int, int, int)>rek = [&](int l, int r, int pa){
		if (l > r) return;
		c++;
		if (pa != -1) g[pa].emplace_back(c);
		int h = smax.query(l, r);
		kon[h] = c; 
		// debug(l, r, h, a[h]);
		
		int L = 0, R = m-1, ll = oo, rr = -oo;
		while (R >= L){
			int mid = (L+R)/2;
			if (b[mid].x >= l){
				ll = mid;
				R = mid-1;
			} else L = mid+1;
		}

		L = 0, R = m-1;
		while (R >= L){
			int mid = (L+R)/2;
			if (b[mid].x <= r){
				rr = mid;
				L = mid+1;
			} else {
				R = mid-1;
			}
		}
		
		if (ll <= rr){
			// debug(l, r, ll, rr);
			while (1){
				int x = gw.query(ll, rr);
				if (x == -oo || b[x].y <= a[h]) break;
				paths[c].emplace_back(x);
				gw.update(x, {-oo, -oo});		
			}
		}
		
		int p = c;
		rek(l, h-1, p);
		rek(h+1, r, p);
	};

	rek(1, n, -1);

	vector<int>dp(n+1), pre(n+1), post(n+1);
	int t = 0;

	function<void(int)>dfs = [&](int v){
		pre[v] = t++;
		for (auto x: g[v]) dfs(x);
		post[v] = t++;
	};

	// for (int i = 1; i<=n; i++){
	// 	for (auto x: paths[i]){
	// 		cerr << i << " " << kon[b[x].x] << " " << b[x].c << "\n";
	// 	}
	// }
	dfs(1);

	TreeSum seg(2*n+3), dp_sum(2*n+3);

	function<void(int, int)>DFS = [&](int v, int pa){
		for (auto x: g[v]) {
			DFS(x, v);
			dp[v] += dp[x];
		}
		int curr = (pa == -1 ? 0 : dp_sum.query(0, pre[v]-1) - seg.query(0, pre[v]-1));
		for (auto x: paths[v]) dp[v] = max(dp[v], seg.query(0, pre[kon[b[x].x]]) - dp_sum.query(0, pre[kon[b[x].x]]) + b[x].c + curr);
		if (pa != -1){
			seg.update(pre[pa], dp[v]);
			seg.update(post[pa], -dp[v]);
		}
		dp_sum.update(pre[v], dp[v]);
		dp_sum.update(post[v], -dp[v]);
	};

	DFS(1, -1);
	// debug(dp);
	cout << s-dp[1] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
