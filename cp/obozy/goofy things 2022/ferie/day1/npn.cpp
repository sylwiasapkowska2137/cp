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
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int MAX = 1e6+7;
int dp[4][MAX];

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
		--a[i];
	}
	if (!a[0]) dp[0][0] = 1;
	else dp[1][0] = 1;
	
	rep(i, 1, n) {
		if (a[i]) dp[0][i] = dp[0][i-1];
		else dp[0][i] = dp[0][i-1]+1;
	
		if (a[i]) dp[1][i] = max(dp[1][i-1], dp[0][i-1])+1;
		else dp[1][i] = dp[1][i-1];
	
		if (a[i]) dp[2][i] = dp[2][i-1];
		else dp[2][i] = max(dp[2][i-1], max(dp[1][i-1], dp[0][i-1])) + 1;
		
		if (a[i]) dp[3][i] = max(max(dp[3][i-1], dp[2][i-1]), max(dp[1][i-1], dp[0][i-1])) + 1;
		else dp[3][i] = dp[3][i-1];
	}
	int ans = 0;
	rep(i, 0, 4) ans = max(ans, dp[i][n-1]);
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
