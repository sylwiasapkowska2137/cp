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

const int MAX = 2e5+7;
vector<int>graf[MAX], gt[MAX], numer, cnt, post, scc[MAX];
int nr;
vector<bool>vis;

void dfs1(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs1(x);
		}
	}
	post.push_back(v);
}

void dfs2(int v){
	vis[v] = 1;
	numer[v] = nr;
	cnt[nr]++;
	for (auto x: gt[v]){
		if (!vis[x]) {
			dfs2(x);
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	for (int i = 0; i<m;i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
		gt[b].push_back(a);
	}
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			dfs1(i);
		}
	}
	reverse(post.begin(), post.end());
	vis.assign(n+1, 0);
	cnt.assign(n+1, 0);
	numer.assign(n+1, 0);
	for (auto x: post){
		if (!vis[x]){
			nr++;
			dfs2(x);
		}
	}
	int ans = 0;
	vector<int>dp(nr+1, 0);
	for (int i = 1; i<=nr; i++){
		if (cnt[i] > 1) dp[i] = 1;
	}
	vector<int>in(nr+1, 0);
	for (int i = 1; i<=n; i++){
		for (auto x: graf[i]){
			if (numer[i] != numer[x]){
				scc[numer[i]].push_back(numer[x]);
				in[numer[x]]++;
			}
		}
	}
	queue<int>q;
	for (int i = 1; i<=nr; i++){
		if (!in[i]) q.push(i);
	}
	vector<int>topo;
	while (!q.empty()){
		int v = q.front();q.pop();
		topo.push_back(v);
		for (auto x: scc[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	reverse(topo.begin(), topo.end());
	for (auto v: topo){
		for (auto x: scc[v]){
			dp[v] |= dp[x]; 
		}
	}
	for (int i = 1; i<=n; i++){
		if (dp[numer[i]]) ans++;
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
