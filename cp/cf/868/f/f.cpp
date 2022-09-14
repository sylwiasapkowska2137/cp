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
const int oo = 1e18, K = 21;
const int N = 1e5+7;
vector<int>a, dp, new_dp, cnt;

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

int ans, l = 1, r = 0;

void calc(int L, int R){
	while (r < R){
		r++;
		ans += cnt[a[r]];
		cnt[a[r]]++;
	}	
	while (l > L){
		--l;
		ans += cnt[a[l]];
		cnt[a[l]]++;
	}
	while (r > R){
		cnt[a[r]]--;
		ans -= cnt[a[r]];
		r--;
	}
	while (l < L){
		cnt[a[l]]--;
		ans -= cnt[a[l]];
		l++;
	}
}

void rec(int d, int l, int r, int optl, int optr){
	if (l > r) return;
	int m = (l+r)/2;
	int opt = oo;
	new_dp[m] = oo;
	for (int i = optl; i<=min(m-1, optr); i++){
		calc(i+1, m);
		//debug(i+1, m, ans);
		if (dp[i] == oo) continue;
		int t = dp[i]+ans;
		if (new_dp[m] >= t){
			new_dp[m] = t;
			opt = i;
		}
	}
	//debug(m, d, new_dp[m], opt);
	rec(d, l, m-1, optl, opt);
	rec(d, m+1, r, opt, optr);
}

void solve(){
	int n, k; read(n); read(k);
	a.resize(n+1);
	cnt.assign(n+1, 0);
	dp.resize(n+1);
	dp[0] = 0;
	new_dp.resize(n+1);
	for (int i = 1; i<=n; i++) {
		read(a[i]);
		ans += cnt[a[i]]++;
		dp[i] = ans;
	}
	r = n;
	for (int k2 = 2; k2<=k; k2++) {
		rec(k2, 1, n, 0, n);
		dp = new_dp;
	}
	
	cout << dp[n] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}