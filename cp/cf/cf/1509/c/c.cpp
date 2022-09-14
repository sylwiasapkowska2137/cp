/*
	Author: sysia
	29.12.2021 13:47:58
*/

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
#define memo(x) memset(x, -1, sizeof(x))
#define debug(x) cerr << x << " "

vi a;
const int MAX = 2007;
const LL INF = 1e18;
LL dp[MAX][MAX];

LL solve(int L, int R){
	if (L > R) return 0;
	if (dp[L][R] != -1) return dp[L][R];
	dp[L][R] = a[R]-a[L]+min(solve(L+1, R), solve(L, R-1));
	return dp[L][R];
}

void solve(){
	int n; cin >> n;
	a.resize(n);
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	memo(dp);
	cout << solve(0, n-1) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
