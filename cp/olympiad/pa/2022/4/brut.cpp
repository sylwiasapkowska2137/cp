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

void move(vector<vector<char>>&a, int &n, int&m, char curr){
	vector<vector<char>>b(max(n, m)+1);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j] == '.') continue;
			b[(curr == 'L' || curr == 'P') ? i : j].emplace_back(a[i][j]);
		}
	}
	// for (int i = 1; i<=n; i++){
		// debug(i, b[i]);
	// }
	vector<vector<char>>c(n+1, vector<char>(m+1, '.'));
	if (curr == 'G' || curr == 'D'){
		for (int j = 1; j<=m; j++){
			if (curr == 'G'){
				for (int i = 0; i<(int)b[j].size(); i++){
					c[i+1][j] = b[j][i];
				}
			} else {
				int ptr = (int)b[j].size()-1;
				for (int i = n; i>=1; i--){
					if (ptr < 0) break;
					c[i][j] = b[j][ptr];
					ptr--;
				}
			}
		}
	} else {
		for (int i = 1; i<=n; i++){
			if (curr == 'L'){
				for (int j = 0; j<(int)b[i].size(); j++){
					c[i][j+1] = b[i][j];
				}
			} else {
				int ptr = (int)b[i].size()-1;
				for (int j = m; j>=1; j--){
					if (ptr < 0) break;
					c[i][j] = b[i][ptr];
					ptr--;
				}
			}
		}
	}
	a = c;
}

void solve(){
	int n, m; cin >> n >> m;
	vector a(n+1, vector<char>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1;j<=m; j++){
			cin >> a[i][j];
		}
	}
	int q; cin >> q;
	while (q--){
		char c; cin >> c;
		move(a, n, m, c);
		// cerr << "\n";
	}
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

	solve();
	
	return 0;
}
