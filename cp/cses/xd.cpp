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

struct TreeSum{
	vector<int>tab;
	int size = 1;

	TreeSum(int n){
		while (size < n) size *= 2;
		tab.assign(2*size, 0);
	}

	int f(int a, int b){return a+b;}

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


void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1), s;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		s.emplace_back(a[i]);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	for (int i = 1; i<=n; i++) a[i] = lower_bound(s.begin(), s.end(), a[i])-s.begin()+1;
	vector cnt(n+1, vector<int>());
	vector<int>ptr(n+1);
	TreeSum t(n+1);
	for (int i = 1; i<=n; i++) {
		if (cnt[a[i]].empty()) t.update(i, 1);
		cnt[a[i]].emplace_back(i);
	}
	vector<vector<pair<int, int>>>que(n+1);
	for (int i = 0; i<q; i++){
		int l, r; cin >> l >> r;
		que[l].emplace_back(r, i);
	}	
	vector<int>ans(q);
	for (int l = 1; l <= n; l++){
		for (auto [r, i]:que[l]) ans[i] = t.query(l, r);
		ptr[a[l]]++;
		if (ptr[a[l]] < (int)cnt[a[l]].size()) t.update(cnt[a[l]][ptr[a[l]]], 1);
	}
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
