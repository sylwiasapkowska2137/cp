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
	vector<int>a(n+1), b(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++) cin >> b[i];
	int mask = 0;
	for (int bit = K-1; bit>=0; bit--){
		mask += (1LL<<bit);
		map<int, int>A, B;
		for (int i = 1; i<=n; i++){
			int x = 0;
			for (int j = K-1; j >= bit; j--){
				if (a[i]&(1LL<<j)){
					x += (1LL<<j);
				}
			}
			A[x&mask]++;
		}
		for (int i = 1; i<=n; i++){
			int x = 0;
			for (int j = K-1; j >= bit; j--){
				if (!(b[i]&(1LL<<j))){
					x += (1LL<<j);
				}
			}
			B[x&mask]++;
		}
		// debug(bit, mask, A, B);
		bool ok = 1;
		for (auto x: A){
			if (B[x.first] != x.second){
				ok = 0;
				break;
		}
			}
		if (!ok) mask -= (1LL<<bit);
	}
	cout << mask << "\n";
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