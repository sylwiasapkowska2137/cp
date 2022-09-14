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

const int mod = 1e9+7;

void solve(){
	int h, w; cin >> h >> w;
	vector<vector<int>>dp(h+1, vector<int>(w+1, 1));
	for (LL i = 1; i<=h; i++){
		for (LL j = 1; j<=w; j++){
			dp[i][j] = dp[i-1][j]; //puste
			dp[i][j] += (4*j*dp[i-1][j-1])%mod;//niesparowany
			while (dp[i][j] >= mod) dp[i][j] -= mod;
			if (j >= 2) {
				dp[i][j] += ((j*(j-1)/2)*(LL)dp[i-1][j-2])%mod;//EW
				while (dp[i][j] >= mod) dp[i][j] -= mod;
			}
			if (i >= 2) {
				dp[i][j] += (j*(i-1)*(LL)dp[i-2][j-1])%mod;//NS
				while (dp[i][j] >= mod) dp[i][j] -= mod;
			}
		}
	}
	int ans = (dp[h][w]-1+mod)%mod;
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
