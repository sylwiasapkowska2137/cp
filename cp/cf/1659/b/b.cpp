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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	if (!k){
		cout << s << "\n";
		for (int i = 0; i<n; i++) cout << "0 ";
		cout << "\n";
		return;
	}
	vector<int>curr(n);
	if (k%2){
		for (int i = 0;i<n; i++){
			if (s[i] == '1'){
				k--;
				curr[i] = 1;
				if (!k){
					for (int j = i+1; j<n; j++){
						if (s[j] == '0') s[j] = '1';
						else s[j] = '0';
					}
					break;
				}
			} else {
				s[i] = '1';
				curr[i] = 0;
			}
		}
	} else {
		for (int i = 0; i<n; i++){
			if (s[i] == '0'){
				s[i] = '1';
				k--;
				curr[i] = 1;
				if (!k) break;
			} else {
				curr[i] = 0;
			}
		}

	}
	// debug(k);
	if (k&1){
		s[n-1] = '0';
		if (curr.back() == 1){
			curr[n-1] = 0;
			k++;
		} else {
			curr[n-1] = 1;
			k--;
		}
	}
	curr[0] += k;
	cout << s << "\n";
	for (int i = 0; i<n; i++) cout << curr[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}