//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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

struct T{
	int l, r, v;
	void read(){
		cin >> l >> r >> v;
	}
};

struct TreeSum{
	vector<int>tab;
	int size = 1;
	
	int f(int a, int b){return a+b;}

	TreeSum(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = f(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; r/=2, l/=2){
			if (!(l&1)) ans = f(ans, tab[l+1]);
			if (r&1) ans = f(ans, tab[r-1]);
		}
		return ans;
	}
};

struct TreeOr{
	vector<int>tab;
	int size = 1;
	
	int f(int a, int b){return (a|b);}

	TreeOr(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = f(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; r/=2, l/=2){
			if (!(l&1)) ans = f(ans, tab[l+1]);
			if (r&1) ans = f(ans, tab[r-1]);
		}
		return ans;
	}
};

const int mod = 1e9+7;

int mul(int a, int b){
	return (a*b)%mod;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<T>a(m);
	for (int i = 0; i<m; i++) a[i].read();
	sort(a.begin(), a.end(), [](auto x, auto y) {return (x.r - x.l == y.r - y.l) ? x.l < y.l : x.r - x.l < y.r - y.l;});
	TreeOr t1(n+1);
	TreeSum t2(n+1);
	for (auto [l, r, v]:a){
		if (t2.query(l, r) == r-l+1) continue;
		int L = l, R = r, ans = -1;
		while (R >= L){
			int mid = (L+R)/2;
			if (t2.query(l, mid) < mid-l+1){
				ans = mid;
				R = mid-1;
			} else {
				L = mid+1;
			}
		}
		assert(ans != -1);
		t1.update(ans, v);
		t2.update(ans, 1);
	}
	vector<int>b(n+1);
	for (int i = 1; i<=n; i++) b[i] = t1.query(i, i);
	// debug(b);
	int ans = 0;
	for (int i = 1; i<=n; i++){
		ans |= b[i];
	}
	ans = mul(ans, 1);
	for (int i = 1; i<n; i++) ans = mul(ans, 2LL);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}