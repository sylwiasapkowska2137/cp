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
const int base = 2137, base2 = 2139;

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

void sub(int &a, int b){
	a -= b;
	if (a < 0) a+= mod;
}

int C2(int a){
	return (a*(a-1))/2;
}

void solve(){
	string s; cin >> s;
	int n = (int)s.size();
	int S = min(n-1, max(700LL, (int)ceil((long double)sqrt(n))));
	int I1 = power(base, mod-2);
	int I2 = power(base2, mod-2);
	int ans = 0;
	for (int len = 1; len <= S; len++){
		pair<int, int>H = {0, 0};
		int p = 1, p2 = 1;
		map<pair<int, int>, int>cnt;
		for (int i = 0; i<len; i++){
			add(H.first, mul(p, s[i]));
			add(H.second, mul(p2, s[i]));
			p = mul(p, base);
			p2 = mul(p2, base2);
		}
		p = mul(p, I1);
		p2 = mul(p2, I2);
		cnt[H]++;
		for (int i = len; i < n; i++){
			sub(H.first, s[i-len]);
			sub(H.second, s[i-len]);
			H.first = mul(H.first, I1);
			H.second = mul(H.second, I2);
			add(H.first, mul(p, s[i]));
			add(H.second, mul(p2, s[i]));
			cnt[H]++;
		}
		debug(cnt);
		int ile = 0;
		for (auto x: cnt) ile += C2(x.second);
		ans += ile*len*len;
		// return;
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
