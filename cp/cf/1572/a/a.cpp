//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
	vector<vector<pair<int, int>>>g(n+1);
	vector<int>in(n+1);
	for (int i = 1; i<=n; i++){
		int k; cin >> k;
		in[i] = k;
		while (k--){
			int x; cin >> x;
			g[x].emplace_back(i, (int)(x > i));
		}
	}
	vector<int>vis(n+1);
	bool cycle = 0;

	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		for (auto [x, c]: g[v]){
			if (vis[x] == 1){
				cycle = 1;
			}
			if (!vis[x]){
				dfs(x);
			}
		}
		vis[v] = 2;
	};

	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			dfs(i);
		}
	}
	if (cycle){
		cout << "-1\n";
		return;
	}
	
	vector<int>topo;
	queue<int>q;
	for (int i = 1; i<=n; i++) if (!in[i]) q.push(i);
	while (q.size()){
		int v = q.front();q.pop();
		topo.emplace_back(v);
		for (auto [x, c]: g[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	// debug(topo);
	reverse(topo.begin(), topo.end());
	vector<int>dp(n+1);
	for (auto v: topo){
		for (auto [x, c]:g[v]){
			dp[v] = max(dp[v], dp[x] + c);
		}
	}
	cout << *max_element(dp.begin(), dp.end())+1 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}