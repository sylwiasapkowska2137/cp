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

// #define int long long
const int K = 21;
// const int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector<int>dp((1<<K), -1);
	vector<int>a;
	for (int i = 0; i<n; i++){
		int x; cin >> x;
		a.emplace_back(x);
		dp[x] = x;
	}
	for (int i = 0; i<K; i++){
		for (int mask = 0; mask<(1<<K); mask++){
			if (mask&(1<<i)){
				if (dp[mask] == -1){
					dp[mask] = dp[mask^(1<<i)];
				}
			}
		}
	}
	auto neg = [&](int x){
		int y = 0;
		for (int i = 0; i<K; i++){
			if (!(x&(1<<i))) y += (1<<i);
		}
		return y;
	};
	for (int i = 0; i<n; i++) cout << dp[neg(a[i])] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
