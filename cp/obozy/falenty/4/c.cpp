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
const int mod = 1e9+7;

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

int add2(int a, int b){
	int ret = a+b;
	if (ret >= mod) ret -= mod;
	return ret;
}

int mul(int a, int b){
	return (a*b)%mod;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0) a+=mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

const int mx = 2e6+7;
int f[mx];

int inv(int x){
	return power(x, mod-2);
}

void solve(){
	f[0] = f[1] = 1;
	for(int i = 2; i < mx; i++) f[i] = mul(f[i-1], i);
	int n, k; cin >> n >> k;
	vector<int>a(k);
	int s = 0;
	for (int i = 0; i<k; i++) {
		cin >> a[i];
		s += a[i];
	}
	int ans = f[s+n-1];
	int b = f[n-1];
	for (auto x: a) b = mul(b, f[x]);
	ans = mul(ans, inv(b));
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
