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

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int p(int a, int b){ //[a, b]
	return a+rng()%(b-a+1);
}

#define int long long
const int oo = 1e18, K = 30;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<char>>tab(n+1, vector<char>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> tab[i][j];
		}
	}
	vector<vector<pair<int, int>>>lizaki;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m-2; j++){
			string s;
			s += tab[i][j];
			s += tab[i][j+1];
			s += tab[i][j+2];
			if (s == "PWG" || s == "GWP"){
				vector<pair<int, int>>xd = {{i, j}, {i, j+1}, {i, j+2}};
				lizaki.emplace_back(xd);
			}
		}
	}
	for (int i = 1; i<=n-2; i++){
		for (int j = 1; j<=m; j++){
			string s;
			s += tab[i][j];
			s += tab[i+1][j];
			s += tab[i+2][j];
			if (s == "PWG" || s == "GWP"){
				vector<pair<int, int>>xd = {{i, j}, {i+1, j}, {i+2, j}};
				lizaki.emplace_back(xd);
			}
		}
	}
	for (int i = 1; i<=n-2; i++){
		for (int j = 1; j<=m-2; j++){
			string s;
			s += tab[i][j];
			s += tab[i+1][j+1];
			s += tab[i+2][j+2];
			if (s == "PWG" || s == "GWP"){
				vector<pair<int, int>>xd = {{i, j}, {i+1, j+1}, {i+2, j+2}};
				lizaki.emplace_back(xd);
			}
		}
	}
	for (int i = 2; i<=n-1; i++){
		for (int j = 2; j<=m-1; j++){
			string s;
			s += tab[i+1][j-1];
			s += tab[i][j];
			s += tab[i-1][j+1];
			if (s == "PWG" || s == "GWP"){
				vector<pair<int, int>>xd = {{i+1, j-1}, {i, j}, {i-1, j+1}};
				lizaki.emplace_back(xd);
			}
		}
	}
	int ans = 0;
	int S = (int)lizaki.size();
	vector<vector<int>>grid(n+1, vector<int>(m+1, -1));
	int t = 4e8;
	while (ans < 19119){
		int i = p(0, S-1);
		vector<int>xx;
		for (auto x: lizaki[i]){
			if (grid[x.first][x.second] != -1){
				xx.emplace_back(grid[x.first][x.second]);
			}
		}
		sort(xx.begin(), xx.end());
		xx.erase(unique(xx.begin(), xx.end()), xx.end());
		if (xx.size() >= 2) continue;
		for (auto v: xx){
			for (auto p:lizaki[v]){
				grid[p.first][p.second] = -1;
			}
		}
		for (auto v: lizaki[i]){
			grid[v.first][v.second] = i;
		}
		ans += (1-xx.size());
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (tab[i][j] == 'W' && grid[i][j] != -1){
				if (grid[i][j] == grid[i-1][j]){
					cout << "|";
				} else if (grid[i][j] == grid[i-1][j-1]){
					cout << "\\";
				} else if (grid[i][j] == grid[i][j-1]){
					cout << "-";
				} else {
					cout << "/";
				}
			} else {
				cout << tab[i][j];
			}
		}
		cout << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
