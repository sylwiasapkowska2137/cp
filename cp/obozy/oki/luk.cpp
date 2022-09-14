//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

const int MAX = 3e5+7;
vector<int>graf[MAX], dp;

void dfs(int v, int mid, int pa = -1){
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, mid, v);
			dp[v] += dp[x]+1;
		}
	}
	dp[v] = max(0, dp[v]-mid);
}

bool check(int mid, int n){
	dp.assign(n+1, 0);
	dfs(1, mid);
	return (dp[1] == 0);
}

void solve(){
	int n; cin >> n;
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int L = 0, R = n;
	int ans = n;
	while (R>=L){
		int m = (L+R)/2;
		if (check(m, n)){
			ans = m;
			R = m-1;
		} else L = m+1;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
