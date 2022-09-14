/*
	Author: sysia
	07.01.2022 16:06:36
*/

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

const int MAX = 3e5+7, K = 20;
vi graf[MAX], depth;
int up[MAX][K];

struct path{
	int lca, sub1, sub2;
};

void dfs(int v, int pa){
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	}
}

int go_up(int x, int ile){
	repd(i, K-1, 0){
		if (ile&(1<<i)){
			x = up[x][i];
		}
	}
	return x;
}

path lca(int a, int b){
	if (a == b) return {a, -1, -1};
	if (depth[a] > depth[b]) swap(a, b);
	int c = b;
	repd(i, K-1, 0){
		if (depth[b]-(1<<i)>=depth[a]){
			b = up[b][i];
		}
	}
	if (a == b) return {a, -1, go_up(c, depth[c]-depth[a]-1)};
	repd(i, K-1, 0){
		if (up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return {up[a][0], min(a, b), max(a, b)};
}

map<pii, int>cnt[MAX];

void solve(){
	int n; cin >> n;
	depth.assign(n+1, 0);
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(1, 1);
	int m; cin >> m;
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		path x = lca(a, b);
		debug(x.lca);
		debug(x.sub1);
		debug(x.sub2);
		cerr << "\n";
		cnt[x.lca][{x.sub1, x.sub2}]++;
	}
	LL ans = 0LL;
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
