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
const int N = 2e5+7;

int tab[N*K][2], cnt[N*K], ends_here[N*K];
int sz;

void add(int x, int pos){
	int v = 0;
	for (int i = K-1; i>=0; i--){
		bool s = (x&(1<<i));
		if (tab[v][s] == -1) tab[v][s] = ++sz;
		v = tab[v][s];
		cnt[v]++;
	}
	ends_here[v] = pos;
}

void remove(int x){
	int v = 0;
	for (int i = K-1; i>=0; i--){
		bool s = (x&(1<<i));
		v = tab[v][s];
		cnt[v]--;
	}
}

int minn(int x){
	int v = 0, ans = 0;
	for (int i = K-1; i>=0; i--){
		bool s = x&(1<<i);
		if (tab[v][s] != -1 && cnt[tab[v][s]] > 0){
			v = tab[v][s];
			ans += (s?(1<<i):0);
		} else {
			v = tab[v][s^1];
			ans += (s?0:(1<<i));
		}
	}
	return ends_here[v];
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	
	memset(tab, -1, sizeof(tab));
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		add(a[i], i+1);
	}
	vector<vector<int>>g(n+1);
	set<pair<int, int>>good;
	for (int i = 0; i<n; i++){
		remove(a[i]);
		pair<int, int>e = {i+1, minn(a[i])};
		if (e.first > e.second) swap(e.first, e.second);
		if (good.find(e) == good.end()){
			g[e.first].emplace_back(e.second);
			g[e.second].emplace_back(e.first);
			good.insert(e);
			debug(e);
		}
		add(a[i], i+1);
	}
	
	vector<int>vis(n+1);
	int cnt = 0, ans = 1;
	bool cycle = 0;
	function<void(int)> dfs = [&](int v){
		vis[v] = 1;
		cnt++;
		for (auto x: g[v]){
			if (!vis[x]) dfs(x);
			else if (vis[x] == 1){
				cycle = 1;
				return;
			}
		}
		vis[v] = 2;
	};

	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			cnt = 0;
			cycle = 0;
			dfs(i);
			if (!cycle){
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; //cin >> t;
	while (t--) solve();
	
	return 0;
}