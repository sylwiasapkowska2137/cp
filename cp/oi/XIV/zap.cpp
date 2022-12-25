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
const int mx = 5e4+7;

vector<int>prime(mx), mobius(mx, 1);

void pre(){
	prime[0] = prime[1] = 1;
	for (int i = 2; i<mx; i++){
		if (!prime[i]){
			for (int j = i; j<mx; j+=i){
				if (j > i) prime[j] = 1;
				if (j%(i*i) == 0) mobius[j] = 0;
				mobius[j] = -mobius[j];
			}
		}
	}	
}

int count(int a, int d, int k){
	int m = min(a/k, d/k);
	int ans = 0;
	for (int l = 1; l <= m; l++){
		ans += mobius[l] * (a/k/l) * (d/k/l);
	}
	return ans;
}

void solve(){
	int q; cin >> q;
	pre();
	while (q--){
		int b, d, k; cin >> b >> d >> k;
		int m = min(b, d);
		if (m < k) cout << "0\n";
		else cout << count(b, d, k) << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
