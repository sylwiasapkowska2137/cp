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

const int INF = 1e9+7;

bool cmp(pii a, pii b){
	if (a.nd == b.nd) return a.st < b.st;
	return a.nd < b.nd;
}

void solve(){
	int n; cin >> n;
	vpii a(n);
	rep(i, 0, n) cin >> a[i].st >> a[i].nd;
	
	vll dp(n+1, INF);
	dp[0] = 0;
	sort(all(a), cmp);
	rep(i, 0, n){
		if (a[i].st > a[i].nd) continue;
		/*
		debug(a[i].st);
		debug(a[i].nd);
		cerr << "\n";
		*/
		repd(j, n-1, 0){
			if (dp[j]+a[i].st <= a[i].nd){
				dp[j+1] = min(dp[j+1], dp[j]+a[i].st);
			}
		}
		rep(k, 0, n+1) {
			if (dp[k] == INF) debug("x");
			else debug(dp[k]);
		}
		cerr << "\n";
	}
	/*
	rep(i, 0, n) debug(ile[i]);
	cerr << "\n";
	rep(i, 0, n) debug(suma[i]);
	cerr << "\n";
	int ans = 0;
	rep(i, 0, n+1) ans = max(ans, ile[i]);
	cout << ans << "\n";
	*/
	repd(i, n, 0){
		if (dp[i]!=INF) {
			cout << i << "\n";
			return;
		}
	}
	cout << "0\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
