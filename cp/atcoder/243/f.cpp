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
const int mod = 998244353, I = 499122177;

int mul(int a, int b){
	return (a*b)%mod;
}

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
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
const int mx = 51;
int dp[mx][mx][mx];

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	int s = accumulate(a.begin(), a.end(), 0);
	int X = inv(s);
	vector<int>p(n);
	for (int i = 0; i<n; i++) p[i] = mul(a[i], X);
	
	vector<int>f(mx);
	f[0] = 1;
	for (int i = 1; i<mx; i++) f[i] = mul(f[i-1], i);
	dp[0][0][0] = 1;
	for (int x = 0; x<n; x++){
		for (int y = 0; y<=m; y++){
			for (int z = 0; z<=k; z++){
				for (int c = 0; c <= k-z; c++){
					add(dp[x+1][y+(c!=0)][z+c], mul(dp[x][y][z], mul(power(p[x], c), inv(f[c]))));
				}
				// debug(i, j, k, dp[i][ck][j]);
			}
		}
	}
	cout << mul(dp[n][m][k], f[k]) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
