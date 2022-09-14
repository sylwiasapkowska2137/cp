//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
	return (a*b)%mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	vector<int>dp1(n+3), dp2(n+3), dp3(n+3);
	for (auto v: a){
		if (v >= 2){
			dp2[v] = mul(dp2[v], 2);
			add(dp2[v], dp1[v-2]);
			add(dp2[v], dp3[v]);
		}
		dp3[v+2] = mul(dp3[v+2], 2);
		add(dp3[v+2], dp2[v+2]); 
		if (v == 0) dp1[v] = mul(2, dp1[v]+1)-1;
		else {
			dp1[v] = mul(2, dp1[v]);
			add(dp1[v], dp1[v-1]);
		}
	}
	int ans = 0;
	for (int i = 0; i<=n; i++){
		add(ans, dp1[i]);
		add(ans, dp2[i]);
		add(ans, dp3[i]);
	}
	int tmp = 1;
	for (int i = 0; i<n; i++){
		if (a[i] == 1){
			tmp = mul(tmp, 2);
		}
	}
	add(ans, tmp-1);
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