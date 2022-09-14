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
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	vector<pair<int, int>>tab;
	for (int i = 1; i<=n; i++){
		int l, r; cin >> l >> r;
		tab.emplace_back(l, i);
		tab.emplace_back(r, -i);
	}
	sort(tab.begin(), tab.end());
	int ans = 0;
	for (int mask = 0; mask<(1<<n); mask++){
		vector<stack<int>>s(2);
		bool ok = 1;
		for (auto [d, b]:tab){
			int c = ((mask&(1<<(abs(b)-1))) ? 1 : 0);
			if (b > 0) {
				s[c].push(b);
			} else {
				if (s[c].empty() || s[c].top() != abs(b)){
					ok = 0;
					break;
				}
				s[c].pop();
			}
		}
		ans += (ok ? 1 : 0);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
