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
const int mod = 1e9+7;
vector<int>fact;

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = (k*k)%mod;
	if (b&1) k = (k*a)%mod;
	return k;
}

int inv(int a){
	return power(a, mod-2);
}

int nck(int n, int k){
	if (k > n || n < 0 || k < 0) return 0;
	return (fact[n]*((inv(fact[k])*inv(fact[n-k]))%mod))%mod;
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	fact.resize(n+1);
	fact[0] = 1;
	for (int i = 1; i<=n; i++) fact[i] = (fact[i-1]*i)%mod;
	vector<int>a(n);
	for (int i = 0; i<n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	if (m == 1){
		cout << n << "\n";
		return;
	}
	vector<int>pref(n+1);
	pref[0] = nck(0, m-2);
	for (int i = 1; i<=n; i++) pref[i] = (pref[i-1]+nck(i, m-2))%mod;
	//debug(pref);
	int ans = 0;
	//debug(a);
	for (int i = 0; i<n; i++){
		int L = 0, R = i-1, anss = -1;
		while (R>=L){
			int mid = (L+R)/2;
			if (a[i]-a[mid] > k){
				L = mid+1;
			} else {
				anss = mid;
				R = mid-1;
			}
		}
		if (anss == -1) continue;
		int len = i-anss-1;
		//debug(i, a[i], anss, len, pref[len]);
		ans += pref[len];
		if (ans >= mod) ans %= mod;
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}