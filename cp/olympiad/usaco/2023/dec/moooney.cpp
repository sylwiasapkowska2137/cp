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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// #define int long long
const long long oo = 1e18;
//  oo2 = 1e9+7, K = 30;
const int mod = 998244353;
struct T{int p, c, x;};

void solve(){
	int n, A, B; cin >> n >> A >> B;
	vector<T>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i].p >> a[i].c >> a[i].x;
	vector<vector<long long>>dp(A+1, vector<long long>(B+1, -oo));
	vector<vector<long long>>new_dp(A+1, vector<long long>(B+1, -oo));
	dp[A][B] = 0;
	for (int i = 0; i<n; i++){
		for (int cA = 0; cA <= A; cA++){
			for (int cB = 0; cB <= B; cB++){
				// cerr << (dp[cA][cB] < 0 ? -1 : dp[cA][cB]) << " ";
				new_dp[cA][cB] = dp[cA][cB];
				for (int I = 0; I <= a[i+1].c; I++){
					if (cA >= (a[i+1].c-I) && cB >= I*a[i+1].x){
						new_dp[cA - (a[i+1].c-I)][cB - I*a[i+1].x] = 
							max(dp[cA][cB]+a[i+1].p, new_dp[cA - (a[i+1].c-I)][cB - I*a[i+1].x]);
					} 
				}
			}
		}
		dp = new_dp;
	}
	long long ans = -oo;
	for (int cA = 0; cA <= A; cA++){
		for (int cB = 0; cB <= B; cB++){
			ans = max(ans, dp[cA][cB]);
		}
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
