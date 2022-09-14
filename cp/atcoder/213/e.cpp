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

const int MAX = 507, INF = 1e9+7;
char graf[MAX][MAX];
int dist[MAX][MAX];
int X0[] =  {1, -1, 0, 0}, Y0[] = {0, 0, 1, -1};
int h, w;

void bfs(){
	deque<pii>q;
	q.pb({1, 1});
	dist[1][1] = 0;
	while (!q.empty()){
		pii v = q.front();
		q.pop_front();
		
		//push front o wadze 0 czyli sasiedzi
		rep(i, 0, 4){
			pii s = {v.st+X0[i], v.nd+Y0[i]};
			if (s.st >= 1 && s.st <= h && s.nd >= 1 && s.nd <= w){
				if (dist[v.st][v.nd]<dist[s.st][s.nd] && graf[s.st][s.nd] == '.'){
					dist[s.st][s.nd] = dist[v.st][v.nd];
					q.push_front(s);
				}
			}
		}
		
		rep(i, -2, 3){
			rep(j, -2, 3){
				if (abs(i) + abs(j) == 4) continue;
				pii s = {v.st+i, v.nd+j};
				if (s.st >= 1 && s.st <= h && s.nd >= 1 && s.nd <= w){
					if (dist[v.st][v.nd]+1<dist[s.st][s.nd]){
						dist[s.st][s.nd] = dist[v.st][v.nd]+1;
						q.pb(s);
					}
				}
			}
		}
	}
}

void solve(){
	cin >> h >> w;
	rep(i, 1, h+1){
		rep(j, 1, w+1){
			cin >> graf[i][j];
			dist[i][j] = INF;
		}
	}
	bfs();
	cout << dist[h][w] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
