#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
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
vi graf[MAX], color, vis;
bool ok = 0;

bool dfs(int v){
	for (auto x: graf[v]){
		if (!vis[x]){
			color[x] = !color[v];
			vis[x] = 1;
			if (!dfs(x)) return 0;
		} else if (color[x] == color[v]) return 0;
	}
	return 1;
}

void solve(){
	int n, m;
	LL x = 0;
	cin >> n >> m;
	vi c(n+1), t(n+1);
	rep(i, 1, n+1) cin >> c[i];
	rep(i, 1, n+1) cin >> t[i];
	rep(i, 1, n+1) x+= (LL)(t[i]-c[i]);
	
	rep(i, 1, n+1) graf[i].clear();
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	if (x&1){
		cout << "NO\n";
		return;
	}
	color.assign(n+1, 0);
	vis.assign(n+1, 0);
	vis[1] = 1;
	color[1] = 0;
	bool ok = dfs(1);
	if (ok){
		//rep(i, 1, n+1) debug(color[i]);
		//cerr << "\n";
		LL a = 0, b = 0;
		rep(i, 1, n+1){
			if (color[i]) a += (LL)(t[i]-c[i]);
			else b += (LL)(t[i]-c[i]);
		}
		debug(a);
		debug(b);
		if (a == b) cout << "YES\n";
		else cout << "NO\n";
	} else cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
