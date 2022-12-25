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

void solve(){
	int n, m; pair<int, int>s;
	cin >> n >> m >> s.first >> s.second;
	int ile; cin >> ile;
	map<int, set<int>>poziom, pion;	
	for (int i = 0; i<ile; i++){
		int x, y; cin >> x >> y;
		poziom[x].insert(y);
		pion[y].insert(x);
	}
	int q; cin >> q;
	while (q--){
		char c; cin >> c;
		int d; cin >> d;
		if (c == 'R'){
			auto it = poziom[s.first].lower_bound(s.second);
			if (it == poziom[s.first].end()) s.second = min(m, s.second+d);
			else s.second = min(*it-1, s.second+d);
		} else if (c == 'L'){
			auto it = poziom[s.first].upper_bound(s.second);
			if (it != poziom[s.first].begin()){
				it--;
				if (it == poziom[s.first].end()){
					// debug(c);
					s.second = max(1LL, s.second-d);
				} else {
					s.second = max(*it+1, s.second-d);
				}
			} else {
				s.second = max(1LL, s.second-d);
			}
		} else if (c == 'D'){
			auto it = pion[s.second].lower_bound(s.first);
			if (it == pion[s.second].end()) s.first = min(n, s.first+d);
			else s.first = min(*it-1, s.first+d);
		} else {
			auto it = pion[s.second].upper_bound(s.first);
			if (it != pion[s.second].begin()){
				it--;
				if (it == pion[s.second].end()){
					s.first= max(1LL, s.first-d);
				} else {
					s.first = max(*it+1, s.first-d);
				}
			} else {
				s.first = max(1LL, s.first-d);
			}
		}
		cout << s.first << " " << s.second << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
