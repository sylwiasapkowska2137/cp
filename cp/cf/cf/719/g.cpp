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
#define memo(x, val) memset(x, val, sizeof(x))
#define debug(x) cerr << x << " "

const int MAX = 2137;
const LL INF = 1e18+7;
LL dist[MAX][MAX];
int graf[MAX][MAX]; 
int x[] = {-1, 1, 0, 0}, y[] = {0, 0, -1, 1};

void bfs(int a, int b, int n, int m, int w){
	queue<pii>q;
	dist[a][b] = 0;
	q.push({a, b});
	while (!q.empty()){
		pii v = q.front(); q.pop();
		rep(i, 0, 4){
			pii s = {v.st+x[i], v.nd+y[i]};
			if (s.st < 1 || s.st > n || s.nd < 1 || s.nd > m) continue;
			if (dist[s.st][s.nd]!=INF) continue;
			if (graf[s.st][s.nd] == -1) continue;
			dist[s.st][s.nd] = dist[v.st][v.nd]+w;
			q.push(s);
		}
	}
}

void solve(){
	int n, m, w;
	LL A = INF, B = INF;
	cin >> n >> m >> w;
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			cin >> graf[i][j];
			dist[i][j] = INF;
		}
	}
	bfs(1, 1, n, m, w);
	cerr << "\n";
	LL ans = min(INF, dist[n][m]);
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			//if (dist[i][j]==INF) debug("-1");
			//else debug(dist[i][j]);
			if (graf[i][j] > 0) A = min(A, dist[i][j]+graf[i][j]);
			dist[i][j] = INF;
		}
		//cerr << "\n";
	}
	
	bfs(n, m, n, m, w);
	cerr << "\n";
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			//if (dist[i][j]==INF) debug("-1");
			//else debug(dist[i][j]);
			if (graf[i][j] > 0) B = min(B, dist[i][j]+graf[i][j]);
		}
		//cerr << "\n";
	}
	ans = min(ans, A+B);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}


