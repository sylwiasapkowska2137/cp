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
	int n, x; cin >> n >> x;
	vector<pair<int, int>>neg, pos;
	for (int i = 1; i<=n; i++){
		int u; cin >> u;
		if (u < 0) neg.emplace_back(u, i);
		else pos.emplace_back(u, i);
	}
	for (int i = 1; i<=n; i++){
		int u; cin >> u;
		if (u < 0) neg.emplace_back(u, -i);
		else pos.emplace_back(u, -i);
	}
	pos.emplace_back(0, 0);
	neg.emplace_back(0, 0);
	sort(neg.rbegin(), neg.rend());
	sort(pos.begin(), pos.end());
	vector<pair<int, int>>hammer(n+1);
	for (int i = 0; i<(int)pos.size(); i++){
		if (pos[i].second < 0){
			hammer[-pos[i].second] = {i, 0};
		}
	}
	for (int i = 0; i<(int)neg.size(); i++){
		if (neg[i].second < 0){
			hammer[-neg[i].second] = {i, 1};
		}
	}
	// debug(neg);
	// debug(pos);
	vector dp((int)pos.size()+2, vector<vector<int>>((int)neg.size()+2, vector<int>(2, oo)));
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int dod = 0; dod < (int)pos.size(); dod++){
		for (int uj = 0; uj < (int)neg.size(); uj++){
			// debug(dod, uj, dp[dod][uj][0], dp[dod][uj][1]);
			
			for (int rep = 0; rep < 2; rep++){
				if (dp[dod][uj][rep] == oo) continue;
				//dp[dod][uj][0] --- jestesmy w neg[uj]
				int start;
				if (rep == 0) start = neg[uj].first;
				else start = pos[dod].first;

				if (dod+1 < (int)pos.size()){
					bool ok = 0;
					ok |= (pos[dod+1].second < 0);
					if (!ok){
						ok |= (hammer[pos[dod+1].second].second == 1 && hammer[pos[dod+1].second].first <= uj);
						ok |= (hammer[pos[dod+1].second].second == 0 && hammer[pos[dod+1].second].first <= dod);
					}
					if (ok)	dp[dod+1][uj][1] = min(dp[dod+1][uj][rep], dp[dod][uj][rep]+abs(start-pos[dod+1].first));
				}
				if (uj + 1 < (int)neg.size()){
					bool ok = 0;
					ok |= (neg[uj+1].second < 0);
					if (!ok){
						ok |= (hammer[neg[uj+1].second].second == 1 && hammer[neg[uj+1].second].first <= uj);
						ok |= (hammer[neg[uj+1].second].second == 0 && hammer[neg[uj+1].second].first <= dod);
					}
					if (ok)	dp[dod][uj+1][0] = min(dp[dod][uj+1][0], dp[dod][uj][rep]+abs(start-neg[uj+1].first));
				}
			}
		}
	}
	int ans = oo;
	if (x > 0){
		int idx = 0;
		for (int i = 0; i<(int)pos.size(); i++){
			if (pos[i].first < x){
				idx = i;
			}
		}
		for (int uj = 0; uj<(int)neg.size(); uj++) ans = min(ans, dp[idx][uj][1] + abs(pos[idx].first-x));
	} else {
		int idx = 0;
		for (int i = 0; i<(int)neg.size(); i++){
			if (neg[i].first > x){
				idx = i;
			}
		}
		// debug(neg);
		// debug(idx);
		for (int dod = 0; dod<(int)pos.size(); dod++) ans = min(ans, dp[dod][idx][0] + abs(neg[idx].first-x));
	}
	if (ans == oo) cout << "-1\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
