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
int dp[2][MAX][MAX];
int tab[MAX][MAX];

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 0, max(n, m)+1) {
		dp[0][i][0] = dp[0][0][i] = INF;
		dp[1][i][0] = dp[1][0][i] = INF;
	}
	dp[0][1][0] = 0; 
	dp[1][1][0] = 0; 
	//cerr << "\n";
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			cin >> tab[i][j];
			dp[0][i][j] = min(dp[0][i-1][j], dp[0][i][j-1])+tab[i][j];
			dp[1][i][j] = INF;
			//debug(dp[0][i][j]);
		}
		//cerr << "\n";
	}
	//cerr << "\n";
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			rep(k, 0, 6){
				int l = 5-k;
				int x = i-k, y = j-l;
				if (x >= 1 && y >= 1) dp[1][i][j] = min(dp[1][i][j], dp[0][x][y]+tab[i][j]);
			}
			if (dp[1][i][j] != INF)dp[1][i][j] = min(dp[1][i][j], min(dp[1][i-1][j], dp[1][i][j-1])+tab[i][j]);
			//debug(dp[1][i][j]);
		}
		//cerr << "\n";
	}
	//debug(dp[0][n][m]);
	cout << min(dp[0][n][m], dp[1][n][m]) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
