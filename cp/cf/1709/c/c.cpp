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

string first(string &s, int open){
	int n = (int)s.size();
	string ans;
	for (int i = 0; i<n; i++){
		if (s[i] == '?'){
			if (open) {
				ans += '(';
				open--;
			} else ans += ')';
		} else ans += s[i];
	}
	return ans;
}

void solve(){
	string s; cin >> s;
	int n = (int)s.size();
	int open = n/2;
	int closed = n/2;
	for (int i = 0; i<n; i++){
		if (s[i] == '(') open--;
		else if (s[i] == ')') closed--;
	}
	if (!open || !closed){
		cout << "YES\n";
		return;
	}
	string a = first(s, open);
	int k = 0;
	while (s[k] != '?' || a[k] != ')') k++;
	int j = n-1;
	while (s[j] != '?' || a[j] != '(') j--;
	swap(a[k], a[j]);
	open = 0, closed = 0;
	for (int i = 0; i<n; i++){
		if (a[i] == '(') open++;
		else closed++;
		if (closed > open){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}