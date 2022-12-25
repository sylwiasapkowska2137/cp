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
	int n, m; cin >> n >> m;
	map<int, int>cnt;
	int sum = 0;
	for (int i = 0; i<n; i++){
		int x; cin >> x;
		cnt[x]++;
		sum += x;
	}
	vector<pair<int, int>>curr;
	for (auto x: cnt) curr.emplace_back(x.first, x.second);
	
	int M = (int)curr.size();
	vector<int>pref(M+1);
	for (int i = 1; i<=M; i++) pref[i] = pref[i-1] + curr[i-1].second*curr[i-1].first;
	
	auto suma = [&](int l, int r){
		r++;l++;
		if (l <= r) return pref[r]-pref[l-1];
		swap(l, r);
		l++;r--;
		int ans = pref[curr.size()];
		if (l <= r) ans -= (pref[r]-pref[l-1]);
		return ans;
		// return pref[curr.size()] - (pref[l] - pref[r-1]);
	};
	if (M >= m-1){
		cout << "0\n";
		return;
	}
	int ans = -oo;
	int r = 0;
	for (int l = 0; l<(int)curr.size(); l++){
		r = max(r, l);
		while (curr[(r+1)%M].first == (curr[r].first+1)%m){
			r = (r+1)%M;
		}
		// debug(l, r, suma(l, r));
		ans = max(ans, suma(l, r));
	}
	cout << sum-ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
