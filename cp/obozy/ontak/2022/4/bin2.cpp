//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const int oo = 1e18, K = 30;
const int M = 1e6+1;
const int mod = 1e9+7;

int mul(int a, int b){
	return (a*b)%mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

vector<int>dp;
typedef vector<vector<int>> T;

T rec(int n, int k){
	if (n == 1){
		return {{k}};
	}
	T tab(n, vector<int>(n));
	if (n&1){
		int Y = power(2, dp[n/2]);
		int Z = power(2, (n+1)/2);
		int L = 0, R = Y-1, ans = 0;
		while (R>=L){
			int m = (L+R)/2;
			if (m*Z > k) {
				R = m-1;
			} else {
				ans = m;
				L = m+1;
			}
		}
		// debug(k-ans*Z, ans);
		T f = rec(n/2, ans);
		for (int i = 0; i<n/2; i++){
			for (int j = 0; j<n/2; j++){
				tab[i][j] = f[i][j];
				tab[i+(n+1)/2][j] = f[i][j];
				tab[i][j+(n+1)/2] = f[i][j];
				tab[i+(n+1)/2][j+(n+1)/2] = f[i][j];
			}
		}
		int curr = k-ans*Z;
		for (int i = n/2; i>=0; i--){
			tab[i][n/2] = (bool)(curr&(1<<(n/2-i)));
			tab[n-i-1][n/2] = tab[i][n/2];
			tab[n/2][i] = (bool)(curr&(1<<(n/2-i)));
			tab[n/2][n-i-1] = tab[n/2][i];
		}
		for (int i = 0; i<n/2; i++){
			tab[n/2+i][n/2] = tab[n/2-i][n/2];
			tab[n/2][n/2+i] = tab[n/2][n/2-i];
		}
	} else {
		T f	= rec(n/2, k);
		for (int i = 0; i<n/2; i++){
			for (int j = 0; j<n/2; j++){
				tab[i][j] = f[i][j];
				tab[i+n/2][j] = f[i][j];
				tab[i][j+n/2] = f[i][j];
				tab[i+n/2][j+n/2] = f[i][j];
			}
		}
	}
	return tab;
}

void solve(){
	int n; cin >> n;
	string k; cin >> k;
	int kk = 0;
	for (int i = 0; i<(int)k.size(); i++){
		kk *=2;
		kk += (k[i]-'0');
	}
	kk--;
	dp.resize(n+1);
	dp[0] = 0;
	for (int i = 1; i<=n; i++){
		if (i&1) dp[i] = dp[i/2]+(i+1)/2;
		else dp[i] = dp[i/2];
	}
	//2^dp[i] = number of ways to make matrix of size i
	// debug(dp);
	T tab = rec(n, kk);
	int ans = 0;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			ans *= 2;
			ans += tab[i][j];
			ans %= mod;
			// cerr << tab[i][j];
		}
		// cerr << endl;
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