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
const int oo = 1e18;
const short oo2 = 5e3+7, K = 30;
const int mod = 998244353, base = 2137;
const int base2 = 2139;

int mul(int a, int b){
	return (a*b)%mod;
}

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0) a += mod;
}

int sub2(int a, int b){
	sub(a, b);
	return a;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	s = "$" + s;
	vector<pair<int, int>>hasz(n+1);
	vector<pair<int, int>>p(n+1), inv(n+1);
	inv[0] = {1, 1}, p[0] = {1, 1};
	int I = power(base, mod-2);
	int I2 = power(base2, mod-2);
	for (int i = 1; i<=n; i++){
		p[i].first = mul(p[i-1].first, base);
		p[i].second = mul(p[i-1].second, base2);
		inv[i].first = mul(inv[i-1].first, I);
		inv[i].second = mul(inv[i-1].second, I2);
		hasz[i] = hasz[i-1];
		add(hasz[i].first, mul(p[i].first, s[i]));
		add(hasz[i].second, mul(p[i].second, s[i]));
	}

	auto H = [&](int l, int r){
		int A = mul(sub2(hasz[r].first, hasz[l-1].first), inv[l-1].first);
		int B = mul(sub2(hasz[r].second, hasz[l-1].second), inv[l-1].second);
		return make_pair(A, B);
	};

	vector<vector<short>>dp(n+1, vector<short>(n+1, oo2));
	dp[1][1] = 1;
	vector<short>DP(n+1, oo2);
	for (short i = 2; i<=n; i++){
		dp[i][i] = i;
		for (short j = 0; j<i; j++){
			//dp[j] + [j+1...i] + [j-len+1, j]
			auto B = H(j+1, i);
			short len = i-j;
			dp[i][len] = min(dp[i][len], (short)(DP[i-len]+len));
			if (j - len + 1 >= 1){
				auto A = H(j-len+1, j);
				dp[i][len] = min(dp[i][len], (short)(dp[j][len] + (short)((A == B) ? (short)0 : len)));
			} 
		}
		// debug(i);
		for (int j = 1; j<=i; j++){
			// if (dp[i][j] == oo)cerr << "x ";
			// else cerr << dp[i][j] << " ";
			DP[i] = min(DP[i], dp[i][j]);
		}
		// cerr << "\n";
		// debug(i, dp[i]);
	}
	short ans = n;
	for (int i = 1; i<=n; i++){
		ans = min(ans, dp[n][i]);
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
