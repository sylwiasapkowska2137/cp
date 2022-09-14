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
	int n; cin >> n;
	vector<int>X(n+1), c(n+1);
	for (int i = 1; i<=n; i++) cin >> X[i];
	for (int i = 1; i<=n; i++) cin >> c[i];
	vector<int>vis(n+1), par(n+1);
	bool cycle;
	int cycle_start, cycle_end;

	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		int x = X[v];
		if (!vis[x]){
			par[x] = v;
			dfs(x);
		} else if(vis[x] == 1){
			cycle = 1;
			cycle_end = v;
			cycle_start = x;
		}
		vis[v] = 2;
	};
	int ans = 0;
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			cycle = 0;
			cycle_start = -1;
			cycle_end = -1;
			dfs(i);
			if (cycle){
				if (cycle_start == -1) continue;
				int tmp = oo;
				for (int v = cycle_end; v != cycle_start; v = par[v]) {
					tmp = min(tmp, c[v]);
				}
				tmp = min(tmp, c[cycle_start]);
				ans += tmp;
			}
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
