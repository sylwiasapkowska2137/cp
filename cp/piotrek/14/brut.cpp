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
	int n, q; cin >> n >> q;
	vector<pair<int, int>>ab(n);
	for (int i = 0; i<n; i++){
		cin >> ab[i].first >> ab[i].second;
	}
	sort(ab.begin(), ab.end(), [](auto x, auto y){return max(x.first, x.second) < max(y.first, y.second);});
	vector<int>x(q);
	for (int i = 0; i<q; i++) cin >> x[i];
	vector<int>tab(q);
	int ans = 0;
	for (int i = n-1; i>=0; i--){
		int flip = 0;
		auto [a, b] = ab[i]; 
		if (a < b) {
			swap(a, b);
			flip = 1;
		}
		for (int j = 0; j<q; j++){
			if (x[j] < b) tab[j] = 0;
			else if (x[j] < a) tab[j] = 1;
			else tab[j] = 2;
		}
		debug(tab);
		int curr = flip;
		for (int j = 0; j<q; j++){
			if (tab[j] == 1) curr = 0;
			if (tab[j] == 2) curr ^= 1;
		}
		if (!curr){
			ans += a;
			debug(a);
		} else {
			ans += b;
			debug(b);
		}
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
