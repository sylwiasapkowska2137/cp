//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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

vector<pair<int, int>>tab; //min, indeks
int sz = 1;

void init(int n, vector<int>&a){
	while (sz < n) sz*=2;
	tab.assign(2*sz+1, {oo, oo});
	for (int i = 0; i<n; i++) tab[i+sz] = {a[i], i};
	for (int i = sz-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
}

pair<int, int>query(int l, int r){
	pair<int, int> ans = {oo, oo};
	l = l+sz-1;
	r = r+sz+1;
	while (r-l>1){
		if (!(l&1)) ans = min(ans, tab[l+1]);
		if (r&1) ans = min(ans, tab[r-1]);
		l/=2;r/=2;
	}
	return ans;
}

void update(int x, int val){
	x += sz;
	tab[x].first = val;
	while (x){
		x/=2;
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	init(n, a);
	int q; cin >> q;
	while (q--){
		int l, r; cin >> l >> r;
		--l;--r;
		vector<pair<int, int>>undo;
		for (int i = 0; i<=K; i++){
			pair<int, int>x = query(l, r);
			if (x.first != oo){
				undo.emplace_back(x);
				update(x.second, oo);
			} else break;
		}
		int ans = oo;
		for (int i = 0; i<(int)undo.size(); i++){
			for (int j = i+1; j<(int)undo.size(); j++){
				ans = min(ans, undo[i].first | undo[j].first);
			}
		}
		cout << ans << "\n";
		for (auto [val, pos]:undo){
			update(pos, val);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
