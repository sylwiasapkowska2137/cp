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
vector<int>graf[MAX], pre, low, point, sub;
vector<long long>ans;
vector<bool>vis;
int tt, n;

int dfs(int v, int pa = -1){
	pre[v] = low[v] = ++tt;
	vis[v] = 1;
	int viss = 1, blocked = 0;
	ans[v] = 2*(n-1);
	for (auto x: graf[v]){
		if (x == pa) continue;
		else if (vis[x]){
			low[v] = min(low[v], pre[x]); 
		} else {
			int t = dfs(x, v);
			viss += t;
			low[v] = min(low[v], low[x]);
			if (low[x] >= pre[v]){
				ans[v]+=(LL)(n-1-t)*t;
				blocked += t;
			}
		}
	}
	ans[v] += (LL)(n-1-blocked)*blocked;
	return viss;
}

void solve(){
	int m; cin >> n >> m;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	pre.assign(n+1, 0);
	low.assign(n+1, 0);
	vis.assign(n+1, 0);
	ans.assign(n+1, 0);
	sub.assign(n+1, 0);
	dfs(1);
	for (int i = 1; i<=n; i++) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
