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

const int MAX = 1e5+7;
vpii graf[MAX];
vi XOR;

void dfs(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x.st != pa){
			XOR[x.st] = XOR[v] ^ x.nd;
			dfs(x.st, v);
		}
	}
}

void solve(){
	int n; cin >> n;
	rep(i, 1, n){
		int a, b, c; cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	XOR.assign(n+1, 0);
	dfs(1);
	//rep(i, 1, n+1) debug(XOR[i]);
	//cerr << "\n";
	vll on(25, 0), off(25, 0), pow(25);
	pow[0] = 1;
	rep(i, 1, 25) pow[i] = pow[i-1]*2;
	rep(i, 1, n+1){
		rep(j, 0, 25){
			if (XOR[i]&(1<<j)) on[j]++;
			else off[j]++;
		}
	}
	LL ans = 0LL;
	rep(i, 0, 25){
		ans += (LL)(pow[i]*on[i]*off[i]);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
