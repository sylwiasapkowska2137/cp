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

const int INF = 1e9+7;

struct rect{
	int x1, x2, y1, y2;
   
	friend istream& operator >> (istream& stream, rect& p) {
		return stream >> p.x1 >> p.y1 >> p.x2 >> p.y2;
	}
};

struct segtree{
	vi tab, lazy;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		lazy.assign(2*size, 0);
	}
	
	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x] += lazy[x];
		tab[2*x+1] += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r, int val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r) {
			tab[x]+=val;
			lazy[x]+=val;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}
	
	int query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return INF;
		if (lx >= l && rx <= r) return tab[x];
		push(x, lx, rx);
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

struct line{
	int x, y1, y2, start;
};

bool cmp(line a, line other){
	if (other.x == a.x) {
		if (a.start == other.start) return a.y2 - a.y1 < other.y2 - other.y1;
		return a.start > other.start;
	}
	return a.x < other.x;
}

void solve(){
	int n; cin >> n;
	vector<rect>tab(n);
	vi scaler;
	rep(i, 0, n){
		cin >> tab[i];
		tab[i].y2--;
		scaler.pb(tab[i].y1);
		scaler.pb(tab[i].y2);
	}
	//wierzcholek i odpowiada za to czy pomalowany jest kawalek od i do i+1
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<int,int>mapa;
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i;
	segtree seg;
	seg.init(sz(scaler)+2);
	rep(i, 0, n){
		tab[i].y1 = mapa[tab[i].y1];
		tab[i].y2 = mapa[tab[i].y2];
	}
	vector<line>sweep;
	for (auto x: tab){
		sweep.pb(line{x.x1, x.y1, x.y2, 0});
		sweep.pb(line{x.x2, x.y1, x.y2, 1});
	}
	sort(all(sweep), cmp);
	/*
	for (auto x: sweep){
		debug(x.x);
		debug(x.y1);
		debug(x.y2);
		debug(x.start);
		cerr << "\n";
	}*/
	int ans = 0;
	for (auto x: sweep){
		if (x.start == 1) { //jestesmy w koncu
			seg.update(1, 0, seg.size-1, x.y1, x.y2, -1);
			if (seg.query(1, 0, seg.size-1, x.y1, x.y2) > 0) ans++;
		} else seg.update(1, 0, seg.size-1, x.y1, x.y2, 1);
	}
	cout << n-ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

