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

const int MAX = 3e3+7, MOD = 998244353;
LL dp[MAX][MAX];

void solve(){
	int n; cin >> n;
	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	
	rep(i, a[0], b[0]+1) dp[0][i] = 1;
	rep(i, 1, n){
		LL suma = 0;
		rep(j, 0, b[i]+1){
			suma += dp[i-1][j];
			if (j >= a[i])dp[i][j] = suma;
			if (suma >= MOD) suma%=MOD;
		}
	}
	
	LL ans = 0LL;
	rep(i, 0, MAX) {
		ans += dp[n-1][i];
		if (ans >= MOD) ans%=MOD;
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
