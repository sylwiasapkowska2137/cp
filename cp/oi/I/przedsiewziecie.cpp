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

const int MAX = 1e5+7;
const LL INF = 1e18+7;
vi graf[MAX], gt[MAX], order, topo;
vb vis;
int n, NR;


void print(){
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			cout << v << " " << x << "\n";
		}
	}
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
	for (auto x: gt[v]){
		if (!vis[x]) dfs2(x);
	}
}

void solve(){
	cin >> n;
	vi t(n+1), in(n+1);
	rep(i, 1, n+1){
		cin >> t[i] >> in[i];
		rep(j, 0, in[i]){
			int y; cin >> y;
			graf[y].pb(i);
			gt[i].pb(y);
		}
	}
	//print();
	vis.assign(n+1, 0);
	rep(v, 1, n+1) if (!vis[v]) dfs1(v);
	reverse(all(order));
	vis.assign(n+1, 0);
	for (auto x: order) {
		if (!vis[x]) {
			NR++;
			dfs2(x);
		}
	}
	if (NR < n){
		cout << "CYKL\n";
		return;
	}
	queue<int>q;
	vll dp(n+1, 0), DP(n+1, 0);
	rep(i, 1, n+1) dp[i] = t[i];
	rep(v, 1, n+1) if (!in[v]) q.push(v);
	while (!q.empty()){
		int v = q.front(); q.pop();
		topo.pb(v);
		for (auto x: graf[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	reverse(all(topo));
	//for (auto x: topo) debug(x);
	//cerr << "\n";
	LL ans = 0LL;
	for (auto v: topo){
		for (auto x: graf[v]){
			dp[v] = max(dp[v], dp[x]+t[v]);
		}
		ans = max(ans, dp[v]);
	}
	reverse(all(topo));
	for (auto v: topo){
		for (auto x: gt[v]){
			DP[v] = max(DP[v], DP[x]+t[x]);
		}
	}
	//rep(i, 1, n+1)debug(dp[i]);
	//cerr << "\n";
	//rep(i, 1, n+1) debug(DP[i]);
	//cerr << "\n";
	cout << ans << "\n";
	int Q; cin >> Q;
	while (Q--){
		int m, d; cin >> m >> d;
		if (d <= ans-dp[m]-DP[m]) cout << "NIE\n";
		else cout << "TAK\n";
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
