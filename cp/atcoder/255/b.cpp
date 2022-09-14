//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

long double d(pair<int, int>a, pair<int, int>b){
	long double x = (a.first-b.first);
	long double y = (a.second-b.second);
	long double z = x*x+y*y;
	return sqrt(z);
}

void solve(){
	int n, k; cin >> n >> k;
	vector<int>ok(n);
	for (int i = 0; i<k; i++) {
		int x; cin >> x;
		ok[x-1] = 1;
	}
	vector<pair<int, int>>p(n);
	for (int i = 0; i<n; i++){
		cin >> p[i].first >> p[i].second;
	}
	long double ans = 0;
	for (int i = 0;i<n; i++){
		if (ok[i]) continue;
		long double tmp = oo;
		for (int j = 0; j<n; j++){
			if (ok[j]){
				tmp = min(tmp, d(p[i], p[j]));
			}
		}
		ans = max(ans, tmp);
	}
	cout << fixed << setprecision(15);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
