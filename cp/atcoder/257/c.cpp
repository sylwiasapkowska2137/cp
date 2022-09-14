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
	string s; cin >> s;
	vector<int>a(n);
	vector<pair<int, int>>tab;
	for (int i = 0; i<n; i++){
		cin >> a[i];
		tab.emplace_back(a[i], s[i]-'0');
	}
	sort(tab.begin(), tab.end());
	debug(tab);
	vector<int>bad(n), suf(n);
	int ans = oo;
	for (int i = 0; i<n; i++){
		bad[i] = (i ? bad[i-1] : 0) + tab[i].second;
	}
	for (int i = n-1; i>=0; i--){
		suf[i] = (i == n-1 ? 0 : suf[i+1]) + (tab[i].second^1);
	}
	for (int i = 0; i<n-1; i++){
		if (tab[i].first != tab[i+1].first) ans = min(ans, bad[i]+suf[i+1]);
	}
	ans = min(ans, bad[n-1]);
	ans = min(ans, suf[0]);
	cout << n-ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
