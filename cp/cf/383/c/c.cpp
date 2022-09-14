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
vi graf[MAX], pre, depth, sub;
int czas;

void dfs(int v, int pa = -1){
	pre[v] = ++czas;
	sub[v] = 1;
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
			sub[v] += sub[x];
		}
	}
}

struct segtree{
	vector<vi> tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, vi(2, 0));
	}
	
	void update(int l, int r, int val, int p){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)){
				tab[l+1][p] += val;
				tab[l+1][p^1] -= val;
			} 
			if (r&1){
				tab[r-1][p] += val;
				tab[r-1][p^1] -= val;
			}
			l/=2;r/=2;
		}
	}
	
	int query(int pos, int p){
		pos += size;
		int ans = 0;
		while (pos > 0){
			ans += tab[pos][p];
			pos/=2;
		}
		return ans;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vi val(n+1, 0);
	rep(i, 1, n+1) cin >> val[i];
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	depth.assign(n+1, 0);
	pre.assign(n+1, 0);
	sub.assign(n+1, 0);
	dfs(1, 1);
	segtree seg;
	seg.init(n+1);
	while (m--){
		int t; cin >> t;
		if (t == 1){
			int v, Val; cin >> v >> Val;
			seg.update(pre[v], pre[v]+sub[v]-1, Val, (depth[v])%2);
		} else {
			int v; cin >> v;
			cout << val[v] + seg.query(pre[v], (depth[v])%2) << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
