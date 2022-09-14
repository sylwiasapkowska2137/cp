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
const int mx = 30;
int adj[mx][mx];
int ans = 1;
int n, k;

void check(vector<int>curr){
	bool ok = 1;
	int c = 0;
	// debug(curr);
	for (int i = 1; i<(int)curr.size(); i++){
		ok &= (adj[curr[i-1]][curr[i]] > 0);
		c += adj[curr[i-1]][curr[i]];
	}
	if (!ok) return;
	// debug(c, curr);
	if (c <= k) {
		ans = max(ans, (int)curr.size());
	}
}

void gen(vector<int>curr){
	check(curr);
	int mn = (curr.empty() ? 1 : curr.back()+1);
	for (int i = mn; i<=n; i++){
		curr.emplace_back(i);
		gen(curr);
		curr.pop_back();
	}
}

void solve(){
	int m; cin >> n >> m >> k;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		adj[a][b] = c;
	}
	gen({1});
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
