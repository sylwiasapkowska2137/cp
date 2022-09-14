//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

#define int long long
const int oo = 1e18;

void imax(int &a, int b){
	a = max(a, b);
}

void solve(){
	int n, K; cin >> n >> K;
	string s, t; cin >> s >> t;
	int dp[n+1][n+1][n+1]; //dp[i][k][ile] = max wynik
	for (int i = 0; i<=n; i++){
		for (int j = 0; j<=n; j++){
			for (int k = 0; k<=n; k++){
				dp[i][j][k] = -oo;
			}
		}
	}
	dp[0][0][0] = 0;
	int e01 = (t[0] == t[1]);
	for (int i = 0; i<n; i++){
		int e0 = (s[i] == t[0]);
		int e1 = (s[i] == t[1]);
		for (int k = 0; k<=K; k++){
			for (int ile = 0; ile<=n; ile++){
				if (dp[i][k][ile] == -oo) continue;
				//no change
				imax(dp[i+1][k][ile+e0], dp[i][k][ile]+(e1?ile:0));
				if (k < K){
					//s[i] -> t[0]
					imax(dp[i+1][k+1][ile+1], dp[i][k][ile]+(e01?ile:0));
					//s[i] -> t[1]
					imax(dp[i+1][k+1][ile+e01], dp[i][k][ile]+ile);
				}
				//debug(i, k, ile, dp[i][k][ile]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i<=K; i++){
		for (int j = 0; j<=n; j++){
			ans = max(ans, dp[n][i][j]);
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; //cin >> t;
	while (t--) solve();
	
	return 0;
}