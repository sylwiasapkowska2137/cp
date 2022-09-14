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

const int MAX = 5e5+7, INF = 1e9+7;
vpii query[MAX];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
	return a+rng()%(b-a+1);
}

struct segtree{
	vll tab;
	int size = 1;
	
	void init(int n, vll &hash, vi &a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		vi last(n+1, -1);
		rep(i, 1, sz(a)) {
			if (last[a[i]] == -1) {
				tab[i+size] = hash[a[i]];
				last[a[i]] = i;
			}
		}
		repd(i, size-1, 0) tab[i] = tab[2*i]^tab[2*i+1];
	}
	
	LL query(int l, int r){
		LL ans = 0;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans ^= tab[l+1];
			if (r&1) ans ^= tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
	
	void update(int pos, LL val){
		pos += size;
		tab[pos] = val;
		while (pos>0){
			pos/=2;
			tab[pos] = tab[2*pos]^tab[2*pos+1];
		}
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vi a(n+1), scaler;
	rep(i, 1, n+1) {
		cin >> a[i];
		scaler.pb(a[i]);
	}
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<int, int>mapa;
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i+1;
	rep(i, 1, n+1) a[i] = mapa[a[i]];
	vi next(n+1, 0), last(n+1, INF);
	repd(i, n, 1){
		next[i] = last[a[i]];
		last[a[i]] = i;
	}
	rep(i, 0, 2*q){
		int l, r; cin >> l >> r;
		query[l].pb({r, i});
	}
	vll hash(n+1, 0);
	
	rep(i, 1, n+1){
		rep(j, 0, 60){
			int x = p(0, 1);
			if (x) hash[i] += (1LL<<j);
		}
		//debug(hash[i]);
	}
	segtree seg;
	seg.init(n+1, hash, a);

	vll ans(2*q, 0);
	rep(l, 1, n+1){
		for (auto [r, i]:query[l]){
			ans[i] = seg.query(l, r);
		}
		seg.update(l, 0);
		if (next[l]!=INF) seg.update(next[l], hash[a[l]]);
	}
	for (int i = 0; i<2*q; i+=2){
		if (ans[i] == ans[i+1]) cout << "TAK\n";
		else cout << "NIE\n";
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
