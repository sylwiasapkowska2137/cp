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
const int oo = 1e18, K = 30;
const int mod = 998244353;

void add(int &a, int b){
	a += b;
	if (a > mod) a-=mod;
}

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
	int n, m, k; cin >> n >> m >> k;
	vector<int>deg(n+1);

	vector<int>f(n+1);
	f[0] = 1;
	for (int i = 1; i<=n; i++) f[i] = mul(f[i-1], i);

	auto inv = [&](int a){
		return power(a, mod-2);
	};

	auto nck = [&](int n, int k){
		if (k > n || n < 0 || k < 0) return 0LL;
		return mul(f[n], mul(inv(f[n-k]), inv(f[k])));
	};

	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}	
	int odd = 0, even = 0;
	for (int i = 1; i<=n; i++){
		if (deg[i]&1) odd++;
		else even++;
	}
	debug(odd, even);
	int ans = 0;
	for (int i = 0; i<=odd; i+=2){
		int left = k-i;
		if (left < 0) break;
		if (left > even) continue;
		add(ans, mul(nck(odd, i), nck(even, left)));
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
