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
vi graf[MAX], leaf, depth;

void dfs(int v, int pa){
	if (sz(graf[v]) == 1) leaf[v] = 1;
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
			leaf[v]+=leaf[x];
		}
	}
}

struct Edge{
	int a, b, leaf; 
	LL c;
};

void solve(){
	int n; LL S; cin >> n >> S;
	vector<Edge>E;
	leaf.assign(n+1, 0);
	depth.assign(n+1, 0);
	rep(i, 1, n+1) graf[i].clear();
	rep(i, 1, n){
		int a, b; LL c; cin >> a >> b >> c;
		graf[a].pb(b);
		graf[b].pb(a);
		E.pb(Edge{a, b, 0, c});
	}
	dfs(1, -1);
	rep(i, 0, n-1){
		if (depth[E[i].a]>depth[E[i].b]) E[i].leaf = leaf[E[i].a];
		else E[i].leaf = leaf[E[i].b];
	}
	LL SUM = 0LL;
	rep(i, 0, n-1) SUM += (LL)(E[i].leaf * E[i].c);
	pq<pll>q;
	rep(i, 0, n-1) {
		q.push({(LL)E[i].leaf*(E[i].c-E[i].c/2), i});
	}
	int ans = 0;
	while (SUM > S){
		int i = q.top().nd;
		q.pop();
		SUM -= (E[i].leaf*(E[i].c-E[i].c/2));
		E[i].c/=2;
		q.push({E[i].leaf*(E[i].c-E[i].c/2), i});
		ans++;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
