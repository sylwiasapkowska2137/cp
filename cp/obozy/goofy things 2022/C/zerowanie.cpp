//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

const LL MOD = 1e9+7;
const int N = 20;

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	vector<long long>dp((1<<N),0);
	vector<long long>power(n+1, 0);
	power[0] = 1;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		dp[a[i]]++;
		power[i+1] = (power[i]*2LL)%MOD;
	}
	for (int i = 0; i<N; i++){
		for (int mask = 0; mask<(1<<N); mask++){
			if (!(mask&(1<<i))){
				dp[mask]+=dp[mask^(1<<i)];
			}
		}
	}
	LL ans = 0LL;
	for (int mask = 0; mask<(1<<N); mask++){
		
		if (__builtin_popcount(mask)&1) {
			ans -= (power[dp[mask]]-1);
			while (ans < 0) ans += MOD;
		} else {
			ans += (power[dp[mask]]-1);
			if (ans >= MOD) ans%=MOD;
		}
	}

	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
