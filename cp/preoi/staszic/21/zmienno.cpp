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

const int MAX = 5e5+7;
vi graf[MAX], gt[MAX], scc[MAX], scc2[MAX], order, numer, in, in2, topo, pos, r, r2;
vb vis, good, good2;
int NR;

void init(int n){
	vis.assign(n+1, 0);
	numer.assign(n+1, 0);
	in.assign(n+1, 0);
	in2.assign(n+1, 0);
	pos.assign(n+1, 0);
	good.assign(n+1, 0);
	good2.assign(n+1, 0);
}

void dfs1(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]) dfs1(x);
	}
	order.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	numer[v] = NR;
	for (auto x: gt[v]){
		if (!vis[x]) dfs2(x);
	}
}

void solve(){
	int n, m; cin >> n >> m;
	init(n);
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		gt[b].pb(a);
	}
	rep(i, 1, n+1) if (!vis[i]) dfs1(i);
	reverse(all(order));
	vis.assign(n+1, 0);
	for (auto x: order){
		if (!vis[x]){
			NR++;
			dfs2(x);
		}
	}
	//cerr << "numer\n";
	//rep(i, 1, n+1) debug(numer[i]);
	//cerr << "\n";
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			if (numer[x]!=numer[v]){
				in[numer[x]]++;
				in2[numer[v]]++;
				scc[numer[v]].pb(numer[x]);
				scc2[numer[x]].pb(numer[v]);
			}
		}
	}
	queue<int>q;
	rep(i, 1, NR+1) if (!in[i]) q.push(i);
	while (!q.empty()){
		int v = q.front(); q.pop();
		topo.pb(v);
		for (auto x: scc[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	//cerr << "topo\n";
	//for (auto x: topo) debug(x);
	//cerr << "\n";
	rep(i, 0, sz(topo)) pos[topo[i]] = i+1;
	r.assign(NR+1, NR+1);
	rep(i, 0, sz(topo)){
		for (auto x: scc[topo[i]]){
			r[topo[i]] = min(r[topo[i]], pos[x]);
		}
	}
	//cerr << "r\n";
	//rep(i, 1, NR+1) debug(r[i]);
	//cerr << "\n";
	rep(i, 1, NR+1) if (r[i]-i == 1) good[i] = 1;
	
	//cerr << "all achievable in graph\n";
	//rep(i, 1, NR+1) debug(good[i]);
	//cerr << "\n";
	
	//repeat
	//cerr << "\nlets repeat\n\n";
	
	rep(i, 1, NR+1) if (!in2[i]) q.push(i);
	topo.clear();
	while (!q.empty()){
		int v = q.front(); q.pop();
		topo.pb(v);
		for (auto x: scc2[v]){
			in2[x]--;
			if (!in2[x]) q.push(x);
		}
	}
	//cerr << "topo2\n";
	//for (auto x: topo) debug(x);
	//cerr << "\n";
	rep(i, 0, sz(topo)) pos[topo[i]] = i+1;
	r2.assign(NR+1, NR+1);
	rep(i, 0, sz(topo)){
		for (auto x: scc2[topo[i]]){
			r2[topo[i]] = min(r2[topo[i]], pos[x]);
		}
	}
	
	//cerr << "r2\n";
	//rep(i, 1, NR+1) debug(r2[i]);
	//cerr << "\n";
	rep(i, 1, NR+1) if (r2[i]-(NR-i+1) == 1) good2[i] = 1;
	
	//cerr << "all achievable in transpose graph\n";
	//rep(i, 1, NR+1) debug(good2[i]);
	//cerr << "\n";
	
	set<int>ans, out;
	rep(i, 1, NR+1) if (good[i] && good2[i]) ans.insert(i);
	rep(i, 1, n+1) if (ans.find(numer[i])!=ans.end()) out.insert(i);
	
	cout << sz(out) << "\n";
	for (auto x: out) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
