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
#define DEBUG(x) cerr << #x << " "

vector<vll>pref;
LL n, m, c, d; 

 
bool warunek(LL mid){
	int ilec = 0, iled = 0, prev = 0;
	LL val = 0LL;
	rep (kolumna, 1, m+1){
		iled = 0;
		val = 0;
		rep(i, 1, n+1){
			val += pref[i][kolumna]-pref[i][prev];
			if (val >= mid){
				val = 0;
				iled++;
			}
		}
		if (iled>=d) {
			ilec++;
			prev = kolumna;
		} 
	}
	//debug(ilec);
	if (ilec>=c) return 1;
	return 0;
}

LL binsearch(LL start, LL koniec){
	while (koniec != start){
		LL mid = (start+koniec)/2;
		if (warunek(mid)) start = mid+1;
		else koniec = mid;
	}
	return koniec;
}

void solve(){
	cin >> n >> m >> c >> d;
	pref.resize(n+2, vll(m+2, 0LL));
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			cin >> pref[i][j];
			pref[i][j] += pref[i][j-1];
		}
	}
	LL start = 1, koniec = 1e15+2137;
	cout << binsearch(start, koniec)-1 << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
