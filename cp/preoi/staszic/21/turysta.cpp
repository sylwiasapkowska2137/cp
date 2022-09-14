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

const int MAX = 2007;
vi graf[MAX], gt[MAX], scc[MAX], in, order, numer, topo, cnt, dp;
vb vis;
int NR;

void dfs1(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs1(x);
		}
	}
	order.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	numer[v] = NR;
	for (auto x: gt[v]){
		if (!vis[x]){
			dfs2(x);
		}
	}
}

void init(int n){
	vis.assign(n+1, 0);
	numer.assign(n+1, 0);
	in.assign(n+1, 0);
	cnt.assign(n+1, 0);
	dp.assign(n+1, 0);
}

void solve(){
	int n; cin >> n;
	init(n);
	rep(i, 2, n+1){
		rep(j, 1, i){
			bool x; cin >> x;
			int a = i, b = j;
			if (!x) swap(a, b);
			graf[a].pb(b);
			gt[b].pb(a); 
		}
	}
	/*
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			cerr << x << " " << v << "\n";
		}
	}
	*/
	
	rep(v, 1, n+1) if (!vis[v]) dfs1(v);
	reverse(all(order));
	vis.assign(n+1, 0);
	for (auto x: order){
		if (!vis[x]){
			NR++;
			dfs2(x);
		}
	}
	rep(i, 1, n+1) debug(numer[i]);
	cerr << "\n";
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			if (numer[x]!=numer[v]){
				scc[numer[v]].pb(numer[x]);
				in[numer[x]]++;
			}
		}
	}
	rep(i, 1, NR+1) debug(in[i]);
	cerr << "\n";
	queue<int>q;
	rep(v, 1, NR+1) if (!in[v]) q.push(v);
	while (!q.empty()){
		int v = q.front(); q.pop();
		topo.pb(v);
		for (auto x: scc[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	reverse(all(topo));
	for (auto x: topo) debug(x);
	cerr << "\n";
	rep(i, 1, n+1) cnt[numer[i]]++;
	rep(i, 1, NR+1) debug(cnt[i]);
	cerr << "\n";
	for (auto v: topo){
		int curr = 0;
		for (auto x: scc[v]){
			
		}
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
