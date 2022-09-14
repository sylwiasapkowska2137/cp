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
const int mx = 32;
bool vis[mx][mx];
vector<pair<int, int>>g[mx][mx];
pair<int, int>match[mx][mx];

bool dfs(int a, int b){
	if (vis[a][b]) return 0;
	vis[a][b] = 1;
	for (auto x: g[a][b]){
		if ((!match[x.first][x.second].first && !match[x.first][x.second].second) || dfs(match[x.first][x.second].first, match[x.first][x.second].second)){
			match[a][b] = x;
			match[x.first][x.second] = {a, b};
			return 1;
		}
	}
	return 0;
}

void solve(){
	int n, m; cin >> n >> m;
	int block = 0;
	vector<vector<int>>blocked(n+1, vector<int>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			char c; cin >> c;
			if (c == '#'){
				blocked[i][j] = 1;
				block++;
			}
		}
	}
	vector<int>x = {1, 1, 2, 2, -1, -1, -2, -2};
	vector<int>y = {2, -2, 1, -1, 2, -2, 1, -1};
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (!blocked[i][j]){
				for (int k = 0; k<8; k++){
					pair<int, int>s = {i + x[k], j+y[k]};
					if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
						if (!blocked[s.first][s.second]){
							g[i][j].emplace_back(s);
							g[s.first][s.second].emplace_back(i, j);
						}
					}
					
				}
			}
		}
	}
	while (1){
		for (int i = 1; i<=n; i++) for (int j = 1; j<=m; j++) vis[i][j] = 0;
		bool ok = 0;
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=m; j++){
				if (!match[i][j].first && !match[i][j].second){
					ok |= dfs(i, j);
				}
			}
		}
		if (!ok) break;
	}
	int ans = 0;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (match[i][j].first) ans++;
		}
	}
	ans/=2;
	ans = n*m-block-ans;
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
