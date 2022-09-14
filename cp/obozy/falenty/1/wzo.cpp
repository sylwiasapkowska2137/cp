//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct TreeSum{
	vector<int>tab;
	int size = 1;

	TreeSum(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
		}
		return ans;
	}

	void update(int x, int v){
		x += size;
		tab[x] += v;
		while (x){
			x/=2;
			tab[x] = tab[2*x] + tab[2*x+1];
		}
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];

	vector<vector<int>>tab(n+1);
	for (int i = 2; i<=n; i++){
		tab[min(i-1, a[i])].emplace_back(i);
	}	
	// ordered_set s;
	const int mx = 1e6+1;
	TreeSum t(mx);
	int ans = 0;
	for (int i = 1; i<=n; i++){
		t.update(a[i], 1);
		for (auto x: tab[i]){
			ans += t.query(x, mx-1);
			// debug(x, t.query(x, mx-1));
		}
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
