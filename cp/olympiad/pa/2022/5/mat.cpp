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
typedef long double ld;


void solve(){
	int n, m; cin >> n >> m;
	vector<int>X = {1, -1, 0, 0};
	vector<int>Y = {0, 0, 1, -1};
	vector a(n+1, vector<ld>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			int ile = 0;
			for (int k = 0; k<4; k++){
				pair<int, int>s = {i+X[k], j+Y[k]};
				if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
					ile++;
				}
			}
			for (int k = 0; k<4; k++){
				pair<int, int>s = {i+X[k], j+Y[k]};
				if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
					a[s.first][s.second] = 1.0/(ld(ile));
				}
			}
		}
	}
	cerr << fixed << setprecision(5);
	cout << fixed << setprecision(17);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cerr << a[i][j] << " ";
		}
		cerr << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
