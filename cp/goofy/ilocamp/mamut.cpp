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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}


vector<bool>vis;
vi order;
vpll points;
int n;

LL dist(pll a, pll b){
	return (a.st-b.st)*(a.st-b.st)+(a.nd-b.nd)*(a.nd-b.nd);
}

void dfs(int v){
	vis[v] = 1;
	order.pb(v);
	int ans = v;
	LL best = 0;
	rep(i, 0, n){
		LL d = dist(points[v], points[i]);
		if (d > best && !vis[i]){
			best = d;
			ans = i;
		}
	}
	if (ans == v) return;
	dfs(ans);
}

void solve(){
	cout << "TAK\n";
	cin >> n;
	points.resize(n);
	vis.assign(n, 0);
	for (int i = 0; i<n; i++){
		cin >> points[i].st >> points[i].nd;
	}
	dfs(0);
	for (auto x: order) cout << x+1 << " ";
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
