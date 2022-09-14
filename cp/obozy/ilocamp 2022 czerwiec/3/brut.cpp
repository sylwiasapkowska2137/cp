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
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	n*=2;
	vector<vector<int>>a(n+1, vector<int>(2));
	for (int j = 0; j<2; j++){
		for (int i = 1; i<=n; i++){
			cin >> a[i][j];
		}
	}
	bool dp[n+2][n/2+2][2];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;
	for (int i = 1; i<=n; i++){
		for (int ile = 0; ile<=n/2; ile++){
			if (ile) {
				if (a[i-1][0] <= a[i][0]) dp[i][ile][0] |= dp[i-1][ile-1][0]; 
				if (a[i-1][1] <= a[i][0]) dp[i][ile][0] |= dp[i-1][ile-1][1];
			}
			if (a[i-1][0] <= a[i][1]) dp[i][ile][1] |= dp[i-1][ile][0];
			if (a[i-1][1] <= a[i][1]) dp[i][ile][1] |= dp[i-1][ile][1];
		}
	}
	
	bool ans = (dp[n][n/2][0] | dp[n][n/2][1]);
	if (!ans){
		cout << "NIE\n";
		return;
	}
	string s;
	int p = n, ile = n/2;
	int m = (dp[n][n/2][1]?1:0);
	while (p){
		if (m) s += "B";
		else s += "A";
		p--;
		if (!m) ile--;
		if (dp[p][ile][0] && a[p][0] <= a[p+1][m]) m = 0;
		else m = 1;
	}
	reverse(s.begin(), s.end());
	cout << s << "\n";
	//cout << "1\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
