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
const int oo = 1e18, K = 30;

void solve(){
	int n, c; cin >> n >> c;
	vector<int>t(n+1), a(n+1);
	for (int i = 1; i<=n; i++){
		cin >> t[i] >> a[i];
	}
	// debug(a);
	int x = 0;
	vector<int>X, Y;
	for (int i = 1; i<=n; i++){
		if (t[i] == 3){
			x ^= a[i];
		} 
		if (t[i] == 2){
			x |= a[i];
		}
		if (t[i] == 1){
			x &= a[i];
		}
		X.emplace_back(x);
	}
	int y = 0;
	for (int i = 0; i<K; i++) y += (1LL<<i);
	for (int i = 1; i<=n; i++){
		if (t[i] == 3){
			y ^= a[i];
		} 
		if (t[i] == 2){
			y |= a[i];
		}
		if (t[i] == 1){
			y &= a[i];
		}
		Y.emplace_back(y);
	}
	// debug(X, Y);
	for (int i = 1; i<=n; i++){
		for (int j = 0; j<K; j++){
			if (c&(1LL<<j)){
				if (Y[i-1]&(1LL<<j)){
					;
				} else {
					c -= (1LL<<j);
				}
			} else {
				if (X[i-1]&(1LL<<j)){
					c += (1LL<<j);
				}
			}
		}
		cout << c << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
