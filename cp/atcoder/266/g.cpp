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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
const int mx = 2e6+7;
int f[mx];

int mul(int a, int b){
	return (a*b)%mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

void solve(){
	int r, g, b, k; cin >> r >> g >> b >> k;
	f[0] = 1;
	for (int i = 1; i<mx; i++) f[i] = mul(f[i-1], i);
	int ans = mul(f[b+r], f[b+g]);
	int ans2 = mul(f[b], mul(f[k], mul(f[r-k], mul(f[g-k], f[b+k]))));
	ans = mul(ans, power(ans2, mod-2));
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
