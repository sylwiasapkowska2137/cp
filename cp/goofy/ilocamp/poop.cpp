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

string a;
int n;

struct node{
	int correct, open, close;
	node(): correct(0), open(0), close(0) {}
};

struct segtree{
	vector<node>tab;
	node empty;
	int size = 1;
	
	segtree(){
		while (size < n) size*=2;
		tab.resize(2*size);
	}
	
	void leaf(int x){
		if (a[x] == '(') tab[x+size].open = 1;
		else tab[x+size].close = 1;
	}
	
	node merge(node a, node b){
		node res;
		int comb = min(a.open, b.close);
		res.correct = a.correct + b.correct + comb;
		res.open = a.open+b.open-comb;
		res.close = a.close+b.close-comb;
		return res;
	}
	
	void build(){
		rep(i, 0, n) leaf(i);
		repd(x, size-1, 1)tab[x] = merge(tab[2*x], tab[2*x+1]);
	}
	
	void print(){
		rep(i, 1, sz(tab)){
			debug(i);
			debug(tab[i].correct);
			debug(tab[i].open);
			debug(tab[i].close);
			cerr << "\n";
		}
	}
	
	node query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return empty;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return merge(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
	
};


void solve(){
	cin >> a;
	n = sz(a);
	segtree seg;
	seg.build();
	//seg.print();
	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		a--;b--;
		cout << 2*seg.query(1, 0, seg.size-1, a, b).correct << "\n";
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
