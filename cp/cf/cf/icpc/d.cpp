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
#define memo(x, y) memset(x, y, sizeof(x))
#define debug(x) cerr << x << " "



void solve(){
	int n, d; cin >> n >> d;
	vi a(n), ans;
	vb del(n, 0);
	rep(i, 0, n) cin >> a[i];

	if (d&1){
		rep(i, 0, n) if ((a[i]+1)&1) del[i] = 1;
	}
	if (d%5 != 0){
		rep(i, 0, n) if (a[i]%5 == 0) del[i] = 1;
	}
	rep(i, 0, n){
		if (!del[i]) ans.pb(a[i]);
	}
	if (!sz(ans)){
		cout << "-1\n";
		return;
	}
	int x = 1;
	for (auto e: ans) x=(x*e)%10;
	if (x%10 == d){
		cout << sz(ans) << "\n";
		for (auto x: ans) cout << x << " ";
		cout << "\n";
		return;
	} 
	LL dp[n+1][10];
	rep(i, 0, n+1){
		rep(j, 0, 10) dp[i][j] = INT_MAX;
	}
	dp[0][1] = 1;
	rep(i, 0, n){
		rep(j, 0, 10) dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
		
		rep(j, 0, 10) dp[i+1][(j*a[i])%10] = min(dp[i+1][(j*a[i])%10], dp[i][j]*a[i]);
	}
	
	rep(i, 0, n+1){
		rep(j, 0, 10){
			debug(dp[i][j]);
		}
		cerr << "\n";
	}
	int x = INT_MAX;
	rep(i, 0, 10){
		if ((dp[n][i]*i))
	}
	
	repd(i, sz(ans)-1, 0){
		
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


