//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using pii_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
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

const int MAX = 3e5+1, INF = 1e9+7;
set<int>graf[MAX];
int parent[MAX], pre[MAX], post[MAX], cc[MAX];
int czas, t = 1;
pii_set s[MAX];
ordered_set kth;

void dfs(int v, int pa = 1){
	parent[v] = pa;
	pre[v] = ++czas;
	s[t].insert({pre[v], v});
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, v);
		}
	}
	post[v] = ++czas;
}

int KTH(int l) {
	auto p = kth.find_by_order(l-1);
	kth.erase(p);
	return (int)(*p);
}

int subsize(int v) {
	int a = s[cc[v]].order_of_key({post[v], INF});
	int b = s[cc[v]].order_of_key({pre[v], 0});
	return a-b;
}

void fix(int v, int p, int nc) {
	s[cc[v]].erase(s[cc[v]].find({pre[v], v}));
	cc[v] = nc;
	s[nc].insert({pre[v], v});
	
	for (auto x: graf[v]) {
		if (x!=p){
			fix(x, v, nc);
		}
	}
}

int solve(int v){
	int sz = sz(s[cc[v]]);
	graf[v].erase(graf[v].find(parent[v]));
	graf[parent[v]].erase(graf[parent[v]].find(v));
	return 0;
	if (subsize(v) >= sz/2) fix(parent[v], parent[v], ++t);
	else fix(v, v, ++t);
	return sz(s[cc[v]]);
}

void solve(){
	int n, x; cin >> n >> x;
	vi g(n);
	rep(i, 1, n-1) cin >> g[i];
	rep(i, 2, n+1) kth.insert(i);
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].insert(b);
		graf[b].insert(a);
	}
	rep(i, 1, n+1) cc[i] = 1;
	dfs(1, 1);
	

	int i = 1, y = 1;
	while (!kth.empty()){
		y = solve(x);
		cout << y << "\n";
		if (kth.empty()) break;
		int l = (y+g[i])%(n - i - 1) + 1;
		x = KTH(l);
		++i;
		return;
   }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
