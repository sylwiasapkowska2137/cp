//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
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

const ll oo = 1e18, K = 30;
const int nax = 1e9+7, N = 4001;
int dp[N], new_dp[N];
int pref[N][N];

int sum(int i, int j){
	return (pref[j][j]-pref[j][i-1]-pref[i-1][j]+pref[i-1][i-1])/2;
}

void rec(int d, int l, int r, int optl, int optr){ 
	if (l > r) return;
	int m = (l+r)/2;
	int opt = nax;
	new_dp[m] = nax;
	for (int i = optl; i<=min(m-1, optr); i++){
		int t = dp[i]+sum(i+1, m);
		if (new_dp[m] >= t){
			new_dp[m] = t;
			opt = i;
		}
	}
	//debug(m, d, dp[m][d], optl, optr);
	rec(d, l, m-1, optl, opt);
	rec(d, m+1, r, opt, optr);
}

void solve(){
	int n, k; read(n); read(k);
	for (int i = 1; i<=n; i++) {
		for (int j = 1; j<=n; j++){
			read(pref[i][j]);
			pref[i][j] += pref[i][j-1]+pref[i-1][j]-pref[i-1][j-1];
		}
	}
	for (int i = 1; i<=n; i++) dp[i] = sum(1, i);
	for (int i = 2; i<=k; i++) {
		rec(i, 1, n, 0, n);
		for (int j = 1; j<=n; j++) dp[j] = new_dp[j];
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