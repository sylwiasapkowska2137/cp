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

// #define int long long
const int oo = 2e9+1, K = 30;

struct edge{
	int a, b, c;
	edge(int _a = 0, int _b = 0, int _c = 0){
		a = _a;
		b = _b;
		c = _c;
	}
};

vector<int>rep, ok;
	
int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

const int M = 6001;
int d[M][M][2];
vector<vector<int>>tab;

bool Union(int a, int b, int c, int ww){
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (tab[a].size() < tab[b].size()) swap(a, b);
	for (auto x: tab[b]){
		for (auto y: tab[a]){
			d[x][y][ww] = c;
			d[y][x][ww] = c;
		}
	}
	for (auto x: tab[b]) tab[a].emplace_back(x);
	rep[b] = a;
	return 1;
}

bool Union2(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (a < b) swap(a, b);
	rep[b] = a;
	ok[a] |= ok[b];
	return 1;
}


void solve(){
	int n, m; cin >> n >> m;
	vector<edge>e[2];
	for (int i = 0; i<m; i++){
		int a, b, w, c; cin >> a >> b >> w >> c;
		e[c].emplace_back(a, b, w);
	}
	
	if (n <= 6000){
		tab.resize(n+1);
		for (int ww = 0; ww<2; ww++){
			rep.resize(n+1);
			for (int i = 1; i<=n; i++){
				for (int j = 1; j<=n; j++){
					d[i][j][ww] = -1;
				}
			}
			for (int i = 1; i<=n; i++) tab[i] = {i};
			iota(rep.begin(), rep.end(), 0);	
			sort(e[ww].begin(), e[ww].end(), [&](auto a, auto b){return a.c < b.c;});
			for (auto [a, b, c]:e[ww]) {
				Union(a, b, c, ww);
				// cerr << a << " " << b << " " << c << endl;
			}
			// cerr << endl;
		}
		int ans = oo;
		for (int i = 1; i<=n; i++){
			for (int j = i+1; j<=n; j++){
				if (d[i][j][0] == -1 || d[i][j][1] == -1) continue;
				ans = min(ans, d[i][j][0]+d[i][j][1]);
			}
		}
		if (ans == oo) cout << "-1\n";
		else cout << ans << endl;
		return;
	}
	
	vector<vector<int>>g(n+1);
	for (auto [a, b, c]:e[0]){
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	int nr;
	vector<int>numer(n+1, -1);

	function<void(int)>dfs = [&](int v){
		numer[v] = nr;
		for (auto x: g[v]){
			if (numer[x] == -1){
				dfs(x);
			}
		}
	};

	for (int i = 1; i<=n; i++){
		if (numer[i] == -1){
			nr++;
			dfs(i);
		}
	}

	int L = 1, R = 1e9+7;
	int ans = oo;
	for
	while (R>=L){
		int m = (L+R)/2;
		vector<vector<int>>G(n+1);
		for (auto [a, b, c]:e[1]){
			if (c <= m){
				G[a].emplace_back(b);
				G[b].emplace_back(a);
			}
		}
		vector<bool>vis(n+1);
		vector<int>curr;
		function<void(int)>dfs2 = [&](int v){
			curr.emplace_back(numer[v]);
			vis[v] = 1;
			for (auto x:G[v]){
				if (!vis[x]){
					dfs2(x);
				}
			}
		};
		bool ok = 0;
		for (int i = 1; i<=n; i++){
			if (!vis[i]){
				dfs2(i);
				sort(curr.begin(), curr.end());
				for (int i = 1; i<(int)curr.size(); i++) {
					if (curr[i] == curr[i-1]){
						ok = 1;
						break;
					}
				}
				curr.clear();
			}
		}
		if (ok){
			ans = m;
			R = m-1;
		} else L = m+1;
	}
	if (ans == oo) cout << "-1\n";
	else cout << ans+1 << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
