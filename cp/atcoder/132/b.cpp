//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

struct segtree{
	int size = 1;
	vi tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}
	
	void update(int p){
		p+=size;
		tab[p]++;
		while (p>0){
			p/=2;
			tab[p]++;
		}
	}
	
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;
			r/=2;
		}
		return ans;
	}
};

void solve(){
	LL n; cin >> n;
	deque<int>a;
	rep(i, 0, n) {
		int x; cin >> x;
		a.pb(x);
	}
	segtree seg;
	seg.init(n+1);
	LL inv = 0LL;
	LL pairs = n*(n-1)/2;
	rep(i, 0, n){
		inv += seg.query(a[i]+1, seg.size-1);
		seg.update(a[i]);
	}
	debug(inv);
	int ans = 0;
	int k = 5;
	bool reversed = 0;
	while (k--){
		int v = a.front();
		if ((pairs - inv < inv || (n-v-(v-1)) >= 0) && !reversed){
			cerr << "reverse\n";
			inv = pairs-inv;
			reversed = 1;
			reverse(all(a));
		} else {
			reversed = 0;
			cerr << "move " << v << "\n";
			inv -= (v-1);
			a.pop_front();
			a.pb(v);
			inv += (n-v);
		}
		ans++;
		debug(inv);
		for (auto x: a) debug(x);
		cerr << "\n";
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
