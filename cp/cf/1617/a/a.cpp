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
	string s; cin >> s;
	string t; cin >> t;
	sort(s.begin(), s.end());
	map<char, int>cnt;
	for (auto c: s){
		cnt[c]++;
	}
	if (t == "abc" && cnt['a'] > 0 && cnt['b'] > 0 && cnt['c'] > 0){
		
		for (int i = 0; i<cnt['a']; i++) cout << 'a';
		for (int i = 0; i<cnt['c']; i++) cout << 'c';
		for (int i = 0; i<cnt['b']; i++) cout << 'b';
		for (char c = 'd'; c <= 'z'; c++){
			for (int i = 0; i<cnt[c]; i++) cout << c;
		}
		cout << "\n";
	} else {
		cout << s << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}