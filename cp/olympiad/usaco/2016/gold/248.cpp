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

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int dp[n+1][n+1];
	int ans = a[0];
	memo(dp);
	rep(len, 1, n+1){
		rep(i, 0, n-len+1){
			int j = i+len-1;
			dp[i][j] = -1;
			if (len == 1) dp[i][j] = a[i];			
			rep(k, i, j){
				if (dp[i][k] == dp[k+1][j] && dp[i][k]>0){
					dp[i][j] = max(dp[i][j], dp[i][k]+1);
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
}

void setIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	setIO("248");
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
