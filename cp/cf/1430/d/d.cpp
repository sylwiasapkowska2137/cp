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
	int n; cin >> n;
	string s; cin >> s;
	set<int>S, S2;
	int cnt = 1;
	vector<int>st(n);
	for (int i = 1; i<n;i++){
		if (s[i] != s[i-1]){
			if (cnt >= 2) S.insert(i-cnt);
			if (cnt == 1) S2.insert(i-cnt);
			st[i-cnt] = cnt;
			cnt = 0;
		}
		cnt++;
	}
	if (cnt) {
		if (cnt >= 2) S.insert(n-cnt);
		if (cnt == 1) S2.insert(n-cnt);
		st[n-cnt] = cnt;
	}
	// debug(st);
	int ans = 0;
	for (int i = 0; i<n; i++){
		if (!st[i]) continue;
		auto it = S.lower_bound(i);
		if (it != S.end()){
			st[*it]--;
			if (st[*it] <= 1) {
				S2.insert(*it);
				S.erase(it);
			}
		} else {
			auto it2 = prev(S2.end());
			st[*it2]--;
			S2.erase(it2);
		}
		if (st[i] == 1) S2.erase(S2.find(i));
		else if (st[i] >= 2) S.erase(S.find(i));
		ans++; 
	}	
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}