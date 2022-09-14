//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, K = 30;

const int mod = 998244353;

int mul(int a, int b){
	return (a*b)%mod;
}

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

int add2(int a, int b){
	int ans = a+b;
	if (ans >= mod) ans-=mod;
	return ans;
}

int C2(int x){
	return (x*(x+1)/2)%mod;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0) a+=mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = add2(tab[2*i],tab[2*i+1]);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = add2(tab[2*x],tab[2*x+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) add(ans,tab[l+1]);
			if (r&1) add(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1), b(n+1), c(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		b[i] = mul(i, a[i]);
		c[i] = mul(i, b[i]);
	}
	segtree A(n+1, a), B(n+1, b), C(n+1, c);
	int inv = power(2, mod-2);
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int x, v; cin >> x >> v;
			A.update(x, v);
			B.update(x, mul(x, v));
			C.update(x, mul(x, mul(x, v)));
		} else {
			int x; cin >> x;
			int ans = 0;
			add(ans, C.query(1, x));
			add(ans, mul(x+1, mul(x+2, A.query(1, x))));
			sub(ans, mul(2*x+3, B.query(1, x)));
			ans = mul(ans, inv);
			cout << ans << "\n";
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
