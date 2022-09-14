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

int n, m, k; 
map<pii, vpii>fb;
map<pii, bool>vis;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

void dfs(int a, int b){
	vis[{a, b}] = 1;
	rep(i, 0, 4){
		pii s = {a+x[i], b+y[i]};
		if (s.st >= 1 && s.nd >= 1 && s.st <= n && s.nd <= m){
			bool ok = 1;
			for (auto V: fb[{a, b}]){
				if (s==V) {
					ok = 0;
					break;
				}
			}
			
			if (ok && !vis[s]) {
				debug(a, b, s);
				dfs(s.st, s.nd);
			}
		}
	}
}

void solve(){
	cin >> n >> m >> k;
	rep(i, 0, k){
		pii a, b; 
		cin >> a.st >> a.nd;
		cin >> b.st >> b.nd;
		fb[a].pb(b);
		fb[b].pb(a);
		vis.clear();
		int nr = 0;
		bool ok = 1;
		debug(a, b);
		rep(X, 1, n+1){
			rep(Y, 1, m+1){
				debug(X, Y);
				if (vis.find({X, Y}) == vis.end()){
					if (nr == 1){
						ok = 0;
						break;
					}
					dfs(X, Y);
					nr++;
				}
			}
			if (nr == 1) break;
		}
		if (ok) cout << "TAK\n";
		else {
			cout << "NIE\n";
			fb[a].pop_back();
			fb[b].pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
