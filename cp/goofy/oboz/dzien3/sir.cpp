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

const int N = 2e5+7, K = 20;
vpii graf[N];
LL ans = 1e18, res = 0;
struct edge{int a, b, d, i;};
vector<edge>mst;
vb used;
vi depth;
vector<vpii> dp(N, vpii(K));
vector<vi> up(N, vi(K, -1));
bool cmp(edge a, edge b) {return a.d < b.d;}

pii comb(pii a, pii b) {
	vi v = {a.st, a.nd, b.st, b.nd};
	int topTwo = -3, topOne = -2;
	for (int c : v) {
		if (c > topOne) {
			topTwo = topOne;
			topOne = c;
		} else if (c > topTwo && c < topOne) topTwo = c;
	}
	return {topOne, topTwo};
}

void dfs(int v, int pa = 0, int d = 0){
	up[v][0] = pa;
	dp[v][0] = {d, -1};
	for (auto x: graf[v]){
		if (x.st!=pa) {
			depth[x.st] = depth[v]+1;
			dfs(x.st, v, x.nd);
		}
	}
}

vi REP, SIZE;

void init_dsu(int n) {
	REP.resize(n+1);
	//SIZE.resize(n+1);
	rep(i, 1, n+1) {
		REP[i] = i;
		//SIZE[i] = 1;
	}
}

int Find(int a){
	if (a == REP[a]) return a;
	return REP[a] = Find(REP[a]);
}

bool Union(int x, int y){
	int a = Find(x);
	int b = Find(y);
	if (a == b)return 0;
	//if (SIZE[a]<SIZE[b]) swap(a, b);
	//SIZE[a]+=SIZE[b];
	REP[b] = a;
	return 1;
}

pii lca(int u, int v) {
	pii ans = {-2, -3};
	if (depth[u] < depth[v]) swap(u, v);
	repd(i, K-1, 0){
		if (depth[u]-depth[v]>=(1<<i)) {
			ans = comb(ans, dp[u][i]);
			u = up[u][i];
		}
	}
	if (u == v) return ans;
	repd(i, K-1, 0){
		if (up[u][i] != -1 && up[v][i] != -1 && up[u][i] != up[v][i]) {
			ans = comb(ans, comb(dp[u][i], dp[v][i]));
			u = up[u][i];
			v = up[v][i];
		}
	}
	ans = comb(ans, comb(dp[u][0], dp[v][0]));
	return ans;
}

void solve(){
	int n, m; cin >> n >> m;
	used.assign(m, 0);
	rep(i, 0, m){
		int a, b, d; cin >> a >> b >> d;
		mst.pb(edge{a, b, d, i});
	}
	sort(all(mst), cmp);
	init_dsu(n);
	rep(i, 0, m) {
		if (Union(mst[i].a, mst[i].b)){
			used[mst[i].i] = 1;
			graf[mst[i].a].pb({mst[i].b, mst[i].d});
			graf[mst[i].b].pb({mst[i].a, mst[i].d});
			res += (LL)mst[i].d;
		}
	}
	depth.assign(n+1, 0);
	dfs(1);
	rep(i, 1, K){
		rep(j, 1, n+1){
			if (up[j][i-1] != -1) {
				up[j][i] = up[up[j][i-1]][i - 1];
				dp[j][i] = comb(dp[j][i - 1], dp[up[j][i-1]][i - 1]);
			}
		}
	}
	rep(i, 0, m){
		if (!used[mst[i].i]){
			pii rem = lca(mst[i].a, mst[i].b);
			ans = min(ans, res+(LL)mst[i].d-(LL)rem.st);
			if (rem.nd != -1) ans=min(ans, res+(LL)mst[i].d-(LL)rem.nd);
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
