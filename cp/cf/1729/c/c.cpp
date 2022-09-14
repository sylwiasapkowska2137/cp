//Sylwia Sapkowska
#include <bits/stdc++.h>
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

void solve(){
	string s; cin >> s;
	int n = (int)s.size();
	s = "$" + s;
	
	if (s[1] == s[n]){
		cout << "0 ";
		int cnt = 0;
		for (auto x: s){
			if (x == s[1]) cnt++;
		}
		cout << cnt << "\n";
		for (int i = 1; i<=n; i++){
			if (s[i] == s[1]){
				cout << i << " ";
			}
		}
		cout << "\n";
		return;
	}
	int ans = abs(s[1]-s[n]);
	if (s[1] < s[n]){
		vector dp(n+1, vector<pair<int, int>>(K, {-oo, -oo}));
		dp[1][s[1]-'a'] = {1, 0};
		for (int i = 2; i<=n; i++){
			pair<int, int> curr = {0, 0};
			for (char c = 'a'; c <= 'z'; c++){
				curr = max(curr, dp[i-1][c-'a']);
				dp[i][c-'a'] = {curr.first+1, i};
			}
		}
		cout << ans << " " << dp[n][s[n]-'a'].first << "\n";
		int pos = n;
		char c = s[n];
		vector<int>ans;
		while (pos > 1){
			ans.emplace_back(dp[pos][c-'a'].second);
			pos = dp[pos][c-'a'].second;
			c = s[pos];
		}
		reverse(ans.begin(), ans.end());
		for (auto x: ans) cout << x << " ";
		cout << "\n";
		return;
	} else {
		
	}

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}