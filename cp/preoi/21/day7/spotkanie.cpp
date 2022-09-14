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

const int MAX = 2e5+7;
vi graf[MAX], parent, depth;
LL ans2 = 1, ans = 0;
vpii G[MAX];

void dfs(int v, int pa = 1){
	parent[v] = pa;
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	}
}

void dfs2(int v, int pa = -1){
	for (auto [x, c]: G[v]){
		if (x!=pa){
			ans2++;
			ans+=c;
			dfs2(x, v);
		}
	}
}
vi REP;

int Find(int a){
	if (a == REP[a]) return a;
	return REP[a] = Find(REP[a]);
}

void Union(int a, int b, int c){
	a = Find(a);
	b = Find(b);
	if (a != b) {
		REP[a] = b;
		G[b].pb({a, c});
	}
}

struct path{
	int a, b, c;
	path() {}                                                                   
	path(int _a, int _b, int _c){                                               
		a = _a, b = _b, c = _c;                                                 
	}    
};

void solve(){
	int n, m; cin >> n >> m;
	vector<path>tab;
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	depth.assign(n+1, 0);
	parent.assign(n+1, 0);
	dfs(1, 1);
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		tab.emplace_back(a, b, c);
	}
	sort(all(tab), [](auto a, auto b){return a.c < b.c;});
	REP.assign(n+1, 0);
	iota(all(REP), 0);
	for (auto &[a, b, c]:tab){
		while (a!=b){
			if (depth[a]>depth[b]){
				Union(a, parent[a], c);
				a = Find(a);
				//debug(a);
				continue;
			}
			if (depth[b]>depth[a]){
				Union(b, parent[b], c);
				b = Find(b);
				//debug(a);
				continue;
			}
			Union(a, parent[a], c);
			Union(b, parent[b], c);
			a = Find(a), b = Find(b);
		}
	}
	dfs2(1);
	cout << ans2 << " " << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
