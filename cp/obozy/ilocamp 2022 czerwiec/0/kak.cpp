//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, K = 30;

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, oo);
	}

	void clear(){
		tab.assign(tab.size(), oo);
	}

	void update(int x, int v){
		x += size;
		tab[x] = min(tab[x], v);
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

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	vector<int>scaler = a;
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	map<int, int>mapa;
	for (int i = 0; i<(int)scaler.size(); i++) mapa[scaler[i]] = i+1;
	for (auto &x: a) x = mapa[x];
	//debug(a);
	vector<int>dp(n, oo);
	segtree seg(n+1);
	seg.update(0, 0);
	for (int i = 0; i<n; i++){
		dp[i] = seg.query(0, a[i]-1)+i;
		seg.update(a[i], dp[i]-i-1);
	}
	//debug(dp);
	reverse(a.begin(), a.end());
	vector<int>dp2(n, oo);
	seg.clear();
	seg.update(0, 0);
	for (int i = 0; i<n; i++){
		dp2[i] = seg.query(0, a[i]-1)+i;
		seg.update(a[i], dp2[i]-i-1);
	}
	reverse(dp2.begin(), dp2.end());
	//debug(dp2);
	int ans = oo;
	for (int i = 0; i<n; i++){
		ans = min(ans, dp[i]+dp2[i]);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
