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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}

const int MAX = 3e5+7;
int Sample[MAX];
vi owners[MAX];
vi ans;

struct rain{
	int l, r, val;
};
vector<rain>q;

struct segtree{
	int size = 1;
	vll tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0LL);
	}
	
	void update(int l, int r, LL val){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1]+=val;
			if (r&1) tab[r-1]+=val;
			l/=2;r/=2;
		}
	}
	
	void add(int pos, int mnoznik){
		LL val = (LL)q[pos].val*mnoznik;
		int l = q[pos].l, r = q[pos].r;
		if (l <= r){
			update(l, r, val);
		} else {
			update(l, size-1, val);
			update(1, r, val);
		}
	}
	
	LL get(int pos){
		LL res = 0LL;
		pos+=size;
		while (pos>0){
			res += tab[pos];
			pos/=2;
		}
		return res;
	}
	
};
segtree seg;

void solve(int lx, int rx, vi &queries, int &ptr){
	if (queries.empty()) return;
	int m = (lx+rx)/2;
	/*
	debug(lx);
	debug(m);
	debug(rx);
	for (auto x: queries) debug(x);
	cerr << "\n";
	*/
	while (ptr < m){
		ptr++;
		seg.add(ptr, 1);
	}
	while (ptr > m){
		seg.add(ptr, -1);
		ptr--;
	}
	//for (auto x: seg.tab) debug(x);
	//cerr << "\n\n";
	vi left, right;
	for (auto x: queries){
		LL curr = 0LL;
		for (auto y:owners[x]){
			curr += seg.get(y);
			if (curr >= Sample[x]) break;
		}
		if (curr >= Sample[x]) {
			left.pb(x);
			ans[x] = rx;
		} else right.pb(x);
	}
	queries.clear();
	if (lx < rx){
		solve(lx, m, left, ptr);
		solve(m+1, rx, right, ptr);
	}	
}

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 1, m+1) {
		int x; cin >> x;
		owners[x].pb(i);
	}
	seg.init(m+1);
	rep(i, 1, n+1) cin >> Sample[i];
	int k; cin >> k;
	q.resize(k+1);
	rep(i, 1, k+1) cin >> q[i].l >> q[i].r >> q[i].val;
	vi curr;
	ans.resize(n+1, -1);
	rep(i, 1, n+1) curr.pb(i);
	int ptr = 0;
	solve(1, k, curr, ptr);
	rep(i, 1, n+1){
		if (ans[i]==-1) cout << "NIE\n";
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
