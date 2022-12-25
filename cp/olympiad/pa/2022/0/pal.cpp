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
const int oo = 1e18;

void solve(){
	string t; cin >> t;
	int n = (int)t.size();
	int cnta = 0, cntb = 0;
	for (auto c: t){
		if (c == 'a') cnta++;
		else cntb++;
	}
	if ((cnta&1) && (cntb&1)){
		cout << "-1\n";
		return;
	}
	set<pair<int, char>>s;
	vector<vector<int>>idx(2);
	auto ti = [&](char c){return (int)(c-'a');};
	for (int i = 0; i<n; i++) idx[ti(t[i])].emplace_back(i);
	vector<vector<int>>ptr(2, vector<int>(2));
	ptr[0][1] = (int)idx[0].size()-1;
	ptr[1][1] = (int)idx[1].size()-1;
	int h = n/2;
	int ans = 0;
	int L = 0, R = n-1;
	while (h--){
		int mn = oo;
		pair<int, int>which = {-1, -1};
		for (int rep1 = 0; rep1 < 2; rep1++){
			for (int rep2 = 0; rep2 < 2; rep2++){
				//rep1 na skrajny lewy, rep2 na skrajny prawy
				if (rep1 == rep2){
					int curr = max(0LL, (idx[rep1][ptr[rep1][0]]-L)) + max(0LL, (R-idx[rep2][ptr[rep2][1]]));
					if (curr <= mn){
						which = {rep1, rep2};
						mn = curr;
					}
				}
				
			}
		}
		// debug(mn, which);
		ans += mn;
		auto [rep1, rep2] = which;
		ptr[rep1][0]++;
		ptr[rep2][1]--;
		// debug(ptr[0][0], ptr[0][1]);
		// debug(ptr[1][0], ptr[1][1]);
		L++;R--;
	}
	assert(ans <= oo && ans >= 0);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
