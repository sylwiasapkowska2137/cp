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
const int mod = 998244353;

void solve(){
	string a, b; cin >> a >> b;
	if (a.size() < b.size()) swap(a, b);
	reverse(b.begin(), b.end());
	while (b.size() < a.size()) b += "0";
	reverse(b.begin(), b.end());
	// debug(a, b);
	string c;
	int carry = 0;
	for (int i = (int)a.size()-1; i>=0; i--){
		int curr = a[i] + b[i] - 2*'0' + carry;
		if (curr >= 10){
			carry = 1;
			curr-=10;
		} else carry = 0;
		c += (char)(curr+'0');
	}
	if (carry) c+=(char)(carry+'0');
	reverse(c.begin(), c.end());
	cout << c << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
