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
	int n, m; cin >> n >> m;
	vector<vector<int>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>vis(n+1);
	int cnt, e;
	vector<int>curr;
	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		e += (int)g[v].size();
		curr.emplace_back(v);
		cnt++;
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
			}
		}
	};

	vector<pair<int, int>>ans(n+1);
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			cnt = 0;e = 0;
			curr.clear();
			dfs(i);
			for (auto v: curr){
				ans[v] = {e+cnt, (int)g[v].size()+1};
			}
		}
	}
	for (int i = 1; i<=n; i++){
		int g = __gcd(ans[i].first, ans[i].second);
		cout << ans[i].first/g << " " << ans[i].second/g << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
