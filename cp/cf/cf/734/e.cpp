#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
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

void solve(){
	int n, k;cin >> n >> k;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int dp[n+1][n+1];
	memo(dp);
	rep(i, 0, n){
		rep(j, 0, i+1){
			dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(a[i]==j+1));
		}
	}
	/*rep(i, 1, n+1){
		rep(j, 0, n+1){
			debug(dp[i][j]);
		}
		cerr << "\n";
	}*/
	repd(i, n, 0){
		//debug(dp[n][i]);
		if (dp[n][i]>=k){
			cout << n-i << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
