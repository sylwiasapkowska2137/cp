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
		tab.assign(2*size, 0);
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = tab[2*x] + tab[2*x+1];
		}
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<int>p(n+1), mx(n+1, -oo), mn(n+2, oo), curr = {0};
	vector<int>ciekawy(n+1);
	for (int i = 1; i<=n; i++){
		cin >> p[i];
		mx[i] = max(mx[i-1], p[i]);
		if (mx[i] > mx[i-1]) ciekawy[i] = 1;
		if (mx[i] == i) curr.emplace_back(i);
	}
	for (int i = n; i>=1; i--){
		mn[i] = min(mn[i+1], p[i]);
		if (mn[i] < mn[i+1]) ciekawy[i] = 1;
	}
	debug(curr);
	vector<pair<int, int>>points(n+1);
	for (int i = 1; i<=n; i++) points[i] = {i+p[i], p[i]-i};
	Tree down(n+2), up(n+2), active(n+1);
	vector dp(n+1, vector<vector<int>>(2, vector<int>(2)));
	auto count = [&](int l, int r){
		vector<int>ord(r-l+1);
		iota(ord.begin(), ord.end(), l);
		sort(ord.begin(), ord.end(), 
			[&](auto x, auto y){ return points[x].first == points[y].first ? 
			points[x].second < points[y].second : points[x].first < points[y].first;
		});
		for (int rep = 0; rep < 2; rep++){
			debug(ord);
			for (auto v: ord){
				dp[v][0][rep] = up.query(v, n)+active.query(v, n);
				dp[v][1][rep] = down.query(1, v) + active.query(1, v);
				if (ciekawy[v]) active.update(v, 1);
				down.update(v, dp[v][0][rep]);
				up.update(v, dp[v][1][rep]);
			}
			// sort(ord.begin(), ord.end(), 
			// 	[&](auto x, auto y){ return points[x].first == points[y].first ? 
			// 	points[x].second < points[y].second : points[x].first < points[y].first;
			// });
			reverse(ord.begin(), ord.end());
			for (auto v: ord){
				up.update(v, 0);
				down.update(v, 0);
				active.update(v, 0);
			}
		}
	};
	for (int i = 1; i<(int)curr.size(); i++) count(curr[i-1]+1, curr[i]);
	for (int i = 1; i<=n; i++){
		int ans = 0;
		for (int a = 0; a < 2; a++){
			for (int b = 0; b < 2; b++){
				ans += dp[i][a][b];
			}
		}
		cout << ans << " ";
	}
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
