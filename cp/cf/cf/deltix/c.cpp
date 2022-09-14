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

const LL MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vll a(n+1), pref(n+1);
	pref[0] = 0;
	rep(i, 1, n+1) {
		cin >> a[i];
		if (!(i&1)) a[i] = -a[i];
		pref[i] = pref[i-1]+a[i];
	}
	if (n&1) a.pop_back();
	LL ans = 0LL;
	rep(i, 1, n+1){
		if (!(i&1)) continue;
		rep(j, i, n+1){
			int len = j-i+1;
			if ((len&1) || len<4) continue;
			debug(i);
			debug(j);
			LL suma = pref[j-1]-pref[i];
			LL x = min(suma, a[i]);//x dodatnie
			LL y = min(suma, -a[j]); //y ujemne
			LL xx = max(0LL, suma-a[i]);
			LL yy = max(0LL, suma+a[j]);
			debug(suma);
			debug(xx);
			debug(x);
			debug(yy);
			debug(y);
			
			cerr << "\n";
		}
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
