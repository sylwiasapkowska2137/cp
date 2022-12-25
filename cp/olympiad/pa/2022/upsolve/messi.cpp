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
const int mod = 1e9+7;

int mul(int a, int b){ return (a*b)%mod; }

void solve(){
	int n; cin >> n;
	vector<string>tab(n);
	for (int i = 0; i<n; i++) cin >> tab[i];
	vector<vector<vector<int>>> p(n), pr(n);
	auto count = [&](string &s, int idx, bool rev){
		int n = (int)s.size();
		vector dp(n, vector<vector<int>>(n+2, vector<int>(2)));
		dp[0][0][0] = 1;
		for (int i = 1; i<n; i++){
			for (int b = 0; b <= n; b++){
				if (s[i] == 'L'){
					dp[i][b][1] = dp[i-1][b][1];
					dp[i][b][0] = b ? dp[i-1][b-1][0]+dp[i-1][b-1][1] : dp[i-1][b][0];
					if (dp[i][b][0] >= mod) dp[i][b][0] -= mod;
				} else {
					dp[i][b][0] = dp[i-1][b][0];
					dp[i][b][1] = dp[i-1][b+1][0] + dp[i-1][b+1][1];
					if (dp[i][b][1] >= mod) dp[i][b][1] -= mod;
				}
			}
		}
		if (!rev) p[idx] = dp[n-1];
		else pr[idx] = dp[n-1];
	};
	for (int i = 0; i<n; i++) count(tab[i], i, 0);
	vector<string>rev = tab;
	for (int i = 0; i<n; i++){
		for (auto c: tab[i]) rev[i] += (c == 'L' ? 'P' : 'L');
	}
	for (int i = 0; i<n; i++) count(rev[i], i, 1);
	for (int i = 0; i<n; i++){
		debug(i);
		for (int last = 0; last < 2; last++){
			for (int j = 0; j<(int)tab[i].size(); j++){
				cerr << p[i][j][last] << " ";
			}
			cerr << "\n";
		}
		cerr << "\n";
		for (int last = 0; last < 2; last++){
			for (int j = 0; j<(int)tab[i].size(); j++){
				cerr << pr[i][j][last] << " ";
			}
			cerr << "\n";
		}
	}
	// return;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			if (!(i == 1 && j == 1)) continue;
			int ans = 0;
			for (int b = 0; b <= min((int)tab[i].size(), (int)tab[j].size()); b++){
				ans += mul((p[i][b][0] + p[i][b][1]), pr[j][b][0]);
				if (ans >= mod) ans -= mod;
			}
			cout << ans << " ";
		}
		// cout << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
