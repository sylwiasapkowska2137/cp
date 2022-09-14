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

struct item{
	int l, r, w;
	item (int _l = 0, int _r = 0, int _c = 0){
		l = _l, r = _r, w = _c;
	}

	void read(){
		cin >> l >> r >> w;
	}

	void d(){
		cerr << l << " " << r << " " << w << endl;
	}
};


void solve(){
	int n, k; cin >> n >> k;
	vector<item>tab(n);
	for (int i = 0; i<n; i++) tab[i].read();
	sort(tab.begin(), tab.end(), [&](auto a, auto b){
		if (a.l != b.l) return a.l < b.l;
		if (a.r != b.r) return a.r < b.r;
		return a.w < b.w;
	});
	
	vector<vector<int>>G(n);
	vector<bool>vis;
	int cnt = 0;

	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		cnt++;
		for (auto x: G[v]){
			if (!vis[x]){
				dfs(x);
			}
		}
	};
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			pair<int, int>com = {max(tab[i].l, tab[j].l), min(tab[i].r, tab[j].r)};
			if (com.first <= com.second){
				G[i].emplace_back(j);
				G[j].emplace_back(i);
				debug(i, j);
			}
		}
	}
	set<pair<int, int>>s;
	for (int i = 0; i<n; i++){
		s.insert({tab[i].w, i});
	}
	vector<int>deg(n);
	for (int i = 0; i<n; i++) deg[i] = (int)G[i].size();
	int ans = 0;
	while (s.size()){
		int val = s.begin()->first;
		int v = s.begin()->second;
		debug(v);
		s.erase(s.begin());
		if (deg[v] == 0) continue;
		ans += tab[v].w;
		for (auto x:G[v]){
			deg[x]--;
			if (deg[x])	s.insert(make_pair(tab[x].w, x));
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
