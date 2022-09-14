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

const int MAX = 1e6+7;
vi graf[MAX], G[MAX];
bitset<MAX> vis, c;
bool ok;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs(x);
		}
	}
}

void dfs2(int v){
	vis[v] = 1;
	c[v] = 1;
	for (auto x: G[v]){
		if (!vis[x]) dfs2(x);
		else if (c[x]) ok = 0;
	}
	c[v] = 0;
}

void solve(){
	int n, m, m2; cin >> n >> m >> m2;
	vpii edges;
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
	}
	set<int>good;
	rep(i, 0, m2){
		int a, b; cin >> a >> b;
		edges.emplace_back(a, b);
		good.insert(a), good.insert(b);
	}
	for (auto x: good){
		vis.reset();
		dfs(x);
		rep(i, 1, n+1){
			if (good.find(i) != good.end() && vis[i] && i!=x){
				G[x].pb(i);
			}
		}
	}
	int ans = 0;
	c.reset();
	vi cycle((1<<m2), 0);
	rep(mask, 0, (1<<m2)){
		rep(i, 0, m2){
			if (mask&(1<<i)){
				cycle[mask] |= cycle[mask^(1<<i)];
			}
		}
		if (cycle[mask]) continue;
		rep(i, 0, m2){
			if (mask&(1<<i)){
				G[edges[i].st].pb(edges[i].nd);
			}
		}
		vis.reset();
		ok = 1;
		for (auto x: good) if (!vis[x] && ok) dfs2(x);
		if (ok) ans = max(ans, __builtin_popcount(mask));
		else cycle[mask] = 1;
		rep(i, 0, m2){
			if (mask&(1<<i)){
				G[edges[i].st].pop_back();
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
