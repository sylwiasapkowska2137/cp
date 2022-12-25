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
const int mod = 1e9+7;

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

int mul(int a, int b){
	return (a*b)%mod;
}

void solve(){
	int n; cin >> n;
	vector dp(n+1, vector<int>(n+1));
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	dp[1][1] = 1;
	for (int i = 2; i<=n; i++){
		for (int j = 1; j<=i; j++){
			dp[i][j] = dp[i-1][j-1];
			add(dp[i][j], mul(j, dp[i-1][j]));
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cerr << dp[i][j] << " ";
		}
		cerr << "\n";
	}
	int len = n-1;
	int mx = 0;
	int ans = a[1];
	for (int i = 1; i<n; i++){
		mx = max(mx, a[i+1]);
		debug(len, mx);
		add(ans, mul(a[i+1]-1, dp[len-1][mx]));
		len--;
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
