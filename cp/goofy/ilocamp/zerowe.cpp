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

const int MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vi tab(n+1);
	rep(i, 1, n+1) cin >> tab[i];
	
	const int MAX = 1e4+1;
	
	LL dp[2][2*MAX+1];
	memo(dp, 0);
	LL ans = 0LL;
	rep(i, 1, n+1){
		bool a = i&1;
		bool b = a^1;
		dp[a][MAX+tab[i]] = dp[a][MAX-tab[i]] = 1;
		rep(j, 0, 2*MAX){
			if (j>=tab[i] && j+tab[i]<2*MAX) {
				dp[a][j] += dp[b][j-tab[i]] + dp[b][j+tab[i]];
				if (dp[a][j]>=MOD) dp[a][j]%=MOD;
			}
			//debug(dp[a][j]);
		}
		//cerr << "\n";
		ans += dp[a][MAX];
		if (ans >= MOD) ans%=MOD;
		memo(dp[b], 0);
	}
	cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

