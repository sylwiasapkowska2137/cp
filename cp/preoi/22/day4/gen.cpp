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
const int MAX = 2e5+7, INF = 1e9+7;
vpii graf[MAX];
vi dist;

void dfs(int v, int pa = -1){
	for (auto [x, c]:graf[v]){
		if (x != pa){
			dist[x] = dist[v]+c;
			dfs(x, v);
		}
	}
}


void solve(){
	int n = p(2, 10);
	int q = p(1, 20);
	cout << n << " " << q << "\n";
	int toadd = n-1, added = 0;
	while (1){
		int x = p(0, 1);
		if (toadd && x){
			//szukamy krawedzi do dodania
			int a = p(1, n);
			dist.assign(n+1, INF);
			dist[a] = 0;
			dfs(a);
			int b = p(1, n);
			while (dist[b] != INF) b = p(1, n);
			int c = p(1, 10);
			cout << "B " << a << " " << b << " " << c <<  "\n";
			toadd--;
			added++;
			graf[a].pb({b, c});
			graf[b].pb({a, c});
			q--;
		} else if (added) {
			int a = p(1, n);
			dist.assign(n+1, INF);
			dist[a] = 0;
			dfs(a);
			int b = p(1, n);
			while (dist[b] == INF) b = p(1, n);
			cout << "P " << a << " " << b << "\n";
			//szukamy a i b do zapytania
			
			q--;
		}
		if (!q) break;
	}

}

void solve2(){
	int n = p(1, 200);
	int L = p(1, 200);
	//cout << n << " " << L << "\n";
	vector<string>s;
	rep(i, 0, n){
		string t;
		rep(j, 0, L) t.pb((char)(p(0, 2)+'a'));
		s.pb(t);
	}
	sort(all(s));
	s.erase(unique(all(s)), s.end());
	cout << sz(s) << " " << L << '\n';
	for (auto x: s) cout << x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve2();
	
	return 0;
}
