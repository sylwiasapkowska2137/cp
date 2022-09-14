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
const int mod = 1e9+9;
const int base = 2137;
const int base2 = 2139;

int mul(int a, int b){
	return (a*b)%mod;
}

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int HASZ(string s){
	int p = 1;
	int ret = 0;
	for (int i = 0; i<(int)s.size(); i++){
		add(ret, mul(s[i], p));
		p = mul(p, base);
	}
	return ret;
}
int HASZ2(string s){
	int p = 1;
	int ret = 0;
	for (int i = 0; i<(int)s.size(); i++){
		add(ret, mul(s[i], p));
		p = mul(p, base2);
	}
	return ret;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0) a+=mod;
}

void solve(){
	int n; cin >> n;
	vector<pair<int, int>>curr(n+1);
	multiset<pair<int, int>>s;
	for (int i = 0; i<n; i++) s.insert({0, 0});
	int q; cin >> q;
	while (q--){
		int idx;
		string S;
		int t;
		cin >> idx >> S >> t;
		int H1 = HASZ(S);
		int H2 = HASZ2(S);
		s.erase(s.find(curr[idx]));
		if (t == 1){
			add(curr[idx].first, H1);
			add(curr[idx].second, H2);
			// curr[idx] = ((curr[idx]+H)%mod+mod)%mod;
		} else {
			// curr[idx] = (curr[idx]-H+mod)%mod;
			sub(curr[idx].first, H1);
			sub(curr[idx].second, H2);
		}
		if (curr[idx].first && curr[idx].second && s.find(curr[idx])!=s.end()){
			cout << "1\n";
		} else {
			cout << "0\n";
		}
		s.insert(curr[idx]);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
