//Sylwia Sapkowska
#include <bits/stdc++.h>
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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
const int mx = 50;
typedef long double ld;

void solve(){
	int n; cin >> n;
	map<int, int>m;
	
	cout << fixed << setprecision(10);
	vector<pair<int, int>>curr;
	while (n--){
		char c; cin >> c;
		int x; cin >> x;
		if (c == '+') m[x]++;
		else {
			m[x]--;
			if (!m[x]) m.erase(x);
		}
		ld subset_count = 1;
		ld ans = 0;
		int ck = mx;
		curr.clear();
		for (auto v: m){
			if (!ck) break;
			ck--;
			curr.emplace_back(v.first, v.second);
		}
		for (int j = (int)curr.size()-1; j>=0; j--){
			ld k = curr[j].second;
			if (subset_count <= oo) subset_count *= (k+1);
			ans = (k/(k+1.0))*(ld)curr[j].first + ans/(k+1.0);
		}
		if (subset_count <= oo2) ans *= (subset_count/(subset_count-1.0));
		cout << ans << "\n";
	}	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
