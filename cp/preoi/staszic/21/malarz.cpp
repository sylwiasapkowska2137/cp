//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const LL INF = 1e18+7;

struct Node{
	LL val, lx = 0, rx = INF;
	Node(){}
	Node(LL val, LL lx, LL rx): val(val), lx(lx), rx(rx) {}
};

struct segtree{
	vector<Node> tab;
	vb lazy;
	int size = 1;
	
	segtree(int n, vi scaler){
		while (size < n) size*=2;
		tab.resize(2*size+1, {0, 0, scaler.back()});
		lazy.assign(2*size+1, 0);
		rep(i, 0, sz(scaler)){
			tab[i+size].val = 1;
			tab[i+size].lx = tab[i+size].rx = scaler[i];
		}
		repd(i, size-1, 1){
			tab[i].lx = tab[2*i].lx;
			tab[i].rx = tab[2*i+1].rx;
			if (tab[i].lx) tab[i].val = tab[i].rx-tab[i].lx+1;
			else tab[i].val = -1;
		}
	}
	
	void invert(int x){
		tab[x].val = (tab[x].rx-tab[x].lx+1)-tab[x].val;
	}
	
	void push(int x){
		if (!lazy[x] || tab[x].lx == tab[x].rx) return;
		lazy[x] = 0;
		invert(2*x);
		invert(2*x+1);
		lazy[2*x] = lazy[2*x+1] = 1;
	}
	
	void update(int x, int l, int r){
		push(x);
		if (!tab[x].lx) return;
		if (tab[x].lx > r || tab[x].rx < l) return;
		if (tab[x].lx >= l && tab[x].rx <= r){
			//debug(x);
			lazy[x] = 1;
			invert(x);
			return;
		}
		
		update(2*x, l, r);
		update(2*x+1, l, r);
		tab[x].val = tab[2*x].val + tab[2*x+1].val;
	}
	
	int query(int x, int l, int r){
		push(x);
		if (!tab[x].lx) return 0;
		if (tab[x].lx > r || tab[x].rx < l) return 0;
		if (tab[x].lx >= l && tab[x].rx <= r) return tab[x].val;
		
		return query(2*x, l, r)+query(2*x+1, l, r);
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vi scaler;
	vpii queries(m);
	vb type(m);
	rep(i, 0, m){
		char typ; int l, r; cin >> typ >> l >> r;
		if (typ == '?') type[i] = 1;
		scaler.pb(l);
		scaler.pb(r);
		queries[i] = {l, r};
	}
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	segtree seg(sz(scaler)+1, scaler);
	rep(i, 0, m){
		if (type[i]) cout << seg.query(1, queries[i].st, queries[i].nd) << "\n";
		else seg.update(1, queries[i].st, queries[i].nd);
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
