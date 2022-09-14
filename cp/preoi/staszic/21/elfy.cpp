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

const int MAX = 2e5+7;
vi graf[MAX], pre, low, point, cnt;
vb vis;
int czas;

void dfs(int v, int pa = -1){
	vis[v] = 1;
	int children = 0;
	pre[v] = low[v] = ++czas;
	for (auto x: graf[v]){
		if (x == pa) continue;
		if (vis[x]) low[v] = min(low[v], pre[x]);
		else {
			dfs(x, v);
			low[v] = min(low[v], low[x]);
			if (low[x] >= pre[v] && pa != -1){
				point[v] = 1;
			}
			children++;
		}
	}
	//if (pa == -1 && children > 1) point[v] = 1;
}

void init(int n){
	czas = 0;
	pre.assign(n+1, 0);
	low.assign(n+1, 0);
	vis.assign(n+1, 0);
	point.assign(n+1, 0);
}

void dfs2(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]){
			cnt[x] = cnt[v];
			if (low[x] >= pre[v]) cnt[x]+=point[v];
			dfs2(x);
		}
	}
}

void solve(){
	int n, m, T; cin >> n >> m >> T;
	init(n);
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(T);
	vis.assign(n+1, 0);
	cnt.assign(n+1, 0);
	dfs2(T);
	rep(i, 1, n+1) cout << cnt[i] << " ";
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
