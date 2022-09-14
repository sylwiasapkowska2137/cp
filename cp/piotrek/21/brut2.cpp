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
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector up(n+1, vector<int>(K));
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

	auto lca = [&](int a, int b){
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[b] - (1<<i) >= depth[a]){
				b = up[b][i];
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

	auto d = [&](int a, int b){
		return depth[a]+depth[b]-2*depth[lca(a, b)];
	};

	vector<int>D(n+1);
	pair<int, int>ans = {-oo, oo};
	function<void(int, int)>DFS = [&](int v, int pa){
		ans = max(ans, {D[v], v});
		for (auto x: g[v]){
			if (x == pa) continue;
			D[x] = D[v] + 1;
			DFS(x, v);
		}
	};
	DFS(1, 1);
	vector<int>vis(n+1);
	queue<int>q;
	q.push(ans.second);
	vis[ans.second] = 1;
	ans = {-oo, -oo};
	D.assign(n+1, 0);
	DFS(q.front(), -1);
	vector<int>A = {q.front(), ans.second};
	q.push(ans.second);
	vis[ans.second] = 1;
	vector<int>f(n+1);

	auto calc = [&](){
		vector<int>curr;
		for (int i = 1; i<=n; i++) if (vis[i]) curr.emplace_back(i);
		debug(curr);
		int mn = oo, ile = 0;
		for (int v = 1; v <= n; v++){
			for (auto x: A){
				f[v] += d(x, v);
			}
			if (f[v] < mn){
				mn = f[v];
				ile = 1;
			} else if (f[v] == mn) ile++;
		}
	
		return ile;
	};
	vector<int>ret(n+1, 1);
	for (int i = 2; i<=n; i+=2){
		ret[i] = calc();
		A.clear();
		for (int k = 0; k < 2; k++){
			int v = q.front();q.pop();
			for (auto x: g[v]){
				if (!vis[x]){
					vis[x] = 1;
					q.push(x);
					A.emplace_back(x);
					break;
				}
			}
		}
	}
	for (int i = 1; i<=n; i++) cout << ret[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
