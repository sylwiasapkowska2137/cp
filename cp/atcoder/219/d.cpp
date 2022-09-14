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

const int MAX = 607, INF = 1e9+7;
int dp[MAX][MAX];

void solve(){
	int n; cin >> n;
	rep(i, 0, MAX) rep(j, 0, MAX) dp[i][j] = INF;
	int x, y; cin >> x >> y;
	dp[0][0] = 0;
	rep(i, 0, n){
		int a, b; cin >> a >> b;
		repd(i, MAX-a-1, 0){
			repd(j, MAX-b-1, 0){
				dp[i+a][j+b] = min(dp[i+a][j+b], dp[i][j]+1);
			}
		}
	}
	
	int ans = INF;
	rep(i, x, MAX){
		rep(j, y, MAX){
			ans = min(ans, dp[i][j]);
		}
	}
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
