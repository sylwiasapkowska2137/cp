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
const int oo = 1e18, mod = 1e9+7, K = 30;

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

int mul(int a, int b){
	return (a*b)%mod;
}

int power(int a, int b){
	if (!b)return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

void solve(){
	int n, k; cin >> n >> k;
	vector dp(n+1, vector<int>(k+1));
	for (int d = 1; d <= 9; d++) dp[1][d%k]++;
	for (int len = 1; len < n; len++){
		for (int ck = 0; ck < k; ck++){
			for (int d = 0; d < 10; d++){
				add(dp[len+1][(ck*10+d)%k], dp[len][ck]);
			}
		}
	}
	int ile = 0, ans = 0;
	for (int i = 1; i<=n; i++){
		debug(dp[i][0]);
		add(ile, dp[i][0]);
		int left = n-i;
		int curr = dp[i][0];
		debug(curr);
		if (left){
			curr = mul(curr, 9);
			curr = mul(curr, power(10, left-1));
		}
		debug(curr);
		add(ans, curr);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
