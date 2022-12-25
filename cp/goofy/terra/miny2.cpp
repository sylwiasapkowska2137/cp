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

const int INF = 1e9+7;

struct mine{
	int p, c, r, i;
};

bool cmp(mine a, mine b){
	return a.p < b.p;
}

struct node{
	multiset<int>s;
	int lx, rx;
};

const int SZ = 262144;
const int MAX = 2*SZ+1;
vi graf[MAX], gt[MAX], post, numer, indeg;
vb vis;
int nr;
node Tab[MAX];
multiset<int>what;

node comb(int x){
	return node{what, Tab[2*x].lx, Tab[2*x+1].rx };
}

void build(vi scaler){
	rep(i, 0, sz(scaler)) Tab[i+SZ].lx = Tab[i+SZ].rx = scaler[i];
	rep(i, sz(scaler), SZ) Tab[i+SZ].lx = Tab[i+SZ].rx = INF;
	repd(i, SZ-1, 1) {
		Tab[i] = comb(i);
		graf[i].pb(2*i);
		graf[i].pb(2*i+1);
		gt[2*i].pb(i);
		gt[2*i+1].pb(i);
	}
}

void add(int pos, int val){
	Tab[pos+SZ].s.insert(val);
}

void edges(int x, int lx, int rx, int l, int r, int from){
	if (lx > r || rx < l) return;
	if (lx >= l && rx <= r){
		graf[from+SZ].pb(x);
		gt[x].pb(from+SZ);
		return;
	}
	edges(2*x, Tab[2*x].lx, Tab[2*x].rx, l, r, from);
	edges(2*x+1, Tab[2*x+1].lx, Tab[2*x+1].rx, l, r, from);
}

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x);
	}
	post.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	numer[v] = nr;
	for (auto x: gt[v]){
		if (!vis[x]) dfs2(x);
	}
}

bool cmp2(mine a, mine b){
	return a.i < b.i;
}

void solve(){
	int n, q; cin >> n >> q;
	vector<mine>tab(n);
	rep(i, 0, n){
		cin >> tab[i].p >> tab[i].r >> tab[i].c;
		tab[i].i = i;
	}
	sort(all(tab), cmp);
	
	//skalowanie do drzewa
	vi scaler;
	rep(i, 0, n) scaler.pb(tab[i].p);
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<int, int>mapa;
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i;
	
	/*
	debug("scaler");
	for (auto x: scaler) debug(x);
	cerr << "\n";
	*/
	
	
	build(scaler);
	rep(i, 0, n) add(mapa[tab[i].p], tab[i].i);
	sort(all(tab), cmp2);
	
	//Print();
	
	rep(i, 0, n) edges(1, 0, INF, tab[i].p-tab[i].r, tab[i].r+tab[i].p, mapa[tab[i].p]);
	
	/*
	cerr << "\n";
	rep(i, 1, sz(seg.tab)){
		debug(i);
		for (auto x: graf[i]) debug(x);
		cerr << "\n";
	}
	*/
	int N = 2*SZ;
	vis.assign(N, 0);
	numer.assign(N, 0);
	rep(i, 1, N) if (!vis[i]) dfs(i);
	vis.assign(N, 0);
	reverse(all(post));
	for (auto x: post){
		if (!vis[x]){
			nr++;
			dfs2(x);
		}
	}
	/*
	debug("numer");
	rep(i, 1, N) debug(numer[i]);
	cerr << "\n";
	*/
	vb empty(N, 1);
	
	rep(i, 1, N){
		int x = i-SZ;
		if (x >= 0 && x < sz(scaler)){
			empty[numer[i]] = 0;
		}
	}
	/*
	debug("empty");
	rep(i, 1, nr+1) debug(empty[i]);
	cerr << "\n";
	*/
	indeg.assign(nr+1, 0);
	rep(i, 1, N){
		for (auto x: graf[i]){
			if (numer[i]!=numer[x] && !empty[numer[i]]) {
				indeg[numer[x]]++;
				//scc[numer[i]].pb(numer[x]);
			}
		}
	}
	rep(i, 1, N){
		for (auto x: graf[i]){
			if (numer[i]!=numer[x] && empty[numer[i]] && indeg[numer[i]]){
				indeg[numer[x]]++;
				//scc[numer[i]].pb(numer[x]);
			}
		}
	}
	
	/*
	debug("scc");
	cerr << "\n";
	rep(i, 1, nr+1){
		debug(i);
		for (auto x: scc[i]) debug(x);
		cerr << "\n";
	}
	*/
	vector<multiset<int>>costs(nr+1);
	vi change(N);
	rep(i, 1, N){
		for (auto x: Tab[i].s){
			costs[numer[i]].insert(tab[x].c);
			change[tab[x].i] = numer[i];
		}
	}
	/*
	cerr << "\n";
	rep(i, 1, nr+1){
		debug(i);
		for (auto x: costs[i]) debug(x);
		cerr << "\n";
	}
	*/
	/*
	debug("change");
	rep(i, 0, n) debug(change[i]);
	cerr << "\n";
	*/
	
	LL ans = 0LL;
	rep(i, 1, nr+1){
		if (!indeg[i] && !empty[i] && !costs[i].empty()) {
			ans += *costs[i].begin();
		}
	}
	
	//debug(ans);
	//cerr << "\n\n";
	//return;
	while (q--){
		int i, x; cin >> i >> x;
		i--;
		if (!indeg[change[i]]) {
			ans-=*costs[change[i]].begin();
			auto it = costs[change[i]].lb(tab[i].c);
			costs[change[i]].erase(it);
			tab[i].c = x;
			costs[change[i]].insert(x);
			/*
			debug("costs:");
			for (auto x: costs[change[i]]) debug(x);
			cerr << "\n";
			*/
			ans+=*costs[change[i]].begin();
		} 
		cout << ans << "\n";
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