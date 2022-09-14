#include <bits/stdc++.h>
using namespace std;

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


const int MAX = 1e6+7;
vector<pair<int, int>>graf[MAX], edges, s;
vector<bool>bridge, vis;
vector<int>pre, low;
int tt, bb;
map<pair<int, int>, int>cnt;

void dfs(int v, int pa = -1){
	low[v] = pre[v] = ++tt;
	vis[v] = 1;
	for (auto [x, c]:graf[v]){
		if (x == pa) continue;
		else if (vis[x]) low[v] = min(low[v], pre[x]);
		else {
			dfs(x, v);
			low[v] = min(low[v], low[x]);
			if (low[x] > pre[v] && cnt[{x, v}] == 1) {
				bridge[c] = 1;
				//debug(x, v);
				bb++;
			} 
		}
	}
}

void _dfs(int v){
	for (auto [x, c]:graf[v]){
		if (!vis[c]){
			vis[c] = 1;
			s[c] = {v, x};
			_dfs(x);
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		graf[a].emplace_back(b, i);
		graf[b].emplace_back(a, i);
		cnt[{a, b}]++, cnt[{b, a}]++;
		edges.emplace_back(a, b);
	}
	s.resize(m);
	vis.assign(n+1, 0);
	low.resize(n+1);
	pre.resize(n+1);
	bridge.assign(m, 0);
	int ans = 0;
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			bb = 0;
			dfs(i);
			ans += bb+1;
		}
	}
	vis.assign(m, 0);
	for (int i = 0; i<m; i++){
		if (bridge[i]) continue;
		if (!vis[i]){
			vis[i] = 1;
			_dfs(edges[i].first);
		}
	}
	cout << ans << "\n";
	//debug(s);
	for (int i = 0; i<m; i++){
		if (bridge[i]) cout << "<";
		else {
			if (s[i] == edges[i]) cout << "<";
			else cout << ">";
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}