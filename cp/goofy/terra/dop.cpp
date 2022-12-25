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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int n, m, k; cin >> n >> m >> k;
	string s, t; cin >> s >> t;
	if (n > m){
		swap(n, m);
		swap(s, t);
	}
	
	
	auto work = [&](string s, string t){
		int n = (int)s.size();
		int m = (int)t.size();
		int u = min(n, m);
		while (s.size() < t.size()) s+='$';
		n = (int)s.size();
	
		int ans = 0;
		for (int rep = 0; rep<m; rep++){
			n = (int)t.size();
			vector<int>curr(n);
			for (int i = 0; i<n; i++){
				if (s[i] == t[i]) curr[i] = 0;
				else curr[i] = -1;
			}
			// debug(s, t, curr);
			int R = 0;
			int sum = curr[0];
			for (int L = 0; L < n; L++){
				if (s[R+1] == '$'){
					if (sum >= -k){
						ans = max(ans, R-L+1);
					}
					break;
				}
				while (R + 1 < n && sum + curr[R+1] >= -k){
					R++;
					sum += curr[R];
				}
				if (sum >= -k){
					ans = max(ans, R-L+1);
				}
				sum -= curr[L];
			}
			reverse(t.begin(), t.end());
			t.pop_back();
			reverse(t.begin(), t.end());
			s.pop_back();
		}
		return min(u, ans);
	};
	int A = work(s, t);
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int B = work(s, t);
	cout << max(A, B) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
