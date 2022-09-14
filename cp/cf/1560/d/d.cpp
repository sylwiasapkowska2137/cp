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

int lcs(vector<int>a, vector<int>b){
	int n = (int)a.size();
	int m = (int)b.size();
	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			if (a[i] == b[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
		}
	}
	return dp[n][m];
}

void solve(){
	int n; cin >> n;
	vector<int>d;
	while(n){
		d.emplace_back(n%10);
		n/=10;
	}
	reverse(d.begin(), d.end());
	int ans = oo;
	for (int k = 0; k<62; k++){
		vector<int>e;
		int K = (1LL<<k);
		while(K){
			e.emplace_back(K%10);
			K/=10;
		}
		reverse(e.begin(), e.end());
		int ptr = 0;
		for (int i = 0; i<(int)d.size(); i++){
			if (ptr < (int)e.size() && e[ptr] == d[i]){
				ptr++;
			}
		}
		ans = min(ans, ((int)d.size()-ptr)+(int)e.size()-ptr);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}