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

int ti(char c){
	return (int)(c-'a');
}

void solve(){
	string t, p; cin >> t >> p;
	int T = (int)t.size();
	int P = (int)p.size();
	vector<vector<int>>c(K);
	for (int i = 0; i<P; i++) c[ti(p[i])].emplace_back(i);
	sort(c.begin(), c.end());
	int ans = 0;
	for (int i = 0; i+P-1 < T; i++){
		vector<vector<int>>d(K);
		for (int j = i; j<i+P; j++)	d[ti(t[j])].emplace_back(j-i);
		sort(d.begin(), d.end());
		if (c == d) ans++;
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
