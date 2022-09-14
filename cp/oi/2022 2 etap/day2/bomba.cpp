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
vector<vector<int>>dist[3];
vector<vector<pii>>from[3];
int n;
pii s, e;
int x[] = {-1, 1, 0, 0}, y[] = {0, 0, -1, 1};


void dijkstra(){
	queue<pair<pii, pii>>q;
	q.push({{0, 0}, s});
	dist[0].assign(n+2, vi(n+2, INF));
	dist[1].assign(n+2, vi(n+2, INF));
	dist[2].assign(n+2, vi(n+2, INF));
	from[0].resize(n+2, vpii(n+2));
	from[1].resize(n+2, vpii(n+2));
	from[2].resize(n+2, vpii(n+2));
	dist[0][s.st][s.nd] = 0;
	from[0][s.st][s.nd] = {-1, -1};
	while (!q.empty()){
		pii v = q.front().nd;
		int state = q.front().st.nd;
		int d = q.front().st.st;
		q.pop();
		debug(v, d, state);
		rep(i, 0, 4){
			pii s = {v.st+x[i], v.nd+y[i]};
			if (s.st >= 1 && s.nd >= 1 && s.st <= n && s.nd <= n){
				if (tab[s.st][s.nd] != 'X'){
					
					if (tab[s.st][s.nd] == '#'){
						//find new state
						int newstate = state;
						if (state == 0) newstate = 1;
						else if (state == 1){
							if (from[state][v.st][v.nd].st == s.st || from[state][v.st][v.nd].nd == s.nd) newstate = 1;
							else {
								//jesli istnieje niczym nie zaslonieta sciezka od 
								if (check(from[state][v.st][v.nd], s))	newstate = 2;
								else continue;
							}
						} else if (state == 2){
							if (from[state][v.st][v.nd].st == s.st || from[state][v.st][v.nd].nd == s.nd){
								newstate = 2;
							} else continue;
						}
						
						if (dist[newstate][s.st][s.nd] == INF){
							dist[newstate][s.st][s.nd] = d+1;
							from[newstate][s.st][s.nd] = v;
							q.push({{d+1,newstate}, s});
						}
					} else {
						if (dist[state][s.st][s.nd] == INF){
							dist[state][s.st][s.nd] = d+1;
							from[state][s.st][s.nd] = from[state][v.st][v.nd];
							q.push({{d+1,state}, s});
						}
					}
				}
			}
		}
	}
}

void solve(){
	cin >> n;
	tab.resize(n+2, vector<char>(n+2));
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			cin >> tab[i][j];
			if (tab[i][j] == 'P') s = {i, j};
			if (tab[i][j] == 'K') e = {i, j};
		}
	}
	dijkstra();
	int ans = INF;
	rep(i, 0, 3){
		ans = min(ans, dist[i][e.st][e.nd]);
		debug(dist[i][e.st][e.nd]);
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
