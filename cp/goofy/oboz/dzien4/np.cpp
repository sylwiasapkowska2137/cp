#include <bits/stdc++.h>
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
#define memo(x, val) memset(x, val, sizeof(x))
#define debug(x) cerr << x << " "

const int MAX = 1e4+3;
vpii graf[MAX];
struct e{int a, b, c;};

void solve(){
	int n, m, k; cin >> n >> m >> k;
	
	vector<e>edges;
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		a--;b--;
		edges.pb({a, b, c});
	}
	vi a, pos(n);
	int dp[k+1][n];
	rep(i, 0, n) a.pb(i);
	int ans = -1;
	
	rep(i, 0, 5500){
		random_shuffle(all(a));
		rep(i, 0, sz(a)) pos[a[i]] = i;
		rep(i, 0, n) graf[i].clear();
		for (auto x: edges){
			if (pos[x.a]<pos[x.b]) graf[x.a].pb({x.b, x.c});
			else graf[x.b].pb({x.a, x.c});
		}
		memo(dp, -1);
		rep(i, 0, n) dp[1][i] = 0;
		
		rep(K, 2, k+1){
			repd(i, n-1, 0){
				for (auto x: graf[a[i]]) if (dp[K-1][x.st]!=-1) dp[K][a[i]] = max(dp[K][a[i]], dp[K-1][x.st]+x.nd);
			}
		}
		rep(i, 0, n) ans = max(ans, dp[k][i]);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
/*
3 3 3 
1 2 3
2 3 5
1 3 4
*/
