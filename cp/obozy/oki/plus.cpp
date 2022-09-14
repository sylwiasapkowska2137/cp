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

const int MAX = 2e5+7;
vpii graf[MAX];
int deg[MAX], it[MAX];
bool vis[MAX], used[MAX];
vi order;

void dfs(int v){
	used[v] = 1;
	for (; it[v]<sz(graf[v]); it[v]++){
		int x = graf[v][it[v]].st;
		int ind = graf[v][it[v]].nd;
		if (vis[ind]) continue;
		//if (used[x]) continue;
		vis[ind] = 1;
		dfs(x);
	}
	order.pb(v);
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	int N = n+m;
	map<pii, int>ans;
	rep(i, 0, k){
		pii x; cin >> x.st >> x.nd;
		x.nd+=n;
		graf[x.st].pb({x.nd, i});
		graf[x.nd].pb({x.st, i});
		//deg[x.st]++;
		deg[x.nd]++;
		ans[{x.nd, x.st}] = i;
	}
	rep(i, 1, N+1){
		if (deg[i]&1){
			cout << "NIE\n";
			return;
		}
	}
	cout << "TAK\n";
	vi out(k);
	rep(i, 1, N+1){
		if (!used[i]){
			dfs(i);
			for (auto x: order) debug(x);
			cerr << "\n";
			if (sz(order)>=2){
				rep(i, 0, sz(order)){
					int prev = i-1;
					if (i == 0) prev = sz(order)-1;
					pii t = {order[prev], order[i]};
					if (t.nd < t.st){
						out[ans[t]] = -1;
					} else {
						swap(t.st, t.nd);
						out[ans[t]] = 1;
					}
				}
			}
			order.clear();
		}
	}
	rep(i, 0, k) cout << out[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
