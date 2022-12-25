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
const int mx = 2e4+7;
// const int mx = 10;

bool solve(vector<int>a, int dest, bool ok = 1){
	int n = (int)a.size();
	vector<int>dp(2*mx+3, -2);
	auto f = [&](int x){return x+mx;};
	// debug(a);
	dp[f(0)] = -1;
	for (int step = 0; step < n; step++){
		// debug(dp);
		vector<int>new_dp(2*mx+3, -2);
		for (int i = -mx; i<=mx; i++){
			if (dp[f(i)] == step-1){
				if ((ok == 1 || step > 0) && i - a[step] >= -mx) new_dp[f(i-a[step])] = step;
				if (i + a[step] <= mx) new_dp[f(i+a[step])] = step;
			}
		}
		dp = new_dp;
		// debug(step, dp);
	}
	// debug(dp[f(dest)]);
	if (dp[f(dest)] != -2) return 1;
	return 0;
}

void solve(){
	int n, x, y; cin >> n >> x >> y;
	vector<int>A, B;
	for (int i = 1; i<=n; i++){
		int x; cin >> x;
		if (i&1) A.emplace_back(x);
		else B.emplace_back(x);
	}
	if (solve(A, x, 0) && solve(B, y, 1)) cout << "Yes\n";
	else cout << "No\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
