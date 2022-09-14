#include <bits/stdc++.h>
#include "wielib.h"
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

const LL MAX = 1e18;

void solve(){
	int n = wezN();
	vi p(n);
	rep(i, 0, n) p[i] = i+1;
	random_shuffle(all(p));
	LL L = 1, maxi = 0;
	rep(i, 0, n){
		if (L == MAX) break;
		if (zamowienie(p[i], L+1)){
			L++;
			LL r = MAX, l = L;
			while (r >= l){
				LL m = (l+r)/2;
				if (zamowienie(p[i], m)) {
					L = m;
					l = m+1;
				} else r = m-1;
			}
		}
	}
	odpowiedz(L);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	srand(2137);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
