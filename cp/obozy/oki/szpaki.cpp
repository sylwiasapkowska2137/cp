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
	const int Size = (1<<17);
	vll tab;
	
	segtree(){
		tab.assign(2*Size+1, 1LL);
	}
	
	void update(int l, int r, LL x, LL k){
		l = l+Size-1;
		r = r+Size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1] = (tab[l+1]*x)%k;
			if (r&1) tab[r-1] = (tab[r-1]*x)%k;
			l/=2;r/=2;
		}
	}
	
	bool query(int pos, LL k){
		pos+=Size;
		LL ans = 1;
		while (pos>0){
			ans *= tab[pos];
			ans %= k;
			pos/=2;
		}
		return (ans == 0);
	}
	
} seg;

void solve(){
	int q; LL k; cin >> q >> k;
	while (q--){
		char type;
		cin >> type;
		if (type == 'N'){
			int a, b; LL c; cin >> a >> b >> c;
			seg.update(a, b, c, k);
		} else {
			int a; cin >> a;
			if (seg.query(a, k)) cout << "TAK\n";
			else cout << "NIE\n";
		}
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
