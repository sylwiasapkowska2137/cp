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

struct E{
	int a, b, c, i;
	bool mst = false;
	E() {}
	E(int _a, int _b, int _c, int _i){
		a = _a, b = _b, c = _c, i = _i;
	}
};

const int MAX = 2e5+7, K = 20;
vector<pair<int, int>>graf[MAX];
int up[MAX][K], maxi[MAX][K];
vector<int> sz, rep, depth;
long long ans;

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b, int c){
	int A = Find(a);
	int B = Find(b);
	if (A == B) return 0;
	if (sz[A] > sz[B]){
		swap(a, b);
		swap(A, B);
	}
	sz[A] += sz[B];
	rep[B] = A;
	ans += c;
	graf[a].push_back({b, c});
	graf[b].push_back({a, c});
	return 1;
}

void dfs(int v, int pa, int from){
	up[v][0] = pa;
	maxi[v][0] = from;
	for (int i = 1; i<K; i++){
		up[v][i] = up[up[v][i-1]][i-1];
		maxi[v][i] = max(maxi[v][i-1], maxi[up[v][i-1]][i-1]);
	}
	for (auto [x, c]: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v, c);
		}
	}
}

int lca(int a, int b){
	if (depth[a] > depth[b]) swap(a, b);
	int curr = 0;
	for (int i = K-1; i>=0; i--){
		if (depth[b]-(1<<i)>=depth[a]){
			curr = max(curr, maxi[b][i]);
			b = up[b][i];
		}
	}
	if (a == b) return curr;
	for (int i = K-1; i>=0; i--){
		if (up[a][i] != up[b][i]){
			curr = max(curr, maxi[a][i]);
			curr = max(curr, maxi[b][i]);
			a = up[a][i];
			b = up[b][i];
		}
	}
	curr = max(curr, maxi[a][0]);
	curr = max(curr, maxi[b][0]);
	return curr;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<E>edges;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		edges.emplace_back(a, b, c, i);
	}
	sort(edges.begin(), edges.end(), [](auto a, auto b){return a.c < b.c;});
	rep.assign(n+1, 0);
	iota(rep.begin(), rep.end(), 0);
	sz.assign(n+1, 1);
	for (auto &[a, b, c, i, added]:edges){
		if (Union(a, b, c)) added = true;
	}
	depth.assign(n+1, 0);
	dfs(1, 1, 0);
	sort(edges.begin(), edges.end(), [](auto a, auto b){return a.i < b.i;});
	for (auto [a, b, c, i, added]:edges){
		if (added){
			cout << ans << "\n";
		} else {
			cout << ans - lca(a, b) + c << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
