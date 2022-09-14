//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int MAX = 1e6+7, INF = 1e9+7;
vi graf[MAX], gt[MAX], G[MAX], vis, numer, post;
int nr;

void dfs1(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]) dfs1(x);
	}
	post.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	numer[v] = nr;
	for (auto x: gt[v]){
		if (!vis[x]) dfs2(x);
	}
}

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		gt[b].pb(a);
	}
	vis.assign(n+1, 0);
	rep(i, 1, n+1) if (!vis[i]) dfs1(i);
	reverse(all(post));
	vis.assign(n+1, 0);
	numer.assign(n+1, 0);
	for (auto x: post){
		if (!vis[x]){
			nr++;
			dfs2(x);
		}
	}
	debug(numer);
	vi in(nr+1, 0), topo;
	queue<int>q;
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			if (numer[v] != numer[x]){
				G[numer[v]].pb(numer[x]);
				in[numer[x]]++;
			}
		}
	}
	rep(i, 1, nr+1) if (!in[i]) q.push(i);
	while (!q.empty()){
		int v = q.front(); q.pop();
		topo.pb(v);
		for (auto x: G[v]){
			if (--in[x] == 0) {
				q.push(x);
			}
		}
	}
	debug(topo);
	vi dp(nr+1, INF);
	reverse(all(topo));
	for (auto v: topo){
		for (auto x: G[v]){
			dp[v] = min(dp[v], dp[x]+1);
		}
		if (dp[v] == INF) dp[v] = 0;
	}
	reverse(all(topo));
	for (auto v: topo){
		for (auto x: G[v]){
			dp[x] = min(dp[x], dp[v]);
		}
	}
	int ans = 0;
	rep(i, 1, nr+1) ans = max(ans, dp[i]);
	cout << ans+1 << "\n";
	rep(i, 1, n+1) cout << dp[numer[i]] << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
