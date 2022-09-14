#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;#include <bits/stdc++.h>

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

struct team{
	LL a, b, c;
};

vector<team>a;
vi curr;

struct segtree{
	vector<vll>tab;
	int size = 1, d;
	vll empty;
	LL NEU = -1;
	
	void init(int n, int D){
		d = D;
		while (size < n) size*=2;
		tab.resize(2*size, vll(d, NEU));
		empty.assign(d, NEU);
	}
	
	vll comb(vll a, vll b){
		if ((b) == empty) return a; 
		if ((a) == empty) return b;
		vll ans(empty);
		rep(i, 0, d){
			rep(j, 0, d){
				if ((a)[i]<0 || (b)[j]<0) continue;
				ans[(i+j)%d] = max(ans[(i+j)%d], (a)[i]+(b)[j]);
			}
		}
		return ans;
	}
	
	void build(LL d){
		rep(i, 0, sz(a)){
			tab[i+size][a[i].a%d] = max(a[i].a, tab[i+size][(int)(a[i].a%d)]);
			tab[i+size][a[i].b%d] = max(a[i].b, tab[i+size][(int)(a[i].b%d)]);
			tab[i+size][a[i].c%d] = max(a[i].c, tab[i+size][(int)(a[i].c%d)]);
		}
		repd(i, size-1, 1) tab[i] = comb(tab[2*i], tab[2*i+1]);
	}
	
	vll query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return empty;
		if (lx >= l && rx <= r)	{
			return tab[x];
		}
		int m = (lx+rx)/2;
		return comb(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
	
};


void solve(){
	LL n, d; cin >> n >> d;
	rep(i, 0, n){
		LL x, y, z; cin >> x >> y >> z;
		a.pb(team{x, y, z});
	}
	segtree seg;
	seg.init(n, d);
	seg.build(d);
	
	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		cout << seg.query(1, 1, seg.size, a, b)[0] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}




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

struct team{
	int a, b, c;
};

void solve(){
	int n, d; cin >> n >> d;
	vector<team>a(n);
	rep(i, 0, n){
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	int q; cin >> q;
	while (q--){
		int A, b; cin >> A >> b;
		A--;b--;
		LL ans = -1;
		int len = b-A+1;
		rep(i, 0, pow(3, len)){
			LL num = i;
			LL curr = 0;
			rep(j, 0, len){
				int x = num%3;
				if (x == 0) curr += a[j+A].a;
				if (x == 1) curr += a[j+A].b;
				if (x == 2) curr += a[j+A].c;
				num/=3;
			}
			if (curr%d == 0) ans = max(ans, curr);
		}
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

