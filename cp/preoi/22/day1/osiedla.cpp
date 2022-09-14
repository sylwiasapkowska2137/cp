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

struct query{
	pii a, b;
};

struct DSU{
	vector<vpii> REP;
	
	void init(int n, int m){
		REP.resize(n+1,vpii(m+1));
		rep(i, 0, n+1){
			rep(j, 1, m+1){
				REP[i][j] = {i, j};
			}
		}
	}
	
	pii Find(int a, int b){
		if (REP[a][b] == make_pair(a, b)) return {a, b};
		return REP[a][b] = Find(REP[a][b].st, REP[a][b].nd);
	}
	
	bool Union(pii a, pii b){
		a = Find(a.st, a.nd);
		b = Find(b.st, b.nd);
		if (a == b) return 0;
		REP[b.st][b.nd] = a;
		return 1;
	}
};

int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

map<pii, vpii>conn;

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<query>Q(q);
	rep(i, 0, q){
		pii a, b; cin >> a.st >> a.nd;
		cin >> b.st >> b.nd;
		conn[a].pb(b);
		conn[b].pb(a);
		Q[i] = {a, b};
	}
	DSU dsu;
	dsu.init(n, m);
	reverse(all(Q));
	
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			rep(k, 0, 4){
				pii s = {i+x[k], j+y[k]};
				if (s.st >= 1 && s.nd >= 1 && s.st <= n && s.nd <= m){
					bool ok = 1;
					for (auto x: conn[s]){
						if (x == make_pair(i, j)){
							ok = 0;
							break;
						}
					}
					if (ok) {
						dsu.Union({i, j}, s);
						//debug(i, j, s.st, s.nd);
					}
				}
			}
		}
	}
	
	vi ans;
	for (auto [a, b]:Q){
		bool x = dsu.Union(a, b);
		ans.pb(x);
	}
	reverse(all(ans));
	for (auto x: ans) {
		if (!x) cout << "TAK\n";
		else cout << "NIE\n";
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
