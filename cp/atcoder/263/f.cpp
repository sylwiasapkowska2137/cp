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
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	int N = (1<<n);
	vector c(N, vector<int>(n));
	for (int i = 0; i<N; i++){
		for (int j = 0; j<n; j++){
			cin >> c[i][j];
		}
	}
	vector dp(N, vector<int>(n+1, -oo));
	dp[0][n] = 0;
	int x;
	for (int j = n-1; j>=0; j--){
		if (j == n-1 || j == n-2){
			x = 1;
		} else {
			x = 2*x;
		}
		for (int mask = 0; mask < N; mask++){
			for(int i = mask; i > 0; i = (i-1) & mask){
				int t = __builtin_popcountll(mask)-__builtin_popcountll(i);
				

				if (t == x){
					int C = 0;
					for (int b = 0; b<n; b++){
						if ((!(i&(1<<b))) && (mask&(1<<b))){
							C += c[b][j];
						}
					}
					dp[mask][j] = min(dp[mask][j], dp[mask^i][j+1] + C);
				}
			}	
		}
	}
	debug(dp);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
