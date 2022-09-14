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

const int MAX = 5e4+7;
vi graf[MAX], gt[MAX], order, numer, topo, scc[MAX];
vb vis;
int NR;

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
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		gt[b].pb(a);
	}
	vis.assign(n+1, 0);
	rep(i, 1, n+1) if (!vis[i]) dfs1(i);
	reverse(all(order));
	vis.assign(n+1, 0);
	numer.assign(n+1, 0);
	for (auto x: order) {
		if (!vis[x]) {
			NR++;
			dfs2(x);
		}
	}
	//rep(i, 1, n+1) debug(numer[i]);
	//cerr << "\n";
	vi in(n+1, 0);
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			if (numer[v] != numer[x]){
				scc[numer[v]].pb(numer[x]);
				in[numer[x]]++;
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
	//for (auto x: topo) debug(x);
	//cerr << "\n";
	reverse(all(topo));
	vi dp(NR+1, 0);
	vi cnt(NR+1, 0);
	rep(i, 1, n+1) cnt[numer[i]]++;
	rep(i, 1, NR+1) dp[i] = cnt[i];
	for (auto v: topo){
		for (auto x: scc[v]){
			dp[v]+=dp[x];
		}
	}
	rep(i, 1, n+1) cout << dp[numer[i]]-1 << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
