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

const int MAX = 2007;

int DP(string s, int n){
	int dp[n+1][n+1];
	memo(dp);
	
	rep(len, 1, n){
		int L = 0, R = len;
		while (R<n){
			dp[L][R] = (s[L] == s[R])?dp[L+1][R-1]:min(dp[L][R-1], dp[L+1][R])+1;
			L++;R++;
		}
	}
	int ans = INT_MAX;
	int L = 0, R = n/2-1;
	while (R<n){
		ans = min(ans, dp[L][R]);
		L++;R++;
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	s+=s;
	cout << DP(s, n+n) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
