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
//jeju ale nieelegancko nawet nie patrz nizej
const int MAX = 2e5+7;
vi graf[MAX], gt[MAX], numer, post, door[MAX], state;
vb vis;
int nr;

void dfs1(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs1(x);
		}
	}
	post.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	numer[v] = nr;
	for (auto x: gt[v]){
		if (!vis[x]){
			dfs2(x);
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	state.resize(n+1);
	rep(i, 1, n+1) cin >> state[i];
	rep(i, 1, m+1){
		int k; cin >> k;
		rep(j, 0, k){
			int x; cin >> x;
			door[x].pb(i);
		}
	}
	rep(i, 1, n+1){
		int a = door[i][0], b = door[i][1];
		if (state[i]){
			graf[a].pb(b);
			graf[b].pb(a);
			graf[m+a].pb(m+b);
			graf[m+b].pb(m+a);
			gt[a].pb(b);
			gt[b].pb(a);
			gt[m+a].pb(m+b);
			gt[m+b].pb(m+a);
		} else {
			graf[m+a].pb(b);
			graf[m+b].pb(a);
			graf[a].pb(m+b);
			graf[b].pb(m+a);
			gt[m+a].pb(b);
			gt[m+b].pb(a);
			gt[a].pb(m+b);
			gt[b].pb(m+a);
		}
	}
	vis.assign(2*m+1, 0);
	rep(i, 1, 2*m+1){
		if (!vis[i]) dfs1(i);
	}
	vis.assign(2*m+1, 0);
	numer.assign(2*m+1, 0);
	reverse(all(post));
	for (auto x: post){
		if (!vis[x]){
			nr++;
			dfs2(x);
		}
	}
	rep(i, 1, m+1){
		if (numer[i] == numer[i+m]) {
			cout << "NIE\n";
			return;
		}
	}
	cout << "TAK\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
