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
	int n, l, r; cin >> n >> l >> r;

	int st = 1, x = n-1;
	while(l-x>=0){
		l -= (x--);
		st++;
	}
	pair<int, int>a = {st, st+l};
	st = 1, x = n-1;
	while(r-x>=0){
		r -= (x--);
		st++;
	}
	pair<int, int>b = {st, st+r};
	debug(a, b);
	if (a.first == b.first){


		return;
	}
	vector<int>t(n);
	iota(t.begin(), t.end(), 1);
	while (a.second <= n){
		//do swaps
		swap(t[a.first-1], t[a.second-1]);
		a.second++;
	}
	reverse(t.begin()+a.first+1, t.end());
	reverse(t.begin()+b.first, t.begin()+b.second+1);
	debug(t);
	x = 1;
	while (x <= b.second){
		swap(t[b.first-1], t[x-1]);
		x++;
		//do swpas
	}
	for (auto x: t) cout << x << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
