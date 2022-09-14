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

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n), pref(n+1);
	int s = 0;
	for (int i = 0; i<n; i++){
		char c; cin >> c;
		if (c == '1'){
			a[i] = 1, s++;
		}
		pref[i+1] = pref[i]+a[i];
	}
	int ones = s*m;
	if (ones % n != 0){
		cout << "-1\n";
		return;
	}
	ones/=n;
	//debug(ones);
	if (ones > s){
		cout << "-1\n";
		return;
	}
	//hipoteza: wynik <= 2
	
	vector<int>t(n+1);
	for (int i = 1; i<=n; i++){
		int x = pref[i]*m-i*ones;
		if (i>=m && t[i-m] == x){
			cout << "1\n";
			cout << i-m+1 << " " << i << "\n";
			return;
		}
		t[i] = x; 
	}
	cout << "2\n";
	for (int i = 1; i<m; i++){
		if (pref[i]+pref[n]-pref[n-(m-i)] == ones){
			cout << "1 " << i << "\n" << n-(m-i)+1 << " " << n << "\n";
			return;
		}
	}
	cout << "-1\n";
	/*
	//dp[i][ones][len] = min number of intervals to achieve this state
	const int oo = 1e18;
	vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(ones+1, vector<int>(m+1, oo)));
	dp[0][0][0] = 0;
	for (int i = 1; i<=n; i++){
		for (int o = 0; o<=ones; o++){
			for (int len = 1; len<=m; len++){
				if (len == 1) {
					dp[i][a[i-1]][len] = 1;
					continue;
				}
				if (len > i) break;
				dp[i][o][len] = min((o>=a[i-1]?dp[i-1][o-a[i-1]][len-1]:oo), dp[i][o][len]);
				for (int j = 0; j<i-1; j++)	dp[i][o][len] = min((o>=a[i-1]?dp[j][o-a[i-1]][len-1]+1:oo), dp[i][o][len]);
				//debug(i, o, len, dp[i][o][len]);
			}
		}
	}
	int ans = oo;
	for (int i = 1; i<=n; i++) ans = min(ans, dp[i][ones][m]);
	cout << ans << "\n";
	*/
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
