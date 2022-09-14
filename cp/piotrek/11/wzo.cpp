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

// #define int long long
// const int oo = 1e18, K = 30;

bool check(long long mid, vector<long long>&A, int &a, int &b, int &n, vector<vector<int>>&dp){
	// debug(mid);
	for (int i = 0; i<=a; i++){
		for (int j = 0; j<=b; j++){
			dp[i][j] = 0;
		}
	}
	for (int aa = 0; aa <= a; aa++){
		int ptr = 0, ptr2 = 0;
		for (int bb = 0; bb <= b; bb++){
			if (aa){
				ptr2 = max(ptr2, dp[aa-1][bb]);
				while (ptr2 < n && A[ptr2+1]-A[dp[aa-1][bb]+1] + 1 <= mid) ptr2++;
				dp[aa][bb] = max(dp[aa][bb], ptr2);
			}
			if (bb){
				ptr = max(ptr, dp[aa][bb-1]);
				while (ptr < n && A[ptr+1]-A[dp[aa][bb-1]+1] + 1 <= 2*mid) ptr++;
				dp[aa][bb] = max(dp[aa][bb], ptr);
			}
			// debug(aa, bb, dp[aa][bb]);
			if (dp[aa][bb] == n) return 1;
		}
	}
	return 0;
}

void solve(){
	int n, a, b; cin >> n >> a >> b;
	vector<long long>A(n+1);
	for (int i = 1; i<=n; i++) cin >> A[i];
	sort(A.begin()+1, A.end());
	if (a + b >= n){
		cout << "1\n";
		return;
	}
	vector<vector<int>>dp(a+1, vector<int>(b+1));
	long long l = 1, r = 1e9+1;
	long long ans = r;
	while (r>=l){
		long long mid = (l+r)/2;
		if (check(mid, A, a, b, n, dp)){
			ans = mid;
			r = mid-1;
		} else l = mid+1;
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
