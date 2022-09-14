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

struct Query{
	int l, r, x, q;
	LL sum;
	
	Query() {}
	Query(int _l, int _r, int _x){
		l = _l, r = _r, x = _x;
		sum = 0, q = 0;
	}
};

vector<Query>Q;
const int MAX = (1<<20);
vi tab[2*MAX];
int sz = MAX;
int n;

void add(int x, int lx, int rx, int l, int r, int idx){
	if (lx > r || rx < l) return;
	if (lx >= l && rx <= r){
		tab[x].pb(idx);
		return;
	}
	int m = (lx+rx)/2;
	add(2*x, lx, m, l, r, idx);
	add(2*x+1, m+1, rx, l, r, idx);
}

void query(int pos, LL val){
	pos += sz;
	while (pos > 0){
		int ptr = 0;
		while (ptr < sz(tab[pos])){
			if (Q[tab[pos][ptr]].q < Q[tab[pos][ptr]].x){
				Q[tab[pos][ptr]].q++;
				Q[tab[pos][ptr]].sum += val;
			}
			if (Q[tab[pos][ptr]].q >= Q[tab[pos][ptr]].x){
				swap(tab[pos][ptr], tab[pos].back());
				tab[pos].pop_back();
				continue;
			}
			ptr++;
		}
		pos/=2;
	}
}

void solve(){
	int q; cin >> n >> q;
	vpii a(n);
	rep(i, 0, n) {
		cin >> a[i].st;
		a[i].nd = i;
	}
	
	sort(all(a), [&](auto x, auto y){return x.st > y.st;});
	rep(i, 0, q){
		int l, r, x; cin >> l >> r >> x;
		l--;r--;
		Q.emplace_back(l, r, x);
		add(1, 0, sz-1, l, r, i);
	}
	/*
	int k = 0;
	for (auto x: seg.tab) {
		debug(k, x);
		k++;
	}
	*/
	for (auto [v, i]: a) query(i, v);
	rep(i, 0, q) cout << Q[i].sum << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
