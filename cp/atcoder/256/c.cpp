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
int ans = 0;
vector<vector<int>>all[3];

void gen(vector<int>a, int sum, int x){
	if ((int)a.size() == 3){
		if (!sum) all[x].emplace_back(a);
		return;
	}
	for (int i = 1; i<=sum; i++){
		a.emplace_back(i);
		gen(a, sum-i, x);
		a.pop_back();
	}
}

void solve(){
	vector<int>h(3), w(3);
	for (int i = 0; i<3; i++) cin >> h[i];
	for (int i = 0; i<3; i++) cin >> w[i];
	
	for (int i = 0; i<3; i++) gen({}, h[i], i);
	set<vector<int>>s;
	for (auto x: all[2]) s.insert(x);
	for (auto x: all[0]){
		for (auto y: all[1]){
			vector<int>c = w;
			for (int i = 0; i<3; i++){
				c[i] -= x[i];
				c[i] -= y[i];
			}
			if (s.find(c) != s.end()) ans++;	
		}
	}
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
