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
	int n; cin >> n;
	vector<int>a(n), w(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++) cin >> w[i];
	int ans = -oo;
	vector<int>curr;
	for (int mask = 1; mask<(1<<n); mask++){
		if (__builtin_popcountll(mask)&1) continue;
		curr.clear();
		int tmp = 0;
		for (int i = 0; i<n; i++){
			if (mask&(1<<i)){
				curr.emplace_back(a[i]);
				tmp += w[i];
			}
		}
		curr.emplace_back(curr[0]);
		curr.emplace_back(curr[1]);
		int s = (int)curr.size();
		vector<int>nw(s+1);
		bool ok = 1;
		for (int i = 1; i<s-1; i++){
			if (curr[i] > curr[i-1] && curr[i] > curr[i+1]){
				nw[i] = 1;
			} else if (curr[i] < curr[i-1] && curr[i] < curr[i+1]){
				nw[i] = -1;
			} else {
				ok = 0;
				break;
			}
		}
		if (!ok) continue;
		// debug(nw);
		for (int i = 2; i<s-1; i++){
			if (nw[i] == nw[i-1]){
				ok = 0;
				break;
			} 
		}
		if (ok) ans = max(ans, tmp);
	}
	if (ans == -oo) cout << "NO\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
