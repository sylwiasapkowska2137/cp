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
	vector<int>a(m+1);
	for (int i = 1; i<=m; i++) cin >> a[i];
	vector<int>p(n+1);
	iota(p.begin(), p.end(), 0);
	vector<int>back(n+1);
	iota(back.begin(), back.end(), 0);
	for (int i = 1; i<=m; i++){
		swap(p[a[i]], p[a[i]+1]);
	}
	vector<int>ans(m+1);
	int pos = 1;
	for (int i = 1; i<=n; i++) if (p[i] == 1) pos = i;
	for (int i = m; i>=1; i--){
		//cofnij ruch p
		swap(p[a[i]], p[a[i]+1]);
		if (p[a[i]] == 1) pos = a[i];
		else if (p[a[i]+1] == 1) pos = a[i]+1;
		ans[i] = back[pos];
		swap(back[a[i]], back[a[i]+1]);
	}
	// debug(p);
	for (int i = 1; i<=m; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
