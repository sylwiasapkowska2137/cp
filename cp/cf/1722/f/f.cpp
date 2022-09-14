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

void solve(){
	int n, m; cin >> n >> m;
	int what = 0;
	vector a(n+2, vector<char>(m+2, '.'));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
			if (a[i][j] == '*') what++;
		}
	}
	vector<int>X = {-1, 0, 1, 0};
	vector<int>Y = {0, 1, 0, -1};
	vector<pair<int, int>>middle;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j] != '*') continue;
			int cnt = 0;
			for (int k = 0; k<4; k++){
				int nxt = (k+1)%4;
				pair<int, int>s = {i + X[k], j + Y[k]};
				pair<int, int>t = {i + X[nxt], j + Y[nxt]};
				// debug(i, j, s, t);
				if (a[s.first][s.second] == '*' && a[t.first][t.second] == '*'){
					cnt++;
				}
			}
			if (cnt > 1){
				cout << "NO\n";
				return;
			} else if (cnt == 1) {
				middle.emplace_back(i, j);
			}
		}
	}
	// debug(2137);
	// debug(middle);
	int ile = (int)middle.size()*3;
	// debug(what, ile);
	if (ile != what){
		cout << "NO\n";
		return;
	}
	// debug(middle);
	int xd = 0;
	vector color(n+1, vector<int>(m+1));
	for (auto [i, j]: middle){
		xd++;
		color[i][j] = xd;
		for (int k = 0; k<4; k++){
			int nxt = (k+1)%4;
			pair<int, int>s = {i + X[k], j + Y[k]};
			pair<int, int>t = {i + X[nxt], j + Y[nxt]};
			// debug(i, j, s, t);
			if (a[s.first][s.second] == '*' && a[t.first][t.second] == '*'){
				color[s.first][s.second] = xd;
				color[t.first][t.second] = xd;

			}
		}
	}
	vector<int>X2 = {-1, -1, -1, 0, 0, 1, 1, 1};
	vector<int>Y2 = {-1, 0, 1, -1, 1, -1, 0, 1};
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j] == '.') continue;
			for (int k = 0; k<8; k++){
				pair<int, int>s = {i + X2[k], j + Y2[k]};
				if (a[s.first][s.second] == '*' && color[i][j] != color[s.first][s.second]){
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}