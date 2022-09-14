//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
	int n, m; cin >> n >> m;
	pair<int, int>s; cin >> s.first >> s.second;
	int d; cin >> d;
	auto dist = [&](pair<int, int>v){
		return abs(s.first-v.first) + abs(s.second - v.second);
	};

	if (s.first - d <= 1 && s.first + d >= n){
		cout << "-1\n";
		return;
	}
	if (s.second - d <= 1 && s.second + d >= m){
		cout << "-1\n";
		return;
	}
	if (s.first - d <= 1 && s.second - d <= 1){
		cout << "-1\n";
		return;
	}
	if (s.first + d >= n && s.second + d >= m){
		cout << "-1\n";
		return;
	}
	cout << n+m-2 << "\n";
	// if (ok || ok2) cout << n+m-2 << "\n";
	// else cout << "-1\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}