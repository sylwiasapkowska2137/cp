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
	vi tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void update(int x, int lx, int rx, int l, int r, int val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x]+=val;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
	}
	
	void set(int x, int lx, int rx, int pos, int val){
		if (lx == rx){
			tab[x] = val;
			return;
		}
		int m = (lx+rx)/2;
		if (pos <= m) set(2*x, lx, m, pos, val-tab[x]);
		else set(2*x+1, m+1, rx, pos, val-tab[x]);
	}
	
	int query(int x, int lx, int rx, int pos){
		if (lx == rx) return tab[x];
		int m = (lx+rx)/2;
		if (pos <= m) return tab[x]+query(2*x, lx, m, pos);
		else return tab[x]+query(2*x+1, m+1, rx, pos);
	}
};

void solve(){
	int n, t, k;
	cin >> n >> t;
	vector<bool>used(n+1, 0);
	segtree seg;
	seg.init(n+2);
	while (t--){
		cin >> k;
		int start = 1, koniec = n, ans = n;
		while (koniec >= start){
			int m = (start+koniec)/2;
			int suma;
			if (!used[m]){
				cout << "? " << 1 << " " << m << "\n"; cout.flush();
				used[m] = 1;
				cin >> suma;
				seg.set(1, 1, n, m, suma);
			} else suma = seg.query(1, 1, n, m);
			//cout << m << " " << suma << "\n";
			if (m-suma>=k){
				ans = m;
				koniec = m-1;
			} else start = m+1;
		}
		cout << "! " << ans << "\n"; cout.flush();
		seg.update(1, 1, n, ans, n, 1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
