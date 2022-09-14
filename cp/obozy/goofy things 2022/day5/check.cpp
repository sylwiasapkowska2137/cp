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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k; cin >> n >> k;
	vi a(n+1), b(n+1);
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) cin >> b[i];
	int s; cin >> s;
	if (s == -1) {
		return 0;
	}
	vpii ans(s);
	rep(i, 0, s){
		int x, y; cin >> x >> y;
		rep(j, x, x+k) a[j] = y;
	}
	bool ok = 1;
	rep(i, 1, n+1) ok&=(a[i] == b[i]);
	ok ^= 1;
	return ok;
}
