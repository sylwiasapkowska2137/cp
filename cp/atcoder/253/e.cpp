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

void add(int&a, int b){
	b %= mod;
	a %= mod;
	a += b;
	if (a >= mod) a-=mod;
}

int sub(int a, int b){
	a %= mod;
	b %= mod;
	a -= b;
	if (a < 0) a+=mod;
	return a;
}

int mul(int a, int b){
	return (a*b)%mod;
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	if (!k){
		int ans = 1;
		for (int i = 1; i<=n; i++){
			ans = mul(ans, m);
		}
		cout << ans << "\n";
		return;
	}
	vector<int>dp(m+1, 1), pref(m+1);
	iota(pref.begin(), pref.end(), 0);
	for (int i = 2; i<=n; i++){
		vector<int>new_dp(m+1, 0);
		for (int j = 1; j<=m; j++){
			//[1, j-k]
			if (j-k >= 1) add(new_dp[j], pref[j-k]);
			//[j+k, m];
			if (j+k <= m) add(new_dp[j], sub(pref[m], pref[j+k-1]));
		}
		dp = new_dp;
		pref[0] = 0;
		for (int j = 1; j<=m; j++){
			pref[j] = pref[j-1]+dp[j]; 
		}
	}
	int ans = 0;
	for (int i = 1; i<=m; i++){
		add(ans, dp[i]);
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
