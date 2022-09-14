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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int p(LL a, LL b){
	return a+rng()%(b-a+1);
}

LL power(LL a, LL b, LL mod){
	if (!b) return 1LL;
	LL k = power(a, b/2, mod);
	k = (k*k)%mod;
	if (b&1) k = (k*a)%mod;
	return k;
}

bool zlozona(LL n, LL x, LL d, LL r){
	LL y = power(x, d, n);
	if (y == 1 || y == n-1) return 0;
	rep(R, 1, r){
		y = (y*y)%n;
		if (y == n-1) return 0;
	}
	return 1;
}
 
bool prime(LL n){
	int r = 0;
	LL d = n-1;
	while (!(d&1)){
		d/=2;
		r++;
	}
	vi tab = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for (auto x: tab){
		if (n == x) return 1;
		if (zlozona(n, x, d, r)) return 0;
	}
	return 1;
}

LL rho(LL n){
	LL x = 0LL, y = 0LL, t = 30, product = 2, i = 1, q;
	while (t++ % 40 || __gcd(product, n) == 1) {
		if (x == y) {
			x = ++i;
			y = (x*x)%n+1;
		}
		q = (product*(max(x, y)-min(x, y)))%n;
		if (q) product = q;
		x = (x*x+1LL)%n;
		y = (y*y+1LL)%n;
		y = (y*y+1LL)%n;
	}
	return __gcd(product, n);
}

vll factor(LL n){
	if (n == 1) return {};
	if (prime(n)) return {n};
	LL x = rho(n);
	vll a = factor(x), b = factor(n/x);
	a.insert(a.end(), all(b));
	return a;
}

void solve(){
	LL n; cin >> n;
	vll ans = factor(n);
	cout << sz(ans) << " ";
	sort(all(ans));
	for (auto x: ans) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
