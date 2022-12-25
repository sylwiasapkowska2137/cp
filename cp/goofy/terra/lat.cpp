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

struct Tree{
	vector<int>tab;
	int size = 1;

	Tree(int n){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
	}

	void update(int l, int r, int v){
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) tab[l+1] = min(tab[l+1], v);
			if (r&1) tab[r-1] = min(tab[r-1], v);
		}
	}

	int query(int x){
		x += size;
		int ans = tab[x];
		while (x){
			x/=2;
			ans = min(ans, tab[x]);
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<int>s(n+1), r(n+1), scaler;
	for (int i = 1; i<=n; i++){
		cin >> s[i] >> r[i];
		scaler.emplace_back(s[i]-r[i]);
		scaler.emplace_back(s[i]+r[i]);
		scaler.emplace_back(s[i]);
	}
	scaler.emplace_back(-oo);
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	Tree t((int)scaler.size()+3);
	vector<int>dp(n+1, oo);
	dp[1] = 0;
	auto get = [&](int x){return (int)(lower_bound(scaler.begin(), scaler.end(), x)-scaler.begin());};
	for (int i = 1; i<=n; i++){
		dp[i] = min(dp[i], t.query(get(s[i])) + s[i]);
		t.update(get(s[i]-r[i]), get(s[i]+r[i]), dp[i] - s[i]);
	}
	// debug(dp);
	if (dp[n] == oo) cout << "-1\n";
	else cout << 2*dp[n] + s[n]-s[1] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
