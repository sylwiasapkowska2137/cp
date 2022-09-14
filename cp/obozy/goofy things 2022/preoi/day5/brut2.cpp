//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

void solve(){
	int n, k; cin >> n >> k;
	vector<LL>a(n+1), pref(n+1, 0);
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++) pref[i] = pref[i-1]+a[i];
	vector<vector<LL>>dp(n+1, vector<LL>(k+1, 0));
	for (int ile = 1; ile<=k; ile++){
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=i; j++){
				dp[i][ile] = max(dp[i][ile], dp[j][ile-1]+(pref[i]-pref[(ile==1)?j-1:j])*(pref[n]-pref[i]));
				//if (x > dp[i][ile]){
				//	dp[i][ile] = x;
				//}
			}
			//debug(i, ile, dp[i][ile]);
		}
	}
	LL ans = 0;
	for (int i = 1; i<=n; i++){
		ans = max(ans, dp[i][k]);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
