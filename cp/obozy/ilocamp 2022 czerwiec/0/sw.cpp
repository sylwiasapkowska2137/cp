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
const int oo = 1e9+7;

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, oo);
	}

	void clear(){
		tab.assign(tab.size(), oo);
	}

	void update(int x, int v){
		x += size;
		tab[x] = min(tab[x], v);
		while (x){
			x/=2;
			tab[x] = min(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = oo;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n, k; scanf("%lld%lld", &n, &k);
	vector<int>d(n+1), on(n+1);
	d[0] = 0;
	for (int i = 1; i<=n; i++) scanf("%lld", &d[i]);
	for (int i = 1; i<=n; i++) scanf("%lld", &on[i]);
	vector<int>dp(n+1);
	dp[0] = 0;
	segtree seg(n+1);
	seg.update(0, 0);
	for (int i = 1; i<=n; i++){
		int idx = i-1, L = 0, R = i-1;
		while (R>=L){
			int m = (L+R)/2;
			if (d[i]-d[m] <= k){
				idx = m;
				R = m-1;
			} else L = m+1;
		}
		dp[i] = seg.query(idx, i-1)+(on[i]^1);
		seg.update(i, dp[i]);
	}
	int ans = dp[n];
	//debug(dp);
	for (int i = n-1; i>=0; i--){
		if (d[n]-d[i] <= k){
			ans = min(ans, dp[i]);
		} 
	}
	//debug(dp);
	printf("%lld\n", ans);
}

int32_t main(){
	
	solve();
	
	return 0;
}
