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
	vector<pair<int, int>>tab;
	int size = 1;

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, {oo, oo});
		for (int i = 0; i<n; i++) tab[i+size] = {a[i], i};
		for (int i = size-1; i>=1; i--)	tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	pair<int, int>query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		pair<int, int> ans = {oo, oo};
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	};

	void update(int x, int v){
		x += size;
		tab[x] = {v, v};
		while (x){
			x/=2;
			tab[x] = min(tab[2*x], tab[2*x+1]);
		}
	}
};

struct project{
	int t, l, r, c; 
	pair<int, int>L, R;
	void read(){
		cin >> t >> l >> r >> c;r++;
		L = {l-t, l+t};
		R = {r-t, r+t};
		// debug(L, R);
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<project>a(m);
	for (int i = 0; i<m; i++) a[i].read();
	sort(a.begin(), a.end(), [](auto x, auto y){return x.L.first < y.L.first;});
	for (int i = 0; i<m; i++){
		debug(a[i].L, a[i].R);
	}
	vector<int>dist(m, oo);
	vector<int>b(m);
	for (int i = 0; i<m; i++) b[i] = a[i].L.second;
	segtree seg(m+1, b);
	set<pair<int, int>>s;
	for (int i = 0; i<m; i++){
		if (a[i].l == 1){
			dist[i] = a[i].c;
			s.insert({a[i].c, i});
			seg.update(i, oo);
		}
	}
	while (s.size()){
		int v = s.begin()->second;
		int d = s.begin()->first;
		s.erase(s.begin());
		int l = 0, r = m-1, idx = -1;
		while (r>=l){
			int mid = (l+r)/2;
			if (a[v].R.first >= a[mid].L.first){
				idx = mid;
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		// debug(v, dist[v], idx);
		if (idx == -1) continue;
		while (1){
			pair<int, int>curr = seg.query(0, idx);
			// debug(curr);
			if (curr.first <= a[v].R.second){
				debug(v, curr.second);
				dist[curr.second] = d + a[curr.second].c;
				s.insert({dist[curr.second], curr.second});
				seg.update(curr.second, oo);
			} else break;
		}
		// for (int x = 0; x<m; x++){
		// 	if (a[x].L.first <= a[v].R.first && a[x].L.second <= a[v].R.second){
		// 		if (dist[x] > d + a[x].c){
		// 			assert(dist[x] == oo);
		// 			dist[x] = d+a[x].c;
		// 			s.insert({dist[x], x});
		// 		}
		// 	}
		// }
	}
	// debug(dist);
	int ans = oo;
	for (int i = 0; i<m; i++){
		if (a[i].r > n){
			ans = min(ans, dist[i]);
		}
	}
	if (ans == oo) cout << "-1\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
