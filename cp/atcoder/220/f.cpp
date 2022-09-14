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
vi graf[MAX];
vll ans, Count;
int n;

void dfs(int v, int parent) {
	for (auto x: graf[v]){
		if (x != parent) {
			dfs(x, v);
			Count[v] += Count[x];
			ans[v] += ans[x] + Count[x];
		}
	}
}

void dfs2(int v, int parent) {
	for (auto x: graf[v]){
		if (x != parent) {
			ans[x] = ans[v] - Count[x] + n - Count[x];
			dfs2(x, v);
		}
	}
}

void solve(){
	cin >> n;
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	ans.assign(n+1, 0);
	Count.assign(n+1, 1);
	dfs(1, -1);
	dfs2(1, -1);
	rep(i, 1, n+1) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
