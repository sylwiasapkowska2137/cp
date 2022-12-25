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
typedef pair<int, int> T;
typedef long double ld;

void solve(){
	int n, m; cin >> n >> m;
	vector<T>town(n), chest(m);
	for (int i = 0; i<n; i++) cin >> town[i].first >> town[i].second;
	for (int i = 0; i<m; i++) cin >> chest[i].first >> chest[i].second;
	vector dp((1<<(n+1))+2, vector<vector<ld>>((1<<(m+1)), vector<ld>(n+m+1, oo)));
	
	auto dist = [&](T a, T b){
		long double x = a.first-b.first;
		long double y = a.second-b.second;
		return sqrt(x*x+y*y);
	};
	for (int i = 0; i<n; i++){
		dp[(1<<i)][0][i] = dist(town[i], make_pair(0, 0));
	}
	for (int i = n; i<n+m; i++){
		dp[0][(1<<(i-n))][i] = dist(chest[i-n], make_pair(0, 0));
	}
	for (int a = 0; a < (1<<n); a++){
		for (int b = 0; b < (1<<m); b++){
			for (int last = 0; last < n; last++){
				if (dp[a][b][last] == oo) continue;
				// debug(a, b, last, dp[a][b][last]);
				if (a&(1<<last)){
					for (int nxt = 0; nxt < n; nxt++){
						if (!(a&(1<<nxt))){
							int nmask = a^(1<<nxt);
							dp[nmask][b][nxt] = min(dp[nmask][b][nxt], 
								dp[a][b][last] + dist(town[last], town[nxt])/(ld)(pow(2, __builtin_popcountll(b))));
						}
					}
					for (int nxt = n; nxt < n+m; nxt++){
						if (!(b&(1<<(nxt-n)))){
							int nmask = b^(1<<(nxt-n));
							dp[a][nmask][nxt] = min(dp[a][nmask][nxt], 
								dp[a][b][last] + dist(town[last], chest[nxt-n])/(ld)(pow(2, __builtin_popcountll(b))));
						}
					}
				}
			}
			for (int last = n; last<n+m; last++){
				if (dp[a][b][last] == oo) continue;
				// debug(a, b, last, dp[a][b][last]);
				if (b&(1<<(last-n))){
					for (int nxt = 0; nxt < n; nxt++){
						if (!(a&(1<<nxt))){
							int nmask = a^(1<<nxt);
							dp[nmask][b][nxt] = min(dp[nmask][b][nxt], dp[a][b][last] + dist(chest[last-n], town[nxt])/(long double)(pow(2, __builtin_popcountll(b))));
						}
					}
					for (int nxt = n; nxt < n+m; nxt++){
						if (!(b&(1<<(nxt-n)))){
							int nmask = b^(1<<(nxt-n));
							dp[a][nmask][nxt] = min(dp[a][nmask][nxt], dp[a][b][last] + dist(chest[last-n], chest[nxt-n])/(long double)(pow(2, __builtin_popcountll(b))));
						}
					}
				}
			}
		}
	}
	ld ans = oo;
	for (int mask = 0; mask<(1<<m); mask++){
		for (int last = 0; last<n; last++){
			ans = min(ans, dp[(1<<n)-1][mask][last] + dist(town[last], make_pair(0, 0))/(ld)(pow(2, __builtin_popcountll(mask))));
		}
		for (int last = n; last<n+m; last++){
			ans = min(ans, dp[(1<<n)-1][mask][last] + dist(chest[last-n], make_pair(0, 0))/(ld)(pow(2, __builtin_popcountll(mask))));
		}
	}
	cout << fixed << setprecision(10) << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
