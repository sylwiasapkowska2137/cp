//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
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
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
    int n; cin >> n;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>used(n+1), sz(n+1);
	function<int(int, int)>dfssize = [&](int v, int pa){
		sz[v] = 1;
		for (auto x: g[v]){
			if (x == pa || used[x]) continue;
			sz[v] += dfssize(x, v);
		}
		return sz[v];
	};
	function<int(int, int, int)>get_centroid = [&](int v, int pa, int ms){
		for (auto x: g[v]){
			if (x == pa || used[x]) continue;
			if (sz[x] * 2 > ms) return get_centroid(x, v, ms);
		}
		return v;
	};
	vector<vector<int>>G(n+1);
	auto add = [&](int a, int b){
		if (a == b) return;
		cerr << a << " " << b << "\n";
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	};
	function<void(int, int)>centroid = [&](int v, int from){
		v = get_centroid(v, v, dfssize(v, v));
        add(from, v);
		used[v] = 1;
		for (auto x: g[v]){
			if (!used[x]){
				centroid(x, v);
			}
		}
	};
	centroid(1, 1);
	
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}