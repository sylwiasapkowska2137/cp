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

struct que{
	int a, b, idx;
};

void solve(){
	int n, r; cin >> n >> r;
	vector<int>t(n+1);
	vector<vector<int>>big(r+1), T(r+1);
	for (int i = 1; i<=n; i++) {
		cin >> t[i];
		big[t[i]].emplace_back(i);
		T[t[i]].emplace_back(i);
	}
	vector<vector<pair<int, int>>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	int qq; cin >> qq;
	vector<vector<que>>Q(r+1);
	for (int i = 0; i<qq; i++){
		int a, b, R; cin >> a >> b >> R;
		big[R].emplace_back(a);
		big[R].emplace_back(b);
		Q[R].emplace_back(que{a, b, i});
	}
	vector<int>ans(qq, -1);
	vector<vector<int>>up(n+1, vector<int>(K, 0));
	vector<int>depth(n+1), D(n+1), pre(n+1);
	int czas = 0;

	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		pre[v] = ++czas;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			D[x] = D[v]+c;
			dfs(x, v);
		}
	};
	dfs(1, 1);

	function<int(int, int)>lca = [&](int a, int b){
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[a]-(1<<i)>=depth[b]){
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

	function<void(int)>solve = [&](int type){
		// debug(type);
		sort(big[type].begin(), big[type].end());
		big[type].erase(unique(big[type].begin(), big[type].end()), big[type].end());
		sort(big[type].begin(), big[type].end(), [&](auto a, auto b){return pre[a] < pre[b];});
		// debug(big[type]);
		vector<int>V = big[type];
		for (int i = 0; i<(int)big[type].size(); i++){
			V.emplace_back(lca(big[type][i], (i == big[type].size()-1)?big[type][0]:big[type][i+1]));
		}
		sort(V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());
		int S = (int)V.size();
		map<int, int>mapa;
		for (int i = 0; i<S; i++) mapa[V[i]] = i; //wierzcholki od 0 do S-1
		sort(V.begin(), V.end(), [&](auto a, auto b){return pre[a] < pre[b];});
		// debug(v);
		vector<vector<pair<int, int>>>G(S);
		for (int i = 0; i<(int)V.size(); i++){
			int p = V[(i == S-1?0:i+1)];
			int l = lca(V[i], p);
			if (l == p) continue;
			G[mapa[l]].emplace_back(mapa[p], D[p]-D[l]);
			G[mapa[p]].emplace_back(mapa[l], D[p]-D[l]);
			// debug(l, p, D[p]-D[l]);
		}
		set<pair<int, int>>q;
		vector<int>dist(S, oo);
		for (auto x: T[type]){
			q.insert({0, mapa[x]});
			dist[mapa[x]] = 0;
		}
		while (q.size()){
			int vv = q.begin()->second;
			int d = q.begin()->first;
			q.erase(q.begin());
			if (dist[vv] < d) continue;
			for (auto [x, c]:G[vv]){
				if (dist[x] > d+c) {
					dist[x] = d+c;
					q.insert({dist[x], x});
				}
			}
		}

		// debug(dist);
		int s = 1, kkk = 1;
		while (s < S) {
			s*=2;
			kkk++;
		}
		vector<vector<int>>jump(S, vector<int>(kkk, 0));
		vector<vector<int>>minn(S, vector<int>(kkk, oo));
		vector<int>D2(S), D3(S);

		function<void(int, int)>DFS = [&](int v, int pa){
			jump[v][0] = pa;
			minn[v][0] = dist[pa]; 
			for (int i = 1; i<kkk; i++){
				jump[v][i] = jump[jump[v][i-1]][i-1];
				minn[v][i] = min(minn[v][i-1], minn[jump[v][i-1]][i-1]);
			}
			for (auto [x, c]:G[v]){
				if (x == pa) continue;
				D2[x] = D2[v]+1;
				D3[x] = D3[v]+c;
				DFS(x, v);
			}
		};

		DFS(0, 0);
		
		function<int(int, int)>lca2 = [&](int a, int b){
			if (D2[a] < D2[b]) swap(a, b);
			for (int i = kkk-1; i>=0; i--){
				if (D2[a]-(1<<i)>=D2[b]){
					a = jump[a][i];
				}
			}
			if (a == b) return a;
			for (int i = kkk-1; i>=0; i--){
				if (jump[a][i] != jump[b][i]){
					a = jump[a][i];
					b = jump[b][i];
				}
			}
			return jump[a][0];
		};

		function<int(int, int)>call = [&](int a, int l){
			int curr = min(dist[a], dist[l]);
			for (int i = kkk-1; i>=0; i--){
				if (D2[a]-(1<<i)>=D2[l]){
					curr = min(curr, minn[a][i]);
					a = jump[a][i];
				}
			}
			return curr;
		};

		for (auto &[a, b, idx]:Q[type]){
			a = mapa[a];
			b = mapa[b];

			int L = lca2(a, b);
			int d = D3[a]+D3[b]-2*D3[L];
			// debug(a, b, L, d);

			ans[idx] = d+2*min(call(a, L), call(b, L));
		}

	};
	
	for (int typ = 1; typ<=r; typ++){
		if (T[typ].size() && Q[typ].size()) solve(typ);
	}
	for (int i = 0; i<qq; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
