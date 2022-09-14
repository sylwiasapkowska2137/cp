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
#define PI 3.14159265359

const int MAX = 2e5+7;
vpii graf[MAX];

struct E{
	int a, b, c;
};

bool cmp(E a, E b){
	return a.c < b.c;
}

int REP[MAX];

int Find(int a){
	if (a == REP[a]) return a;
	return REP[a] = Find(REP[a]);
}

void Union(int a, int b, int c){
	int A = Find(a);
	int B = Find(b);
	if (A == B) return;
	if (A < B) swap(A, B);
	REP[B] = A;
	graf[a].pb({b, c});
	graf[b].pb({a, c});
}

const int L = 19;


vector<vector<int>> up, maxi;
vi depth;
int n, czas;

void dfs(int v, int p, int w = INT_MIN){
	up[v][0] = p;
	maxi[v][0] = w;
	for (int i = 1; i<=L; i++){
		up[v][i] = up[up[v][i-1]][i-1];
		maxi[v][i] = max(maxi[v][i-1], maxi[up[v][i-1]][i-1]);
	}
	for (auto x: graf[v]){
		if (x.st!=p){
			depth[x.st] = depth[v]+1;
			dfs(x.st, v, x.nd);
		}
	}
}

void lca_init(int s){
	n = s;
	czas = 0;
	up.resize(n+1, vector<int>(L+1));
	maxi.resize(n+1, vector<int>(L+1, INT_MIN));
	depth.resize(n+1);
}

int lca(int x, int y){
	if (depth[x]<depth[y]) swap(x, y);
	for (int i = L; i>=0; i--){
		if (depth[x]-(1<<i)>=depth[y]) x = up[x][i];
	}
	if (x == y)return x;
	for (int i = L; i>=0; i--){
		if (up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

int call(int a, int b){
	int res = INT_MIN;
	for (int i = L; i>=0; i--){
		if (depth[a] - (1<<i) >= depth[b]){
			res = max(res, maxi[a][i]);
			a = up[a][i];
		}
	}
	return res;
}


void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<E>edges;
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		edges.pb({a, b, c});
	}
	sort(all(edges), cmp);
	rep(i, 1, n+1) REP[i] = i;
	for (auto [a, b, c]: edges){
		Union(a, b, c);
	}
	lca_init(n);
	dfs(1, 1);
	while (q--){
		int a, b, c; cin >> a >> b >> c;
		int x = lca(a, b);
		int res = max(call(a, x), call(b, x));
		if (res >= c) cout << "Yes\n";
		else cout << "No\n";
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
