//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int I = 499122177;

void add(int &a, int b){
	a += b;
	if (a > mod) a-=mod;
}

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

void solve(){
	int n, k; cin >> n >> k;
	int s = 0;
	int pos = 0, ck = k;
	while (pos <= n){
		pos += ck;
		ck++;
		s++;
	}
	s+=10;//.37
	// debug(s);
	// debug(power(2, mod-2));
	// vector<vector<int>>dp(n+1, vector<int>(s+1, 0));
	// dp[0][0] = 1;
	vector<int>dp(n+1);
	dp[0] = 1;
	vector<int>ans(n+1);
	for (int move = 0; move < s; move++){
		vector<int>new_dp(n+1);
		for (int i = 0; i<=n; i++){
			// for (int j = i+k+move; j<=n; j+=(k+move)){
			if (i + k + move > n) continue;
			// debug(dp);
			add(new_dp[i+k+move], dp[i]); 
			add(dp[i+k+move], dp[i]); 
			// }
		}	
		dp = new_dp;
		// debug(dp);
		for (int i = 1; i<=n; i++){
			add(ans[i], dp[i]);
		}
		// add(ans[i], dp[pos]);
	}
	for (int pos = 1; pos <= n; pos++){
		cout << ans[pos] << " ";
	}
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}