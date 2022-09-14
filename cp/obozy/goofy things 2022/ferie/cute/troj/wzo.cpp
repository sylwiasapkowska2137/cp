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

int p(int a, int b){
	return a+rng()%(b-a+1);
}
const int MAX = 5e5+7;
int tab[MAX][3];
vi lewo, idx, numer, hamilton;

bool win(int a, int b){ //czy a wygrywa z b
	int val = 0;
	rep(i, 0, 3) if (tab[a][i] < tab[b][i]) val++;
	return (val >= 2);
}

struct segtree{
	vi tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, INT_MAX);
	}
	
	void clear(){
		tab.assign(sz(tab), INT_MAX);
	}
	
	void set(int pos, int val){
		pos+=size;
		tab[pos] = val;
		while (pos > 0){
			pos/=2;
			tab[pos] = min(tab[2*pos], tab[2*pos+1]);
		}
	}
	
	int query(int l, int r){
		int ans = INT_MAX;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2; 
		}
		return ans;
	}
	
} seg;

void edges(int a, int b, int n){
	seg.clear();
	vi tmp(n);
	iota(all(tmp), 1);
	sort(all(tmp), [&](auto x, auto y){return tab[x][b] > tab[y][b];});
	debug(tmp);
	for (auto &x: tmp) x = idx[x];
	debug(tmp);
	for (auto x: tmp){
		lewo[x] = min(lewo[x], seg.query(tab[hamilton[x-1]][a], n));
		seg.set(tab[hamilton[x-1]][a], x);
	}
	debug(lewo);
}

void scc(int n){
	numer.assign(n+1, 0);
	int nalewo = n, nr = 1;
	repd(i, n, 1){
		numer[hamilton[i-1]] = nr;
		nalewo = min(nalewo, lewo[i]);
		if (nalewo>=i) nr++;
	}
}

vi dnc(int a, int b){
	if (a == b) return {a};
	int m = (a+b)/2;
	vi x = dnc(a, m), y = dnc(m+1, b), ans;
	int ptr_x = 0, ptr_y = 0; //sprawilo mi to o wiele wiekszą przymenosc niz powinno peter XDD
	rep(i, 0, sz(x)+sz(y)){
		if (ptr_x < sz(x) && (ptr_y == sz(y) || win(x[ptr_x], y[ptr_y]))){
			ans.pb(x[ptr_x]);
			ptr_x++;
		} else {
			ans.pb(y[ptr_y]);
			ptr_y++;
		}
	}
	x.clear();y.clear();
	return ans;
}


void solve(){
	int n; cin >> n;
	seg.init(n+1);
	rep(i, 1, n+1){
		rep(j, 0, 3){
			cin >> tab[i][j];
		}
	}
	hamilton = dnc(1, n);
	debug(hamilton);
	idx.resize(n+1);
	rep(i, 0, sz(hamilton)) idx[hamilton[i]] = i+1;
	debug(idx);
	lewo.assign(n+1, INT_MAX);
	edges(0, 1, n);
	edges(1, 2, n);
	edges(2, 0, n);
	rep(i, 1, n+1) lewo[i] = min(lewo[i], i);
	debug(lewo);
	scc(n);
	debug(numer);
	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		if (win(a, b) || numer[a] == numer[b]) cout << "TAK\n";
		else cout << "NIE\n";
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
