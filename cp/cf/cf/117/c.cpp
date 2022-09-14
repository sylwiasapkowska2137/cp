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

LL ile(LL rows, LL k){
	LL ans;
	if (rows <= k){
		ans = rows*(rows+1)/2;
	} else {
		ans = k*(k+1)/2;
		rows-=k;
		//rows-1 + (rows -2) + ... rows times
		LL left = (k-1)-(rows);
		ans += ((k-1)*k/2 - left*(left+1)/2);
	}
	return ans;
}

void solve(){
	LL k, x; cin >> k >> x;
	LL l = 1, r = 2*k-1, ans = 1;
	if (ile(2*k-1, k) < x){
		cout << 2*k-1 << "\n";
		return;
	}
	while (r >= l){
		LL m = (l+r)/2;
		if (ile(m, k) >= x){
			ans = m;
			r = m-1;
		} else l = m+1;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
