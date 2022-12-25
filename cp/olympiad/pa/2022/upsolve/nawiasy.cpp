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
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

struct TreeMin{
	vector<int>tab;
	int size = 1;

	TreeMin(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	int query(int l, int r){
		int ans = oo;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
		}
		return ans;
	}
};

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	s = '$'+s;
	vector<int>B(n+1), prev(2*n+2, -1), which(n+1);
	int rep = 1;
	for (int i = 1; i<=n; i++) B[i] = B[i-1] + (s[i] == '(' ? 1 : -1);
	// debug(B);
	TreeMin t(n+2, B);
	int offset = n;
	for (int i = 0; i<=n; i++){
		if (prev[B[i]+offset] == -1){
			which[i] = rep++;
		} else {
			if (t.query(prev[B[i]+offset], i) >= B[i]){
				which[i] = which[prev[B[i]+offset]];
			} else {
				which[i] = rep++;
			}
		}
		prev[B[i]+offset] = i;
	}
	// debug(which);
	auto C2 = [&](int x){return x*(x-1)/2;};
	auto count = [&](int lambda){
		int ans = 0;
		vector<int>cnt(n+1);
		vector<T>dp(n+1, {oo, oo});
		dp[0] = {0, 0};
		int L = 0, R = 0;
		cnt[which[0]]++;
		auto add = [&](int idx){
			ans -= C2(cnt[which[idx]]);
			cnt[which[idx]]++;
			ans += C2(cnt[which[idx]]);
		};
		auto remove = [&](int idx){
			ans -= C2(cnt[which[idx]]);
			cnt[which[idx]]--;
			ans += C2(cnt[which[idx]]);
		};
		auto fit = [&](int l, int r){
			l--;
			// debug(ans);
			while (R < r) add(++R);
			while (L > l) add(--L);
			while (L < l) remove(L++);
			while (R > r) remove(R--);
			// debug(ans);
		};
		function<void(int, int, int, int)>rec2 = [&](int a, int b, int c, int d){
			if (a > b) return;
			T mn = {oo, oo};
			int opt = oo;
			int mid = (a+b)/2;
			for (int i = c; i <= min(mid-1, d); i++){
				// debug(L, R);
				fit(i+1, mid); //i
				// debug(L, R);
				// exit(0);
				int curr = dp[i].first + ans + lambda;
				if (curr < mn.first){
					opt = i;
					mn = min(mn, {curr, dp[i].second+1});
				}
			}
			// debug(mid, mn);
			dp[mid] = min(dp[mid], mn);
			rec2(a, mid-1, c, opt);
			rec2(mid+1, b, opt, d);
		};
		//dp[i] = {min wynik, min k}
		function<void(int, int)> rec = [&](int a, int b){
			if (a >= b) return;
			int mid = (a+b)/2;
			rec(a, mid);
			rec2(mid+1, b, a, mid);
			rec(mid+1, b);
		};
		rec(0, n);
		return dp[n];
	};
	int l = 0, r = oo2, ans = oo2;
	// count(1);
	// exit(0);
	while (r >= l){
		int mid = (l+r)/2;
		T curr = count(mid);
		// debug(mid, curr);
		if (curr.second <= k){
			ans = mid;
			r = mid-1;
		} else l = mid+1;
	}
	// debug(ans);
	T ret = count(ans);
	cout << ret.first - ret.second * ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
