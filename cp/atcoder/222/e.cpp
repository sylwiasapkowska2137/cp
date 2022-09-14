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

const int MAXN = 1007, MAXM = 107, MAXK = 1e5+7, MOD = 998244353;
int ile[MAXN][MAXN];
vi graf[MAXN], pa, depth;
int dp[MAXN][2*MAXK+1];

void dfs(int v, int par = -1){
	for (auto x: graf[v]){
		if (x!=par){
			pa[x] = v;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	}
}

void restore_edges(int a, int b){
	if (depth[a]<depth[b]) swap(a, b);
	//a glebiej
	int k = depth[a]-depth[b];
	while (k){
		ile[a][pa[a]]++;
		ile[pa[a]][a]++;
		a = pa[a];
		k--;
	}
	while (pa[a]!=pa[b]){
		ile[a][pa[a]]++;
		ile[pa[a]][a]++;
		a = pa[a];
		ile[b][pa[b]]++;
		ile[pa[b]][b]++;
		b = pa[b];
	}
}

LL count_dp(vi tab, int K){
	int n = sz(tab);
	for (auto x: tab) debug(x);
	dp[0][MAXK] = 1;
	rep(i, 1, n+1){
		rep(j, 0, 2*MAXK){
			if (j>=tab[i-1] && j+tab[i-1]<=2*MAXK) {
				dp[i][j] = dp[i-1][j-tab[i-1]]+dp[i-1][j+tab[i-1]];
				if (dp[i][j]>=MOD) dp[i][j]%=MOD;
			}
			//debug(dp[i][j]);
		}
		//cerr << "\n";
	}
	return dp[n][MAXK+K];
}

void solve(){
	int n, m, K; cin >> n >> m >> K;
	vi path(m);
	rep(i, 0, m) cin >> path[i];
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	pa.assign(n+1, 1);
	depth.assign(n+1, 0);
	dfs(1);
	rep(i, 1, m) restore_edges(path[i], path[i-1]);
	vi tab;
	int S = 0;
	LL mul = 1;
	rep(i, 1, n+1){
		for (auto x: graf[i]){
			if (i > x) {
				if (ile[i][x] == 0) mul = (mul*2)%MOD;
				else tab.pb(ile[i][x]);
				S+=ile[i][x];
			}
		}
	}
	if((S+K)%2 || S+K<0){
		cout << 0;
		return;
	}
	//ile sposobów by otrzymac sumę k
	LL x = count_dp(tab, K);
	x = (x*mul)%MOD;
	cout << x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
