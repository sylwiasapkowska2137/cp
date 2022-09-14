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
	int x, p; cin >> x >> p;
	int y, r; cin >> y >> r;
	while (x && x%10 == 0){
		x/=10;
		p++;
	}
	while (y && y%10 == 0){
		y/=10;
		r++;
	}
	int X = x, Y = y;
	int len1 = 0;
	while (x){
		x/=10;
		len1++;
	}
	int len2 = 0;
	while (y){
		y/=10;
		len2++;
	}
	if (len1 + p != len2 + r){
		if (len1 + p > len2 + r){
			cout << ">\n";
		} else {
			cout << "<\n";
		}
	} else {
		while (len1 < len2) {
			X *= 10;
			len1++;
		}
		while (len1 > len2) {
			Y *= 10;
			len2++;
		}
		if (X > Y){
			cout << ">\n";
		} 
		if (X < Y){
			cout << "<\n";
		}
		if (X == Y){
			cout << "=\n";
		}
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