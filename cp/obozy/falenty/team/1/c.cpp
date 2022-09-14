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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<int, int>>>g(n+1);

	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}

	set<pair<pair<int, int>, int>>s;
	s.insert({{0, 0}, 1});
	vector<vector<int>>dist(n+1, vector<int>(k+1, oo));
	dist[1][0] = 0;
	while (s.size()){
		int d = s.begin()->first.first;
		int ile = s.begin()->first.second;
		int v = s.begin()->second;
		s.erase(s.begin());
		if (dist[v][ile] < d){
			continue;
		}
		// debug(d, ile, v);
		for (auto [x, c] : g[v]){
			if (ile + c <= k && dist[x][ile+c] > dist[v][ile] + 1){
				// debug(x, ile+c);
				dist[x][ile+c] = dist[v][ile]+1;
				s.insert({{dist[x][ile+c], ile+c}, x});
			}
		}
	}
	int ans = oo;
	for (int i = 0; i<=k; i++) ans = min(ans, dist[n][i]);
	if (ans == oo) cout << "-1\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
