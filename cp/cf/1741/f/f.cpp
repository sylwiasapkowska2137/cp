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
	int l, r, c, i;
	void read(int idx){
		cin >> l >> r >> c;
		i = idx;
	}
};

struct TreeMax{
	vector<int>tab;
	int size = 1;

	TreeMax(int n){
		while (size < n) size*=2;
		tab.assign(2*size, -oo);
	}

	void update(int x, int v){
		x += size;
		tab[x] = max(tab[x], v);
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		int ans = -oo;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
		}
		return ans;
	}
};

struct TreeMin{
	vector<int>tab;
	int size = 1;

	TreeMin(int n){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
	}

	void update(int x, int v){
		x += size;
		tab[x] = min(tab[x], v);
		while (x){
			x/=2;
			tab[x] = min(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		int ans = oo;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<T>tab(n);
	for (int i = 0; i<n; i++) tab[i].read(i);
	vector<int>ans(n, oo);

	map<int, vector<tuple<int, int, int>>>mp;
	for (auto [l, r, c, i]: tab) mp[r].emplace_back(l, c, i);	
	TreeMax t(n+2);
	for (auto x: mp){
		for (auto [l, c, idx]: x.second) t.update(c, x.first);
		for (auto [l, c, idx]: x.second){
			int x = max((c > 1 ? t.query(1, c-1) : -oo), (c < n ? t.query(c+1, n) : -oo));
			if (x >= l) ans[idx] = 0;
			else ans[idx] = l-x;
		}
	}

	mp.clear();
	for (auto [l, r, c, idx]: tab) mp[l].emplace_back(r, c, idx);
	// sort(tab.begin(), tab.end(), [](auto x, auto y){return (x.l == y.l) ? x.r < y.r : x.l < y.l;});
	t.tab.assign(2*t.size, -oo);
	for (auto x: mp){
		for (auto [r, c, idx]: x.second) t.update(c, r);
		for (auto [r, c, idx]: x.second){
			int x = max((c > 1 ? t.query(1, c-1) : -oo), (c < n ? t.query(c+1, n) : -oo));
			if (x >= r)	ans[idx] = 0;
		}
	}
	
	mp.clear();
	for (auto [l, r, c, idx]:tab) mp[-l].emplace_back(r, c, idx);
	TreeMin t2(n+2);
	// sort(tab.begin(), tab.end(), [](auto x, auto y){return (x.l == y.l) ? x.r < y.r : x.l > y.l;});
	for (auto x: mp){
		for (auto [r, c, idx]:x.second) t2.update(c, -x.first);
		for (auto [r, c, idx]: x.second){
			int x = min((c > 1 ? t2.query(1, c-1) : oo), (c < n ? t2.query(c+1, n) : oo));
			// debug(l, r, c, idx, x);
			if (x <= r) ans[idx] = 0;
			else ans[idx] = min(ans[idx], x-r);
		}
		
	}

	for (int i = 0; i<n; i++) cout << ans[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}