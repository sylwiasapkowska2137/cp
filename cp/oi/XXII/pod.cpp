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
const int oo = 1e9+7, K = 30;

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		for (int i = 1; i<(int)a.size(); i++)tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = -oo;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

struct segmin{
	vector<int>tab;
	int size = 1;

	segmin(int n){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
	}

	segmin(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
		for (int i = 1;i<(int)a.size();i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--)	tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = min(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = oo;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

vector<int>solve(vector<int>a, int n, int k){
	vector<int>last(k+1, -1), dp(n+1);
	segtree seg(n+1);
	for (int i = n; i>=1; i--){
		if (last[a[i]] == -1) last[a[i]] = i;
		int r = last[a[i]];
		dp[i] = i;
		if (i != r) dp[i] = max(dp[i], seg.query(i+1, r));
		seg.update(i, dp[i]);
	}
	return dp;
}

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector<int>dp = solve(a, n, k);
	vector<int>first(k+1, -1), b(n+1);
	segmin seg(n+1);
	for (int i = 1; i<=n; i++){
		if (first[a[i]] == -1) first[a[i]] = i;
		b[i] = first[a[i]];
	}
	vector<int>dp2(n+1);
	segmin seg2(n+1, b);
	for (int i = 1; i<=n; i++){
		int m = seg2.query(i, dp[i]);
		dp2[i] = seg.query(m, i);
		if (dp2[i] == oo) dp2[i] = i;
		seg.update(i, dp2[i]);
	}
	vector<int>last(k+1, -1);
	for (int i = n; i>=1; i--){
		if (last[a[i]] == -1) last[a[i]] = i;
	}
	for (int i = 1; i<=n; i++) b[i] = last[a[i]];
	segtree seg3(n+1, b);
	for (int i = 1; i<=n; i++) dp[i] = max(dp[i], seg3.query(dp2[i], dp[i]));
	// debug(dp2);
	// debug(dp);
	vector<pair<int, int>>curr;
	vector<int>kon(n+1, -1);
	for (int i = 1; i<=n; i++) kon[dp2[i]] = max(kon[dp2[i]], dp[i]);
	for (int i = 1; i<=n; i++){
		if (i == 1 && kon[i] == n) continue;
		if (kon[i] != -1) curr.emplace_back(i, kon[i]);
	}
	// debug(curr);
	int cnt = 0;
	vector<int>vis(n+1);
	vector<vector<pair<int, int>>>segments(n+1);
	for (int i = 1; i<=n; i++){
		if (vis[i] || kon[i] == -1) continue;
		int s = i;
		int e = kon[s];
		segments[cnt].emplace_back(s, e);
		if (s == 1 && e == n) continue;
		while (e+1 <= n && kon[e+1] != -1){
			s = e+1;
			e = kon[s];
			vis[s] = 1;
			segments[cnt].emplace_back(s, e);
		}
		cnt++;
	}
	int mn = oo;
	auto f = [&](vector<pair<int, int>>tab){
		// debug(tab);
		int R = 0, len = tab[0].second-tab[0].first+1;
		for (int L = 0; L<(int)tab.size(); L++){
			while (R+1 < (int)tab.size()){
				int nlen = len+tab[R+1].second-tab[R+1].first+1;
				int d = abs(len-(n-len));
				int d2 = abs(nlen-(n-nlen));
				if (d2 <= d){
					R++;
					len = nlen;
					// debug(L, R);
					mn = min(mn, d2);
				} else break;
			}
			mn = min(mn, abs(len-(n-len)));
			len -= (tab[L].second-tab[L].first+1);
		}
	};

	
	for (int i = 0; i<=n; i++){
		if (segments[i].empty()) break;
		f(segments[i]);
	}
	// return;
	sort(curr.begin(), curr.end(), [](auto x, auto y){return x.second > y.second;});
	vector<long long>DP(n+2);
	vector<int> pref(n+2);
	for (auto [l, r]:curr){
		DP[l] += DP[r+1]+1;
		pref[l]++;pref[r+1]--;
	}
	bool ok = 0;
	for (int i = 1; i<=n+1; i++){
		pref[i] += pref[i-1];
		if (i<=n && !pref[i]){
			ok = 1;
		}
	}
	// debug(DP);
	long long s = accumulate(DP.begin(), DP.end(), 0LL);
	if (!ok) s--;
	cout << s << " " << mn << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}