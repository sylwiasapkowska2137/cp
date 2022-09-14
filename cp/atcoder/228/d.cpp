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

struct segtree{
	int size = (1<<20);
	vll tab;
	
	segtree(){
		tab.assign(2*size, -1);
	}
	
	void update(int p, int val){
		p+=size;
		tab[p] = val;
		while (p){
			p/=2;
			tab[p] = min(tab[p<<1], tab[(p<<1)|1]);
		}
	}
	
	int bs(int x, int lx, int rx, int k){ //pierwsze -1 na prawo od k
		if (lx == rx) return x-size;
		int m = (lx+rx)/2;
		if (rx < k) return bs(2*x+1, m+1, rx, k);
		else return bs(2*x, lx, m);
	}
};


void solve(){
	int q; cin >> q;
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
