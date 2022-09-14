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

const int MAX = 3e5+7, K = 21;
vi graf[MAX], depth, sub, order, euler, first, last, parent, pos, order2;
int up[MAX][K];

struct segtreekth{
	vi tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		rep(i, 2, n+1) tab[i+size] = 1;
		repd(i, size-1, 1) tab[i] = tab[2*i]+tab[2*i+1];
	}
	
	void update(int pos){
		pos += size;
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
};

struct segtreesub{
	vll tab;
	int size = 1;
	
	void init(int n, vi&a){
		while (size < n) size*=2;
		size*=2;
		tab.assign(2*size+1, 0);
		rep(i, 0, sz(order)) tab[i+size+1] = sub[a[i]];
	}
	
	void update(int l, int r, int val){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1]+=val;
			if (r&1) tab[r-1]+=val;
			l/=2;r/=2;
		}
	}
	
	int query(int x){
		x += size;
		int ans = 0;
		while (x){
			ans += tab[x];
			x/=2;
		}
		return ans;
	}
};

struct segdepth{
	vi tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		size*=2;
		tab.assign(2*size+1, 0);
		//rep(i, 0, sz(euler)) tab[i+size+1] = depth[euler[i]];
		//repd(i, size-1, 1) tab[i] = max(tab[2*i], tab[2*i+1]);
	}
	
	void update(int l, int r, int val){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1] = max(tab[l+1], val);
			if (r&1) tab[r-1] = max(tab[r-1], val);
			l/=2;r/=2;
		}
	}
	
	int query(int x){
		x+=size;
		int ans = 0;
		while (x){
			ans = max(ans, tab[x]);
			x/=2;
		}
		return ans;
	}
};

void dfs(int v = 1, int pa = 0){
	up[v][0] = pa;
	parent[v] = pa;
	sub[v] = 1;
	order.pb(v);
	order2.pb(0);
	pos[v] = sz(order);
	euler.pb(v);
	first[v] = sz(euler);
	last[v] = first[v];
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
			euler.pb(v);
			last[v] = sz(euler);
			sub[v] += sub[x];
		}
	}
	order.pb(0);
	order2.pb(v);
}

int call(int v, int k){
	repd(i, K-1, 0){
		if (k&(1<<i)){
			v = up[v][i];
		}
	}
	return v;
}


void solve(){
	int n, x1; cin >> n >> x1;
	vi g(n);
	rep(i, 1, n-1) cin >> g[i];
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	depth.assign(n+1, 0);
	first.assign(n+1, 0);
	pos.assign(n+1, 0);
	last.assign(n+1, 0);
	sub.assign(n+1, 0);
	parent.assign(n+1, 0);
	dfs(1);
	segtreekth kth;
	kth.init(n);
	segdepth segdep;
	segdep.init(n+1);
	segtreesub segsubpre, segsubpost;
	segsubpre.init(n+1, order);
	segsubpost.init(n+1, order2);
	
	debug(depth);
	debug(sub);
	debug(euler);
	debug(order);
	debug(order2);
	debug(first);
	debug(last);
	debug(pos);
	
	int y = segsubpre.query(pos[x1])+segsubpost.query(pos[x1]);
	cout << y << "\n";
	kth.update(x1);
	int diff = segdep.query(first[x1]);
	int v = call(x1, depth[x1]-diff+1);
	debug(pos[v], pos[parent[x1]], y);
	
	segsubpre.update(0, pos[parent[x1]], -y);
	segsubpost.update(0, pos[parent[x1]], y);
	segsubpre.update(0, pos[v], y);
	segsubpost.update(0, pos[v], -y);
	segdep.update(first[x1], last[x1], depth[x1]);
	//debug(kth.tab);
	//debug(segdep.tab);
	//debug(segsub.tab);
	//return;
	rep(i, 1, n-1){
		int l = (g[i]+y)%(n-i-1)+1;
		//debug(l);
		x1 = kth.kth(1, 0, kth.size-1, l);
		debug(l, x1);
		int y = segsubpre.query(pos[x1])+segsubpost.query(pos[x1]);
		cout << y << "\n";
		kth.update(x1);
		int diff = segdep.query(first[x1]);
		int v = call(x1, depth[x1]-diff+1);
		debug(diff, v,pos[v], parent[x1]);
		int X = segsubpre.query(pos[x1]);
		segsubpre.update(0, pos[parent[x1]], -X);
		segsubpost.update(0, pos[parent[x1]], X);
		segsubpre.update(0, pos[v], X);
		segsubpost.update(0, pos[v], -X);
		segdep.update(first[x1], last[x1], depth[x1]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
