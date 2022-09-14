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

// #define int long long
const int oo = 1e9+7, K = 30;

struct node{
	int l, r, i;
	node(int _l = 0, int _r = 0, int _i = 0){
		l = _l, r = _r, i = _i;
	}
};

struct TreeMax{
	vector<int>tab;
	int size = 1;

	TreeMax(int n){
		while (size < n) size*=2;
		tab.assign(2*size, -oo);
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
		int ans = -oo;
		for (l += size-1, r+=size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
		}
		return ans;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	m = a.back();
	n = (int)a.size();
	vector<vector<int>>div(m+1);
	vector<vector<pair<int,int>>>dp(m+1);
	for (int i = 1; i<=m; i++){
		for (int j = i; j<=m; j+=i){
			div[j].emplace_back(i);
		}
		for (auto d: div[i]){
			if (i % d == 0){
				int L = 0, R = dp[i/d].size()-1, ans = oo;
				while (R >= L){
					int mid = (L+R)/2;
					if (dp[i/d][mid].first >= d){
						ans = mid;
						R = mid-1;
					} else L = mid+1;
				}
				if (ans != oo){
					dp[i].emplace_back(d, dp[i/d][ans].second);
				}
			}
		}
		div[i].clear();
		dp[i].emplace_back(i, i);
		// debug(i, dp[i]);
	} 
	vector<node>tab;
	for (int i = 0; i<n; i++){
		for (auto [a, b]:dp[a[i]]){
			tab.emplace_back(a, b, i);
		}
	}
	dp.clear();
	sort(tab.begin(), tab.end(), [](auto x, auto y){
		if (x.l == y.l) return x.r < y.r;
		return x.l < y.l;	
	});
	// for (auto [a, b, idx]:tab){
	// 	debug(a, b, idx);
	// }
	// cerr << "\n";

	vector<multiset<int>>mx(n+1);
	int cnt = n-1, R = 0, ans = oo;
	mx[tab[0].i].insert(tab[0].r);
	TreeMax t(n+1);
	t.update(tab[0].i, tab[0].r);
	for (int L = 0; L < (int)tab.size(); L++){
		while (R+1 < (int)tab.size() && cnt){
			R++;
			if (mx[tab[R].i].empty()) cnt--;
			mx[tab[R].i].insert(tab[R].r);
			t.update(tab[R].i, *mx[tab[R].i].begin());
		}
		if (!cnt) ans = min(ans, t.query(0, n)-tab[L].l);
		mx[tab[L].i].erase(mx[tab[L].i].find(tab[L].r));
		if (mx[tab[L].i].empty()){
			cnt++;
			t.update(tab[L].i, -oo);
		} else t.update(tab[L].i, *mx[tab[L].i].begin());
	}
	cout << ans << "\n";
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}