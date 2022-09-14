//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
	vector<vector<int>>adj(n+1, vector<int>(n+1));
	vector<vector<int>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	vector<bool>vis(n+1);
	int cnt = 0;

	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		cnt++;
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
			}
		}
	};

	dfs(1);
	if (cnt != n){
		cout << "NO\n";
		return;
	}

	vector<int>klika((1<<n), 1);
	for (int mask = 1; mask<(1<<n); mask++){
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				if (i == j) continue;
				if ((mask&(1<<i)) && (mask&(1<<j))){
					klika[mask] &= adj[i+1][j+1];
				}
			}
		}
		// debug(mask, klika[mask]);
	}
	vector<vector<int>>G((1<<n)+1);
	for (int mask = 1; mask<(1<<n); mask++){
		if (!klika[mask]) continue;
		for (int mask2 = mask+1; mask2<(1<<n); mask2++){
			if (!klika[mask2]) continue;
			int x = (mask&mask2);
			if (__builtin_popcountll(x) != 1) continue;
			// debug(mask, mask2);
			// if (!(mask == 9 && mask2 == 23)) continue;
			bool ok = 1;
			int com = 0;
			for (int i = 0; i<n; i++) if ((mask&(1<<i)) && (mask2&(1<<i))) com = i;
			// debug(com);
			for (int i = 0; i<n; i++){
				if ((mask&(1<<i)) && i != com){
					for (int j = 0; j<n; j++){
						if ((mask2&(1<<j)) && j != com){
							// debug(i+1, j+1);
							ok &= (!adj[i+1][j+1]);	
						}
					}
				}
			}
			if (ok) {
				// debug(mask, mask2);
				G[mask].emplace_back(mask2);
				G[mask2].emplace_back(mask);
				cerr << mask << " " << mask2 << "\n";
			}
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
