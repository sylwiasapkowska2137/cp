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

const int MAX = 2e5+7;
vpii graf[MAX];
vb vis;

void dfs(int v, int mid){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (x.nd <= mid && !vis[x.st]){
			dfs(x.st, mid);
		}
	}
}

bool warunek(int mid, int n){
	vis.assign(n+1, 0);
	dfs(1, mid);
	int ans = 0;
	rep(i, 1, n+1) ans += vis[i];
	return (ans == n);
}

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb({b, i});
		graf[b].pb({a, i});
	}
	int l = 0, r = m, ans = -1;
	while (l!=r){
		int mid = (l+r)/2;
		if (warunek(mid, n)) {
			r = mid;
		} else l = mid+1;
	}
	if (l == m) cout << "NIE ISTNIEJE\n";
	else cout << l+1 << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
