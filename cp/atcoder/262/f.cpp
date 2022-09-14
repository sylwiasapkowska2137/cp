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

struct segtree{
	vector<int>tab, lazy;
	int size = 1;

	segtree(int n, int where){
		while (size < n) size*=2;
		tab.resize(2*size);
		lazy.assign(2*size, -1);
		for (int i = where; i<n-1; i++) tab[i+size] = 1;
		for (int i = size-1; i>=1; i--) tab[i] = tab[2*i] + tab[2*i+1];
	}

	void push(int x, int lx, int rx){
		if (lazy[x] == -1 || lx == rx) return;
		tab[2*x] = tab[2*x+1] = 0;
		lazy[2*x] = lazy[2*x+1] = 0;
		lazy[x] = -1;
	}


	void update(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] = 0;
			lazy[x] = 0;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r);
		update(2*x+1, m+1, rx, l, r);
		tab[x] = tab[2*x] + tab[2*x+1];
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r)+query(2*x+1, m+1, rx, l, r);
	}
};

vector<int>calc(vector<int>&a, int k, int &n, int where){
	if (k < 0) return {oo};
	segtree seg(n+1, where);
	vector<int>pos(n+1), good(n+1);;
	for (int i = 0; i<n; i++) pos[a[i]] = i;
	int st = -1;
	for (int i = 1; i<=n; i++){
		if (pos[i] <= st) continue;
		int L = st+1, R = pos[i]-1;
		int x = (L <= R ? seg.query(1, 0, seg.size-1, L, R) : 0);
		if (x <= k){
			k -= x;
			if (L <= R) seg.update(1, 0, seg.size-1, L, R);
			good[pos[i]] = 1;
			st = pos[i];
		}
	}
	vector<int>ret;
	int last = 0;
	for (int i = 0; i<n; i++) {
		if (good[i]){
			ret.emplace_back(a[i]);
			last = i;
		}
	}
	for (int i = last+1; i<n; i++) ret.emplace_back(a[i]);
	return ret;
}

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	// vector test(n + 1, vector(n + 1, vector<int>(n + 1)));

	int pos = n-1, mn = a[0], where = 0;
	for (int i = 0; i<k-1; i++, pos--){
		if (mn > a[pos]){
			mn = a[pos];
			where = pos;
		}
	}
	vector<int>A = calc(a, k, n, 0);
	k -= (n-where);
	rotate(a.begin(), a.begin()+where, a.end());
	vector<int>B = calc(a, k, n, where);
	if (A > B) swap(A, B);
	for (auto x: A) cout << x << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
