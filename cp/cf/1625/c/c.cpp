/*
	Author: sysia
	12.01.2022 17:46:31
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

const int MAX = 503;
const LL INF = 1e18;
LL dp[MAX][MAX];

void solve(){
	int n, l, k; cin >> n >> l >> k;
	vll a(n+1), d(n+1);
	rep(i, 1, n+1) cin >> d[i];
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 0, n+3){
		rep(j, 0, n+3){
			dp[i][j] = INF;
		}
	}
	dp[1][1] = 0;
	
	d.pb(l);
	n++;
	rep(i, 2, n+1){
		rep(j, 1, n+1){
			rep(u, 1, i){
				dp[i][j] = min(dp[i][j], dp[u][j-1]+(d[i]-d[u])*a[u]);
			}
		}
	}
	LL ans = INF;
	rep(i, 0, k+1){
		ans = min(ans, dp[n][n-i]);
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
