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
	vector<int>a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		if (a[i]&1){
			a[i] += (a[i]%10);
		}
	}
	auto ok = [&](int x, int y){
		if (x == y) return 1;
		vector<int>tmp;
		int v = x;
		while (v-x <= 20){
			if (v % 10 == 0) break;
			v += (v%10);
			if (v == y) return 1;
			tmp.emplace_back(v);
		}
		for (auto x: tmp){
			if (y > x && (y-x)%20 == 0) return 1;
		}
		return 0;
	};

	sort(a.begin(), a.end());
	bool ans = 1;
	for (int i = 0; i<n; i++){
		ans &= ok(a[i], a[n-1]);
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}