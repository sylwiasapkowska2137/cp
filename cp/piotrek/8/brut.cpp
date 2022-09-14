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
	vector<vector<int>>adj(n+1, vector<int>(n+1));
	for (int t = 0; t<m; t++){
		int a, b; cin >> a >> b;
		adj[a][b] = 1;
		while (1){
			bool any = 0;
			for (int x = 1; x<=n; x++){
				for (int y = 1; y<=n; y++){
					for (int z = 1; z<=n; z++){
						if (x == y || x == z || y == z) continue;
						if (adj[y][z] && adj[z][y] && adj[x][z] && !adj[x][y]){
							adj[x][y] = 1;
							any = 1;
						} 
					}
				}
			}
			if (!any) break;
		}
		int ans = 0;
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=n; j++){
				if (adj[i][j]){
					// debug(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
