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
const int base = 2137, mod = 1e15+1;

mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	vector<uint64_t> val(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		val[i] = rng();
	}
	vector<int>cnt(n+1, 0);
	vector<uint64_t> H(n+1);
	int h = 0LL;
	map<uint64_t, vector<int>>pref;
	pref[0].emplace_back(0);
	for (int i = 1; i<=n; i++){
		cnt[a[i]]++;
		h+=val[a[i]];
		if (cnt[a[i]] == 3)	{
			h-=3LL*val[a[i]];
			cnt[a[i]] = 0;
		}
		H[i] = h;
	}
	int l = 0;
	cnt.assign(n+1, 0);
	int bad = -1, ans = 0;
	for (int r = 1; r<=n; r++){
		cnt[a[r]]++;
		if (cnt[a[r]] == 4) bad = a[r];
		while (bad != -1){
			cnt[a[l]]--;
			if (a[l] == bad){
				l++;
				bad = -1;
				break;
			} 
			l++;
		}
		int x = (int)(lower_bound(pref[H[r]].begin(), pref[H[r]].end(), l-1)-pref[H[r]].begin());
		int t = (int)pref[H[r]].size()-x;
		ans += t;
		//debug(l, r, a[r], x, t);
		pref[H[r]].emplace_back(r);
	}
	// for (auto x: pref){
	// 	debug(x.first, x.second);
	// }
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