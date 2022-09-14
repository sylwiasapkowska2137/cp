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
	vector<string>s;
	for (int i = 0; i<n; i++){
		string t; cin >> t;
		s.emplace_back(t);
	}
	while (q--){
		string pref, suf; cin >> pref >> suf;
		int ans = 0;
		for (int i = 0; i<n; i++){
			if (s[i].size() >= pref.size() && s[i].size() >= suf.size()){
				bool ok = 1;
				for (int j = 0; j<(int)pref.size(); j++){
					ok &= (s[i][j] == pref[j]);
				}
				for (int j = (int)suf.size()-1, x = (int)s[i].size()-1; j>=0; j--, x--){
					ok &= (s[i][x] == suf[j]);
				}
				if (ok) ans++;
			}
		}
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
