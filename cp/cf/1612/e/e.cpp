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
typedef long double ld;
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	vector<int>s;
	map<int, vector<int>>p;
	for (int i = 0; i<n; i++){
		int m, k; cin >> m >> k;
		p[m].emplace_back(k);
		s.emplace_back(m);
	}
	s.emplace_back(0);
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	// debug(s);
	auto count = [&](int pos, int t){
		int ans = 0;
		for (auto x: p[pos]){
			ans += min(t, x);
		}
		return ans;
	};
	cerr << fixed << setprecision(5);
	int S = (int)s.size();
	int ans = 0, pt = 0;
	vector<int>ret;
	for (int t = 1; t<=min(S-1, 21LL); t++){
		vector dp(S+1, vector<int>(t+1, -1));
		for (int i = 0; i<=S; i++) dp[i][0] = 0;
		for (int i = 1; i<S; i++){
			for (int sz = 1; sz <= t; sz++){
				dp[i][sz] = max(dp[i-1][sz], dp[i-1][sz-1] + count(s[i], t));
			}
		}
		if (dp[S-1][t] == -1) continue;
		int ev = dp[S-1][t];
		if (ev * pt >= ans * t){
			//restore set;
			ret.clear();
			pt = t;
			ans = ev;
			int pos = S-1, sz = t;
			while ((int)ret.size() < t){
				if (dp[pos-1][sz-1] + count(s[pos], t) == dp[pos][sz]) {
					ret.emplace_back(s[pos]);
					pos--;
					sz--;
				} else if (pos && dp[pos-1][sz] == dp[pos][sz]){
					pos--;
				} else {
					assert(false);
				}
			}
		}
		// ld curr = dp[n-1][t]/(ld)(t);
		// cerr << curr << "\n";
	}
	cout << (int)ret.size() << "\n";
	for (auto x: ret) cout << x << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}