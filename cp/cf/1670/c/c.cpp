//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
const int mod = 1e9+7;

int mul(int a, int b){
	return (a*b)%mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n), b(n), fixed(n+1);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++) cin >> b[i];

	vector<vector<int>>g(n+1);
	for (int i = 0; i<n; i++){
		int x; cin >> x;
		if (x || a[i] == b[i]) {
			int t = (x?x:a[i]);
			if (fixed[t]){
				cout << "0\n";
				return;
			} fixed[x?x:a[i]] = 1;
		}
		g[a[i]].emplace_back(b[i]);
		g[b[i]].emplace_back(a[i]);
	}
	vector<int>vis(n+1);
	int cnt = 0;

	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		if (fixed[v]) cnt++;
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
			}
		}
	};

	int ans = 1;
	for (int i = 1; i<=n; i++){
		if (!vis[i] ){
			cnt = 0;
			dfs(i);
			if (!cnt) {
				ans = (ans*2)%mod;
			}
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}