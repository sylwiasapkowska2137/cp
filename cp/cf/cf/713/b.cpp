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
	pii a = {-1, -1}, b = {-1, -1}, c, d;
	cin >> n;
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			char c;cin >> c;
			if (c == '*'){
				if (a.st == -1) a = {i, j};
				else {
					if (b.st == -1) b = {i, j};
				}
			}
		}
	}
	if (a.st == b.st){
		if (a.st == n) {
			c = {n-1, a.nd};
			d = {n-1, b.nd};
		} else {
			c = {a.st+1, a.nd};
			d = {a.st+1, b.nd};
		}
	} else if (a.nd == b.nd){
		if (a.nd == n) {
			c = {a.st, n-1};
			d = {b.st, n-1};
		} else {
			c = {a.st, a.nd+1};
			d = {b.st, b.nd+1};
		}
	} else {
		c = {a.st, b.nd};
		d = {b.st, a.nd};
	}
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			pii x = {i, j};
			if (x == a) cout << "*";
			else if (x == b) cout << "*";
			else if (x == c) cout << "*";
			else if (x == d) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
