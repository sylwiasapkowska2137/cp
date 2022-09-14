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

// #define int long long
const int oo = 1e9+7, K = 30;

void solve(){
	int n; cin >> n;
	vector<int>a(n+1), w(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++) cin >> w[i];
	int dp[n+1][n+1][2][2];
	for (int i = 0; i<=n; i++){
		for (int j = 0; j<=n; j++){
			for (int k = 0; k<2; k++){
				for (int l = 0; l<2; l++){
					dp[i][j][k][l] = -oo;
				}
			}
		}
	}
	int ans = -oo;
	for (int i = 1; i<=n; i++){
		dp[i][i][1][0] = w[i];
		dp[i][i][1][1] = w[i];
		for (int k = 0; k<2; k++){
			for (int l = 0; l<2; l++){
				for (int fi = 1; fi < i; fi++){
					for (int j = 1; j<i; j++){
						//dp[i][k][l]
						if (l && a[j] < a[i]) dp[i][fi][k][l] = max(dp[i][fi][k][l], dp[j][fi][k^1][l^1]+w[i]); 
						if (!l && a[j] > a[i]) dp[i][fi][k][l] = max(dp[i][fi][k][l], dp[j][fi][k^1][l^1]+w[i]);
					}
				}
			}
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=i; j++){
			for (int l = 0; l<2; l++){
				if (l && a[i] > a[j]) ans = max(ans, dp[i][j][0][l]);
				if (!l && a[i] < a[j]) ans = max(ans, dp[i][j][0][l]);
			}
		}
	}
	if (ans == -oo) cout << "NO\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
