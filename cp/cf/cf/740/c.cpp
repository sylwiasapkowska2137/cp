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
	int n;
	cin >> n;
	vpii tab;
	rep(i, 0, n){
		int ile; cin >> ile;
		int x, ans = 0;
		rep(j, 0, ile) {
			cin >> x;
			ans = max(ans, x-j);
		}
		tab.pb({ans, ile});
	}
	sort(all(tab));
	//for (auto x: tab) debug(x);
	int start = 1, koniec = 1e9, ans = n;
	while (koniec >= start){
		int m = (start+koniec)/2;
		int s = m;
		bool ok = 1;
		rep(i, 0, n){
			if (s < tab[i].st){
				ok = 0;
				break;
			} else {
				s+=tab[i].nd;
			}
		}
		if (ok){
			koniec = m-1;
			ans = m;
		} else start = m+1;
	}
	cout << ans+1 << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
