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
	int n, k, p; cin >> n >> k >> p;
	vector<vector<int>>g;
	if (k&1){
		g.resize(2*n+2);
		k*=2;
		int cnt = n+1;
		for (int i = 1; i<n; i++){
			int a, b; cin >> a >> b;
			g[a].emplace_back(cnt);
			g[cnt].emplace_back(a);
			g[cnt].emplace_back(b);
			g[b].emplace_back(cnt);
			cnt++;
		}	
		n += n-1;
	} else {
		g.resize(n+1);
		for (int i = 1; i<n; i++){
			int a, b; cin >> a >> b;
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		}
	}
	queue<int>q;
	vector<int>dist(n+1, oo);
	while (p--){
		int v; cin >> v;
		q.push(v);
		dist[v] = 0;
	}

	vector<int>rep(n+1), sz(n+1, 1);
	iota(rep.begin(), rep.end(), 0);
	function<int(int)>f = [&](int a){return a == rep[a] ? a : rep[a] = f(rep[a]);};
	function<void(int, int)>u = [&](int a, int b){
		a = f(a);b=f(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		rep[b] = a;
	};
	auto sameset = [&](int a, int b){return f(a) == f(b);};
	while (q.size()){
		int v = q.front();q.pop();
		for (auto x: g[v]){
			if (dist[x] == oo){
				dist[x] = dist[v]+1;
				if (dist[x] < k/2){
					q.push(x);
				}
			}
			// debug(x, v);
			u(x, v);
		}
	}
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>depth(n+1);
	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
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
			if (depth[a] - (1<<i) >= depth[b]) {
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

	function<int(int, int)>jump = [&](int v, int ile){
		for (int i = K-1; i>=0; i--){
			if (ile&(1<<i)){
				v = up[v][i];
			}
		}
		return v;
	};
	int Q; cin >> Q;
	while (Q--){
		int a, b; cin >> a >> b;
		int l = lca(a, b);
		int d = depth[a] + depth[b] - 2*depth[l];
		if (d <= k) {
			cout << "TAK\n";
			continue;
		}
		int A, B;
		if (depth[a] - depth[l] >= k/2) A = jump(a, k/2);
		else A = jump(b, d-k/2);
		if (depth[b] - depth[l] >= k/2)	B = jump(b, k/2);
		else B = jump(a, d-k/2);
		// debug(a, b, A, B);
		if (sameset(A, B)) cout << "TAK\n";
		else cout << "NIE\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
