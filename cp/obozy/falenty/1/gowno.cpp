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
	int n, m; cin >> n >> m;
	vector a(n+1, vector<char>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
		}
	}

	// vector<int>X = {-1, -1, -1, 0, 0, 1, 1, 1};
	// vector<int>Y = {-1, 0, 1, -1, 1, -1, 0, 1};

	vector dist(n+1, vector<int>(m+1, oo));
	// auto bfs = [&](bool f){
	// 	queue<pair<int, int>>q;
	// 	q.push({1, 1});
		
	// 	dist[1][1] = 0;
	// 	while (q.size()){
	// 		pair<int, int>v = q.front();q.pop();
	// 		for (int k = 0; k<9; k++){
	// 			pair<int, int>s = {v.first+X[k], v.second+Y[k]};
	// 			if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
	// 				if (a[s.first][s.second] == 'O') continue;
	// 				if (f && a[s.first][s.second] == '.') continue;
	// 				if (dist[s.first][s.second] != oo) continue;
	// 				dist[s.first][s.second] = dist[v.first][v.second] + 1;
	// 				q.push(s);
	// 			}
	// 		}
	// 	}
	// };

	// bfs(1);
	// if (dist[n][m] != oo){
	// 	cout << "-1\n";
	// 	return;
	// }
	
	vector<int>X2 = {-1, 0, 1, 0};
	vector<int>Y2 = {0, -1, 0, 1};
	set<pair<int, pair<int, int>>>s;
	dist.assign(n+1, vector<int>(m+1, oo));
	auto dijkstra = [&](){
		while (s.size()){
			int d = s.begin()->first;
			pair<int, int>v = s.begin()->second;
			s.erase(s.begin());
			if (dist[v.first][v.second] < d) continue;
			for (int k = 0; k<4; k++){
				pair<int, int>ss = {v.first + X2[k], v.second + Y2[k]};
				if (ss.first >= 1 && ss.second >= 1 && ss.first <= n && ss.second <= m){
					if (a[ss.first][ss.second] == 'X') continue;
					if (a[ss.first][ss.second] == 'O'){
						if (dist[ss.first][ss.second] > dist[v.first][v.second]){
							dist[ss.first][ss.second] = dist[v.first][v.second];
							s.insert({dist[ss.first][ss.second], ss});
						}
					} else {
						if (dist[ss.first][ss.second] > dist[v.first][v.second]+1){
							dist[ss.first][ss.second] = dist[v.first][v.second]+1;
							s.insert({dist[ss.first][ss.second], ss});
						}
					}
				}
			}
		}
	};

	for (int i = 1; i<=n; i++){
		if (a[i][1] == 'X') continue;
		if (a[i][1] == 'O') {
			s.insert({0, {i, 1}});
			dist[i][1] = 0;
		} else {
			s.insert({1, {i, 1}});
			dist[i][1] = 1;
		}
	}

	dijkstra();
	int ans = oo;
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		if (dist[i][j] == oo) cerr << "x ";
	// 		else cerr << dist[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	for (int i = 1; i<=n; i++) ans = min(ans, dist[i][m]);
	for (int i = 1; i<=m; i++) ans = min(ans, dist[1][i]);

	s.clear();
	dist.assign(n+1, vector<int>(m+1, oo));
	for (int i = 1; i<=m; i++){
		if (dist[n][i] == 'X') continue;
		if (a[n][i] == 'X') continue;
		if (a[n][i] == 'O') {
			s.insert({0, {n, i}});
			dist[n][i] = 0;
		} else {
			s.insert({1, {n, i}});
			dist[n][i] = 1;
		}
	}
	dijkstra();
	// cerr << "\n";
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		if (dist[i][j] == oo) cerr << "x ";
	// 		else cerr << dist[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	for (int i = 1; i<=m; i++) ans = min(ans, dist[1][i]);
	for (int i = 1; i<=n; i++) ans = min(ans, dist[i][m]);
	
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
