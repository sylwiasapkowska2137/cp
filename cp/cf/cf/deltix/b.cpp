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
	int n; cin >> n;
	int even = 0, odd = 0;
	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
		if (a[i]&1) {
			odd++;
			a[i] = 1;
		}else {
			even++;
			a[i] = 0;
		}
	}
	if (abs(even-odd) > 1){
		cout << "-1\n";
		return;
	}
	vi next(n), nextzero(n);
	next[n-1] = n-1;
	repd(i, n-2, 0){
		next[i] = next[i+1];
		if (a[i]) next[i] = i;
	}
	LL ans = LLONG_MAX;
	if (even >= odd){
		vi tab[2];
		rep(i, 0, n){
			if ((a[i]&1) != (i&1)){
				tab[a[i]].pb(i);
			}
		}
		LL tmp = 0;
		rep(i, 0, min(sz(tab[0]), sz(tab[1]))){
			tmp += (LL)(abs(tab[0][i]-tab[1][i]));
		}
		ans = min(ans, tmp);
	} 
	if (odd >= even){
		vi tab[2];
		rep(i, 0, n){
			if ((a[i]&1) == (i&1)){
				tab[a[i]].pb(i);
			}
		}
		LL tmp = 0;
		rep(i, 0, min(sz(tab[0]), sz(tab[1]))){
			tmp += (LL)(abs(tab[0][i]-tab[1][i]));
		}
		ans = min(ans, tmp);
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
