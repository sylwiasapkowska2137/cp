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
	vector<int>a(n);
	for (int i =  0; i<n; i++) cin >> a[i];
	int len = 2, ans = 0;
	while (len <= n){
		int i;
		for (i = 0; i<n; ){
			int mn = oo, mx = -oo;
			// debug(i);
			for (int j = 0; j<len; j++){
				mn = min(mn, a[i]);
				mx = max(mx, a[i]);
				i++;
			}
			i--;
			// debug(mn, mx);
			if (mx%len == 0 && mx-mn+1 == len){
				if (a[i+1-len] != mn){
					ans++;
					int start = i+1-len;
					for (int j = start; j+(len/2)<=i; j++){
						swap(a[j], a[j+len/2]);
					}
				}
			} else {
				cout << "-1\n";
				return;
			}
			i++;
		}
		len*=2;
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}