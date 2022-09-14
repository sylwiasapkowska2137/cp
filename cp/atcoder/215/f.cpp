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
	vpii p(n);
	pii tab[4];
	rep(i, 0, n){
		cin >> p[i].st >> p[i].nd;
		if (i == 0){
			rep(j, 0, 4) tab[j] = p[i];
		}
		tab[0] = min(tab[0], p[i]);
		tab[3] = max(tab[3], p[i]);
	}
	rep(i, 0, n){
		if (p[i].st <= tab[2].st && p[i].nd >= tab[2].nd) tab[2] = p[i];
		if (p[i].st >= tab[1].st && p[i].nd <= tab[1].nd) tab[1] = p[i];
	}
	cout << max(min(abs(tab[0].st-tab[3].st), abs(tab[0].nd-tab[3].nd)),min(abs(tab[1].st-tab[2].st), abs(tab[1].nd-tab[2].nd))) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
