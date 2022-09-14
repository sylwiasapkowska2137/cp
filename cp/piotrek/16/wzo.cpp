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

// #define int long long
const int oo = 1e9+7, K = 30;

struct TreeMax{
	typedef pair<int, int> T;
	vector<T>tab;
	int size = 1;
	T f(T a, T b){return max(a, b);}

	TreeMax(int n){
		while (size < n) size*=2;
		tab.assign(2*size, {-oo, -oo});
	}

	void update(int x, T v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = f(tab[2*x], tab[2*x+1]);
		}
	}

	T query(int l, int r){
		T ans = {-oo, -oo};
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = f(ans, tab[l+1]);
			if (r&1) ans = f(ans, tab[r-1]);
		}
		return ans;
	}
};

struct TreeMin{
	typedef pair<int, int> T;
	vector<T>tab;
	int size = 1;
	T f(T a, T b){return min(a, b);}

	TreeMin(int n){
		while (size < n) size*=2;
		tab.assign(2*size, {oo, oo});
	}

	void update(int x, T v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = f(tab[2*x], tab[2*x+1]);
		}
	}

	T query(int l, int r){
		T ans = {oo, oo};
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = f(ans, tab[l+1]);
			if (r&1) ans = f(ans, tab[r-1]);
		}
		return ans;
	}
};

struct X{
	int L, R, i;
};

void solve(){
	int n; cin >> n;
	vector<X>a(n);
	for (int i = 0; i<n; i++){
		cin >> a[i].L >> a[i].R;
	}
	sort(a.begin(), a.end(), [](auto x, auto y){return x.L < y.L;});
	for (int i = 0; i<n; i++) a[i].i = i;
	int N = n+n+2;
	TreeMax t(N);
	for (int i = 0; i<n; i++) t.update(a[i].L, {a[i].R, i});
	vector<vector<int>>g(n+1);
	for (int i = 0; i<n; i++){
		auto [l, r, idx] = a[i];
		while (1){
			pair<int, int>x = t.query(l, r);
			if (x.first <= r) break;
			// debug(i, x.second);
			g[i].emplace_back(x.second);
			g[x.second].emplace_back(i);
			t.update(a[x.second].L, {-oo, -oo});
		}
	}
	sort(a.begin(), a.end(), [](auto x, auto y){return x.R < y.R;});
	TreeMin t2(N);
	for (int i = 0; i<n; i++) t2.update(a[i].R, {a[i].L, i});
	for (int i = n-1; i>=0; i--){
		auto [l, r, idx] = a[i];
		while (1){
			pair<int, int>x = t2.query(l, r);
			// debug(l, r, idx, x);
			if (x.first >= l) break;
			// debug(idx, a[x.second].i);
			g[idx].emplace_back(a[x.second].i);
			g[a[x.second].i].emplace_back(idx);
			t2.update(a[x.second].R, {oo, oo});
		}
	}
	
	vector<int>vis(n, -1);
	function<void(int)>dfs = [&](int v){
		for (auto x: g[v]){
			if (vis[x] != -1 && vis[x] == vis[v]){
				cout << "0\n";
				exit(0);
			}
			if (vis[x] != -1) continue;
			vis[x] = (vis[v]^1);
			dfs(x);
		}
	};

	int ans = 0;
	
	for (int i = 0; i<n; i++){
		if (vis[i] == -1){
			ans++;
			vis[i] = 1;
			dfs(i);
		}
	}
	vector<stack<int>>s(2);
	vector<pair<int, int>>tab;
	for (int i = 0; i<n; i++){
		tab.emplace_back(a[i].L, a[i].i+1);
		tab.emplace_back(a[i].R, -(a[i].i+1));
	}
	sort(tab.begin(), tab.end());
	// debug(vis);
	for (auto [c, b]:tab){
		int idx;
		if (b > 0){
			idx = b-1;
			s[vis[idx]].push(idx);
		} else {
			idx = -b-1;
			if (s[vis[idx]].empty() || s[vis[idx]].top() != idx) {
				cout << "0\n";
				return;
			}
			s[vis[idx]].pop();
		}
	}

	int ret = 1;
	const int mod = 1e9+7;
	for (int i = 0; i<ans; i++){
		ret = (ret*2LL)%mod;
	}
	cout << ret << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
