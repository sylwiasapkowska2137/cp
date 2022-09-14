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
const int oo = 1e18, K = 10;

void solve(){
	string s; getline(cin, s);
	int n, k; cin >> n >> k;
	int x, y; cin >> x >> y;
	vector<int>a(k);
	for (int i = 0; i<k; i++) cin >> a[i];
	vector<int>p(k);
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<vector<int>>up(n+1, vector<int>(K+1));
	vector<int>depth(n+1);

	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		for (int i = 1; i<K; i++){
			up[v][i] = up[up[v][i-1]][i-1];
		}
		for (auto x: g[v]){
			if (x!=pa){
				depth[x] = depth[v]+1;
				dfs(x, v);
			}
		}
	};
	dfs(1, 1);
	function<int(int, int)>lca = [&](int a, int b){
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[a]-(1<<i) >= depth[b]){
				a = up[a][i];
			}
		}
		if (a == b) return a;
		for (int i = K-1; i>=0; i--){
			if (up[a][i] != up[b][i]){
				a = up[a][i];
				b = up[b][i];
			}
		}
		return up[a][0];
	};

	function<int(int, int)>D = [&](int a, int b){
		return depth[a]+depth[b]-2*depth[lca(a, b)];
	};
	int ans = oo;
	iota(p.begin(), p.end(), 0);
	do{
		int curr = 0;
		int prev = x;
		for (int i = 0; i<k; i++){
			curr += D(prev, a[p[i]]);
			prev = a[p[i]];
		}
		curr += D(prev, y);
		ans = min(ans, curr);
	} while (next_permutation(p.begin(), p.end()));
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
