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
const int mod = 998244353;

int mul(int a, int b){
	a %= mod;
	b %= mod;
	return (a*b)%mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

int inv(int a){
	return power(a, mod-2);
}

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int>d(n);
	for (int i = 0; i<n; i++) cin >> d[i];
	sort(d.begin(), d.end());
	int s = accumulate(d.begin(), d.end(), 0);
	vector<int>pref(n+1);
	for (int i = 1; i<=n; i++) pref[i] = pref[i-1]+d[i-1];
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		int k = d.end()-lower_bound(d.begin(), d.end(), b);
		int ans = 0;
		if (k >= a){
			int weak = pref[n-k];
			int strong = (pref[n]-pref[n-k]+mod)%mod;
			add(ans, mul(strong, mul(k-a, inv(k))));
			add(ans, mul(weak, mul(k+1-a, inv(k+1))));
		}
		cout << ans << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}