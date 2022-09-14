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

void solve(){
	int n, m, e; cin >> n >> m >> e;
	vector<int>rep(n+m+1), sz(n+m+1);
	for (int i = n+1; i<=n+m; i++) sz[i] = 1;
	iota(rep.begin(), rep.end(), 0);
	vector<pair<int, int>>edges(e+1);
	for (int i = 1; i<=e; i++) cin >> edges[i].first >> edges[i].second;
	int q; cin >> q;
	vector<int>a(q), bad(e+1);
	for (int i = 0; i<q; i++) {
		cin >> a[i];
		bad[a[i]] = 1;
	}
	function<int(int)>Find = [&](int v){
		if (v == rep[v]) return v;
		return rep[v] = Find(rep[v]);
	};

	int ans = 0;
	function<void(int, int)>Union = [&](int x, int y){
		x = Find(x);
		y = Find(y);
		if (x == y) return;
		rep[y] = x;
		sz[x] += sz[y];
		if (x <= n && y > n) ans += sz[y];
	};

	for (int i = 1; i<=e; i++){
		if (!bad[i]){
			// debug
			Union(edges[i].first, edges[i].second);
		}
	}
	reverse(a.begin(), a.end());
	vector<int>ret;
	for (auto x: a){
		ret.emplace_back(ans);
		Union(edges[x].first, edges[x].second);
	}
	reverse(ret.begin(), ret.end());
	for (auto x: ret) cout << x << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
