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

typedef double ld;

const int M = 501;
ld dp[2*M][2*M][2];
ld d[M][M];

void solve(int P){
	int n; cin >> n;
	vector<pair<int, int>>p(n);
	for (int i = 0; i<n; i++) cin >> p[i].first >> p[i].second;
	for (int i = 0; i<n; i++) p.emplace_back(p[i]);
	for (int i = 0; i<2*n; i++){
		for (int j = 0; j<2*n; j++){
			for (int k = 0; k<2; k++){
				dp[i][j][k] = oo;
			}
		}
	}
	for (int i = 0; i<2*n; i++){
		dp[i][i][0] = 0;
		dp[i][i][1] = 0;
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			d[i][j] = sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first) + (p[i].second-p[j].second)*(p[i].second-p[j].second));
		}
	}
	for (int len = 1; len<=n; len++){
		for (int l = 0; l<n; l++){
			int r = l+len;
			for (int k = l; k<r; k++){
				dp[l][r][1] = min({dp[l][r][1], dp[l][k][1]+d[k%n][r%n]+dp[k+1][r][1], dp[l][k][0]+min(d[k%n][(k+1)%n], d[l][r%n])+dp[k+1][r][1]});
				dp[l][r][0] = min({dp[l][r][0], dp[l][k][0]+d[l][(k+1)%n]+dp[k+1][r][0], dp[l][k][0]+min(d[k%n][(k+1)%n], d[l][r%n])+dp[k+1][r][1]});
			}
			// debug(l, r, dp[l][r][0], dp[l][r][1]);
		}
	}
	if (P == 1){
		ld ans = oo;
		for (int l = 0; l<n; l++) ans = min({ans, dp[l][l+n][0], dp[l][l+n][1]});
		cout << ans << endl;
	} else {
		;
	}
	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed << setprecision(12);
	int p; cin >> p;
	int t = 1; cin >> t;
	while (t--) solve(p);
	
	return 0;
}