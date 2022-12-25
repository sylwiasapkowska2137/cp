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
const int mod = 1100000017;

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0) a+= mod;
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	s = "$"+s;
	vector dp(n+1, vector<int>(n+1));
	for (int i = 1; i<=n; i++) dp[i][i] = 1;
	for (int len = 2; len<=n; len++){
		for (int i = 1; i<=n ; i++){
			int j = i+len-1;
			if (j > n) break;
			if (s[i] == s[j]){
				add(dp[i][j], dp[i][j-1]);
				add(dp[i][j], dp[i+1][j]+1);
			} else {
				// add(dp[i][j], dp[i][j-1]);
				add(dp[i][j], dp[i+1][j]);
				add(dp[i][j], dp[i][j-1]);
				sub(dp[i][j], dp[i+1][j-1]);
			}
		}
	}
	cout << dp[1][n] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
