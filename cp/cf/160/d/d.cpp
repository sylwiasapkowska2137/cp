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
	E (int _a = 0, int _b = 0, int _c = 0, int _i = 0){
		a = _a, b = _b, c = _c, i = _i;
	}
};

const int MAX = 1e6+8;
vector<E>ee[MAX];
vector<int>rep, sz, ans, d, depth;
vector<pair<int, int>> graf[MAX];
int czas;
vector<bool>vis;

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (sz[a] < sz[b]) swap(a, b);
	rep[b] = a;
	sz[a] += sz[b];
	return 1;
}

void init(int n){
	rep.resize(n+1);
	iota(rep.begin(), rep.end(), 0);
	sz.assign(n+1, 1);
}

void dfs(int v, int pa = -1){
	vis[v] = 1;
	d[v] = depth[v];
	bool flag = 0;
	for (auto [x, idx]: graf[v]){
		if (x == pa && !flag) {
			flag = 1;
			continue;
		}
		if (vis[x]) d[v] = min(d[v], depth[x]);
		else {
			depth[x] = depth[v]+1;
			dfs(x, v);
			d[v] = min(d[v], d[x]);
			if (d[x] > depth[v]){
				ans[idx]++;
			}
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	vector<E>edges;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		edges.emplace_back(a, b, c, i);
		ee[c].emplace_back(a, b, c, i);
	}
	init(n);
	ans.assign(m, 0);
	vis.assign(n+1, 0);
	d.assign(n+1, 0);
	depth.assign(n+1, 0);
	for (int i = 1; i<MAX; i++){
		vector<int>fajen;
		for (auto [a, b, c, idx]:ee[i]){
			int A = Find(a);
			int B = Find(b);
			if (A!=B){
				ans[idx] = 1;
				graf[A].push_back({B, idx});
				graf[B].push_back({A, idx});
				fajen.push_back(A);
				fajen.push_back(B);
			}
		}
		for (auto v: fajen){
			if (!vis[v]) dfs(v);
		}
		for (auto v: fajen){
			vis[v] = 0;
			graf[v].clear();
		}
		for (auto [a, b, c, idx]:ee[i]){
			Union(a, b);
		}
	}
	for (int i = 0; i<m; i++){
		if (!ans[i]) cout << "none\n";
		else if (ans[i] == 2) cout << "any\n";
		else cout << "at least one\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
