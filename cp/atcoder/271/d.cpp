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

void solve(){
	int n, S; cin >> n >> S;
	vector<int>a(n+1), b(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i] >> b[i];
	}
	vector<vector<int>>dp(n+1, vector<int>(S+1));
	dp[0][0] = 1;
	for (int i = 1; i<=n; i++){
		for (int s = 0; s <= S; s++){
			if (s >= a[i]){
				dp[i][s] |= dp[i-1][s-a[i]];
			} 
			if (s >= b[i]){
				dp[i][s] |= dp[i-1][s-b[i]];
			}
		}
	}
	if (dp[n][S]){
		cout << "Yes\n";
		int sum = S;
		string ans;
		for (int pos = n; pos >= 1; pos--){
			if (sum >= a[pos]){
				if (dp[pos-1][sum-a[pos]]){
					ans += "H";
					sum -= a[pos];
				} else {
					ans += "T";
					sum -= b[pos];
				}
			} else {
				ans += "T";
				sum -= b[pos];
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	} else {
		cout << "No\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
