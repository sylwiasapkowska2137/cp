//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
const int mx = 1007;
int c[mx][mx];

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int mul(int a, int b){
	return (a*b)%mod;
}

int nck(int n, int k){
	if (k > n || k < 0 || n < 0) return 0;
	return c[n][k];
}

int add2(int a, int b){
	int ret = a+b;
	if (ret >= mod) ret -= mod;
	return ret;
}

void solve(){
	c[0][0] = 1;
	for (int i = 1; i < mx; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j<i; j++){
			c[i][j] = add2(c[i-1][j], c[i-1][j-1]);
		}
	}
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	vector<int>dp(n+1);
	dp[n] = 1;
	for (int i = n-1; i>=0; i--){
		if (a[i] <= 0) continue;
		for (int j = i; j<n; j++){
			add(dp[i], mul(dp[j+1], nck(j-i, a[i])));
		}
	}
	// debug(dp);
	int ans = 0;
	for (int i = 0; i<n; i++) add(ans, dp[i]);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}