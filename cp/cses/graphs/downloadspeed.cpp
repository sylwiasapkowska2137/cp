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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
const LL INF = 1e18+7;

LL bfs(int s, int t, vi &parent, vvll&cap, vvi&graf, int&n){
	parent.assign(n+1, -1);
	parent[s] = -2;
	queue<pair<int, LL>>q;
	q.push({s, INF});
	while (!q.empty()){
		int v = q.front().st;
		LL flow = q.front().nd;
		q.pop();
		
		for (auto x: graf[v]){
			if (parent[x] == -1 && cap[v][x]){
				parent[x] = v;
				LL new_flow = min(flow, cap[v][x]);
				if (x == t) return new_flow;
				q.push({x, new_flow});
			}
		}
	}
	return 0LL;
}

LL maxflow(int s, int t, vvll&cap, vvi&graf, int&n){
	LL flow = 0;
	vi parent(n+1, 0);
	while (1){
		LL new_flow = bfs(s, t, parent, cap, graf, n);
		if (!new_flow) break;
		flow += new_flow;
		int curr = t;
		while (curr != s){
			int prev = parent[curr];
			cap[prev][curr] -= new_flow;
			cap[curr][prev] += new_flow;
			curr = prev;
			//debug(curr);
		}
		//debug(cap);
	}
	return flow;
}

void solve(){
	int n, m; cin >> n >> m;
	vvll cap(n+1, vll(n+1, 0));
	vvi graf(n+1, vi());
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		graf[a].pb(b);
		graf[b].pb(a);
		cap[a][b] += c;
		//cap[b][a] -=c;
	}
	//debug(graf);
	cout << maxflow(1, n, cap, graf, n) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
