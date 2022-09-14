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
#define memo(x, val) memset(x, val, sizeof(x))
#define debug(x) cerr << x << " "


const int MAX = 102;
vi graf[MAX], gt[MAX], post, numer;
vb vis;
LD dp[MAX][MAX][MAX];
const LD INF = -1e16;
int nr;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x);
	}
	post.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	numer[v] = nr;
	for (auto x: gt[v]){
		if (!vis[x]) dfs2(x);
	}
}

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 0, MAX){
		rep(j, 1, n+1){
			rep(k, 1, n+1){
				dp[i][j][k] = INF;
			}
		}
	}
	rep(i, 1, n+1) dp[0][i][i] = 0;
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		graf[a].pb(b);
		gt[b].pb(a);
		dp[1][a][b] = (LD)c;
	}
	vis.assign(n+1, 0);
	numer.assign(n+1, 0);
	rep(i, 1, n+1){
		if (!vis[i]) dfs(i);
	}
	vis.assign(n+1, 0);
	repd(i, sz(post)-1, 0){
		if (!vis[post[i]]){
			nr++;
			dfs2(post[i]);
		}
	}
	LD ans = 0;
	rep(len, 1, n+1){
		rep(i, 1, n+1){
			rep(j, 1, n+1){
				if (numer[i]!=numer[j]) continue;
				rep(k, 1, n+1){
					dp[len][i][j] = max(dp[len][i][j], dp[len-1][i][k]+dp[1][k][j]);
				}
			}
		}
	}
	rep(len, 1, n+1){
		rep(v, 1, n+1){
			ans = max(ans, (LD)dp[len][v][v]/(LD)(len));
		}
	}
	cout << setprecision(4) << fixed << ans << "\n";
}



int main(){
	solve();
}

