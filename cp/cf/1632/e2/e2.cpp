/*
	Author: sysia
	30.01.2022 21:59:03
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
 
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

#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

const int MAX = 3e5+7, K = 20, INF = 1e9+7;
vi graf[MAX], depth, D[MAX];
vector<vi>up;

void dfs(int v, int pa = 1){
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	}
}

int lca(int a, int b){
	if (depth[a] < depth[b]) swap(a, b);
	repd(i, K-1, 0){
		if (depth[a]-(1<<i)>=depth[b]){
			a = up[a][i];
		}
	}
	if (a == b) return a;
	repd(i, K-1, 0){
		if (up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

int dist(int a, int b){
	return depth[a]+depth[b]-2*depth[lca(a, b)];
}

void solve(){
	int n; cin >> n;
	rep(i, 1, n+1) {
		graf[i].clear();
		D[i].clear();
	}
	up.assign(n+1, vi(K, 0));
	depth.assign(n+1, 0);
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(1);
	
	vi que(n);
	iota(all(que), 1);
	sort(all(que), [](int a, int b){return depth[a] < depth[b];});
	vi ans(n+1, depth[que.back()]);
	int x = que.back();
	int y = x;
	int d = 0;
	repd(i, sz(que)-1, 1){
		int z = que[i];
		int a = dist(x, z);
		int b = dist(y, z);
		if (a >= max(d, b)){
			y = z;
			d = a;
		} else if (b >= max(d, a)){
			x = z;
			d = b;
		}
		debug(z, x, y, d);
		int w = depth[que[i-1]]-(d+1)/2;
		if (w>0) ans[w] = min(ans[w], depth[que[i-1]]);
	}
	repd(i, n-1, 1) ans[i] = min(ans[i], ans[i+1]);
	rep(i, 1, n+1) cout << ans[i] << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
