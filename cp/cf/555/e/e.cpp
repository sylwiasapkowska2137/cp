//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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

const int MAX = 2e5+7, K = 20;
int up[MAX][K];
vector<int>graf[MAX], rep, sz, low, pre, vis, G[MAX], depth, UP, DOWN;
int czas, nr;
vector<pair<int, int>>bridge;
map<pair<int, int>, int>cnt;

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	rep[b] = a;
}

void dfs(int v, int pa = -1){
	vis[v] = nr;
	low[v] = pre[v] = ++czas;
	for (auto x: graf[v]){
		if (x == pa) continue;
		if (vis[x]) low[v] = min(low[v], pre[x]);
		else{
			dfs(x, v);
			low[v] = min(low[v], low[x]);
			if (low[x] > pre[v] && cnt[{x, v}] == 1) bridge.push_back({x, v});
			else Union(x, v);
		}
	}

}

int LCA(int a, int b){
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = K-1; i>=0; i--){
		if (depth[b]-(1<<i) >= depth[a]){
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
}

void init(int n){
	vis.assign(n+1, 0);
	pre.assign(n+1, 0);
	low.assign(n+1, 0);
	rep.assign(n+1, 0);
	iota(rep.begin(), rep.end(), 0);
	sz.assign(n+1, 1);
}

void dfs2(int v, int pa){
	vis[v] = 1;
	up[v][0] = pa;
	for (int i = 1; i<K; i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}
	for (auto x: G[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs2(x, v);
		}
	}
}

void dfs3(int v, int pa){
	vis[v] = 1;
	for (auto x: G[v]){
		if (x!=pa){
			dfs3(x, v);
			DOWN[v] += DOWN[x];
			UP[v] += UP[x]; 
		}
	}
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		cnt[{a, b}]++;
		cnt[{b, a}]++;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	init(n);
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			nr++;
			dfs(i);
		}
	}
	vector<pair<int, int>>paths;
	for (int i = 0; i<q; i++){
		int a, b; cin >> a >> b;
		if (vis[a] != vis[b]){
			cout << "No\n";
			return;
		}
		paths.emplace_back(a, b);
	}
	//debug(bridge);
	//debug(rep);
	vector<int>scaler;
	for (int i = 1; i<=n; i++) scaler.push_back(rep[i]);
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	map<int, int>comp;
	for (int i = 0; i<(int)scaler.size(); i++) comp[scaler[i]] = i+1;
	//debug(comp);
	for (auto [a, b]: bridge){
		int A = comp[Find(a)];
		int B = comp[Find(b)];
		G[A].push_back(B);
		G[B].push_back(A);
		//debug(A, B);
	}
	int N = (int)(scaler.size());
	depth.assign(N+1, 0);
	UP.assign(N+1, 0);
	DOWN.assign(N+1, 0);
	vis.assign(N+1, 0);
	for (int i = 1; i<=N; i++){
		if (!vis[i]){
			dfs2(i, i);
		}
	}
	//debug(roots);
	for (auto [a, b]:paths){
		int A = comp[Find(a)];
		int B = comp[Find(b)];
		if (A == B) continue;
		int L = LCA(A, B);
		UP[A]++;
		UP[L]--;
		DOWN[B]++;
		DOWN[L]--;
		//debug(A, B, L);
	}
	vis.assign(N+1, 0);
	for (int i = 1; i<=N; i++){
		if (!vis[i]){
			dfs3(i, i);
		}
	}
	//debug(UP);
	//debug(DOWN);
	for (int i = 1; i<=N; i++){
		if (UP[i] > 0 && DOWN[i] > 0){
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
