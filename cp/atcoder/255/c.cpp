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
	int x, a, d, n; cin >> x >> a >> d >> n;
	if (d >= 0){
		int f = a;
		int l = a+(n-1)*d;
		debug(f, l);
		debug((x>f));
		if (x < f || x > l){
			cout << min(abs(x-f), abs(x-l)) << "\n";
			return;
		}
		int ans = n-2;
		int L = 0, R = n-1;
		while (R>=L){
			int m = (L+R)/2;;
			int e = a+m*d;
			if (abs(x) >= abs(e)){
				ans = m;
				R = m-1;
			} else L = m+1;
		}
		int e = a+ans*d;
		int p = e-d;
		int nx = e+d;
		debug(ans, e, p);
		cout << min({abs(x-e), abs(x-p), abs(x-nx)}) << "\n";
	} else {
		int f = a;
		int l = a+(n-1)*d;
		if (x < f || x > l){
			cout << min(abs(x-f), abs(x-l)) << "\n";
			return;
		}
		int ans = n-2;
		int L = 0, R = n-1;
		while (R>=L){
			int m = (L+R)/2;;
			int e = a+m*d;
			if (x <= e){
				ans = m;
				R = m-1;
			} else L = m+1;
		}
		int e = a+ans*d;
		int p = e-d;
		cout << min(abs(x-e), abs(x-p)) << "\n";
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
