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

void solve(){
	int n, q; cin >> n >> q;
	vi a(n+1);
	rep(i, 1, n+1) cin >> a[i];
	while (q--){
		int A, B, C, D; cin >> A >> B >> C >> D;
		vi x, y;
		rep(i, A, B+1) x.pb(a[i]);
		sort(all(x));
		x.erase(unique(all(x)), x.end());
		rep(i, C, D+1) y.pb(a[i]);
		sort(all(y));
		y.erase(unique(all(y)), y.end());
		bool ok = 1;
		if (sz(x) != sz(y)) {
			cout << "NIE\n";
			continue;
		}
		rep(i, 0, sz(x)) ok &= (x[i] == y[i]);
		if (ok) cout << "TAK\n";
		else cout << "NIE\n";
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
