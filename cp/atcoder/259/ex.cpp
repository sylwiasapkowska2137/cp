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
vector<int>f;

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

int inv(int a){
	return power(a, mod-2);
}

int nck(int n, int k){
	if (n < 0 || k < 0 || n-k < 0) return 0;
	return mul(f[n], mul(inv(f[k]), inv(f[n-k])));
}

struct segtree{
	vector<int>tab;
	int size = 1;
	
	segtree(int n){
		while (size < n) size*=2;
		tab.resize(2*size);
		for (int i = 1; i<size; i++) tab[i+size] = i;
		for (int i = size-1; i>=1; i--) tab[i] = mul(tab[2*i], tab[2*i+1]);
	}

	int query(int l, int r){
		int ans = 1;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = mul(ans, tab[l+1]);
			if (r&1) ans = mul(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<vector<int>>a(n+1, vector<int>(n+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	f.resize(3*n);
	f[0] = 1;
	for (int i = 1; i<(int)f.size(); i++) f[i] = mul(f[i-1], i);
	segtree seg(3*n);
	for (int a = 1; a <= n; a++){
		for (int c = a; c <= n; c++){

		}
	}	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
