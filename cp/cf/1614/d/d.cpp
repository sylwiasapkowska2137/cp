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
// const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	const int mx = 5e6+7;
	vector<int>cnt(mx);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i<mx; i++){
		for (int j = 2*i; j<mx; j+=i){
			cnt[i] += cnt[j];
		}
	}
	vector<int>dp(mx);
	pair<int, int>ans = {0, 1};
	for (int i = mx-1; i>=1; i--){
		dp[i] = i * cnt[i];
		for (int j = i; j < mx; j += i){
			dp[i] = max(dp[i], dp[j] + i*(cnt[i]-cnt[j]));
		}
		// debug(x, dp[x]);
		ans = max(ans, {dp[i], i});
	}
	cout << ans.first << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}