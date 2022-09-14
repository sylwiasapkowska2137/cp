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

mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

void solve(){
	int n; cin >> n;
	vector<int>a(n), b(n);
	vector<int>scaler;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		scaler.emplace_back(a[i]);
	}
	for (int i = 0; i<n; i++) {
		cin >> b[i];
		scaler.emplace_back(b[i]);
	}
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	map<int, uint64_t>values;
	for (auto x: scaler){
		values[x] = rng();
	} 
	uint64_t H = 0;
	map<int, int>cnt;
	vector<int>A(n+1), B(n+1);
	for (int i = 0; i<n; i++){
		cnt[a[i]]++;
		if (cnt[a[i]] == 1){
			H += values[a[i]];
		}
		A[i] = H;
	}
	cnt.clear();
	H = 0;
	for (int i = 0; i<n; i++){
		cnt[b[i]]++;
		if (cnt[b[i]] == 1){
			H += values[b[i]];
		}
		B[i] = H;
	}
	int q; cin >> q;
	while (q--){
		int l, r; cin >> l >> r;
		if (A[l-1] == B[r-1]) cout << "Yes\n";
		else cout << "No\n";
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
