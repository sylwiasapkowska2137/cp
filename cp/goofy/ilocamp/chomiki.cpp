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

const int Size = 5e5+7;
vi tab(2*Size, 10);

int query(int l, int r){
	l = l+Size-1;
	r = r+Size+1;
	int ans = 10;
	while (r-l>1){
		if (!(l&1)) ans = min(ans, tab[l+1]);
		if (r&1) ans = min(ans, tab[r-1]);
		l/=2;r/=2;
	}
	return ans;
}

void solve(){
	int n, q; cin >> n >> q;
	rep(i, 1, n+1) cin >> tab[i+Size];
	repd(i, Size-1, 0){
		tab[i] = min(tab[2*i], tab[2*i+1]);
	}
	while (q--){
		int a, b; cin >> a >> b;
		cout << query(a, b) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
