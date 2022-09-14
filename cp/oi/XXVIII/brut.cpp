//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
const int oo = 1e18;

void solve(){
	int n, d; cin >> n >> d;
	vector<vector<int>>s(n);
	for (int i = 0; i<n; i++){
		int x; cin >> x;
		for (int j = 0; j<x; j++) {
			int v; cin >> v;
			s[i].emplace_back(v);
		}
	}

	function<int(int)>dist = [&](int X){
		return min(X, d-X);
	};

	
	for (int i = 1; i<n; i++){
		int a = s[i-1].size();
		int b = s[i].size();
		if (a == 0 && b == 0) {
			cout << "0\n";
		} else if (a == 1 && b == 1){
			cout << dist(abs(s[i][0]-s[i-1][0])) << "\n";
		} else if (a == 1 && b == 0){
			cout << dist(s[i-1][0]) << "\n";
		} else {
			cout << dist(s[i][0]) << "\n";
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
