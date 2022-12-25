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
	int n; cin >> n;
	vector<pair<int, int>>edges;
	for (int i = 1; i<=n; i++){
		edges.emplace_back(i, i%n+1);
	}
	for (int i = 2; i<=n; i++){
		edges.emplace_back(1, i);
	}
	debug(edges);
	int curr = 0;
	vector<vector<int>>ans;
	int M = (int)edges.size();
	for (int mask2 = 1; mask2 < (1<<M); mask2++){
		map<int, int>cnt;
		bool ok2 = 0;
		for (int i = 0; i<n; i++){
			if (mask2&(1<<i)){
				ok2 = 1;
			}
		}
		for (int i = 0; i<M; i++){
			if (mask2&(1<<i)){
				cnt[edges[i].first]++;
				cnt[edges[i].second]++;
			}
		}
		bool ok = 1;
		for (auto x: cnt){
			if (x.second&1){
				ok = 0;
			}
		}
		if (ok && !ok2){
			curr = 0;
			break;
		}
		if (ok) {
			vector<int>now;
			for (int i = 0; i<M; i++){
				if (mask2&(1<<i)){
					now.emplace_back(i);
				}
			}
			// debug(now);
			ans.emplace_back(now);
		}
	}
	sort(ans.begin(), ans.end(), [](auto x, auto y){return x.size() < y.size();});
	// for (auto x: ans) {
		// debug(x);
	// }
	cout << (int)ans.size() << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
