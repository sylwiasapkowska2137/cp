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

typedef vector<vi> vvi;
const int MAX = 2e5+7;
int a[MAX][2];
const int INF = 1e9+7;
int n;

struct node{
	int tab[2][2] = {{INF, INF}, {INF, INF}};
};

struct segtree{
	vector<node>tab;
	int size = 1;
	node EMPTY;
	
	void init(int n){
		while (size < n) size*=2;
		tab.resize(2*size+1);
	}
	
	bool Empty(node x){
		rep(i, 0, 2){
			rep(j, 0, 2){
				if (x.tab[i][j] != INF) return 0;
			}
		}
		return 1;
	}
	
	node merge(node x, node y, int mid){
		//merge [..., mid], [mid+1, ...]
		if (Empty(x)) return y;
		if (Empty(y)) return x;
		node ans;
		rep(i, 0, 2){
			rep(j, 0, 2){
				rep(k, 0, 2){
					rep(l, 0, 2){
						if (a[mid][k] <= a[mid+1][l]){
							ans.tab[i][j] = min(ans.tab[i][j], x.tab[i][k]+y.tab[l][j]-1);
						} else {
							ans.tab[i][j] = min(ans.tab[i][j], x.tab[i][k]+y.tab[l][j]);
						}
					}
				}
			}
		}
		return ans;
	}
	
	void build(int x, int lx, int rx){
		if (lx == rx){
			if (lx >= n) return;
			tab[x].tab[0][0] = 1;
			tab[x].tab[1][1] = 1; 
			return;
		}
		int m = (lx+rx)/2;
		build(2*x, lx, m);
		build(2*x+1, m+1, rx);
		tab[x] = merge(tab[2*x], tab[2*x+1], m);
	}
	
	void update(int x, int lx, int rx, int pos, int g, int c){
		if (lx == rx){
			if (lx < n){
				a[pos][0] = g;
				a[pos][1] = c;
			}
			return;
		}
		int m = (lx+rx)/2;
		if (pos <= m) update(2*x, lx, m, pos, g, c);
		else update(2*x+1, m+1, rx, pos, g, c);
		tab[x] = merge(tab[2*x], tab[2*x+1], m);
	}
	
	node query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return EMPTY;
		if (lx >= l && rx <= r)	return tab[x];
		int m = (lx+rx)/2;
		return merge(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r), m);
	}
};

void solve(){
	int q; cin >> n >> q;
	rep(i, 0, n) cin >> a[i][0] >> a[i][1];
	segtree seg;
	seg.init(n);
	seg.build(1, 0, seg.size-1);
	while (q--){
		int type; cin >> type; 
		if (type == 1){
			int t, g, c; cin >> t >> g >> c;
			seg.update(1, 0, seg.size-1, t-1, g, c);
		} else {
			int l, r; cin >> l >> r;
			--l;--r;
			node ans = seg.query(1, 0, seg.size-1, l, r);
			int xd = INF;
			rep(i, 0, 2){
				rep(j, 0, 2){
					xd = min(xd, ans.tab[i][j]);
				}
			}
			cout << xd << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
