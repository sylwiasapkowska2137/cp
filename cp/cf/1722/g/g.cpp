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
	int n; cin >> n;
	int big = (1LL<<25);
	if (n%4 != 2){
		if (n%4 == 1) cout << "0 ";
		else if (n%4 == 3) cout << "2 1 3 ";
		n -= (n%4);
		for (int i = 1; i<=n; i++){
			if (i&1) cout << (i+7)/2 << " ";
			else cout << (i+7)/2+big << " ";
		}
		cout << "\n";
		return;
	}
	// debug(2137);
	int odd = 0, even = 0;
	for (int i = 1; i<n; i++){
		if (i%2 == 1) {
			cout << 2*(i/2)+2 << " ";
			odd ^= (2*(i/2)+2);
		} else {
			int curr = 2*i+1;
			if (i == n-2){
				curr += 2*big;
			}
			cout << curr << " ";
			even ^= curr;
		}
	}
	cout << (odd ^ even) << " ";
	cout << "\n";
	// debug(odd, even);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}