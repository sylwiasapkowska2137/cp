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
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "

const int MAX = 1007, INF = 1e9+7;

int dp[MAX][MAX][2];

void solve(){
	int n, m; cin >> n >> m;
	bool ok = 0;
	rep(i, 2, n+1) dp[i][0][0] = dp[i][0][1] = INF;
	rep(i, 2, m+1) dp[0][i][0] = dp[0][i][1] = INF;
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			int x; cin >> x;
			x = abs(x);
			if (!x)	{
				ok = 1;
				x = 10;
			} 
				while (x%2 == 0){
					x/=2;
					dp[i][j][0]++;
				}
				while (x%5 == 0){
					x/=5;
					dp[i][j][1]++;
				}
			rep(k, 0, 2){
				dp[i][j][k] += min(dp[i-1][j][k], dp[i][j-1][k]);
			}
		}
	}
	int ans = min(dp[n][m][0], dp[n][m][1]);
	if (ok) cout << min(1, ans); 
	else cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
