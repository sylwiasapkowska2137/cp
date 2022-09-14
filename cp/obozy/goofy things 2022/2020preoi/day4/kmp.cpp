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

vector<int>kmp(string &s){
	int n = (int)s.size();
	vector<int>pi(n);
	for (int i = 1; i<n; i++){
		int j = pi[i-1];
		while (j && s[i]!=s[j]) j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	string s = "a";
	if (a[0] != 0){
		cout << "NIE\n";
		return;
	}
	for (int i = 1; i<n; i++){
		if (a[i]-a[i-1] > 1){
			cout << "NIE\n";
			return;
		}
	}
	for (int i = 1; i<n; i++){
		if (a[i] == 0){
			s += ((s[0] == 'a')?'b':'a');
			continue;
		}
		if (a[i]>a[a[i]-1])	s += s[a[i]-1];
		else s += ((s[a[i]-1] == 'a')?'b':'a');
	}
	vector<int>pi = kmp(s);
	bool ok = 1;
	for (int i = 0; i<n; i++){
		ok &= (pi[i] == a[i]);
	}
	if (ok) cout << "TAK\n" << s << "\n";
	else cout << "NIE\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
