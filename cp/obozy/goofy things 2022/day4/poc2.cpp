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

const int MAX = (1<<20), N = 5e5+7;
vi tab[MAX];
int base = 8;
bitset<N>vis;

void build(vi &a, int x, int lx, int rx){
	if (lx == rx) {
		if (lx < sz(a)) tab[x] = {a[lx]};
		return;
	}
	int m = (lx+rx)/2;
	build(a, 2*x, lx, m);
	build(a, 2*x+1, m+1, rx);
	if (tab[2*x].empty()) return;
	if (tab[2*x+1].empty()) {
		tab[x] = tab[2*x];
		return;
	}
	merge(all(tab[2*x]), all(tab[2*x+1]),back_inserter(tab[x]));
	tab[x].erase(unique(all(tab[x])), tab[x].end());
}

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
	build(a, 1, 1, base);
	int x = 1;
	while (x<2*base){
		debug(x);
		for (auto v: tab[x]) debug(v);
		cerr << "\n";
		x++;
	}
	while (q--){
		int A, B; cin >> A >> B;
		vis.clear();
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
