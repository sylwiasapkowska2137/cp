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


void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int>>edges;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		edges.emplace_back(a, b);
	}
	vector<int>L(n+1, 1), R(n+1, m), ans(n+1, m);
	while (1){
		bool ok = 1;
		vector<vector<int>>p(m+1);
		for (int i = 1; i<n; i++){
			if (L[i] == R[i]) continue;
			ok = 0;
			int mid = (L[i]+R[i])/2;
			p[mid].emplace_back(i);
		}
		if (ok) break;
		vector<int>rep(n+1);
		iota(rep.begin(), rep.end(), 0);

		function<int(int)>Find = [&](int a){
			if (a == rep[a]) return a;
			return rep[a] = Find(rep[a]);
		};

		function<void(int, int)>Union = [&](int a, int b){
			a = Find(a);
			b = Find(b);
			if (a == b) return;
			rep[b] = a;
		};

		for (int i = 1; i<=m; i++){
			Union(edges[i-1].first, edges[i-1].second);	
			for (auto x: p[i]){
				if (Find(x) == Find(x+1)){
					ans[x] = i;
					R[x] = i;
				} else {
					L[x] = i+1;
				}
			}
		}
	}
	segmax seg(n, ans);
	for (int i = 0; i<q; i++){
		int l, r; cin >> l >> r;
		if (l == r) cout << "0 ";
		else cout << seg.query(l, r-1) << " ";
	}
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

/*
3 3 6
1 2
3 2
3 1
1 1
1 2
1 3
2 2
2 3
3 3
*/