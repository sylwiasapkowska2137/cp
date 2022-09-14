//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
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

const ll oo = 1e18, K = 30;
const int nax = 1e9+7;
vector<vector<ll>>dp;
vector<vector<int>> c, pref;

//dp[i][j] = min koszt, i ludzi, j grup
//dp[i][j] = min((k<i) dp[k][j-1]+C(k+1, i));
//liczymy dp[L...R][d] dla d grup, wiemy ze optymalne k nalezy do przedzialu [optl, optr]
void rec(int d, int l, int r, int optl, int optr){ 
	if (l > r) return;
	int m = (l+r)/2;
	int opt = nax;
	for (int i = optl; i<=min(m-1, optr); i++){
		if (dp[m][d] >= dp[i][d-1]+c[i+1][m]){
			dp[m][d] = dp[i][d-1]+c[i+1][m];
			opt = i;
		}
	}
	//debug(m, d, dp[m][d], optl, optr);
	rec(d, l, m-1, optl, opt);
	rec(d, m+1, r, opt, optr);
}

void solve(){
	int n, k; cin >> n >> k;
	c.resize(n+1, vector<int>(n+1));
	pref.resize(n+1, vector<int>(n+1));
	for (int i = 1; i<=n; i++) {
		for (int j = 1; j<=n; j++){
			cin >> pref[i][j];
			pref[i][j] += pref[i][j-1]+pref[i-1][j]-pref[i-1][j-1];
		}
	}

	for (int i = 1; i<=n; i++){
		for (int j = i+1; j<=n; j++){
			c[i][j] = (pref[j][j]-pref[j][i-1]-pref[i-1][j]+pref[i-1][i-1])/2;
			c[j][i] = c[i][j];
		}
	}
	dp.resize(n+1, vector<ll>(k+1, oo));
	dp[0][0] = 0;	
	for (int i = 1; i<=k; i++) rec(i, 1, n, 0, n);
	cout << dp[n][k] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}