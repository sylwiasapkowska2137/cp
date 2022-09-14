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

void solve(){
	int n; cin >> n;
	vi z(n+1), d(n+1);
	rep(i, 1, n+1) cin >> z[i] >> d[i];
	int r = 1, l = 2;
	LL zr = 0, zl = 0, dr = 0, dl = 0, c = 0;
	repd(i, n, 2){
		dl += d[i];
		zl += z[i];
		c += dl * z[i];
	}
	//popraw
	while (dr + d[r] < dl){
		c = c+z[l]*(dr+d[r]) - z[l]*dl;
		zr += z[l];
		zl -= z[l];
		dr += d[r];
		dl -= d[l];
		r = (r%n)+1;
		l = (l%n)+1;
	}
	LL ans = c;
	rep(i, 2, n+1){
		LL D = d[i-1];
		c = c-zr*D+(zl+z[i-1])*D;
		zr -= z[i];
		zl += z[i-1];
		dr -= D;
		dl += D;
		while (dr + d[r] < dl){
			c = c+(z[l]*(dr+d[r]) - z[l]*dl);
			zr += z[l];
			zl -= z[l];
			dr += d[r];
			dl -= d[l];
			r = (r%n)+1;
			l = (l%n)+1;
		}
		ans = min(ans, c);
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
