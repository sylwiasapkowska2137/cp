//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
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
const int mod = 998244353, I = 499122177;

void sub(int &a, int b){
	a -= b;
	if (a < 0) a += mod;
}

int mul(int a, int b){
	return (a*b)%mod;
}

int sum(int L, int R){
	L = mul(L, 1);
	R = mul(R, 1);
	int a = mul(L, mul(L-1, I));
	int b = mul(R, mul(R+1, I));
	sub(b, a);
	return b;
}

int add2(int a, int b){
	int ret = a+b;
	if (ret >= mod) ret -= mod;
	return ret;
}

struct T{
	int mx = 0, mn = 0, L, R = -oo;
};

struct TreeSum{
	vector<T>tab;
	vector<int>lazy;
	int size = 1;

	T f(T a, T b){
		if (a.R == -oo) return b;
		if (b.R == -oo) return a;
		T ret;
		ret.mx = max(a.mx, b.mx);
		ret.mn = min(a.mn, b.mn);
		ret.L = a.L;
		ret.R = b.R;
		return ret;
	}

	TreeSum(int n, vector<int>&s){
		while (size < n) size*=2;
		tab.resize(2*size);
		lazy.assign(2*size, -1);
		for (int i = 0; i<(int)s.size(); i++) {
			tab[i+size].L = tab[i+size].R = s[i];
			if (i+1 < (int)s.size()) tab[i+size].R = s[i+1]-1;
		}
		for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]);
		// for (int i = 0; i<2*size; i++) {
		// 	debug(i, tab[i].L, tab[i].R);
		// }
	}

	void push(int x){
		if (lazy[x] == -1) return;
		tab[2*x].mx = tab[2*x+1].mx = lazy[x];
		tab[2*x].mn = tab[2*x+1].mn = lazy[x];
		lazy[2*x] = lazy[2*x+1] = lazy[x];
		lazy[x] = -1;
	}

	void update(int x, int l, int r, int v){
		int lx = tab[x].L, rx = tab[x].R;
		if (lx != rx) push(x);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x].mn = tab[x].mx = lazy[x] = v;
			return;
		}
		update(2*x, l, r, v);
		update(2*x+1, l, r, v);
		tab[x] = f(tab[2*x], tab[2*x+1]);
	}

	int query(int x, int l, int r){
		int lx = tab[x].L, rx = tab[x].R;
		if (lx != rx) push(x);
		// debug(x, lx, rx, tab[x].mn, tab[x].mx);
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r && tab[x].mx == tab[x].mn) {
			// debug(x);
			return mul(mul(tab[x].mx, 1), sum(lx, rx));
		}
		return add2(query(2*x, l, r), query(2*x+1, l, r));
	}
};

int power(int a, int b){
	if(!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

void solve(){
	int n, q; cin >> n >> q;
	vector<int>s;
	s.emplace_back(1);
	s.emplace_back(n);
	vector<tuple<int, int, int>>tab;
	for (int i = 0; i<q; i++){
		int d, l, r; cin >> d >> l >> r;
		tab.emplace_back(d, l, r);
		s.insert(s.end(), {l-1, l, r, r+1});
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	int S = (int)s.size()+2;
	TreeSum t(S, s);
	for (auto [d, l, r]:tab){
		int ans = mul(sum(l, r), mul(d, 1));
		// debug(sum(l, r), t.query(1, l, r));
		sub(ans, t.query(1, l, r));
		cout << ans << "\n";
		t.update(1, l, r, d);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
