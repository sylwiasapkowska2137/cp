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
	typedef pair<int, int> T;
	T s;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
			if (a[i][j] == 'S'){
				s = {i, j};
			}
		}
	}
	vector color(n+1, vector<int>(m+1));
	queue<T>q;
	vector<int>X = {-1, 1, 0, 0};
	vector<int>Y = {0, 0, -1, 1};
	for (int k = 0; k<4; k++){
		T x = {s.first + X[k], s.second + Y[k]};
		if (x.first >= 1 && x.second >= 1 && x.first <= n && x.second <= m){
			if (a[x.first][x.second] == '#') continue;
			q.push(x);
			// debug(x, k+1);
			color[x.first][x.second] = k+1;
		}
	}
	// return;
	while (q.size()){
		T v = q.front();q.pop();
		// debug(v);
		if (v == s) continue;
		for (int k = 0; k<4; k++){
			T x = {v.first + X[k], v.second + Y[k]};
			if (x == s) continue;
			if (x.first >= 1 && x.second >= 1 && x.first <= n && x.second <= m){
				if (a[x.first][x.second] == '#') continue;
				if (color[x.first][x.second] != color[v.first][v.second] && color[x.first][x.second]){
					cout << "Yes\n";
					// debug(x, v);
					return;
				}
				if (color[x.first][x.second] == 0){
					color[x.first][x.second] = color[v.first][v.second];
					q.push(x);
				}
				
			}
		}
	}
	cout << "No\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
