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

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1), curr(k+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		curr[a[i]]++;
	}
	int ans = 0, mn = oo;
	for (int l = 1; l<=n; l++){
		for (int r = l; r<=n; r++){
			vector<int>cnt(k+1, 0);
			for (int i = l; i<=r; i++){
				cnt[a[i]]++;
			}
			bool ok = 1;
			for (int i = 1; i<=k; i++){
				if (cnt[i]){
					if (cnt[i] != curr[i]){
						ok = 0;
						break;
					}
				}
			}
			if (ok){
				// debug(l, r);
				ans++;
				int len = r-l+1;
				int d = abs(len-(n-len));
				mn = min(mn, d);
			}
		}
	}
	cout << ans-1 << " " << mn << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
