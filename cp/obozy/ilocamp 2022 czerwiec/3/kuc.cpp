//Sylwia Sapkowska
#include <bits/stdc++.h>
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
const int mod = 1e9+7;

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

int mul(int a, int b){
	return (a*b)%mod;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0) a+=mod;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int, int>>edges;
	vector<vector<int>>g(n+1);
	vector<int>in(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		edges.emplace_back(a, b);
		in[b]++;
	}
	queue<int>q;
	for (int i = 1; i<=n; i++){
		if (!in[i]){
			q.push(i);
		}
	}
	vector<int>topo;
	while (!q.empty()){
		int v = q.front();q.pop();
		topo.emplace_back(v);
		for (auto x: g[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}

	debug(topo);
	vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
	for (int i = n-1; i>=0; i--){
		int v = topo[i];
		dp[v][v] = 1;
		for (int j = i; j>=0; j--){
			int x = topo[j];
			for (auto y: g[x]){
				add(dp[x][v], dp[y][v]);
			}
		}
	}
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=n; j++){
	// 		debug(i, j, dp[i][j]);
	// 	}
	// }
	vector<int>pos(n+1);
	for (int i = 0; i<n; i++) pos[topo[i]] = i;
	vector<int>DP(n+1);
	for (auto v: topo){
		DP[v] = mul(dp[1][v], mul(dp[1][v], dp[1][v]));
		for (auto [a, b]:edges){ 
			if (pos[b] <= pos[v]){
				sub(DP[v], mul(DP[a], mul(dp[b][v], mul(dp[b][v], dp[b][v]))));
			}
		}
		//debug(v, DP[v]);
	}
	cout << DP[n] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
