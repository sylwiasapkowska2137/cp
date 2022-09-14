#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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

vi A;

struct node{
	
	int pref, suf, total, lx, rx;
	bool ok;
};


struct segtree{
	vector<node>tab;
	int size = 1;
	
	node comb(node a, node b){
		return node{
			((A[a.rx]<=A[b.lx] && a.pref == a.rx-a.lx+1) ? a.pref+b.pref : a.pref),
			((A[a.rx]<=A[b.lx] && b.suf==b.rx-b.lx+1) ? b.suf+a.suf: b.suf),
			//total = number of non-decreasing intervals which are not prefix neither a suffix of the segment,
			
			a.lx, b.rx, 
			(a.pref == b.suff && a.pref == a.rx-a.lx+1)
		};
	}
	
	node single(int lx){
		return node{
			1, 1, 0, lx, lx, 1
		};
	}
	
	node comb(int x){
		return comb(tab[2*x], tab[2*x+1]);
	}
	
	void init(int n){
		while (size<n) size*=2;
		tab.resize(2*size);
	}
	
	void build(int x, int lx, int rx){
		if (lx == rx) {
			tab[x] = single(lx);
			return;
		}
		int m = (lx+rx)/2;
		build(2*x, lx, m);
		build(2*x+1, m+1, rx);
		tab[x] = comb(x);
	}
	
	
};

void solve(){
	int n, q; cin >> n >> q;
	A.resize(n);
	rep(i, 0, n) cin >> A[i];
	
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
