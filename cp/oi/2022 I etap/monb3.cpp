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

const int INF = 1e9+7, MAX = 1e5+7;

bool cmp(pii a, pii b){
	if (a.nd == b.nd) return a.st < b.st;
	return a.nd < b.nd;
}

void solve(){
	int n; cin >> n;
	vpii a(n);
	rep(i, 0, n) cin >> a[i].st >> a[i].nd;
	sort(all(a), cmp);
	vi dp(MAX, 0);
	rep(i, 0, n){
		if (a[i].st > a[i].nd) continue;
		repd(j, a[i].nd-a[i].st, 0){
			dp[j+a[i].st] = max(dp[j]+1, dp[j+a[i].st]);
		}
	}
	int ans = 0;
	rep(i, 0, MAX) ans = max(ans, dp[i]);
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
