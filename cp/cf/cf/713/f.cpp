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
	int n, c; cin >> n >> c;
	vll a(n), b(n-1), cost(n), days(n); //koszt dotarcia do i-tego zawodu
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n-1) cin >> b[i];
	cost[0] = 0;
	days[0] = 0;
	rep(i, 1, n){
		days[i] = days[i-1]+ceil((LD)(b[i-1]-cost[i-1])/(LD)a[i-1]);
		cost[i] = ceil((LD)(cost[i-1]+b[i-1]/(LD)a[i-1]))*a[i-1]-b[i-1];
	}
	LL ans = LLONG_MAX;
	rep(i, 0, n){
		LL x = days[i]+i+(LL)ceil((LD)(c-cost[i])/(LD)a[i]);
		ans = min(ans, x);
		//debug(x);
		//debug(days[i]);
		//debug(cost[i]);
		//cerr << "\n";
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
