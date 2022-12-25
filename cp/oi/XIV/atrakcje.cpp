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

const int oo = 1e9+7;
typedef pair<int, int> T;

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<short int, short int>>>g(n);
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		a--;b--;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	vector dist(k+2, vector<int>(n, oo));
	auto dijkstra = [&](int from, int ck){
		priority_queue<T, vector<T>, greater<T>>pq;
		pq.push({0, from});
		dist[ck][from] = 0;
		while (pq.size()){
			auto [d, v] = pq.top();pq.pop();
			if (dist[ck][v] < d) continue;
			for (auto [x, c]:g[v]){
				if (dist[ck][x] > dist[ck][v] + c) {
					pq.push({dist[ck][x] = dist[ck][v] + c, x});
				}
			}
		}
	};
	for (int i = 0; i<=k; i++) dijkstra(i, i);
	dijkstra(n-1, k+1);
	vector<vector<pair<short int, int>>>G(k+2);
	g.clear();
	int mdir; cin >> mdir;
	vector<int>M(k+2);
	for (int i = 0; i<mdir; i++){
		short int a, b; cin >> a >> b;
		a--;b--;
		M[b] |= (1<<a);
	}

	vector dp((1LL<<(k+2))+2, vector<int>(k+2, oo));
	for (int v = 0; v <= k+1; v++) dp[0][v] = 0;
	for (int mask = 1; mask<(1<<(k+2)); mask++){
		for (int v = 0; v <= k+1; v++){
			for (int w = 0; w <= k+1; w++){
				if ((mask&(1<<w)) && (mask&M[v]) == M[v]){
					dp[mask][v] = min(dp[mask][v], dp[mask^(1<<w)][w] + dist[w][v]);
				}
			}
		}
	}
	int curr = 0;
	for (int i = 0; i<=k; i++) curr += (1<<i);
	int ans = oo;
	for (int v = 0; v <= k+1; v++) {
		debug(dp[curr][v]);
		ans = min(ans, dp[curr][v] + dist[v][k+1]);
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
