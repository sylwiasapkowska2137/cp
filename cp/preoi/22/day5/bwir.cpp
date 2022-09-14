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

const int MAX = 3e5+7;
vi graf[MAX];
vi pa;
set<pii>s;
int y;

void dfs(int v, int pa = -1){
	y++;
	for (auto x: graf[v]){
		if (x!=pa && s.find({x, v}) == s.end()){
			dfs(x, v);
		}
	}
}

void dfsp(int v, int par = 1){
	pa[v] = par;
	for (auto x: graf[v]){
		if (x!=par){
			dfsp(x, v);
		}
	}
}

void solve(){
	int n, x1; cin >> n >> x1;
	vi g(n-2);
	pa.assign(n+1, 0);
	rep(i, 1, n-1) cin >> g[i];
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfsp(1);
	
	vi parent(n+1, 1);
	parent[1] = 0; 
	y = 0;
	s.insert({x1, pa[x1]});
	s.insert({pa[x1], x1});
	parent[x1] = 0;
	dfs(x1);
	cout << y << "\n";
	rep(i, 1, n-1){
		int l = (g[i]+y)%(n-i-1)+1;
		//debug(l);
		rep(j, 2, n+1){
			l-=parent[j];
			if (!l){
				x1 = j;
				break;
			}
		}
		debug(x1);
		y = 0;
		s.insert({x1, pa[x1]});
		s.insert({pa[x1], x1});
		parent[x1] = 0;
		dfs(x1);
		cout << y << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
