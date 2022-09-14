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

struct node{
	int min1, min2, max1, max2, minc, maxc, sum = -1, hash = 0;
	void d(){cerr << min1 << " " << min2 << " " << minc << " " << sum << " " << max1 << " " << max2 << " " << maxc << " " << "\n";}
};

/*
typ 1; a[i] = min(a[i], k);
typ 2: a[i] += k;
typ 3: a[i] = max(a[i], k);
*/

struct segtree{
	vector<node>tab;
	vector<int>lazy, pot;
	int p, mod;
	int size = 1;

	void add(int &a, int b){
		a += b;
		if (a >= mod) a-=mod;
	}

	void sub(int &a, int b){
		a -= b;
		if (a < 0) a += mod;
	}

	int mul(int a, int b){
		return (a*b)%mod;
	}

	int power(int b){
		b %= (mod-1);
		return pot[b];
	}

	int add2(int a, int b){
		return (a+b+mod)%mod;
	}

	node leaf(int v){
		node ret;
		ret.min1 = ret.max1 = ret.sum = v;
		ret.hash = power(v);
		ret.min2 = oo;
		ret.max2 = -oo;
		ret.minc = ret.maxc = 1;
		return ret;
	}

	node f(node a, node b){
		if (a.sum == -1) return b;
		if (b.sum == -1) return a;
		node ret;
		ret.sum = a.sum+b.sum;
		ret.hash = add2(a.hash, b.hash);
		if (a.min1 == b.min1){
			ret.min1 = a.min1;
			ret.minc = a.minc+b.minc;
			ret.min2 = min(a.min2, b.min2);
		} else if (a.min1 < b.min1){
			ret.min1 = a.min1;
			ret.minc = a.minc;
			ret.min2 = min(a.min2, b.min1);
		} else {
			ret.min1 = b.min1;
			ret.minc = b.minc;
			ret.min2 = min(b.min2, a.min1);
		}

		if (a.max1 == b.max1){
			ret.max1 = a.max1;
			ret.maxc = a.maxc+b.maxc;
			ret.max2 = max(a.max2, b.max2);
		} else if (a.max1 > b.max1){
			ret.max1 = a.max1;
			ret.maxc = a.maxc;
			ret.max2 = max(a.max2, b.max1);
		} else {
			ret.max1 = b.max1;
			ret.maxc = b.maxc;
			ret.max2 = max(b.max2, a.max1);
		}
		return ret;
	}

	segtree(int n, vector<int>&a, int pp, int modd){
		p = pp;
		mod = modd;
		while (size < n) size*=2;
		tab.resize(2*size);
		lazy.assign(2*size, 0);
		pot.resize(mod+1);
		pot[0] = 1;
		for (int i = 1; i<=mod; i++) pot[i] = mul(pot[i-1], p);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = leaf(a[i]);
		for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]); 
	}

	void push(int x, int lx, int rx){
		if (lx == rx) return;
		int m = (lx+rx)/2;
		
		apply(2*x, lx, m, 2, lazy[x]);
		apply(2*x+1, m+1, rx, 2, lazy[x]);
		lazy[x] = 0;

		apply(2*x, lx, m, 1, tab[x].max1);
		apply(2*x+1, m+1, rx, 1, tab[x].max1);
		
		apply(2*x, lx, m, 3, tab[x].min1);
		apply(2*x+1, m+1, rx, 3, tab[x].min1);
	}

	bool break_condition(int x, int t, int k){
		if (t == 1) return (tab[x].max1 <= k);
		if (t == 2) return 0;
		if (t == 3) return (tab[x].min1 >= k);
		assert(false);
	}

	bool apply_condition(int x, int t, int k){
		if (t == 1) return (tab[x].max1 > k && k > tab[x].max2);
		if (t == 2) return 1;
		if (t == 3) return (tab[x].min1 < k && k < tab[x].min2);
		assert(false);
	}

	void apply(int x, int lx, int rx, int t, int k){
		if (t == 1){ 
			if (k >= tab[x].max1) return;
			tab[x].sum -= tab[x].max1*tab[x].maxc;
			sub(tab[x].hash, mul(power(tab[x].max1), tab[x].maxc));
			tab[x].max1 = k;
			tab[x].sum += tab[x].max1*tab[x].maxc;
			add(tab[x].hash, mul(power(tab[x].max1), tab[x].maxc));
			if (lx == rx) tab[x].min1 = tab[x].max1;
			else {
				if (k <= tab[x].min1) tab[x].min1 = k;
				else if (k < tab[x].min2) tab[x].min2 = k;
			}
		}
		if (t == 2){ 
			tab[x].sum += k*(rx-lx+1);
			tab[x].hash = mul(tab[x].hash, power(k));
			tab[x].max1 += k;
			tab[x].min1 += k;
			if (tab[x].max2 != -oo) tab[x].max2 += k;
			if (tab[x].min2 != oo) tab[x].min2 += k; 
			lazy[x] += k;
		}
		if (t == 3){ 
			if (k <= tab[x].min1) return;
			tab[x].sum -= tab[x].min1*tab[x].minc;
			sub(tab[x].hash, mul(power(tab[x].min1), tab[x].minc));
			tab[x].min1 = k;
			tab[x].sum += tab[x].min1*tab[x].minc;
			add(tab[x].hash, mul(power(tab[x].min1), tab[x].minc));
			if (lx == rx) tab[x].max1 = tab[x].min1;
			else {
				if (k >= tab[x].max1) tab[x].max1 = k;
				else if (k > tab[x].max2) tab[x].max2 = k;
			}
		}
	}

	void update(int x, int lx, int rx, int l, int r, int t, int k){
		if (break_condition(x, t, k) || lx > r || rx < l) return;
		if (lx >= l && rx <= r && apply_condition(x, t, k)){
			apply(x, lx, rx, t, k);
			return;	
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, t, k);
		update(2*x+1, m+1, rx, l, r, t, k);
		tab[x] = f(tab[2*x], tab[2*x+1]);
	}

	int query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return tab[x].hash;
		push(x, lx, rx);
		int m = (lx+rx)/2;
		return add2(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

struct query{
	int t, a, b, c, d;
	query(){}
	query(int _t, int _a, int _b, int _c, int _d){
		t = _t, a = _a, b = _b, c = _c, d = _d;
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector<pair<int, int>>p = {{2137, 1e6+3}, {2139, 1e6+33}};
	vector<query>Q;
	vector<int>ans(q, 1);
	for (int i = 0; i<q; i++){
		int t; cin >> t;
		if (t){
			int l, r, k; cin >> l >> r >> k;
			Q.emplace_back(t, l, r, k, -1);
		} else {
			int l, r; cin >> l >> r;
			int l1, r1; cin >> l1 >> r1;
			Q.emplace_back(t, l, r, l1, r1);
		}
	}

	for (int k = 0; k<2; k++){
		segtree seg(n+1, a, p[k].first, p[k].second);
		int i = 0;
		for (auto [t, a, b, c, d]: Q){
			if (d == -1){
				seg.update(1, 0, seg.size-1, a, b, t, c);
				if (t == 1) seg.update(1, 0, seg.size-1, a, b, 3, c);
			} else {
				int A = seg.query(1, 0, seg.size-1, a, b);
				int B = seg.query(1, 0, seg.size-1, c, d);
				// debug(a, b, c, d, A, B);
				ans[i] &= (A == B);
			}
			i++;
		}
	}
	
	for (int i = 0; i<q; i++){
		if (Q[i].t) continue;
		if (ans[i]) cout << "YES\n";
		else cout << "NO\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}