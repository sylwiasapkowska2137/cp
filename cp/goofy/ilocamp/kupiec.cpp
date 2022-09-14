#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
 
const int MAX = 1e6+7;
vpii graf[MAX];
LL dp[MAX][2];

void dfs(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x.st != pa){
			dfs(x.st, v);
			LL val = dp[x.st][0]+x.nd;
			if (val > dp[v][0]) {
				dp[v][1] = dp[v][0];
				dp[v][0] = val;
			} else if (val > dp[v][1]) dp[v][1] = val;
		}
	}
}

void solve(){
	int n; cin >> n;
	rep(i, 1, n){
		int a, b, c; 
		cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	dfs(1);
	LL ans = 0LL;
	rep(i, 1, n+1){
		ans = max(ans, dp[i][0]+dp[i][1]);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}


