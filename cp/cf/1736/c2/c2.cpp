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

struct Tree{
	vector<int>tab, lazy;
	int size = 1;

	Tree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		lazy.assign(2*size, 0);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i]-i;
		for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return oo;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}

	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x] += lazy[x];
		tab[2*x+1] += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}

	void update(int x, int lx, int rx, int l, int r, int val){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] += val;
			lazy[x] += val;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	Tree t(n+3, a);
	int curr = 0;
	vector<vector<pair<int, int>>>change(n+3);
	for (int i = 1; i<=n; i++){
		int L = i, R = n;
		int ans = oo;
		while (R >= L){
			int mid = (L+R)/2;
			if (t.query(1, 0, t.size-1, i, mid) < 0){
				ans = mid;
				R = mid-1;
			} else {
				L = mid+1;
			}
		}
		L = ans+1, R = n;
		int ans2 = oo;
		while (R >= L){
			int mid = (L+R)/2;
			if (t.query(1, 0, t.size-1, ans+1, mid) < 0){
				ans2 = mid;
				R = mid-1;
			} else {
				L = mid+1;
			}
		}
		if (ans == oo) ans = n+1;
		if (ans2 == oo) ans2 = n+1;
		change[ans].emplace_back(ans-i+1, ans2-ans);
		debug(ans, ans2, ans-i, ans2-i);
		curr += (ans-i);
		t.update(1, 0, t.size-1, i, n, 1);
	}
	for (int i = 1; i<=n; i++){
		debug(i, change[i]);
		change[i].emplace_back(-oo, 0);
		sort(change[i].begin(), change[i].end());
		
		for (int j = 1; j<(int)change[i].size(); j++){
			change[i][j].second += change[i][j-1].second;
		}
	}
	int q; cin >> q;
	while (q--){
		int pos, val; cin >> pos >> val;
		debug(change[pos]);
		pair<int, int>now = {val, 0};
		int currans = lower_bound(change[pos].begin(), change[pos].end(), now)-change[pos].begin();
		int ret = curr;
		if (currans < (int)change[pos].size()){
			ret += change[pos][currans].second;
		}
		cout << ret << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}