//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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

int ti(char c){
	return (int)(c-'a');
}

void solve(){
	string s; cin >> s;
	int n = (int)s.size();
	int diff = 0;
	vector<int>cnt(K, 0);
	char c = s.back();
	for (auto c: s){
		cnt[ti(c)]++;
		if (cnt[ti(c)] == 1){
			diff++;
		}
	}	
	vector<int>curr(K, 0);
	vector<char>ord;
	for (int i = n-1; i>=0; i--){
		if (curr[ti(s[i])] == 0){
			ord.emplace_back(s[i]);
		}
		curr[ti(s[i])]++;
	}
	reverse(ord.begin(), ord.end());
	int ile = 0;
	for (int i = 0; i<(int)ord.size(); i++){
		if (cnt[ti(ord[i])]%(i+1) != 0){
			cout << "-1\n";
			return;
		} 
		ile += cnt[ti(ord[i])]/(i+1);
	}
	string ans = s.substr(0, ile);
	string tmp = ans;
	int ptr = 0;
	string check = tmp;
	while (tmp.size()){
		string nowy;
		for (auto c: tmp){
			if (c == ord[ptr]) continue;
			nowy.push_back(c);
		}
		check += nowy;
		tmp = nowy;
		ptr++;
	}
	if (check == s) {
		cout << ans << " ";
		for (auto c: ord) cout << c;
		cout << "\n";
	} else cout << "-1\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}