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
	int n, m, start; cin >> n >> m >> start;
	vector<vector<pair<int, int>>>g(n+1), gt(n+1);
	vector<int>deg(n+1);
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		gt[b].emplace_back(a, c);
		deg[a]++;
	}
	vector<vector<int>>dp(n+1, vector<int>(2));
	for (int i = 1; i<=n; i++){
		dp[i][0] = oo;
		dp[i][1] = -oo;
	}
	set<pair<int, int>>s;
	for (int i = 1; i<=n; i++){
		if (!deg[i]){
			dp[i][0] = dp[i][1] = 0;
			s.insert({0, i});
			for (auto [x, c]: gt[i]){
				if (dp[x][0] > dp[i][1]+c){
					dp[x][0] = dp[i][1]+c;
					s.insert({dp[x][0], x});
				}
			}
		}
	}
	vector<bool>vis(n+1);
	while (s.size()){
		int v = s.begin()->second;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto [x, c]:gt[v]){
			deg[x]--;
			if (!deg[x]){
				for (auto [u, d]: g[x]){
					dp[x][1] = max(dp[x][1], dp[u][0]+d);
				}
				for (auto [u, d]: gt[x]){
					if (dp[u][0] > dp[x][1]+d){
						dp[u][0] = dp[x][1]+d;
						s.insert({dp[u][0], u});
					}
				}
			}
		}
	}
	if (dp[start][0] == oo) cout << "INFINITY\n";
	else cout << dp[start][0] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
