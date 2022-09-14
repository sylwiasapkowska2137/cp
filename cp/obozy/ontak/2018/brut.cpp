//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,tune=native")
#pragma GCC optimize("unroll-loops")
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

const int MAX = 150002, K = 17;
vi graf[MAX], depth, pre, post;
int up[MAX][K], czas;

void dfs(int v, int pa){
	pre[v] = ++czas;
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	}
	post[v] = ++czas;
}

int LCA(int a, int b){
	if (depth[a] > depth[b]) swap(a, b);
	repd(i, K-1, 0){
		if (depth[b]-(1<<i)>=depth[a]){
			b = up[b][i];
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

int ans = 0;
pii para = {1, 2};

struct Path{
	int a, b, idx, lca;
	
	Path() {}
	Path(int _a, int _b, int _i){
		a = _a, b = _b, idx = _i;
		lca = LCA(a, b);
	}
};

vector<Path>path;

bool isanc(int a, int b){
	return (pre[a]<=pre[b] && post[a]>=post[b]);
}

void intersect(int a1, int b1){
	if (a1 == b1) return;
	Path& a = path[a1];
	Path& b = path[b1];
	int curr = 0, tmp = 0, lca;
	lca = LCA(a.a, b.a);
	if (!isanc(lca, a.lca) && !isanc(lca, b.lca)){
		if (isanc(a.lca, b.lca)) tmp += depth[lca]-depth[b.lca];
		else tmp += depth[lca]-depth[a.lca];
	}
	lca = LCA(a.b, b.b);
	if (!isanc(lca, b.lca) && !isanc(lca, b.lca)){
		if (isanc(a.lca, b.lca)) tmp += depth[lca]-depth[b.lca];
		else tmp += depth[lca]-depth[a.lca];
	}
	curr = max(curr, tmp);
	tmp = 0;
	lca = LCA(a.a, b.b);
	if (!isanc(lca, a.lca) && !isanc(lca, b.lca)){
		if (isanc(a.lca, b.lca)) tmp += depth[lca]-depth[b.lca];
		else tmp += depth[lca]-depth[a.lca];
	}
	lca = LCA(a.b, b.a);
	if (!isanc(lca, b.lca) && !isanc(lca, b.lca)){
		if (isanc(a.lca, b.lca)) tmp += depth[lca]-depth[b.lca];
		else tmp += depth[lca]-depth[a.lca];
	}
	curr = max(curr, tmp);
	if (curr > ans){
		ans = curr;
		para = {a1+1, b1+1};
	}
}

void solve(){
	int n, p; cin >> n >> p;
	rep(v, 2, n+1){
		int x; cin >> x;
		graf[x].pb(v);
	}
	depth.assign(n+1, 0);
	pre.assign(n+1, 0);
	post.assign(n+1, 0);
	dfs(1, 1);
	rep(i, 0, p){
		int a, b; cin >> a >> b;
		path.emplace_back(a, b, i);
	}
	 
	rep(i, 0, p){
		rep(j, i+1, p){
			intersect(i, j);
		}
	}
	cout << ans << "\n";
	// << para.st << " " << para.nd << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
