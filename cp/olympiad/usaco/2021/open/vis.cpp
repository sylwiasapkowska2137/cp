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

const int MAX = 1e5+7;

struct edge{
	int a, b; 
	LL w;
};

vector<pair<int, int>>graf[MAX], gt[MAX];
vector<int>post, comp;
int n;
vector<int>rep;
vector<bool>vis;
vector<LL>W[MAX];

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	rep[b] = a;
}

void dfs1(int v){
	vis[v] = 1;
	for (auto [x, c]: graf[v]){
		if (!vis[x]){
			dfs1(x);
		}
	}
	post.push_back(v);
}

void dfs2(int v){
	vis[v] = 1;
	comp.emplace_back(v);
	for (auto [x, c]:gt[v]){
		if (!vis[x]) dfs2(x);
	}
}

void solve(){
	cin >> n;
	rep.assign(n+1, 0);
	iota(rep.begin(), rep.end(), 0);
	vector<edge>e;
	for (int i = 1; i<=n; i++){
		int a, v; cin >> a >> v;
		graf[i].emplace_back(a, v);
		gt[a].emplace_back(i, v);
		e.push_back(edge{a, i, v});
	}
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			dfs1(i);
		}
	}
	reverse(post.begin(), post.end());
	vis.assign(n+1, 0);
	LL ans = 0LL;
	for (auto x: post){
		if (!vis[x]){
			dfs2(x);
			int l = comp[0];
			for (auto v: comp) Union(l, v);
			comp.clear();
		}
	}
	for (auto [a, b, w]:e){
		if (Find(a) != Find(b))	ans += w;
		else W[Find(a)].push_back(w);
	}
	for (int i = 1; i<=n; i++){
		if (W[i].empty()) continue;
		sort(W[i].begin(), W[i].end());
		for (auto x: W[i]) ans += (LL)x;
		ans -= (LL)W[i][0];
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
