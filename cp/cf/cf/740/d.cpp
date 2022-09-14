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
	int n;LL MOD; cin >> n >> MOD;
	vll dp(n+1, 0), pref(n+2, 0);
	dp[n] = 1;
	pref[n] = 1;
	pref[n+1] = 0;
	repd(i, n-1, 1){
		dp[i] = pref[i+1];
		if (dp[i]>=MOD) dp[i]%=MOD;
		int x = 2;
		while (x*i<=n){
			//debug(x);
			//dp[i]+=seg.suma(x*i, min(n, x*i+x-1));
			dp[i]+=pref[x*i];
			if (x*i+x-1<=n) dp[i]-=pref[x*i+x];
			while (dp[i]<0) dp[i]+=MOD;
			if (dp[i]>=MOD)dp[i]%=MOD;
			x++;
		}
		pref[i] = pref[i+1]+dp[i];
		if (pref[i]>=MOD) pref[i]%=MOD;
	}
	cout << dp[1] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
