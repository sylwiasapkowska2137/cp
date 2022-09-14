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
	int n, m, s1, s2, e1, e2; cin >> n >> m;
	cin >> s1 >> e1 >> s2 >> e2;
	vector<vector<pair<int, int>>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}

	auto happy_dijkstra = [&](int src){
		set<pair<int, int>>s;
		vector<int>dist(n+1, oo);
		s.insert({dist[src] = 0, src});
		while (s.size()){
			auto [d, v] = *s.begin();
			s.erase(s.begin());
			if (dist[v] < d) continue;
			for (auto [x, c]:g[v]){
				if (d + c < dist[x]) {
					s.insert({dist[x] = d+c, x});
				}
			}
		}
		return dist;
	};

	auto S1 = happy_dijkstra(s1);
	auto E1 = happy_dijkstra(e1);
	auto S2 = happy_dijkstra(s2);
	auto E2 = happy_dijkstra(e2);

	vector<vector<int>>dp(n+1, vector<int>(2, oo));
	vector<pair<int, int>>curr;
	for (int i = 1; i<=n; i++){
		if (S1[e1] == S1[i] + E1[i]){
			dp[i][0] = S2[i];
			dp[i][1] = E2[i];
			curr.emplace_back(E1[i], i);
		}
	}
	int ans = S2[e2];
	sort(curr.begin(), curr.end());
	for (auto [d, v]:curr){
		for (auto [x, c]:g[v]){
			if (E1[x] + c == E1[v]){
				dp[v][0] = min(dp[v][0], dp[x][0]);
				dp[v][1] = min(dp[v][1], dp[x][1]);
			}
		}
		ans = min(ans, dp[v][0] + E2[v]);
		ans = min(ans, dp[v][1] + S2[v]);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
