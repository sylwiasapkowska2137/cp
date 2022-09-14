//Sylwia Sapkowska
#include <bits/stdc++.h>
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
	int n; cin >> n;
	vector<int>a(n), pref(n+1);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		pref[i+1] = pref[i]+a[i];
	}
	int s = (int)sqrt(2*n+2137);
	//vector<vector<int>>dp(n+1, vector<int>(s+1, -oo));
	vector<int>dp(n+1, oo);
	//dp[i][j] = maksymalna suma ostatniego przedzialu dlugosci j, ktorego początek jest w indeksie i
	//for (int i = 0; i<=n; i++) dp[i][0] = oo;
	int ans = 1;
	for (int j = 1; j<=s; j++){
		vector<int>new_dp(n+1, -oo);
		for (int i = n-1; i>=0; i--){
			if (i+j > n) continue;
			new_dp[i] = new_dp[i+1];
			int s = pref[i+j]-pref[i];
			if (s < dp[i+j]) new_dp[i] = max(new_dp[i], s);
			//debug(i, j, dp[i][j]);
		}
		if (new_dp[0] != -oo) ans = j;
		swap(dp, new_dp);
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
