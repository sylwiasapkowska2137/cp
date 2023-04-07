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
	int n, x; cin >> n >> x;
	vector<T>dp ((1<<n), {oo, oo});
	dp[0] = T{1, 0};
	vector<int>a(n+1);
	for (int i = 0; i<n; i++) cin >> a[i];
	
	for (int mask = 1; mask < (1<<n); mask++){
		for (int i = 0; i<n; i++){
			if (mask&(1<<i)){
				if (dp[mask^(1<<i)].second + a[i] <= x){
					dp[mask] = min(dp[mask], T{dp[mask^(1<<i)].first, dp[mask^(1<<i)].second + a[i]});
				} else {
					dp[mask] = min(dp[mask], T{dp[mask^(1<<i)].first + 1, a[i]});
				}		
			}
		}
		debug(mask, dp[mask]);
	}
	cout << dp[(1<<n)-1].first << "\n";	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
