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

// #define int long long
const int oo = 1e9+7, K = 30;
const int mod = 998244353;

int ti(char c){
	return (int)(c-'a');
}

void solve(){
	string s; cin >> s;
	vector<int>cnt(K);
	vector<pair<int, int>>tab;
	int n = (int)s.size();
	vector<vector<int>>pref(n+1, vector<int>(K));
	s = "$"+s;
	for (int i = 1; i<=n; i++){
		for (int j = 0; j<K; j++)pref[i][j] = pref[i-1][j];
		pref[i][ti(s[i])]++;
	}
	for (int i = 1; i<=n; i++){
		int x = ti(s[i]);
		if (!cnt[x]){
			tab.emplace_back(i, i);
			cnt[x]++;
			continue;
		} 
		int L = i, R = n, ans = i;
		while (R >= L){
			int mid = (L+R)/2;
			bool ok = 1;
			for (char c = 'a'; c <= 'z'; c++){
				if (pref[i-1][ti(c)] < pref[mid][ti(c)]-pref[i-1][ti(c)]){
					ok = 0;
					break;
				}
			}
			if (ok){
				ans = mid;
				L = mid+1;
			} else {
				R = mid-1;
			}
		}
		tab.emplace_back(i, ans);
		cnt[x]++;
	}
	int start = 1, end = 0;
	int ans = 0;
	for (int i = 0; i<(int)tab.size(); i++){
		if (tab[i].first <= end) continue;
		ans++;
		end = max(end, tab[i].second);
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
