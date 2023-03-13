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

void solve(){
	int n; cin >> n;
	vector<int>x(n), h(n);
	for (int i = 0; i<n; i++) cin >> x[i] >> h[i];
	int N1, H1, N2, H2; cin >> N1 >> H1 >> N2 >> H2;
	if (H1 < H2){
		swap(H1, H2);
		swap(N1, N2);
	}
	int ans = 1;
	for (int rep = 0; rep < 2; rep++){
		for (int l = 0; l < n; l++){
			vector<vector<int>>dp(N1+1, vector<int>(N2+1, 0));
			dp[N1][N2] = 1;
			for (int r = l+1; r < n; r++){
				vector<vector<int>>new_dp(N1+1, vector<int>(N2+1, 0));
				int dist = abs(x[r] - x[r-1]) - h[r-1];
				if (dist <= 0) {
					ans = max(ans, r-l+1);
					continue;
				}
				for (int a = 0; a <= N1; a++){
					for (int b = 0; b <= N2; b++){
						if (dp[a][b]){
							for (int ileA = 0; ileA <= a; ileA++){
								for (int ileB = 0; ileB <= b; ileB++){
									if (ileA * H1 + ileB * H2 >= dist){
										new_dp[a-ileA][b-ileB] = 1;
									}
								}
							}
						}
					}
				}
				bool ok = 0;
				for (int a = 0; a <= N1; a++){
					for (int b = 0; b <= N2; b++){
						ok |= new_dp[a][b];
					}
				}
				if (ok) ans = max(ans, r-l+1);
				else break;
				dp = new_dp;
			}
		}
		reverse(x.begin(), x.end());
		reverse(h.begin(), h.end());
	}
	cout << ans + N1 + N2 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
