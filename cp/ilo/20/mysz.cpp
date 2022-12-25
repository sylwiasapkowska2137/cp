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

void solve(){
	int n, m; cin >> n >> m;
	vector<int>b(2*n+1);
	for (int i = 1; i<=n+n-1; i++) cin >> b[i];
	vector<vector<int>>curr(n+1);
	vector<int>a;
	int sum = 0, sum2 = 0;
	auto pre = [&](int x){
		curr[x].clear();
		curr[x] = {a[x]};
		if (x == n) {
			sum += curr[x][0];
			return; 
		}
		curr[x].emplace_back(a[x+n]);
		int ilo = a[x] * a[x+n];
		if (ilo >= 0){
			curr[x][0] = abs(curr[x][0]);
			curr[x][1] = abs(curr[x][1]);
		} else {
			if (curr[x][0] > 0) {
				curr[x][1] = -curr[x][1];
				curr[x][0] = -curr[x][0];
			}
		}	
		sum += curr[x][0];
		sum2 += curr[x][1];
	};
	vector<pair<int, int>>que(m+1);
	for (int i = 1; i<=m; i++) cin >> que[i].first >> que[i].second;
	vector<int>ans(m+1, -oo);
	for (int rep = 0; rep < 2; rep++){
		sum = 0, sum2 = 0;
		a = b;
		for (int i = 1; i<=n; i++){
			curr[i].clear();
			pre(i);
		}		
		ans[0] = max({ans[0], abs(sum) + sum2, sum - curr[n][0] + abs(sum2 + curr[n][0])});
		for (int k = 1; k<=m; k++){
			int pos = que[k].first;
			int val = que[k].second;
			a[pos] = val;
			if (pos > n) pos-=n;
			sum -= curr[pos][0];
			sum2 -= curr[pos][1];
			// debug(curr[pos]);
			pre(pos);
			// debug(curr[pos]);
			// debug(sum, sum2);
			ans[k] = max({ans[k], abs(sum) + sum2, sum - curr[n][0] + abs(sum2 + curr[n][0])});
			que[k].first = 2*n - que[k].first;
		}
		reverse(b.begin(), b.end());
	}
	for (int i = 0; i<=m; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
