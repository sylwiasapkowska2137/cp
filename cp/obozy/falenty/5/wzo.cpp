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
const int mod = 998244353;
const int mx = 10, mx2 = 12;

void solve(){
	int n; cin >> n;
	vector<vector<int>>dp(mx, vector<int>(mx2));	
	dp[0][0] = 1;
	for (int i = 0; i < mx; i++) dp[1][i] = 1;
	for (int i = 2; i<mx; i++){
		for (int s = 0; s < mx2; s++){
			for (int d = 0; d < mx; d++){
				if (s >= d) {
					dp[i][s] += dp[i-1][s-d];
				}
			}
			debug(i, s, dp[i][s]);
		}
	}
	function<int(int, int, int)>f = [&](int x, int y, int len){
		if (!len) return 0LL;
		int last = x;
		for (int i = 1; i<len; i++) last/=10;
		int ans = dp[len-1][y];
		for (int i = 0; i<last; i++) {
			if (y >= i) {
				ans += dp[len-1][y-i];
			}
		}
		ans += f(x-pow(10, len-1)*last, y - last, len-1);
		debug(last, x, y, ans);
		return ans;
	};

	for (int s = 1; s <= 3; s++){
		int L = 1, R = f(n, s, 9LL);
		debug(s, R);
	}
	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
