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

const int MAX = 1e6+7, INF = 1e9+7;
vi tab[MAX];

struct segtree{
	vi tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, INF);
	}
	
	void build(vi a){
		rep(i, 0, sz(a)) tab[i+size] = a[i];
		repd(i, size-1, 0) tab[i] = min(tab[2*i], tab[2*i+1]); 
	}
	
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = INF;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]); 
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vi a(n), scaler;
	rep(i, 0, n){
		cin >> a[i];
		scaler.pb(a[i]);
	}
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<int, int>mapa;
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i;
	rep(i, 0, n) a[i] = mapa[a[i]];
	rep(i, 0, n) {
		//debug(a[i]);
		tab[a[i]].pb(i);
	}
	segtree seg;
	seg.init(n);
	seg.build(a);
	LL ans = 0LL;
	rep(i, 0, MAX){
		//gasienica
		//cerr << "i ";
		//debug(i);
		//cerr << "\n";
		if (sz(tab[i])<=1) continue;
		int koniec = 1;
		rep(start, 0, sz(tab[i])-1){
			while (koniec < sz(tab[i]) && seg.query(tab[i][start], tab[i][koniec])>=i) koniec++;
			//debug(start);
			//debug(koniec);
			//cerr << "\n";
			ans += (koniec-start-1);
		}
		//cerr << "\n";
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
