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
const int nax = 1e9+7, N = 8001;
int dp[N], new_dp[N];
int C[N][N];
 
void rec(int d, int l, int r, int optl, int optr){ 
	if (l > r) return;
	int m = (l+r)/2;
	int opt = nax;
	new_dp[m] = nax;
	for (int i = optl; i<=min(m-1, optr); i++){
		int t = dp[i]+C[i+1][m];
		if (new_dp[m] >= t){
			new_dp[m] = t;
			opt = i;
		}
	}
	//debug(m, d, dp[m][d], optl, optr);
	rec(d, l, m-1, optl, opt);
	rec(d, m+1, r, opt, optr);
}

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	s = "$"+s;
	vector curr(n+1, vector<int>(n+1));
	for (int l = 1; l <= n; l++){
		int p = 0;
		for (int r = l; r <= n; r++){
			curr[l][r] = curr[l][r-1];
			p += (s[r] == ')' ? -1 : 1);
			if (!p) curr[l][r]++; 
			if (p < 0) p = -oo;
		}
	}	
	for (int r = 1; r <= n; r++){
		for (int l = r; l >= 1; l--){
			C[l][r] += C[l+1][r];
			C[l][r] += curr[l][r];
		}
	}
	for (int i = 1; i<=n; i++) dp[i] = C[1][i];
	for (int i = 2; i<=k; i++) {
		rec(i, 1, n, 0, n);
		for (int j = 1; j<=n; j++) dp[j] = new_dp[j];
	}
	cout << dp[n] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}