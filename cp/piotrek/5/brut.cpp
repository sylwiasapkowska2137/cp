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
const int oo = 1e18, K = 20;

void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>big;
	for (int i = 1; i<=n; i++){
		char c; cin >> c;
		if (c == '1') big.emplace_back(i);
	}
	int m = (int)big.size();
	if (!m){
		cout << "0\n";
		return;
	}
	int ans = 0;
	for (int mask = 1; mask<(1<<m); mask++){
		vector<int>curr;
		for (int i = 0; i<m; i++){
			if (mask&(1<<i)){
				curr.emplace_back(big[i]);
			}
		}
		vector<vector<int>>dist(n+1, vector<int>(n+1, 0));
		
		function<void(int, int, int)>dfs = [&](int v, int pa, int from){
			for (auto x: g[v]){
				if (x == pa) continue;
				dist[from][x] = dist[from][v]+1;
				dfs(x, v, from);
			}
		};

		for (int v = 1; v <= n; v++){
			dfs(v, v, v);
		}
		vector<int>bad(n+1);
		for (auto v: curr){
			bool ok = 1;
			for (auto x: curr){
				for (int k = 1; k<=n; k++){
					if (x == k || x == v || v == k) continue;
					if (dist[x][k] + dist[v][k] == dist[x][v]){
						bad[k] = 1;
					}
				}
			}
		}
		int tmp = 0;
		for (auto v: curr) if (!bad[v]) tmp++;
		for (int i = 1; i<=n; i++) if (bad[i]) tmp--;
		ans = max(ans, tmp);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
