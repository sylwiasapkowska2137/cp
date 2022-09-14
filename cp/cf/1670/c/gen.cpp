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

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n = p(1, 1000);
	cout << n << "\n";
	vector<int>a(n);
	iota(a.begin(), a.end(), 1);
	shuffle(a.begin(), a.end(), rng);
	for (auto x: a) cout << x << " ";
	cout << "\n";
	vector<int>b(n);
	iota(b.begin(), b.end(), 1);
	shuffle(b.begin(), b.end(), rng);
	for (auto x: b) cout << x << " ";
	cout << "\n";
	vector<bool>used(n+1, 0);
	for (int i = 0; i<n; i++){
		int x = p(0, 1);
		if (x) {
			int y = p(0, 1);
			if (y && !used[b[i]]) {
				cout << b[i] << " ";
				used[b[i]] = 1;
			} else {
				if (used[a[i]]){
					cout << b[i] << " ";
					used[b[i]] = 1;
				} else {
					cout << a[i] << " ";
					used[a[i]] = 1;
				}
				
			}
		} else cout << "0 ";
	}
	
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cout << "1\n";
	while (t--) solve();
	
	return 0;
}
