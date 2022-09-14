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
	int n; cin >> n;
	vector<int>a(n+1);
	int x = 0;
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		x ^= a[i];
	}
	if (x){
		cout << "NO\n";
		return;
	}
	vector<int>ans;
	auto sol = [&](int m, int y){
		for (int i = 1; i<m; i+=2) ans.emplace_back(i+y);
		for (int i = m-4; i>=1; i-=2) ans.emplace_back(i+y);
	};

	auto print = [&]{
		cout << "YES\n";
		cout << (int)ans.size() << "\n";
		for (auto x: ans) cout << x << " ";
		cout << "\n";
	};

	if (n&1){
		sol(n, 0);
		print();
		return;
	}
	int c = 0;
	for (int i = 1; i<=n; i++){
		c ^= a[i];
		if (!c && (i&1)){
			sol(i, 0);
			sol((n-i), i);
			print();
			return;
		}
	}
	cout << "NO\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}