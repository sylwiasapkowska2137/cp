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
const int oo = 1e18, K = 30;
const int mod = 998244353;

void add(int &a, int b){
	a += b;
	if (a > mod) a-=mod;
}

int mul(int a, int b){
	return (a*b)%mod;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	a.emplace_back(oo);
	vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
	vector<vector<int>>dp2(n+1, vector<int>(n+1, 0));
	for (int i = 0; i<n; i++) {
		dp[i][i] = 1;
		dp2[i][i] = 1;
	}
	for (int len = 1; len<=n; len++){
		for (int l = 0; l<n; l++){
			int r = l+len;
			if (r >= n) break;
			//dp[l][r]
			for (int k = l; k<r; k++){
				add(dp[l][r], mul(dp2[l][k], dp[k+1][r]));
				if (a[k+1] < a[r+1]) add(dp2[l][r], mul(dp2[l][k], dp[k+1][r]));
			}
			//debug(l, r, dp[l][r]);
		}
	}
	cout << dp[0][n-1] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
