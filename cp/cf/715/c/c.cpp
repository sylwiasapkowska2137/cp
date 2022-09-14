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

namespace IO {
  const int MAXSIZE = 1 << 18 | 1;
  char buf[MAXSIZE], *p1, *p2;
 
  inline int Gc() {
    return p1 == p2 &&
      (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
  }
  template<typename T> inline void read(T& x) {
    x = 0; int f = 0, ch = Gc();
    while (!isdigit(ch)) f |= ch == '-', ch = Gc();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
    if (f) x = -x;
  }
}
using IO::read;

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


const int K = 16;
int M, PHI;
vector<int>down, depth, sub, vis, upp;
vector<vector<pair<int, int>>>g;
vector<vector<int>>up, val;
vector<bool>used;
vector<unordered_map<int, int>>cnt;
unordered_map<int, int>all;
LL ans = 0;

int mul(int a, int b){
	return (LL)a*(LL)b %M;
}

void add(int &a, int b){
	a += b;
	a %= M;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

int inv(int a){
	return power(a, PHI-1);
}

void init(int n){
	g.resize(n);
	down.resize(n);
	upp.resize(n);
	used.assign(n, 0);
	cnt.resize(n);
	up.resize(n, vector<int>(K));
	val.resize(n, vector<int>(K));
	depth.assign(n, 0);
	sub.assign(n, 0);
}

int phi(int n) {
    int result = n;
    for (int i = 2; i*i<=n; i++) {
        if (n%i == 0) {
            while (n%i==0) n/=i;
            result -= result/i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

int sub_dfs(int v, int pa){
	sub[v] = 1;
	for (auto [x, c]: g[v]){
		if (x == pa || used[x]) continue;
		sub[v] += sub_dfs(x, v);
	}
	return sub[v];
}

int get(int v, int ms, int pa){
	for (auto [x, c]: g[v]){
		if (x == pa || used[x]) continue;
		if (sub[x]*2>ms) return get(x, ms, v);
	}
	return v;
}

void dfs(int v, int pa, int cc){
	up[v][0] = pa;
	val[v][0] = cc;
	vis.emplace_back(v);
	int p = 10;
	for (int i = 1; i<K; i++) {
		up[v][i] = up[up[v][i-1]][i-1];
		val[v][i] = mul(val[v][i-1], p);
		add(val[v][i], val[up[v][i-1]][i-1]);
		p = mul(p, p);
	}
	for (auto [x, c]: g[v]){
		if (x == pa || used[x]) continue;
		down[x] = (10*down[v]+c)%M;
		depth[x] = depth[v]+1;
		dfs(x, v, c);
	}
	
}

void dfs2(int v, int pa, int from){
	cnt[from][upp[v]]++;
	all[upp[v]]++;
	for (auto [x, c]: g[v]){
		if (x == pa || used[x]) continue;
		dfs2(x, v, from);
	}
}

void dfs3(int v, int pa, int from){
	int val = (-down[v]+M)%M;
	val = mul(val, inv(power(10, depth[v])));
	ans += (all[val]-cnt[from][val]);
	for (auto [x, c]:g[v]){
		if (x == pa || used[x]) continue;
		dfs3(x, v, from);
	}
}

void centroid(int v){
	v = get(v, sub_dfs(v, v), v);
	// debug(v);
	depth[v] = 0;
	dfs(v, v, 0);
	for (auto i: vis){
		int I = i;
		for (int j = K-1; j>=0; j--){
			if (depth[I]&(1<<j)){
				upp[i] = mul(upp[i], power(10, (1<<j)));
				add(upp[i], val[I][j]);
				I = up[I][j];
			}
		}
		// if (!upp[i])ans++;
	}
	for (auto [x, c]:g[v]){
		if (!used[x]) {
			dfs2(x, v, x);
		}
	}
	for (auto [x, c]:g[v]){
		if (used[x]) continue;
		dfs3(x, v, x);
	}
	//wyczysc wszystko
	for (auto i: vis){
		ans += (i==v?0:(down[i] == 0)+(upp[i] == 0));
		upp[i] = 0;
		down[i] = 0;
	}
	for (auto [x, c]: g[v]) cnt[x].clear();
	all.clear();
	vis.clear();

	used[v] = 1;
	for (auto [x, c]: g[v]){
		if (!used[x]){
			centroid(x);
		}
	}
}

void solve(){
	int n; read(n); read(M);
	PHI = phi(M);
	init(n+1);
	for (int i = 1; i<n; i++){
		int a, b, c; read(a); read(b); read(c);
		a++;b++;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	centroid(1);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}