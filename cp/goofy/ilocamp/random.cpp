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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

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

int n;
const int MAX = 1e5+7, Q = 1e4+1, INF = 1e9+7;
vi graf[MAX], dist;
vb vis;
pii query[Q];


int losuj(int a, int b){ return a+rand()%(b-a+1);}

 

void bfs(int v){
	vis.assign(n+1, 0);
	vis[v] = 1;
	dist[v] = 0;
	queue<int>k;
	k.push(v);
	while (!k.empty()){
		v = k.front();
		k.pop();
		for (auto x: graf[v]){
			if (!vis[x]){
				vis[x] = 1;
				k.push(x);
				dist[x] = dist[v]+1;
			}
		}
	}
}


void solve(){
	srand(2137);
	int m; cin >> n >> m;
	dist.resize(n+1);
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	int p; cin >> p;
	rep(i, 0, p) cin >> query[i].st >> query[i].nd;
	vi ans(p+1, INF);
	rep(i, 0, 200){
		int c = losuj(1, n);
		dist.assign(n+1, INF);
		bfs(c);
		rep(j, 0, p) ans[j] = min(ans[j], dist[query[j].st]+dist[query[j].nd]);
	}
	rep(i, 0, p) cout << ((ans[i]==INF)?-1:ans[i]) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
