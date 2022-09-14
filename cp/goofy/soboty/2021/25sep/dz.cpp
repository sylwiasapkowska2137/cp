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

int p(int a, int b){ return a+rand()%(b-a+1);}

void solve(){
	int n; cin >> n;
	vll a(n);
	rep(i, 0, n) cin >> a[i];
	
	srand(2137);
	
	LL ans = 1;
	rep(tmp, 0, 20){
		int x = p(0, n-1);
		vll divisors;
		LL curr = a[x];
		//debug(curr);
		//rozlozyc na dzielniki
		for (LL i = 1; i*i<=curr; i++){
			if (curr%i==0){
				if (curr/i != i) divisors.pb(i);
				divisors.pb(curr/i);
			}
		}
		sort(all(divisors));
		//for (auto x: divisors) debug(x);
		//cerr << "\n";
		
		vi ile(sz(divisors), 0);
		rep(i, 0, n) ile[lower_bound(all(divisors), __gcd(curr, a[i]))-divisors.begin()]++;
		
		//for (auto x: ile) debug(x);
		//cerr << "\n";
		rep(i, 0, sz(divisors)){
			if (ile[i]>=(n/2+n%2)) ans = max(ans, divisors[i]);
			rep(j, i+1, sz(divisors)){
				if (divisors[j]%divisors[i] == 0){
					ile[i] += ile[j];
					if (ile[i]>=(n/2+n%2)) ans = max(ans, divisors[i]);
				}
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
