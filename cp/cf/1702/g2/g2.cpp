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
const int oo = 1e18, K = 20;

void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>pre(n+1), depth(n+1);
	int czas;

	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		pre[v] = ++czas;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto x: g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};

	dfs(1, 1);

	function<int(int, int)>lca = [&](int a, int b){
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[a] - (1<<i) >= depth[b]){
				a = up[a][i];
			}
		}
		if (a == b) return a;
		for (int i = K-1; i>=0; i--){
			if (up[a][i] != up[b][i]){
				a = up[a][i];
				b = up[b][i];
			}
		}
		return up[a][0];
	};

	int q; cin >> q;
	while (q--){
		int k; cin >> k;
		vector<int>good(k);
		for (int i = 0; i<k; i++) cin >> good[i];
		if (k == 1){
			cout << "YES\n";
			continue;
		}
		sort(good.begin(), good.end(), [&](auto x, auto y){return pre[x] < pre[y];});
		// debug(good);
		vector<int>V = good;
		for (int i = 0; i<k; i++){
			int nx = (i == k-1?0:i+1);
			V.emplace_back(lca(good[i], good[nx]));
		}
		sort(V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());
		sort(V.begin(), V.end(), [&](auto a, auto b){return pre[a] < pre[b];});
		// debug(V);
		int S = (int)V.size();
		map<int, int>mapa;
		for (int i = 0; i<S; i++) mapa[V[i]] = i;
		vector<int>deg(S+1);
		for (int i = 0; i<S; i++){
			int nx = (i == S-1?0:i+1);
			int a = V[i], b = V[nx];
			int l = lca(a, b);
			// debug(a, b, l);
			
			if (l != b) {
				deg[mapa[l]]++;
				deg[mapa[b]]++;
			}
		}
		int leaf = 0, two = 0;
		bool ok = 1;
		for (int i = 0; i<S; i++){
			if (deg[i] == 1) leaf++;
			else if (deg[i] == 2) two++;
			else {
				ok = 0;
				break;
			}
		}
		if (!ok || leaf != 2) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}