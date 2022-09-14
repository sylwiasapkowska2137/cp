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

const int MAX = 1e6+7;
vi graf[MAX], pre, post, low, depth, G[MAX];
vb vis;
set<pii>s;
int czas;

void dfs(int v, int pa = -1){
	vis[v] = 1;
	pre[v] = low[v] = czas++;
	for (auto x: graf[v]){
		if (x == pa) continue;
		if (vis[x]) low[v] = min(low[v], pre[x]);
		else{
			depth[x] = depth[v]+1;
			G[x].pb(v);
			G[v].pb(x);
			dfs(x, v);
			low[v] = min(low[v], low[x]);
			if (low[x] == pre[x]) {
				s.insert({min(v, x), max(x, v)});
			}
		}
	}
	post[v] = czas++;
}

bool subtree(int a, int b){//czy a jest w poddrzewie b
	return (pre[a]>=pre[b] && post[a]<=post[b]);
}

void DFS(int v, int pa = -1){
	pre[v] = ++czas;
	for (auto x: G[v]){
		if (x!=pa) DFS(x, v);
	}
	post[v] = ++czas;
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	pre.assign(n+1, 0);
	post.assign(n+1, 0);
	low.assign(n+1, 0);
	vis.assign(n+1, 0);
	depth.assign(n+1, 0);
	dfs(1);
	
	pre.assign(n+1, 0);
	post.assign(n+1, 0);
	DFS(1);
	
	while (q--){
		int a, b, x, y; cin >> a >> b >> x >> y;
		if (pre[a]>pre[b]) swap(a, b);
		if (pre[y]<pre[x]) swap(x, y);
		//a jest wyzej w drzewie dfs
		if (s.find({min(x, y), max(x, y)})==s.end()) cout << "TAK\n";
		else {
			int z = 0;
			if (subtree(b, y) && !subtree(a, y)) z++;
			if (subtree(a, y) && !subtree(b, y)) z++;
			if (z == 1) cout << "NIE\n";
			else cout << "TAK\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
