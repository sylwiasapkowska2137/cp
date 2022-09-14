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

// #define int long long
const int oo = 2e9+7, K = 30;

struct segmax{
	vector<int>tab;
	int size = 1;

	segmax(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, -oo);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = -oo;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

struct segmin{
	vector<int>tab;
	int size = 1;

	segmin(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = min(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = oo;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n, t; cin >> t >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	segmin smin(n+1, a);
	segmax smax(n+1, a);
	int L = 1, R = n, ans = 1;
	while (R>=L){
		int mid = (L+R)/2;
		bool ok = 0;
		for (int e = mid; e <= n; e++){
			ok |= (smax.query(e-mid+1, e)-smin.query(e-mid+1, e) <= t);
			if (ok) break;
		}
		if (ok){
			ans = mid;
			L = mid+1;
		} else R = mid-1;
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}