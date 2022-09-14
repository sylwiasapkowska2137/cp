//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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

vector<int>X = {-1, 1, 0, 0};
vector<int>Y = {0, 0, -1, 1};
vector<vector<int>>vis, point;//
vector<vector<char>>a;
int czas = 0;
pair<int, int>start;
int n, m;

void dfs(pair<int, int>v, pair<int, int>pa){
	vis[v.first][v.second] = 1;
	// pre[v.first][v.second] = low[v.first][v.second] = ++czas;
	int children = 0;
	int deg = 0;
	for (int k = 0; k<4; k++){
		pair<int, int>s = {v.first+X[k], v.second+Y[k]};
		if (s == pa) continue;
		if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
			if (a[s.first][s.second] == '#') continue;
			// debug(v, s);
			deg++;
			if (vis[s.first][s.second]){
				// low[v.first][v.second] = min(low[v.first][v.second], pre[s.first][s.second]);
			} else {
				dfs(s, v);
				// low[v.first][v.second] = min(low[v.first][v.second], low[s.first][s.second]);
				// if (low[s.first][s.second] >= pre[v.first][v.second] && pa != start){
				// 	point[v.first][v.second] = 1;
				// }
				// children++;
			}
		}
	}
	if (deg <= 2){
		point[v.first][v.second] = 1;
	}
	// if (pa == start && children > 0){
	// 	point[v.first][v.second] = 1;
	// }
}

void init(){
	vis.assign(n+1, vector<int>(m+1, 0));
	// pre.assign(n+1, vector<int>(m+1, 0));
	// low.assign(n+1, vector<int>(m+1, 0));
	point.assign(n+1, vector<int>(m+1, 0));
	a.assign(n+1, vector<char>(m+1));
	czas = 0;
}

void dfs2(pair<int, int>v){
	vis[v.first][v.second] = 1;
	vector<pair<int, int>>good;
	for (int k = 0; k<4; k++){
		pair<int, int>s = {v.first+X[k], v.second+Y[k]};
		if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
			if (a[s.first][s.second] == '#') continue;
			good.emplace_back(s);
		}
	}
	if (good.size() <= 2){
		a[v.first][v.second] = '+';
		for (auto s: good){
			if (vis[s.first][s.second]) continue;
			if (!point[s.first][s.second]) continue;
			dfs2(s);
		}
	}
}

void solve(){
	cin >> n >> m;
	init();
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
			if (a[i][j] == 'L'){
				start = {i, j};
			}
		}
	}

	dfs(start, start);

	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		cerr << point[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	if (!point[start.first][start.second]){
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=m; j++){
				cout << a[i][j];
			}
			cout << "\n";
		}
		return;
	}
	vis.assign(n+1, vector<int>(m+1, 0));
	dfs2(start);
	a[start.first][start.second] = 'L';
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cout << a[i][j];
		}
		cout << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}