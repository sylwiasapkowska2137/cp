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

const int MAX = 5e5+7;
vi graf[MAX], G[MAX];

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	vi good(n+1, 0);
	queue<int>q;
	q.push(1);
	vb vis(n+1, 0);
	while (!q.empty()){
		int v = q.front(); q.pop();
		vis[v] = 1;
		for (auto x: graf[v]){
			if (!vis[x]) {
				good[x]++;
				G[v].pb(x);
				if (good[x]*2 == sz(graf[x]) && x >= 3) q.push(x);
			}
		}
	}
	/*
	cerr << "\n";
	rep(v, 1, n+1){
		for (auto x: G[v]){
			debug(v);
			debug(x);
			cerr << "\n";
		}
	}
	*/
	rep(i, 3, n+1){
		if (sz(G[i])*2 != sz(graf[i])){
			cout << "NIE\n";
			exit(0);
		}
	}
	if (sz(G[1])!=sz(graf[1]) || sz(G[2])!=0){
		cout << "NIE\n";
		exit(0);
	}
	vi in(n+1, 0), topo;
	rep(v, 1, n+1) for (auto x: G[v]) in[x]++;
	rep(v, 1, n+1) if (!in[v]) q.push(v);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		topo.pb(v);
		for (auto x: G[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	vi ans(n+1);
	//for (auto x: topo) debug(x);
	//cerr << "\n";
	
	int x = 0;
	rep(i, 0, n) ans[topo[i]] = ++x;
	cout << "TAK\n";
	rep(i, 1, n+1) cout << ans[i] << " ";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
