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
	int n = 8;
	string s; getline(cin, s);
	vector<vector<char>>a(n+1, vector<char>(n+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 1; i<=n; i++){
		bool ok = 1;
		if (a[i][1] == '.') continue;
		for (int j = 2; j<=n; j++){
			if (a[i][1] != a[i][j]){
				ok = 0;
				break;
			}
		}
		if (ok){
			cout << a[i][1] << "\n";
			return;
		}
	}
	for (int i = 1; i<=n; i++){
		bool ok = 1;
		if (a[1][i] == '.') continue;
		for (int j = 2; j<=n; j++){
			if (a[1][i] != a[j][i]){
				ok = 0;
				break;
			}
		}
		if (ok){
			cout << a[1][i] << "\n";
			return;
		}
		// cerr << "\n";
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