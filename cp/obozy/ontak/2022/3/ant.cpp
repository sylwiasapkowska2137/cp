//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

const int oo = 2e9+7, K = 30;

vector<int>w;
typedef vector<pair<int, int>> T;

struct segtree{
	vector<T>tab;
	T v, z, curr, ans;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.resize(2*size);
	}

	T f(const T &a, const T &b){
		v.clear();z.clear();
		// debug(a, b);
		merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v));
		// debug(v);
		for (int i = v.size()-1; i>=0; i--) {
			if (z.empty()) z.emplace_back(v[i]);
			else if (z.back().first != v[i].first) z.emplace_back(v[i]);
			else z.back().second = min(z.back().second, v[i].second);
		}
		while (z.size() > 1) z.pop_back();
		reverse(z.begin(), z.end());
		// debug(z);
		for(int i = 1; i < (int)z.size(); ++i) {
			assert(z[i-1].first < z[i].first);
		}
		
		return z;
	}

	void update(int x, const T &v){
		x += size;
		tab[x] = f(tab[x], v);
		while (x){
			x/=2;
			tab[x] = f(tab[2*x], tab[2*x+1]);
		}
	}

	void clear(){
		tab.assign(tab.size(), {});
	}

	void update(int x, pair<int, int>v){
		curr = {v};
		x += size;
		tab[x] = f(tab[x], curr);
		while (x){
			x/=2;
			tab[x] = f(tab[2*x], tab[2*x+1]);
		}
	}

	T query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		ans.clear();
		while (r-l>1){
			if (!(l&1)) ans = f(ans, tab[l+1]);
			if (r&1) ans = f(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int pp(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n; cin >> n;
	vector<int>a(n+1), scaler;
	w.resize(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		scaler.emplace_back(a[i]);
	}
	for (int i = 1; i<=n; i++) cin >> w[i];
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	for (int i = 1; i<=n; i++) a[i] = (int)(lower_bound(scaler.begin(), scaler.end(), a[i])-scaler.begin())+1;
	// debug(a);
	int ans = -oo;
	segtree seg0(n+1);
	segtree seg1(n+1);
	T i0, i1;
	int x = pp(1, n);
	rotate(a.begin()+1, a.begin()+x, a.end());
	rotate(w.begin()+1, w.begin()+x, w.end());
	for (int essa = 0; essa < 2; essa++){
		// debug(a);
		// T dp[n+1][2];
		seg0.clear();
		seg1.clear();	
		for (int i = 1; i<=n; i++){
			i1 = seg0.query(a[i]+1, n); 
			i0 = seg1.query(0, a[i]-1);
			for (auto &x: i1) x.first += w[i];
			seg1.update(a[i], {w[i], a[i]});
			for (auto &x: i0) x.first += w[i];
			seg0.update(a[i], i0);
			seg1.update(a[i], i1);
			for (auto x: i0) if (a[i] > x.second) ans = max(ans, x.first);
		}
		for (int i = 1; i<=n; i++) a[i] = n-a[i]+1;
	}
	if (ans == -oo) cout << "NO\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
