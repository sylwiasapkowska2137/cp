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
	vector<pair<int, int>>par(n+1);
	for (int i = 1; i<=n; i++){
		int a, b; cin >> a >> b;
		if (a) par[a] = {i, 0};
		if (b) par[b] = {i, 1};
	}
	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		// debug(a, b);
		vector<int>curr;
		while (a != 1){
			debug(a);
			curr.emplace_back(par[a].second);
			a = par[a].first;
		}
		reverse(curr.begin(), curr.end());
		int A = 0;
		for (auto x: curr) {
			A *= 2;
			A += x;
		}
		curr.clear();
		while (b != 1){
			curr.emplace_back(par[b].second);
			b = par[b].first;
		}
		reverse(curr.begin(), curr.end());
		int B = 0;
		for (auto x: curr) {
			B *= 2;
			B += x;
		}
		if (A >= B) cout << "TAK\n";
		else cout << "NIE\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
