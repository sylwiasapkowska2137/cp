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

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, -oo);
	}

	int query(int l, int r){
		int ans = -oo;
		l = l+size-1;
		r = r+size+1;
		while(r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}

	void update(int x, int v){
		x += size;
		tab[x] = max(tab[x], v);
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector<int>dp(n+1);
	vector<int>pref(n+1);
	for (int i = 1; i<=n; i++) pref[i] = pref[i-1] + a[i];
	segtree seg(n+1, pref);
	vector<int>s = pref;
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	auto get = [&](int v) {return (int)(lower_bound(s.begin(), s.end(), v)-s.begin());};
	seg.update(get(0), 0);
	for (int i = 1; i<=n; i++){
		dp[i] = max(dp[i-1] + (a[i] >= 0 ? (a[i] > 0 ? 1 : 0) : -1), seg.query(0, get(pref[i])-1) + i);
		seg.update(get(pref[i]), dp[i]-i);	
	}
	cout << dp[n] << "\n";
}
	

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}