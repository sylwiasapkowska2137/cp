//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
	int n, k; cin >> n >> k;
	set<vector<int>>s;
	vector<vector<int>>tab;
	for (int i = 0; i<n; i++){
		vector<int>a;
		for (int j = 0; j<k; j++){
			int x; cin >> x;
			a.emplace_back(x);
		}
		s.insert(a);
		tab.emplace_back(a);
	}
	int ans = 0;
	for (int i = 0; i<n; i++){
		int cnt = 0;
		for (int j = 0; j<n; j++){
			if (i == j) continue;
			vector<int>rev;
			for (int c = 0; c < k; c++){
				if (tab[i][c] == tab[j][c]){
					rev.emplace_back(tab[i][c]);
				} else {
					rev.emplace_back(3-tab[i][c]-tab[j][c]);
				}
			}
			if (s.find(rev) != s.end()) cnt++;
		}
		cnt/=2;
		// debug(i, cnt);
		ans += cnt*(cnt-1)/2;
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