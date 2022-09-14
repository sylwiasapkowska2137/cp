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

void solve(){
	int n, K; cin >> n >> K;
	string s, t; cin >> s >> t;
	vector<vector<int>>dp(n+1, vector<int>(n+1, -oo));
	//dp[i][k][ile] = max wynik
	dp[0][0] = 0;
	int c = (t[0] == t[1]);
	for (int i = 1; i<=n; i++){
		vector<vector<int>>new_dp(n+1, vector<int>(n+1, -oo));
		int a = (s[i-1] != t[0]);
		int b = (s[i-1] != t[1]);
		for (int k = 0; k<=K; k++){
			for (int ile = 0; ile<=n; ile++){
				new_dp[k][ile] = max({
					(ile - (a^1) >= 0 ? dp[k][ile-(a^1)] + (!b?ile-(a^1):0) : -oo), //no change
					(k && ile ? dp[k-1][ile-1] + (c?ile-1:0): -oo), //s[i-1] ----> t[0]
					(k && ile-c >= 0 ? dp[k-1][ile-c] + ile-c :-oo) //s[i-1] ---> t[1]
				});
				//debug(i, k, ile, dp[i][k][ile]);
			}
		}
		dp = new_dp;
	}
	int ans = 0;
	for (int i = 0; i<=K; i++){
		for (int j = 0; j<=n; j++){
			ans = max(ans, dp[i][j]);
		}
	}
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
