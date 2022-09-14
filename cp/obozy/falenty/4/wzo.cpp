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
const int base = 2137;

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

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	s = "$"+s;
	vector<int>H(n+1), p(n+1), inv(n+1);
	p[0] = 1;
	inv[0] = 1;
	int I = power(base, mod-2);
	for (int i = 1; i<=n; i++){
		p[i] = mul(p[i-1], base);
		inv[i] = mul(inv[i-1], I);
		H[i] = add2(H[i-1], mul(s[i], p[i]));
	}
	// debug(H);
	auto Hash = [&](int l, int r){
		int ans = H[r];
		sub(ans, H[l-1]);
		return mul(ans, inv[l-1]);
	};
	auto check = [&](int mid){
		// debug(mid);
		vector<int>f;
		for (int i = mid; i<=n; i++){
			// debug(i-mid+1, i, Hash(i-mid+1, i));
			f.emplace_back(Hash(i-mid+1, i));
		}
		sort(f.begin(), f.end());
		f.emplace_back(oo);
		int prev = 0;
		for (int i = 1; i<(int)f.size(); i++){
			if (f[i] != f[i-1]){
				// debug(i-prev);
				if (i-prev >= k) {
					return 1;
				}
				prev = i;
			}
		}
		return 0;
	};

	int L = 1, R = n;
	int ans = -1;
	while (R >= L){
		int mid = (L+R)/2;
		if (check(mid)){
			ans = mid;
			L = mid+1;
		} else R = mid-1;
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