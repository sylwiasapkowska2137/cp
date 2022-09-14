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

const LL INF = 2e18;

void solve(){
	int n;
	LL T;
	cin >> n >> T;
	vll ilosc(n+1), sila(n+2);
	ilosc[0] = 0;
	sila[n+1] = LLONG_MAX;
	rep(i, 1, n+1) {
		cin >> ilosc[i];
	}
	rep(i, 1, n+1) {
		cin >> sila[i];
		sila[i]/=T;
		//debug(sila[i]);
	}
	repd(i, n, 0) sila[i] = min(sila[i], sila[i+1]);
	
	//rep(i, 1, n+1) debug(sila[i]);
	//cerr << "\n";
	
	LL start = 1, koniec = INF;
	while (koniec != start){
		LL m = (start+koniec)/2;
		bool ok = 1;
		LL curr_czas = 0, curr_ilosc = 0;
		rep(i, 1, n+1){
			if (ilosc[i] > m) ok = 0;
			if (curr_ilosc + ilosc[i] > m){
				curr_czas++;
				if (curr_czas > sila[i]) ok = 0;
				curr_ilosc = ilosc[i];
			} else curr_ilosc += ilosc[i];
			
			if (!ok) break;
		}
		if (ok) koniec = m;
		else start = m+1;
	}
	cout << koniec << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
