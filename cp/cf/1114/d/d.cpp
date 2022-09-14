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

// #define int long long
const int oo = 1e9, K = 30;

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	int dp[n+1][n+1][2];
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++){
			if (i == j) dp[i][i][0] = dp[i][i][1] = 0;
			else dp[i][j][0] = dp[i][j][1] = oo;
		}
	}
	for (int r = 0; r<n; r++){
		for (int l = r; l>=0; l--){
			for (int k = 0; k<2; k++){
				if (l) dp[l-1][r][0] = min(dp[l-1][r][0], dp[l][r][k]+(int)((k?a[r]:a[l]) != a[l-1]));
				if (r+1 < n) dp[l][r+1][1] = min(dp[l][r+1][1], dp[l][r][k]+(int)((k?a[r]:a[l]) != a[r+1]));
			}
		}
	}
	// for (int l = 0; l<n; l++){
	// 	for (int r = l; r<n; r++){
	// 		debug(l, r, dp[l][r][0], dp[l][r][1]);
	// 	}
	// }
	cout << min(dp[0][n-1][0], dp[0][n-1][1]) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}