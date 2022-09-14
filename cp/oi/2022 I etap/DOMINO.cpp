//Sylwia Sapkowska
//domino
//template from https://codeforces.com/profile/Geothermal
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

//remember about 1008

const LL MAX = 1e18;
const int INF = 1e9+7;
vll fib;
map<LL, int>mapa;

int dp(LL m){
	if (m == 1) return 0;
	if (mapa.find(m) != mapa.end()) return mapa[m];
	int ans = INF;
	repd(i, sz(fib)-1, 2){
		if (m%fib[i] == 0){
			ans = min(ans, dp(m/fib[i])+i+1);
		}
	}
	mapa[m] = ans;
	/*
	debug(m);
	debug(ans);
	cerr << "\n";
	*/
	return mapa[m];
}

void solve(){
	fib.pb(1);
	fib.pb(1);
	int i = 2;
	while (fib.back() <= MAX){
		fib.pb(fib.back()+fib[sz(fib)-2]);
		//debug(fib.back());
		mapa[fib.back()] = i;
		i++;
	}
	
	LL m; cin >> m;
	if (m == 1){
		cout << "1\n";
		return;
	}
	
	int ans = dp(m);
	if (ans >= 1e9) cout << "NIE\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
