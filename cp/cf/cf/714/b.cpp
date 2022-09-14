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

const int MAX = 2e5+7;
const LL MOD = 1e9+7;
LL silnia[MAX];

LL choose(LL n, LL k){
	if (n<0 || k<0 || n<k) return 0;
	return (silnia[n]/(silnia[k]*silnia[n-k]))%MOD;
}

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int AND = a[0];
	rep(i, 1, n) AND &= a[i];
	rep(i, 0, n) a[i]^=AND;
	LL zero = 0;
	rep(i, 0, n) if (!a[i]) zero++;
	LL ans = zero*(zero-1);
	if (ans>=MOD) ans%=MOD;
	ans *= silnia[n-2];
	if (ans >= MOD) ans %= MOD;
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	silnia[0] = 1;
	rep(i, 1, MAX) {
		silnia[i] = silnia[i-1]*i;
		if (silnia[i]>=MOD) silnia[i] %= MOD;
	}
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
 
