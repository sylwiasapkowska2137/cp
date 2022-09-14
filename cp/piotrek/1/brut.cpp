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
	int n, m, q; cin >> n >> m >> q;
	vector<vector<int>>tab(n+2, vector<int>(m+2, 1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			char c; cin >> c;
			if (c == '#') tab[i][j] = 0;
		}
	}

	function<bool()>bfs = [&](){
		vector<vector<int>>vis(n+1, vector<int>(m+1));
		vis[1][1] = 1;
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=m; j++){
				if (tab[i][j]){
					vis[i][j] |= vis[i-1][j];
					vis[i][j] |= vis[i][j-1];
				}
			}
		}
		return vis[n][m];
	};

	while (q--){
		int a, b; cin >> a >> b;
		tab[a][b] = 0;
		if (bfs()) cout << "TAK\n";
		else {
			cout << "NIE\n";
			tab[a][b] = 1;
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
