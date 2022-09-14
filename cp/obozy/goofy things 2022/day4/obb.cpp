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

const LL INF = 1e18;

void solve(){
	LD n, m;int q; cin >> n >> m >> q;
	//map<int, int>rev, rev2;
	vpii rev, rev2;
	rep(k, 1, n){
		int x = ceil(n/(LD)(k+1));
		if (rev.empty() || rev.back().st != x) rev.pb({x, k});
	}
	rev.pb({n, 0});
	//for (auto x: rev) cerr << x.st << " " << x.nd << "\n";
	//cerr << "\n";
	rep(k, 1, m){
		int x = ceil(m/(LD)(k+1));
		if (rev2.empty() || rev2.back().st != x) rev2.pb({x, k});
	}
	rev2.pb({m, 0});
	//for (auto x: rev2) cerr << x.st << " " << x.nd << "\n";
	//cerr << "\n";
	vll dp(n+m-1, INF);
	for (auto x: rev){
		for (auto y: rev2){
			dp[x.nd+y.nd] = min(dp[x.nd+y.nd], (LL)x.st*y.st);
		}
	}
	dp[0] = n*m;
	rep(i, 1, sz(dp)) dp[i] = min(dp[i], dp[i-1]);
	//cerr << "\n";
	while (q--){
		int k; cin >> k;
		cout << dp[k] << "\n";
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
