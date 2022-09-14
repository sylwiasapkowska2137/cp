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
int d;

struct segtree{
	vector<pair<int, int>>tab;
	vector<int>czas;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.resize(2*size, {-oo, -oo});
		czas.assign(2*size, 0);
	}

	void update(int x, pair<int, int>v, int t){
		x += size;
		if (v >= tab[x] || czas[x] < t-d){
			tab[x] = v;
			czas[x] = t;
		} else return;
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}

	pair<int, int>query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		pair<int, int>ans = {-oo, -oo};
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return {ans.first, -ans.second};
	}

	void undo(int x, int t){
		x += size;
		if (czas[x] <= t){
			tab[x] = {-oo, -oo};
			czas[x] = 0;
			while (x){
				x/=2;
				tab[x] = max(tab[2*x], tab[2*x+1]);
			}
		}
	}

	void print(){
		for (int i = size+1; i<(int)tab.size(); i++){
			cerr << i-size << " " << tab[i].first << " " << tab[i].second << " " << czas[i] << "\n";
		}
		cerr << "\n";
	}
};

struct changes{
	int mx, dp, idx;
};

void solve(){
	int n; cin >> n >> d;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	segtree seg(n+1);
	seg.update(0, {0, 0}, 0);
	vector<int>dp(n+1, 1);
	deque<changes>q;
	for (int i = 1; i<=n; i++){
		while (q.size() && q.front().idx < i-d) {
			seg.undo(q.front().mx, q.front().idx);
			q.pop_front();
		}
		debug(i);
		seg.print();
		pair<int, int>x = seg.query(a[i], n);
		debug(x);
		if (x.first != -oo){
			dp[i] = max(dp[i], x.first);
			seg.update(x.second, {dp[i], -x.second}, i);
			q.push_back({x.second, dp[i], i});
		}
		pair<int, int>y = seg.query(0, a[i]-1);
		if (y.second != -oo){
			dp[i] = max(dp[i], y.first+1);
			seg.update(a[i], {y.first+1, -a[i]}, i);
			q.push_back({a[i], dp[i], i});
		}
		seg.update(a[i], {1, -a[i]}, i);
	}
	debug(dp);

	cout << dp[n] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
