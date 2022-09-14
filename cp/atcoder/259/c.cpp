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
	string s, t; cin >> s >> t;
	vector<pair<char, int>>tab, tab2;
	int cnt = 1;
	for (int i = 1; i<(int)s.size(); i++){
		if (s[i] == s[i-1]){
			cnt++;
		} else {
			tab.emplace_back(s[i-1], cnt);
			cnt = 1;
		}
	}
	tab.emplace_back(s.back(), cnt);
	// debug(tab);
	cnt = 1;
	swap(s, t);
	swap(tab, tab2);
	for (int i = 1; i<(int)s.size(); i++){
		if (s[i] == s[i-1]){
			cnt++;
		} else {
			tab.emplace_back(s[i-1], cnt);
			cnt = 1;
		}
	}
	tab.emplace_back(s.back(), cnt);
	// debug(tab);
	if (tab.size() != tab2.size()){
		cout << "No\n";
		return;
	}
	for (int i = 0; i<(int)tab.size(); i++){
		if (tab[i].first != tab2[i].first){
			cout << "No\n";
			return;
		}
		if (tab2[i].second == 1 && tab[i].second > 1){
			cout << "No\n";
			return;
		}
		if (tab2[i].second > 1 && tab[i].second < tab2[i].second){
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
