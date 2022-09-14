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

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	
	vi lewo(n, -1), prawo(n, n);
	stack<int>s;
	rep(i, 0, n){
		while (!s.empty() && a[s.top()] >= a[i]) s.pop();
		if (!s.empty()) lewo[i] = s.top();
		s.push(i);
	}
	//rep(i, 0, n) debug(lewo[i]);
	//cerr << "\n";
	while (!s.empty()) s.pop();
	repd(i, n-1, 0){
		while (!s.empty() && a[s.top()] >= a[i]) s.pop();
		if (!s.empty()) prawo[i] = s.top();
		s.push(i);
	}
	//rep(i, 0, n) debug(prawo[i]);
	//cerr << "\n";
	LL ans = 0LL;
	rep(i, 0, n){
		LL x = prawo[i]-lewo[i]-1;
		//debug(x);
		ans = max(ans, x*(LL)a[i]);
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
