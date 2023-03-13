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
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;

void solve(){
	int n = 20;
	int k = 4;
	vector dp(n+1, vector<int>(k+1));
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[3][0] = 1;
	for (int ck = 1; ck<=k; ck++){
		for (int i = 0; i<=n; i++){
			for (int j = 0; j<4; j++){
				dp[i][ck] += ((1<<ck) * j <= i ? dp[i-(1<<ck)*j][ck-1] : 0);
			}
		}
	}
	for (int i = 1; i<=n; i++){
		debug(i, dp[i][k]);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
