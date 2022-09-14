//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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

LL ans;

void backtrack(int n, vector<int>&a, int idx, int k, vector<int>curr){
	if ((int)curr.size() == k){
		//do sth
		LL tmp = 0;
		int prev = 0;
		for (int i = 0; i<(int)curr.size(); i++){
			LL x1 = 0, x2 = 0;
			for (int j = prev+1; j<=curr[i]; j++){
				x1 += a[j];
			}
			for (int j = curr[i]+1; j<=n; j++){
				x2 += a[j];
			}
			tmp += x1*x2;
			prev = curr[i];
		}
		ans = max(ans, tmp);
		return;
	}
	if (idx >= n) return;
	curr.push_back(idx);
	backtrack(n, a, idx+1, k, curr);
	curr.pop_back();
	backtrack(n, a, idx+1, k, curr);
}

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	backtrack(n, a, 1, k, {});
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
