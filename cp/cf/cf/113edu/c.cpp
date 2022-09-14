#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

const LL MOD = 998244353;
const int MAX = 2e5+7;
LL silnia[MAX];

 
LL pow(LL a, LL b) {
	LL ans = 1;
	while (b){
		if(b&1) ans = (1ll*ans*a)%MOD;
		b /= 2;
		a = (1ll*a*a)%MOD;
	}
	return ans;
}
 
LL inv(LL a){
	return pow(a, MOD-2);
}
 
LL choose(LL n, LL k){
	if (n < 0 || k < 0 || k>n) return 0;
	return (((silnia[n]*inv(k))%MOD)*inv(n-k))%MOD;
}

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	if (a[n-1] == a[n-2]){
		cout << silnia[n] << "\n";
	} else if (a[n-1]-a[n-2]>1){
		cout << "0\n";
	} else {
		LL cnt = 0;
		rep(i, 0, n) if (a[i] == a[n-2]) cnt++;
		LL ans = silnia[n]*cnt;
		if (ans >= MOD) ans%=MOD;
		ans*=inv(cnt+1);
		if (ans>=MOD) ans%=MOD;
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	silnia[0] = 1;
	rep(i, 1, MAX) silnia[i] = (silnia[i-1]*i)%MOD;
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
