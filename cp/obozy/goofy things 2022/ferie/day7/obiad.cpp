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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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

int p(int a, int b){
	return a+rng()%(b-a+1);
}


// https://codeforces.com/blog/entry/90413
// SEND NODES XDDDDD
bool check(LD x, int n, int s, vi &cnt, vi &ile, vi &cena){
	LL left = s;
	debug(x);
	rep(i, 1, n+1){
		LL k = max(0LL, (LL)ceil((x*(LD)cnt[i]-(LD)ile[i])));
		debug(k);
		left -= (cena[i]*k);
		if (left < 0) {
			debug(0);
			return 0;
		}
	}
	debug((left>=0));
	return (left >= 0);
}

void solve(){
	cout << fixed << setprecision(10);
	int n, m, s; cin >> n >> m >> s;
	vi cnt(n+1, 0);
	rep(i, 1, m+1){
		int x; cin >> x;
		cnt[x]++;
	}
	vi ile(n+1), cena(n+1);
	rep(i, 1, n+1) cin >> ile[i] >> cena[i];
	LD L = 0, R = 5;
	LD EPS = 1e-10;
	check(2, n, s, cnt, ile, cena);
	cerr << "\n";
	check(3, n, s, cnt, ile, cena);
	cerr << "\n";
	check(2.777777777777776, n, s, cnt, ile, cena);
	cerr << "\n";
	
	while (R-L>EPS){
		LD M = (L+R)/2;
		debug(M);
		if (check(M, n, s, cnt, ile, cena)){
			L = M;
		} else R = M-EPS;
	}
	cout << L << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
