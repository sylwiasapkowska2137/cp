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

int mul(int a, int b){
	return (a*b)%mod;
}

void add(int &a, int b){
	a += b;
	if (a > mod) a-=mod;
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

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.resize(2*size);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = (tab[2*x] + tab[2*x+1])%mod;
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) add(ans, tab[l+1]);
			if (r&1) add(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<n; i++) cin >> a[i];
	segtree seg(n+1);
	vector<int>dp(n+1);
	for (int i = n-1; i>=1; i--){
		dp[i] = mul(seg.query(i+1, i+a[i])+1, inv(a[i]))+1;
		seg.update(i, dp[i]);
	}
	cout << dp[1] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
