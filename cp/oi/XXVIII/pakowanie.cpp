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

const LL INF = -1e18;

struct segtree{
	int size = 1;
	vll tab, lazy;
	
	void init(int n, vll&s){
		while(size < n) size*=2;
		tab.assign(2*size+1, INF);
		lazy.assign(2*size+1, 0LL);
		rep(i, 0, n) tab[i+size] = s[i];
		repd(i, size-1, 0) tab[i] = max(tab[2*i], tab[2*i+1]);
	}
	
	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x]+=lazy[x];
		tab[2*x+1]+=lazy[x];
		lazy[2*x]+=lazy[x];
		lazy[2*x+1]+=lazy[x];
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r, LL val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x]+=val;
			lazy[x]+=val;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = max(tab[2*x], tab[2*x+1]);
	}
	
	int binsearch(int x, int lx, int rx){
		if (lx == rx) return lx;
		push(x, lx, rx);
		int m = (lx+rx)/2;
		if (tab[2*x]>0) return binsearch(2*x, lx, m);
		else return binsearch(2*x+1, m+1, rx);
	}
	
};


void solve(){
	int n; cin >> n;
	vll a(n);
	rep(i, 0, n) cin >> a[i];
	LL S = accumulate(all(a), 0LL);
	vll s(n, 0);
	LL curr = 0LL;
	repd(i, n-1, 0){
		s[i] = a[i]-curr;
		curr+=a[i];
	}
	//rep(i, 0, n) debug(s[i]);
	//cerr << "\n";
	segtree seg;
	seg.init(n, s);
	vll ans(n);
	repd(i, n-1, 0){
		ans[i] = S;
		int x = seg.binsearch(1, 0, seg.size-1);
		S-=a[x];
		seg.update(1, 0, seg.size-1, 0, x-1, a[x]);
		seg.update(1, 0, seg.size-1, x, x, 2LL*INF);
	}
	rep(i, 0, n) cout << ans[i] << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
