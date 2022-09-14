//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

int query(int a, int b){
	cout << "? " << a << " " << b << "\n";
	cout.flush();
	int d; cin >> d;
	return d;
}

void answer(int d){
	cout << "! " << d << "\n";
	cout.flush();
	exit(0);
}

void solve(){
	int n; cin >> n;
	vector<int>d1(n+1), d2(n+1);
	for (int i = 3; i<=n; i++) d1[i] = query(1, i);
	for (int i = 3; i<=n; i++) d2[i] = query(2, i);
	vector<pair<int, int>>d;
	for (int i = 3; i<=n; i++){
		d.emplace_back(d1[i]+d2[i], i);
	}
	sort(d.begin(), d.end());
	if (d[0].first != 3) answer(d[0].first);
	int cnt = 0;
	for (int i = 0; i<(int)d.size(); i++) if (d[i].first == 3) cnt++;
	if (cnt == 2 && query(d[0].second, d[1].second) == 1) answer(3);
	answer(1);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
