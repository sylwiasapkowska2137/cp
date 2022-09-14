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
	int n, m; cin >> n >> m;
	vector<int>in(n+1);
	vector<vector<int>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		in[b]++;
	}
	queue<int>q;
	for (int i = 1; i<=n;i++) if (!in[i]) q.push(i);
	vector<int>topo;
	while (!q.empty()){
		int v = q.front(); q.pop();
		topo.emplace_back(v);
		for (auto x: g[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	in.assign(n+1, 0);
	vector<int>out(n+1);
	for (int i = 1; i<=n; i++){
		out[i] = (int)g[i].size();
		for (auto j:g[i]){
			in[j]++;
		}
	}
	int ans = 1;
	reverse(topo.begin(), topo.end());
	vector<int>dp(n+1, -oo);
	for (auto v: topo){
		if (in[v] >= 2) dp[v] = 1;
		if (out[v] >= 2) {
			for (auto x: g[v]){
				if (in[x] >= 2)	dp[v] = max(dp[v], dp[x]+1);
			}
			ans = max(ans, dp[v]);
		}
	}
	//debug(dp);
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