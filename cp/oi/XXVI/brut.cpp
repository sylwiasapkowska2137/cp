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

const int MAX = 1e5+7, K = 20;
const LL INF = 1e18;
vpii graf[MAX];
int up[MAX][K];
vi type, cnt, depth, dest[MAX], closest;
vll D;

void dfs1(int v, int pa = 1){
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto [x, c]:graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			D[x] = D[v]+(LL)c;
			dfs1(x, v);
		}
	}
}

struct Query{
	int a, b, i;
	Query(){}
	Query(int _a, int _b, int _i){
		a = _a, b = _b, i = _i;
	}
};

vector<Query> query[MAX];

int lca(int a, int b){
	if (depth[a] > depth[b]) swap(a, b);
	repd(i, K-1, 0){
		if (depth[b]-(1<<i) >= depth[a]) {
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

LL dist(int a, int b){
	LL ans = D[a]+D[b]-2*D[lca(a, b)];
	return ans;
}

void dijkstra(int i, int n){
	set<pll>s;
	vll dist(n+1, INF);
	closest.assign(n+1, 0);
	for (auto x: dest[i]){
		s.insert({0, x});
		dist[x] = 0;
		closest[x] = x;
	}
	while (!s.empty()){
		LL d = s.begin()->st;
		int v = s.begin()->nd;
		s.erase(s.begin());
		if (dist[v] < d) continue;
		for (auto [x, c]:graf[v]){
			if (dist[x] > d+c){
				dist[x] = d+c;
				closest[x] = closest[v];
				s.insert({dist[x], x});
			}
		}
	}
}

void solve(){
	int n, r; cin >> n >> r;
	type.resize(n+1);
	cnt.assign(r+1, 0);
	rep(i, 1, n+1){
		cin >> type[i];
		cnt[type[i]]++;
		dest[type[i]].pb(i);
	}
	rep(i, 1, n){
		int a, b, c; cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	depth.assign(n+1, 0);
	D.assign(n+1, 0);
	dfs1(1);
	int q; cin >> q;
	rep(i, 0, q){
		int a, b, s; cin >> a >> b >> s;
		query[s].emplace_back(a, b, i);
	}
	int S = max(1, (int)sqrt(n));
	vll ans(q, INF);
	rep(i, 1, r+1){
		for (auto [a, b, idx]: query[i]){
			for (auto c:dest[i]){
				ans[idx] = min(ans[idx], dist(a, c)+dist(b, c));
			}
		}
	}
	rep(i, 0, q){
		if (ans[i] == INF) cout << "-1\n";
		else cout << ans[i] << "\n";
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
