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

// #define int long long
typedef long long ll;
const int K = 20;
const ll p = 2137, mod = 1e9+7;
const ll p2 = 3697, mod2 = 1e9+9;

void add(ll &a, ll b){
	a += b;
	if (a >= mod) a -= mod;
}

void add2(ll &a, ll b){
	a += b;
	if (a >= mod2) a -= mod2;
}

ll mul(ll a, ll b){
	return (a*b)%mod;
}

ll mul2(ll a, ll b){
	return (a*b)%mod2;
}

ll sub(ll a, ll b){
	a -= b;
	if (a < 0) a+=mod;
	return a;
}

ll sub2(ll a, ll b){
	a -= b;
	if (a < 0) a+=mod2;
	return a;
}

ll power(ll a, ll b, ll m){
	if (!b) return 1LL;
	ll k = power(a, b/2, m);
	k = (k*k)%m;
	if (b&1) k = (k*a)%m;
	return k;
}

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int losuj(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n; cin >> n;
	vector<vector<pair<int, int>>>g(n+1);
	for (int i = 1; i<=n; i++){
		int a, b; cin >> a >> b;
		if (a) g[i].emplace_back(a, 0);
		if (b) g[i].emplace_back(b, 1);
	}
	vector<int>sum(n+1), depth(n+1);
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<ll>H1(n+1), H2(n+1);
	vector<ll>pot(n+1), pot2(n+1);
	vector<ll>inv(n+1), inv2(n+1);
	vector<int>pre(n+1), post(n+1);
	int czas = 0;
	ll tmp = losuj(420, 2136);
	pot[0] = pot2[0] = 1;
	inv[0] = power(p, mod-2, mod);
	inv2[0] = power(p2, mod2-2, mod2);
	for (int i = 1; i<=n; i++){
		pot[i] = mul(pot[i-1], p);
		pot2[i] = mul2(pot2[i-1], p2);
		inv[i] = mul(inv[i-1], inv[0]);
		inv2[i] = mul2(inv2[i-1], inv2[0]);
	}

	function<void(int, int)>dfs = [&](int v, int pa){
		pre[v] = ++czas;
		up[v][0] = pa;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto [x, c]: g[v]){
			sum[x] = sum[v]+c;
			depth[x] = depth[v]+1;
			H1[x] = H1[v];
			H2[x] = H2[v];
			add(H1[x], mul(pot[depth[x]], (c+tmp)));
			add2(H2[x], mul2(pot2[depth[x]], (c+tmp)));
			dfs(x, v);
		}
		post[v] = ++czas;
	};

	function<int(int)>Find = [&](int a){
		for (int i = K-1; i>=0; i--){
			if (sum[up[a][i]]){
				a = up[a][i];
			}
		}
		return a;
	};

	function<bool(int, int, int, int)>check = [&](int a, int b, int c, int d){
		ll hash1 = mul(sub(H1[a], H1[b]), inv[depth[b]]);
		ll hash2 = mul2(sub2(H2[a], H2[b]), inv2[depth[b]]);
		ll hash3 = mul(sub(H1[c], H1[d]), inv[depth[d]]);
		ll hash4 = mul2(sub2(H2[c], H2[d]), inv2[depth[d]]);
		return (hash1 == hash3 && hash2 == hash4);
	};

	function<int(int, int)>jump = [&](int v, int j){
		for (int i = K-1; i>=0; i--){
			if (j&(1<<i)){
				v = up[v][i];
			}
		}
		return v;
	};

	function<bool(int, int)>subtree = [&](int a, int b){
		return (pre[a] <= pre[b] && post[a] >= post[b]);
	};

	dfs(1, 1);
	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		int da = Find(a);
		int db = Find(b);
		int x = depth[a]-depth[da];
		int y = depth[b]-depth[db];
		if (x != y){
			if (x > y) cout << "TAK\n";
			else cout << "NIE\n";
			continue;
		}
		if (check(a, da, b, db)){
			cout << "TAK\n";
			continue;
		}
		// cerr << "later..\n";
		for (int i = K-1; i>=0; i--){
			if (depth[a]-(1<<i) < depth[da]) continue;
			int ta = jump(a, (1<<i));
			int tb = jump(b, (1<<i));
			if (check(da, ta, db, tb)){
				da = ta;
				db = tb;
			}
		}
		// debug(a, b, da, db);
		int wa = 0, wb = 0;
		for (auto [v, c]:g[da]){
			if (subtree(v, a)){
				wa = c;
			}
		}
		for (auto [v, c]:g[db]){
			if (subtree(v, b)){
				wb = c;
			}
		}
		assert(wa != wb);
		if (wa < wb) cout << "NIE\n";
		else cout << "TAK\n";
	}
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
