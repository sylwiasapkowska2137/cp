//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	map<int, int>last;
	for (int i = 0; i<n; i++) last[a[i]] = i;
	int l = 0, r = 0, m = last[a[0]];
	map<int, int>cnt;
	int ans = 0;
    vector<pair<int, int>>blocks;
	while (l < n){
		cnt.clear();
		cnt[a[r]]++;
		while (r < m){
			r++;
			m = max(m, last[a[r]]);
			cnt[a[r]]++;
		}
		int xd = 0;
		for (auto x: cnt) xd = max(xd, x.second);
		ans += (r-l+1)-xd;
		blocks.emplace_back(l, r);
		l = r+1;
		m = l;
	}
	cout << ans << "\n";
    while (q--){
        int i, x; cin >> i >> x;
        //set x on ith position;
        i--;
        
    }
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}