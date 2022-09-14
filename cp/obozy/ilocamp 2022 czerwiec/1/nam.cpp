//Sylwia Sapkowska
#include <bits/stdc++.h>
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

void add(int& a, int b){
	a += b;
	if (a >= mod) a-=mod;
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

int inv(int a){
	return (power(a, mod-2));
}

void solve(){
	int h, w; cin >> h >> w;
	int ans = 0;
	vector<int>fact(max(h, w)+2), inv_num(max(h, w)+2), inv_fact(max(h, w)+2);
	fact[0] = 1;
	for (int i = 1; i<(int)fact.size(); i++) fact[i] = mul(fact[i-1], i);
	inv_num[0] = inv_num[1] = 1LL;
	for (int i = 2; i<(int)fact.size(); i++) inv_num[i] = mul(inv_num[mod%i], (mod-mod/i));
	inv_fact[0] = inv_fact[1] = 1LL;
	for (int i = 2; i<(int)fact.size(); i++) inv_fact[i] = mul(inv_fact[i-1],inv_num[i]);
	int X = mul(fact[w], fact[h]);
	for (int hl = 0; hl<=h; hl++){
		for (int vl = 0; vl<=w; vl++){
			for (int sl = 0; sl<=h*w; sl++){
				if (vl + hl + 2*sl > h+w) break;
				if (h - hl - 2*vl - sl < 0) break;
				if (w - vl - 2*hl - sl < 0) break;
				int tmp = X;
				tmp = mul(tmp, mul(inv_fact[hl], mul(inv_fact[vl], mul(inv_fact[sl], mul(inv_fact[h-hl-2*vl-sl], inv_fact[w-vl-2*hl-sl])))));
				tmp = mul(tmp, inv(power(2, hl+vl)));
				tmp = mul(tmp, power(4, sl));
				//debug(hl, vl, sl, tmp);
				add(ans, tmp);
			}
		}
	}
	cout << ans-1 << "\n";

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
