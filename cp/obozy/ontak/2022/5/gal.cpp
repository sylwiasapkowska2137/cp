//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
typedef long double LD;

LD d(pair<int, int>a, pair<int, int>b){
	LD x = a.first-b.first;
	LD y = a.second-b.second;
	return sqrt(x*x+y*y);
}

void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int, int>>a(n), b(m);
	for (auto &[x, y]:a) cin >> x >> y;
	for (auto &[x, y]:b) cin >> x >> y;
	vector<LD>best(n, oo);
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			best[i] = min(best[i], d(a[i], b[j]));
		}
	}
	// debug(best);
	LD ans = oo;
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			ans = min(ans, d(a[i], a[j]));
			ans = min(ans, best[i]+best[j]);
		}
	}
	cout << fixed << setprecision(15) << ans/2.0 << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
