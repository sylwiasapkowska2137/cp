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

//https://codeforces.com/blog/entry/94522

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vi a(n+1, 0), pref(n+1, 0);
	rep(i, 1, n+1){
		cin >> a[i];
		a[i] %= m;
		pref[i] = (pref[i-1]+a[i])%m;
	}
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int l, r; cin >> l >> r;
			int ans = 307;
			rep(A, l, r+1){
				rep(B, A, r+1){
					int sum = (pref[B]-pref[A-1]+m)%m;
					ans = min(ans, sum);
				}
			}
			cout << ans << "\n";
		} else {
			int pos, val; cin >> pos >> val;
			val %= m;
			a[pos] = val;
			rep(i, 1, n+1){
				pref[i] = (pref[i-1]+a[i])%m;
			}
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
