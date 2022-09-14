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
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
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
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int INF = 1e9+7;
vector<vector<char>>tab;
int ans = INF;
int n;
int x[] = {-1, 1, 0, 0}, y[] = {0, 0, -1, 1};

void solve(){
	cin >> n;
	tab.assign(n+2, vector<char>(n+2, 'X'));
	pii S, e;
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			cin >> tab[i][j];
			if (tab[i][j] == 'P') S = {i, j};
			if (tab[i][j] == 'K') e = {i, j};
		}
	}
	
	vector<vi> dist(n+2, vi(n+2, INF));
	dist[e.st][e.nd] = 0;
	rep(i, 0, 4){
		if (tab[e.st+x[i]][e.nd+y[i]] == '#') {
			dist[e.st+x[i]][e.nd+y[i]] = 1;
		}
	}
	queue<pii>q;
	q.push(e);
	while(!q.empty()){
		pii v = q.front();
		q.pop();
		rep(i, 0, 4){
			pii s = {v.st+x[i], v.nd+y[i]};
			if (dist[s.st][s.nd] == INF && tab[s.st][s.nd] != '#' && tab[s.st][s.nd] != 'X'){
				dist[s.st][s.nd] = dist[v.st][v.nd]+1;
				q.push(s);
			}
		}
	}

	vector<vector<vi>> vis(n+2, vector<vi>(n+2, vi(5, INF)));
	
	q.push(S);
	vis[S.st][S.nd][0] = 0;
	while (!q.empty()){
		pii v = q.front(); q.pop();
		rep(i, 0, 4){
			pii s = {v.st+x[i], v.nd+y[i]};
			if (s.st >= 1 && s.nd >= 1 && s.st <= n && s.nd <= n){
				if (tab[s.st][s.nd] == '.'){
					
					if (vis[s.st][s.nd][0] == INF){
						vis[s.st][s.nd][0] = vis[v.st][v.nd][0]+1;
						q.push(s);
					}
					
				} else if (tab[s.st][s.nd] == '#'){
					
					bool ok = 0;
					if (vis[s.st][s.nd][1] == INF){
						vis[s.st][s.nd][1] = vis[v.st][v.nd][0]+1;
						ok = 1;
					}
					if (vis[s.st][s.nd][2] == INF){
						vis[s.st][s.nd][2] = vis[v.st][v.nd][0]+1;
						ok = 1;
					}
					if (ok) q.push(s);
				}
			}
		}
		
		rep(i, 0, 2){
			pii s = {v.st+x[i], v.nd+y[i]};
			if(tab[s.st][s.nd] != 'X'){
				if(vis[s.st][s.nd][1]==INF){
					vis[s.st][s.nd][1] = vis[v.st][v.nd][1]+1;
					q.push(s);
				}
			}
		}
		rep(i, 2, 4){
			pii s = {v.st+x[i], v.nd+y[i]};
			if(tab[s.st][s.nd] != 'X'){
				if(vis[s.st][s.nd][4]==INF){
					vis[s.st][s.nd][4] = vis[v.st][v.nd][1]+1;
					q.push(s);
				}
			}
		}
		
		
		rep(i, 0, 2){
			pii s = {v.st+x[i], v.nd+y[i]};
			if(tab[s.st][s.nd]!='X'){
				if(vis[s.st][s.nd][3] == INF){
					vis[s.st][s.nd][3] = vis[v.st][v.nd][2]+1;
					q.push(s);
				}
			}
		}
		rep(i, 2, 4){
			pii s = {v.st+x[i], v.nd+y[i]};
			if(tab[s.st][s.nd]!='X'){
				if(vis[s.st][s.nd][2] == INF){
					vis[s.st][s.nd][2] = vis[v.st][v.nd][2]+1;
					q.push(s);
				}
			}
		}
		rep(i, 0, 2){
			pii s = {v.st+x[i], v.nd+y[i]};
			if(tab[s.st][s.nd]!='X'){
				if(vis[s.st][s.nd][3] == INF){
					vis[s.st][s.nd][3] = vis[v.st][v.nd][3]+1;
					q.push(s);
				}
			}
		}
		rep(i, 2, 4){
			pii s = {v.st+x[i], v.nd+y[i]};
			if (tab[s.st][s.nd] != 'X'){
				if (vis[s.st][s.nd][4] == INF){
					vis[s.st][s.nd][4] = vis[v.st][v.nd][4]+1;
					q.push(s);
				}
			}
		}
		
	}

	rep(i, 1, n+1){
		rep(j, 1, n+1){
			int tmp = INF;
			rep(k, 0, 5) tmp = min(tmp, vis[i][j][k]);
			ans = min(ans, tmp+dist[i][j]);
		}
	}
	
	if (ans == INF) cout << "NIE\n";
	else cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
