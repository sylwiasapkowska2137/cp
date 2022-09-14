//Sylwia Sapkowska
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}
// wrrrrrr
void solve(){
	int n, m, d; cin >> n >> m >> d;
	vi cnt(n+1, 0);
	rep(i, 1, m+1){
		int x; cin >> x;
		cnt[x]++;
	}
	int dp[n+1][n+1];
	memo(dp, -1);
	dp[d][d-1] = cnt[d];
	int ans = 0; 
	rep(i, 1, n+1){
		rep(j, 0, n+1){
			if (dp[i][j] == -1) continue;
			rep(k, 0, 3){
				if (i+j+k <= n) dp[i+j+k][j+k-1] = max(dp[i+j+k][j+k-1], dp[i][j]+cnt[i+j+k]);
			}
			ans = max(ans, dp[i][j]);
		}
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
