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
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	const int S = 1e6;
	vector<LL>dp(S+1, 0);
	dp[0] = 1;
	const LL mod = 1e9+7;
	for (int i = 1; i<=n; i++){
		vector<int>div;
		for (int d = 1; d*d<=a[i]; d++){
			if (a[i]%d == 0) {
				div.emplace_back(d);
				if (d != a[i]/d) div.emplace_back(a[i]/d);
			}
		}
		sort(div.rbegin(), div.rend());
		//debug(a[i], div);
		for (auto x: div){
			dp[x] = (dp[x]+dp[x-1])%mod;
		}
	}
	LL ans = 0LL;
	for (int i = 0; i<=S; i++){
		ans = (ans+dp[i])%mod;
	}
	ans--;
	if (ans < 0) ans += mod;
	cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
