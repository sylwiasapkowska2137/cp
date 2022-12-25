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

const int oo = 1e9+7;

struct Tree{
	vector<vector<int>>tab;
	int size = 1;

	Tree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.resize(2*size);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size].emplace_back(a[i]);
		for (int i = size-1; i>=1; i--){
			tab[i].resize(tab[2*i].size() + tab[2*i+1].size());
			merge(tab[2*i].begin(), tab[2*i].end(), tab[2*i+1].begin(), tab[2*i+1].end(), tab[i].begin());
		}
	}
	
	int query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return tab[x].end()-upper_bound(tab[x].begin(), tab[x].end(), r);
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r) + query(2*x+1, m+1, rx, l, r);
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(2*n+2);
	vector<pair<int, int>>val(n+1);
	for (int i = 1; i<=2*n; i++) {
		cin >> a[i];
		if (val[a[i]].first) val[a[i]].second = i;
		else val[a[i]].first = i;
	}
	vector<int>was(n+1), nxt(2*n+2, -oo);
	for (int i = 2*n; i>=1; i--){
		if (was[a[i]]) nxt[i] = was[a[i]];
		was[a[i]] = i;
	}
	Tree t(2*n+2, nxt);
	long long ans = 0;
	for (int i = 1; i<=n; i++) {
		ans += (long long)t.query(1, 0, t.size-1, val[i].first, val[i].second);
	}
	cout << ans+n << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
