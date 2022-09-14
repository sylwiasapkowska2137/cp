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

struct segtree{
	vll tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void set(int pos, int val){
		pos+=size;
		tab[pos] = val;
		while (pos>0){
			pos/=2;
			tab[pos] = tab[2*pos]+tab[2*pos+1];
		}
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0;
		while (r-l>1){
			if (!(l&1)) ans+=tab[l+1];
			if (r&1) ans+=tab[r-1];
			l/=2;
			r/=2;
		}
		return ans;
	}
};

const int MAX = 1e5+7;
LL dp[11][MAX];

void solve(){
	int n, k; cin >> n >> k;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	segtree seg;
	seg.init(n+1);
	rep(i, 0, n){
		dp[1][i] = seg.query(0, a[i]-1);
		seg.set(a[i]-1, 1); 
		debug(dp[1][i]);
	}
	rep(i, 0, n){
		seg.tab[i+seg.size] = dp[1][i];
	}
	repd(i, seg.size-1, 0){
		seg.tab[i] = seg.tab[2*i]+seg.tab[2*i+1];
	}
	cerr << "\n";
	rep(K, 2, k+1){
		for (auto x: seg.tab) debug(x);
		cerr << "\n";
		rep(i, 0, n){
			dp[K][i] = seg.query(0, a[i]-1);
			//seg.set(a[i]-1, dp[K][i]); 
			debug(dp[K][i]);
		}
		cerr << "\n";
		rep(i, 0, n){
			seg.tab[i+seg.size] = dp[K][i];
		}
		repd(i, seg.size-1, 0){
			seg.tab[i] = seg.tab[2*i]+seg.tab[2*i+1];
		}
		
	}
	LL ans = 0LL;
	rep(i, 0, n) ans+=dp[k][i];
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
