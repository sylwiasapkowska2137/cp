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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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
#define debug(x) cerr << x << " "

const int MAX = 2e5+7;
vi depth, graf[MAX], sz, mini, ans, pre, post, parent;
LL LEFT;
vb vis;
int n, L, R, czas;

void dfs(int v, int pa = 0){
	mini[v] = v;
	pre[v] = ++czas;
	parent[v] = pa;
	for (auto x: graf[v]){
		if (x != pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
			sz[v]+=sz[x];
			mini[v] = min(mini[v], mini[x]);
		}
	}
	post[v] = ++czas;
}

const int INF = 1e9+7;

void solve(){
	cin >> n;
	LEFT = n*(n-1)/2;
	L = 0, R = 0;
	czas = 0;
	rep(i, 0, n) graf[i].clear();
	depth.assign(n, 0);
	pre.assign(n, 0);
	parent.assign(n, 0);
	post.assign(n, 0);
	sz.assign(n, 1);
	ans.assign(n, 0);
	vis.assign(n, 0);
	mini.assign(n, INF);
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(0);
	vll ans(n+1, 0);
	for (auto x: graf[0]) ans[0] += ((LL)sz[x]-1)*(LL)sz[x];
	ans[0]/=2;
	LEFT -= ans[0];
	
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
/*
1
9
0 1
1 2
2 3
2 6
1 5
0 4
4 7
4 8
*/
