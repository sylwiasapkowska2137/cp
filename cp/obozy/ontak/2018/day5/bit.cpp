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
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

LL p(LL a, LL b){
	return a+rng()%(b-a+1);
}

const LL INF = 1e18;

struct segtreesum{
	vll tab;
	int size = 1;
	
	void init(int n, vll &a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		rep(i, 0, sz(a)) tab[i+size] = a[i];
		repd(i, size-1, 0) tab[i] = tab[2*i]+tab[2*i+1];
	}
	
	void update(int pos, LL val){
		pos += size;
		tab[pos] = val;
		while (pos > 0){
			pos /=2;
			tab[pos] = tab[2*pos]+tab[2*pos+1];
		}
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0LL;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
};

struct segtreexor{
	vll tab;
	int size = 1;
	
	void init(int n, vll &a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0LL);
		rep(i, 0, sz(a)) tab[i+size] = a[i];
		repd(i, size-1, 0) tab[i] = tab[2*i]^tab[2*i+1];
	}
	
	void update(int pos, LL val){
		pos += size;
		tab[pos] = val;
		while (pos > 0){
			pos /=2;
			tab[pos] = tab[2*pos]^tab[2*pos+1];
		}
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0LL;
		while (r-l>1){
			if (!(l&1)) ans ^= tab[l+1];
			if (r&1) ans ^= tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
};

struct segtreemin{
	vll tab;
	int size = 1;
	
	void init(int n, vll &a){
		while (size < n) size*=2;
		tab.assign(2*size+1, INF);
		rep(i, 0, sz(a)) tab[i+size] = a[i];
		repd(i, size-1, 0) tab[i] = min(tab[2*i],tab[2*i+1]);
	}
	
	void update(int pos, LL val){
		pos += size;
		tab[pos] = val;
		while (pos > 0){
			pos /=2;
			tab[pos] = min(tab[2*pos],tab[2*pos+1]);
		}
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = INF;
		while (r-l>1){
			if (!(l&1)) ans = min(ans,tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

LL sum0(LL x){
	return x*(x+1)/2LL;
}

LL sum1(LL x){
	return x*(x+1)*(2*x+1)/6LL;
}

LL sum0(LL l, LL r){
	return sum0(r)-sum0(l-1);
}

LL sum1(LL l, LL r){
	return sum1(r)-sum1(l-1);
}


const int MAX = 1e6+7;
LL h[MAX], prefh[MAX];

LL xorr(LL l, LL r){
	return prefh[l-1]^prefh[r];
}

void solve(){
	int n, t; cin >> n >> t;
	vll a(n+1, 0), b(n+1, 0), c(n+1, 0);
	rep(i, 1, n+1) {
		cin >> a[i];
		b[i] = a[i]*a[i];
	}
	rep(i, 1, MAX) h[i] = p(1LL, INF);
	rep(i, 1, MAX) prefh[i] = prefh[i-1]^h[i];
	rep(i, 1, n+1) c[i] = h[a[i]];
	//debug(c);
	segtreemin segmin;
	segmin.init(n+1, a);
	segtreesum segsum0;
	segsum0.init(n+1, a);
	segtreexor segxor;
	segxor.init(n+1, c);
	segtreesum segsum1;
	segsum1.init(n+1, b);
	int q; cin >> q;
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r; cin >> l >> r;
			LL mini = segmin.query(l, r);
			LL one = segsum0.query(l, r);
			LL two = segsum1.query(l, r);
			LL three = segxor.query(l, r);
			bool ok = 1;
			int len = r-l;
			ok &= (sum0(mini, mini+len) == one);
			ok &= (sum1(mini, mini+len) == two);
			ok &= (xorr(mini, mini+len) == three);
			cout << (ok ? "YES\n": "NO\n");
		} else {
			int pos; LL val; cin >> pos >> val;
			segmin.update(pos, val);
			segsum0.update(pos, val);
			segsum1.update(pos, val*val);
			segxor.update(pos, h[val]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
