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

const LL MOD = 998244353;

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	
	LL dp[n+1][11];
	rep(i, 0, n+1){
		rep(j, 0, 10){
			dp[i][j] = 0LL;
		}
		
	}
	
	dp[0][a[0]] = 1;
	
	rep(i, 0, n){
		rep(digit, 0, 10){
			dp[i+1][(digit+a[i+1])%10] += dp[i][digit];
			if (dp[i+1][(digit+a[i+1])%10]>=MOD) dp[i+1][(digit+a[i+1])%10]%=MOD;
			dp[i+1][(digit*a[i+1])%10] += dp[i][digit];
			if (dp[i+1][(digit*a[i+1])%10] >= MOD) dp[i+1][(digit*a[i+1])%10]%=MOD;
		}
	}
	rep(i, 0, 10){
		if (i == 0) cout << dp[n-1][0] << "\n";
		else cout << dp[n][i] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
