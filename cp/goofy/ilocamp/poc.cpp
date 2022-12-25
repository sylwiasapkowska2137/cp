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

const int oo = 1e9+7;

void solve(){
	int n, k, q; cin >> n >> k >> q;
	vector<long long>a(n+1), pref(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
	}
	vector<int>nxt(n+1);
	int R = 1;
	long long sum = a[1];
	vector<int>dp(n+2), dp2(n+1);
	for (int L = 1; L<=n; L++){
		while (R+1<=n && sum + a[R+1] <= k){
			R++;
			sum += a[R];
		}
		nxt[L] = R;
		sum -= a[L];
	}
	for (int i = n; i>=1; i--) dp[i] = dp[nxt[i]+1] + 1;
	sum = oo;
	for (int i = 1; i<=n; i++){
		sum += a[i];
		if (sum > k){
			dp2[i] = dp2[i-1]+1;
			sum = a[i];
		} else dp2[i] = dp2[i-1];
	}
	// debug(dp);
	// debug(dp2);
	int idx = 1;
	set<int>S;
	while (idx <= n){
		S.insert(idx);
		idx = nxt[idx]+1;
	}
	// debug(S);
	cout << (int)S.size() << "\n";
	while (q--){
		int pos, val; cin >> pos >> val;
		auto it = S.lower_bound(pos);
		if (it == S.end() || *it > pos) it--;
		if (it != S.begin()) it--;
		int st = *it;
		int t = 0, ans = st;
		while (ans <= pos){
			int L = ans, R = n, curr = ans;
			while (R >= L){
				int mid = (L+R)/2;
				long long s = pref[mid]-pref[ans-1];
				if (pos <= mid){
					s -= a[pos];
					s += val;
				}
				if (s > k){
					R = mid-1;
				} else {
					curr = mid;
					L = mid+1;
				}
			}
			ans = curr+1;
			t++;
		}
		cout << dp2[st-1] + t + dp[ans] << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
