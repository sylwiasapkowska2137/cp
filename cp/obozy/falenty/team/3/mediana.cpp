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

// #define int long long
// const int oo = 1e18, oo2 = 1e9+7, K = 30;
// const int mod = 998244353;

void solve(){
	int n, ck, m; cin >> n >> ck >> m;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(2))));
	
	for (int i = 1; i<=n; i++){
		dp[i][0][0][0] = 1;
		for (int j = 0; j<=n; j++){
			for (int k = 0; k <= n; k++){
				if (j + k >= i) break;
				for (int p = 1; p<i; p++){
					if (a[i] - a[p] >= m){
						if (k) {
							dp[i][j][k][1] |= dp[p][j][k-1][0];
							dp[i][j][k][1] |= dp[p][j][k-1][1];
						}
					} else {
						if (j){
							dp[i][j][k][0] |= dp[p][j-1][k][0];
							dp[i][j][k][1] |= dp[p][j-1][k][1];
						}
					}
				}
			}
		}
	}
	bool ok = 0;
	for (int x = 0; )
	cout << (ok ? "TAK" : "NIE") << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
