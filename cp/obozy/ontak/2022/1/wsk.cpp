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
	int n, m; cin >> n >> m;
	vector<int>a(n+1), b(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++) cin >> b[i];
	vector<pair<int, int>>p;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		p.emplace_back(a, b);
	}
	sort(p.begin(), p.end());
	debug(p);
	vector<int>dp_poz(n+1), dp_pion(n+1);
	vector<vector<int>>dp(m, vector<int>(2));
	for (int i = 0; i<m; i++){
		auto [x, y] = p[i];
		dp[i][1] = b[y]+a[x];
		dp[i][0] = a[x]+b[y];
		for (int j = 0; j<i; j++){
			auto [x1, y1] = p[j];
			if (y == y1){
				dp[i][0] = max({dp[i][0], dp[j][0]+a[x], dp[j][1]+a[x]});
			}
			if (x == x1){
				dp[i][1] = max({dp[i][1], dp[j][1]+b[y], dp[j][0]+b[y]});
			}
		}
		debug(i, dp[i][0], dp[i][1]);
	}
	int ans = 0;
	for (int i = 0; i<m; i++){
		auto [x, y] = p[i];
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
	}
	cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
