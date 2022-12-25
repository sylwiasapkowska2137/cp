//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353, mod2 = 1e9+7, base = 2137;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0) a+=mod;
}

void sub2(int &a, int b){
	a -= b;
	if (a < 0) a+=mod2;
}

int mul(int a, int b){
	return (a*b)%mod;
}

void add2(int &a, int b){
	a += b;
	if (a >= mod2) a-=mod2;
}

int mul2(int a, int b){
	return (a*b)%mod2;
}

int add21(int a, int b){
	int ret = a + b;
	if (ret >= mod) ret -= mod;
	return ret;
}

int add22(int a, int b){
	int ret = a + b;
	if (ret >= mod2) ret -= mod2;
	return ret;
}

struct TreeSum{
	typedef pair<int, int> T;
	vector<T>tab;
	int size = 1;

	TreeSum(int n){
		while (size < n) size*=2;
		tab.resize(2*size);
	}

	void update(int x, T v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x].first = add21(tab[2*x].first, tab[2*x+1].first);
			tab[x].second = add22(tab[2*x].second, tab[2*x+1].second);
		}
	}

	T query(int l, int r){
		T ans = {0, 0};
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) {
				add(ans.first, tab[l+1].first);
				add2(ans.second, tab[l+1].second);
			}
			if (r&1){
				add(ans.first, tab[r-1].first);
				add2(ans.second, tab[r-1].second);
			}
		}
		return ans;
	}
};

struct TreeXor{
	vector<int>tab;
	int size = 1;

	TreeXor(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = tab[2*x] ^ tab[2*x+1];
		}
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans ^= tab[l+1];
			if (r&1) ans ^= tab[r-1];
		}
		return ans;
	}
};

const int mx = 1e6+7;

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	vector<int>p1(mx), p2(mx);
	p1[0] = p2[0] = 1;
	for (int i = 1; i<(int)p1.size(); i++) {
		p1[i] = mul(p1[i-1], base);
		p2[i] = mul2(p2[i-1], base);
	}
	TreeSum t(n+5);
	TreeXor T(n+5); 
	int ret = 0;
	map<int, ordered_set>indexes;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		t.update(i, {p1[a[i]], p2[a[i]]});
		indexes[a[i]].insert(i);
		T.update(i, a[i]);
	}
	int q; cin >> q;
	for (int i = 0; i<q; i++){
		int type; cin >> type;
		if (type == 1){
			int pos, val; cin >> pos >> val;
			indexes[a[pos]].erase(pos);
			t.update(pos, {p1[val], p2[val]});
			T.update(pos, val);
			a[pos] = val;
			indexes[val].insert(pos);
			continue;
		}
		int l, r; cin >> l >> r;
		int val = T.query(l, r);
		if (indexes[val].empty()) continue;
		int ile = indexes[val].order_of_key(r+1) - indexes[val].order_of_key(l);
		if (ile % 2 == 0) continue;
		int pos = indexes[val].order_of_key(l);
		int remove = *indexes[val].find_by_order(pos+ile/2);
		// debug(val, ile, pos, remove, l, r);
		int half = l + (r-l+1)/2;
		if (remove > half) half--;
		pair<int, int> t1 = t.query(l, half);
		pair<int, int> t2 = t.query(half+1, r);
		if (remove > half) {
			sub(t2.first, p1[val]);
			sub2(t2.second, p2[val]);
		} else {
			sub(t1.first, p1[val]);
			sub2(t1.second, p2[val]);
		}
		// debug(t1, t2);
		if (t1 == t2) ret++;
	}
	cout << ret << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	for (int i = 1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}
