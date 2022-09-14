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

struct team{
	LL a, b, c;
};

const LL INF = -1e16;

void solve(){
	int n, d; cin >> n >> d;
	vector<team>a(n);
	rep(i, 0, n) cin >> a[i].a >> a[i].b >> a[i].c;
	LL dp[n+2][d+1];
	rep(i, 0, n+1) rep(j, 0, d+1) dp[i][j] = INF;
	
	dp[0][0] = 0;
	rep(i, 0, n){
		rep(j, 0, d){
			int x = (a[i].a+j)%d;
			dp[i+1][x] = max(dp[i][j]+a[i].a, dp[i+1][x]);
			x = (a[i].b+j)%d;
			dp[i+1][x] = max(dp[i][j]+a[i].b, dp[i+1][x]);
			x = (a[i].c+j)%d;
			dp[i+1][x] = max(dp[i][j]+a[i].c, dp[i+1][x]);
		}
	}
	
	int q; cin >> q;
	while(q--){
		int a, b; cin >> a >> b;
		LL ans = INF;
		rep(i, 0, d){
			if (dp[b][i] < 0 || dp[a-1][i] < 0) continue;
			ans = max(ans, dp[b][i]-dp[a-1][i]);
		}
		if (ans == INF) cout << "-1\n";
		else cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

