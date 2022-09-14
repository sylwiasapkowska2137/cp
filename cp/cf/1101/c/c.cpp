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

void solve(){
	int n; cin >> n;
	vector<pair<int, int>>tab, out;
	for (int i = 0; i<n; i++){
		int l, r; cin >> l >> r;
		tab.emplace_back(l, r);
		out.emplace_back(l, r);
	}
	sort(tab.begin(), tab.end());
	int maxi = tab[0].second, i;
	for (i = 1; i<n; i++){
		if (maxi < tab[i].first) break;
		maxi = max(maxi, tab[i].second);
	}
	if (i == n){
		cout << "-1\n";
		return;
	}
	for (int i = 0; i<n; i++){
		if (out[i].second <= maxi)	cout << "2 ";
		else cout << "1 ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
