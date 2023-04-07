//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
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
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int n, d, tt; cin >> n >> d >> tt;
	vector C(n+1, vector<int>(n+1, oo));
	vector<int>t(n+1);
	for (int i = 1; i<=n; i++) cin >> t[i];
	for (int i = 1; i<=n; i++){
		int mn = oo;
		int cnt = 0;
		for (int j = i; j<=n; j++){
			mn = min(mn+1, t[j]);
			if (mn <= tt) cnt++;
			C[i][j] = cnt;
		}
	}
	vector dp(n+1, vector<int>(d+2, oo));
	dp[0][0] = 0;
    for (int i = 1; i<=n; i++){
        dp[i][1] = C[1][i];
        debug(dp[i][1]);
        for (int cd = 1; cd <= d+1; cd++){
            for (int j = 0; j<i; j++){
                dp[i][cd] = min(dp[i][cd], dp[j][cd-1] + C[j+1][i]);
            }
            debug(i, cd, dp[i][cd]);
        }
    }
    cout << dp[n][d+1] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}