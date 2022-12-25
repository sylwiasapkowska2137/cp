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

int ti(char c){
	return (int)(c-'a');
}

void solve(){
	int n; cin >> n;
	vector<int>A(K), B(K);
	A[0] = B[0] = 1;
	while (n--){
		int t; cin >> t;
		int x; string s; cin >> x >> s;
		if (t == 1){
			for (auto c: s){
				A[ti(c)]+=x;
			}
		} else {
			for (auto c: s){
				B[ti(c)]+=x;
			}
		}
		int ans = 0;
		for (int i = 1; i<K; i++){
			if (B[i]){
				ans = 1;
				break;
			}
		}
		if (ans) cout << "YES\n";
		else if (A[0] > B[0]) {
			cout << "NO\n";
		} else {
			if (A[0] == B[0]) {
				cout << "NO\n";
				continue;
			}
			//a[0] < b[0];
			ans = 0;
			for (int i = 1; i<K; i++){
				if (A[i]){
					ans = 1;
					break;
				}
			}
			if (ans) cout << "NO\n";
			else cout << "YES\n";
		}
		
	}
	// exit(0);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}