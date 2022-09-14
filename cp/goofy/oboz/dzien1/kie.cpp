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

struct kanapka{LL m, c, k;};
vector<kanapka>sandwich;
struct diff{LL mc, ck, m;};
vector<diff> v1, v2;
bool cmp(diff a, diff b){return a.mc < b.mc;}
int n;

struct segtree{
	vll tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, -1);
	}
	
	void update(int pos, LL val){
		pos += size;
		tab[pos] = max(tab[pos], val);
		while (pos>0){
			pos/=2;
			tab[pos] = max(tab[2*pos], tab[2*pos+1]);
		}
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = INT_MIN;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	cin >> n;
	
	rep(i, 0, n){
		LL m, c, k; cin >> m >> c >> k;
		sandwich.pb(kanapka{m, c, k});
	}
	
	LL ans = 0LL;
	int left = n/2;
	int right = n-left;
	//swap(left, right);
	
	//maski bitowe dla lewej czesci
	rep(bitmask, 1, (1<<left)){
		kanapka curr = kanapka{0,0,0};
		rep(j, 0, left){
			if (bitmask&(1<<j)){
				curr.m += sandwich[j].m;
				curr.c += sandwich[j].c;
				curr.k += sandwich[j].k;
			}
		}
		if (curr.m >= curr.c && curr.c >= curr.k) ans = max(ans, curr.m);
		v1.pb(diff{curr.m-curr.c, curr.c-curr.k, curr.m});
		/*
		debug(curr.m);
		debug(curr.c);
		debug(curr.k);
		cerr << "\n";
		*/
	}
	//cerr << "\n";
	//maski bitowe dla prawej czesci
	
	rep(bitmask, 1, (1<<right)){
		kanapka curr = kanapka{0,0,0};
		rep(j, 0, right){
			if (bitmask&(1<<j)){
				curr.m += sandwich[j+left].m;
				curr.c += sandwich[j+left].c;
				curr.k += sandwich[j+left].k;
			}
		}
		if (curr.m >= curr.c && curr.c >= curr.k) ans = max(ans, curr.m);
		v2.pb(diff{curr.m-curr.c, curr.c-curr.k, curr.m});
		/*
		debug(curr.m);
		debug(curr.c);
		debug(curr.k);
		cerr << "\n";
		*/
	}
	
	sort(all(v1), cmp);
	sort(all(v2), cmp);
	/*
	cerr << "\n";
	for (auto x: v1){
		debug(x.mc);
		debug(x.ck);
		debug(x.m);
		cerr << "\n";
	}
	cerr << "\n";
	for (auto x: v2){
		debug(x.mc);
		debug(x.ck);
		debug(x.m);
		cerr << "\n";
	}
	cerr << "\n";
	*/
	
	vpll forseg;
	for (auto x: v2) forseg.pb({x.ck, x.m});
	sort(all(forseg));
	forseg.erase(unique(all(forseg)), forseg.end());
	map<pll, int>mapa;
	rep(i, 0, sz(forseg)) mapa[forseg[i]] = i;
	segtree seg;
	seg.init(sz(forseg)+1);
	
	//debug(ans);
	
	int koniec = sz(v2)-1;
	rep(start, 0, sz(v1)){
		while (koniec >= 0 && v1[start].mc + v2[koniec].mc >= 0){
			seg.update(mapa[{v2[koniec].ck, v2[koniec].m}], v2[koniec].m);
			koniec--;
		}
		auto it = mapa.lb({-v1[start].ck, -1});
		if (it != mapa.end() && (koniec + 1 < sz(v2) && v1[start].mc + v2[koniec+1].mc >= 0)) {
			LL x = seg.query(it->nd, seg.size-1);
			if (x>=0) ans = max(ans, v1[start].m + x);
			//debug(ans);
		}
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
