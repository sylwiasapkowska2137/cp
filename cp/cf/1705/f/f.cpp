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

int query(string &s){
	cout << s << "\n";
	cout.flush();
	int x; cin >> x;
	if (x == (int)s.size()) exit(0);
	return x;
}

void solve(){
	int n; cin >> n;
	if (n == 2){
		for (string x: vector<string>{"FF", "TT", "FT", "TF"}){
			query(x);
		}
		return;
	}
	string s;
	for (int i = 0; i<n; i++) s += "F";
	int f = query(s);
	vector<int>two, one;
	for (int i = 0; i+1<n; i+=3){
		s[i] = s[i+1] = 'T';
		if (i+2 < n) one.emplace_back(i+2);
		int p = query(s);
		if (p == f) two.emplace_back(i);
		if (p <= f) s[i] = s[i+1] = 'F';
		f = max(f, p);
	}
	if (n%3 == 1) one.emplace_back(n-1);
	
	function<char(char)>neg = [](char c){
		return (c == 'T'?'F':'T');
	};

	for (auto x: two){
		s[x] = 'T';
		s[x+1] = 'F';
	}
	f = query(s);
	
	debug(one, two);
	int t = min((int)one.size(), (int)two.size());	
	for (int i = 0; i<t; i++){
		s[two[i]] = neg(s[two[i]]);
		s[two[i]+1] = neg(s[two[i]+1]);
		s[one[i]] = neg(s[one[i]]);
		int p = query(s);
		int d = p-f;
		if (d == 1){
			s[one[i]] = neg(s[one[i]]);
		} else if (d == -1){
			s[two[i]] = neg(s[two[i]]);
			s[two[i]+1] = neg(s[two[i]+1]);
		} else if (d == -3){
			s[two[i]] = neg(s[two[i]]);
			s[two[i]+1] = neg(s[two[i]+1]);
			s[one[i]] = neg(s[one[i]]);
		}
		f = max(f, p);
	}
	f = query(s);
	for (int i = t; i<(int)one.size(); i++){
		s[one[i]] = neg(s[one[i]]);
		int p = query(s);
		if (p < f) s[one[i]] = neg(s[one[i]]);
		else p = f;
	}
	f = query(s);
	for (int i = t; i<(int)two.size(); i++){
		s[two[i]] = neg(s[two[i]]);
		s[two[i]+1] = neg(s[two[i]+1]);
		int p = query(s);
		if (p < f){
			s[two[i]] = neg(s[two[i]]);
			s[two[i]+1] = neg(s[two[i]+1]);
		}
		f = max(f, p);
	}
	assert(false);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}