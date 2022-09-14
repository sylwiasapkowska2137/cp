//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

const LL base = 2137, mod = 1e9+7;
/*
LL power(LL a, LL b){
	if (!b) return 1LL;
	LL k = power(a, b/2);
	k = (k*k)%mod;
	if (b&1) k = (k*a)%mod;
	return k;
}

LL inv(LL a){
	return power(a, mod-2);
}
*/
void solve(){
	int n, m; cin >> n >> m;
	LL H = 0, pot = 1;
	for (int i = 1; i<=n; i++){
		char c; cin >> c;
		H = (H+c*pot)%mod;
		pot = (pot*base)%mod;
	}
	vector<LL>H1(m+1, 0);
	pot = 1;
	for (int i = 1; i<=m; i++){
		char c; cin >> c;
		H1[i] = (H1[i-1]+c*pot)%mod;
		pot = (pot*base)%mod;
	}
	pot = 1;
	const LL I = 440336924;
	LL inv = 1;
	for (int i = n; i<=m; i++){
		LL hash = (H1[i]-H1[i-n]+mod)%mod;
		hash = (hash*inv)%mod;
		if (hash == H) cout << i-n+1 << "\n";
		pot = (pot*base)%mod;
		inv = (inv*I)%mod;
	}
}

void solve2(){
	int x, m; cin >> x >> m;
	string s, t; cin >> s >> t;
	s = s+"%"+t;
	t.clear();
	int n = (int)s.size();
	vector<int>pi(n, 0);
	for (int i = 1; i<n; i++){
		int j = pi[i-1];
		while (j && s[i] != s[j]) j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	for (int i = 0; i<n; i++){
		if (pi[i] == x){
			cout << i-2*x+1 << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve2();
	
	return 0;
}
