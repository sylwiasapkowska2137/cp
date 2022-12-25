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
	for (int i = 0; i<n; i++) cin >> a[i];
	vector<int>B = a;
	vector<int>used(n);
	vector<int>ans;
	int prev = 0;
	for (int rep = 0; rep < K; rep++){
		if (ans.size() == n) break;
		int mx = 0, idx = -1;
		for (int i = 0; i<n; i++){
			if (used[i]) continue;
			for (int b = 0; b<K; b++){
				if (prev&(1<<b)){
					if (B[i]&(1<<b)){
						B[i] -= (1<<b);
					}
				}
			}
			if (B[i] >= mx){
				mx = B[i];
				idx = i;
			}
			
		}
		// debug(rep, mx, idx);
		ans.emplace_back(a[idx]);
		used[idx] = 1;
		prev |= mx;
	}
	for (int i = 0; i<n; i++) if (!used[i]) ans.emplace_back(a[i]);
	for (auto x: ans) cout << x << " ";
	cout << "\n";
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