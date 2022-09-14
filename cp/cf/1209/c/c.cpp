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
	int n; cin >> n;
	vector<int>a;
	vector<pair<int, int>>b;
	for (int i = 0; i<n; i++){
		char c; cin >> c;
		a.emplace_back(c-'0');
		b.emplace_back(a.back(), i);
	}
	sort(b.begin(), b.end());
	for (int x = 0; x<=9; x++){
		int idx = oo;
		for (int i = 0; i<n; i++){
			if (a[i] > x) {
				idx = i;
				break;
			}
		}

		vector<int>c, d;
		for (int i = 0; i<n; i++){
			if (b[i].first == x && (d.empty() || (a[d.back()] == x)) && b[i].second < idx) {
				d.emplace_back(b[i].second);
			} else if (b[i].first <= x) {
				c.emplace_back(b[i].second);
			} else {
				d.emplace_back(b[i].second);
			}
		}
		
		if (is_sorted(c.begin(), c.end()) && is_sorted(d.begin(), d.end())){
			vector<int>color(n);
			for (auto v: c) color[v] = 1;
			for (auto v: d) color[v] = 2;
			for (auto v: color) cout << v;
			cout << "\n";
			return;
		}
	}
	cout << "-\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}