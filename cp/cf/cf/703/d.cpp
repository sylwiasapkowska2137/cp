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
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "

void solve(){
	int n, k; cin >> n >> k;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int start = 1, koniec = n, ans = 1; 
	while (koniec >= start){
		int m = (start+koniec)/2;
		vi b(n+1), pref(n+1);
		pref[0] = 0;
		rep(i, 1, n+1){
			if (a[i-1]>=m) b[i] = 1;
			else b[i] = -1;
		}
		rep(i, 1, n+1) pref[i] = pref[i-1]+b[i];
		
		int mini = 0, maxi = pref[k];
		rep(i, k+1, n+1){
			mini = min(mini, pref[i-k]);
			maxi = max(maxi, pref[i]-mini);
		}
		
		if (maxi > 0){
			start = m+1;
			ans = m;
		} else koniec = m-1;
	}
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
