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
typedef long double ld;



void solve(){
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(3);
	int n, len; cin >> n >> len;
	vector<int>w(n+1), x(n+1), v(n+1);
	for (int i = 1; i<=n; i++) cin >> w[i] >> x[i] >> v[i];
	auto f = [&](ld mid){
		vector<pair<ld, int>>tab;
		int ans = 0;
		for (int i = 1; i<=n; i++) tab.emplace_back((ld)x[i]+mid*v[i], i);
		sort(tab.begin(), tab.end());
		int r = 0, s = w[tab[0].second];
		for (int l = 0; l < n; l++){
			while (r+1 < n && tab[r+1].first - tab[l].first <= len) {
				r++;
				s += w[tab[r].second];
			}
			ans = max(ans, s);
			s -= w[tab[l].second];
		}
		return ans;
	};
	ld l = 0, r = oo;
	const ld eps = 1e-9; 
	while (r - l > eps){
		ld m1 = l + (r-l)/3;
		ld m2 = r - (r-l)/3;
		if (f(m1) > f(m2)) l = m1;
		else r = m2;
	}
	debug(l);
	cout << max(f(0), f(l)) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
