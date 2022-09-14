//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
	string s; getline(cin, s);
	int n, k; cin >> n >> k;
	int x, y; cin >> x >> y;
	vector<vector<int>>g(n+1);
	vector<int>big(n+1);
	for (int i = 0; i<k; i++){
		int x; cin >> x;
		big[x] = 1;
	}

	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	
	vector<int>parent(n+1), bad(n+1), sub(n+1), depth(n+1);
	function<void(int, int)>dfs = [&](int v, int pa){
		if (big[v]) bad[v] = 1;
		parent[v] = pa;
		sub[v] = 1;
		for (auto x: g[v]){
			if (x!=pa){
				bad[x] |= bad[v];
				depth[x] = depth[v]+1;
				dfs(x, v);
				sub[v] += sub[x];
			}
		}
	};

	dfs(x, x);
	debug(bad);
	int cut = 0;

	for (int i = 1; i<=n; i++){
		if (!bad[i] && bad[parent[i]]){
			cut += (sub[i]);
			debug(i);
		}
	}
	debug(cut);
	cout << 2*((n-cut)-1)-depth[y] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}