//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> pii_set;

const int MAX = 3e5+7, INF = 1e9+7;
vi graf[MAX];
pii_set s[MAX];
set<int>bad[MAX];
int parent[MAX], cc[MAX], pre[MAX], post[MAX];
int czas, t = 1;

void dfs(int v, int pa = 1){
	parent[v] = pa;
	pre[v] = ++czas;
	s[t].insert({pre[v], v});
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, v);
		}
	}
}

vi tab;
int Size = 1;

void init(int n){
	while (Size < n) Size*=2;
	tab.assign(2*Size+1, 0);
	rep(i, 2, n+1) tab[i+Size] = 1;
	repd(i, Size-1, 1) tab[i] = tab[2*i]+tab[2*i+1];
}

void update(int pos){
	pos += Size;
	while (pos > 0){
		tab[pos]--;
		pos/=2;
	}
}

int kth(int x, int lx, int rx, int k){
	if (lx == rx) return lx;
	int m = (lx+rx)/2;
	if (tab[2*x] >= k){
		return kth(2*x, lx, m, k);
	} else return kth(2*x+1, m+1, rx, k-tab[2*x]);
}


int subtreesize(int v) {
	int stout = s[cc[v]].order_of_key({post[v], INF});
	int stin = s[cc[v]].order_of_key({pre[v], 0});
	return stout-stin;
}

void fix(int v, int p, int nc) {
	s[cc[v]].erase({pre[v], v});
	cc[v] = nc;
	s[nc].insert({pre[v], v});
	
	for (auto x: graf[v]) {
		if (x!=p && bad[x].find(v) == bad[x].end()){
			fix(x, v, nc);
		}
	}
}

void solve(){
	int n, x; cin >> n >> x;
	vi g(n);
	rep(i, 1, n-1) cin >> g[i];
	rep(i, 1, n+1) cc[i] = 1;
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	init(n);
	dfs(1, 1);
	
	int y;
	rep(i, 0, n-1){
		if (i){
			int l = (y+g[i])%(n-i-1)+1;
			x = kth(1, 0, Size-1, l);
		}
		//debug(x);
		update(x);
		y = solve(x);
		cout << y << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
