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
int n, m, k, l;
vvi t;

vi solve1d(vi v, int s){
	vi mini;
	deque<int>q;
	rep(i, 0, s){
		while (!q.empty() && q.back() > v[i]) q.pop_back();
		q.pb(v[i]);
	}
	mini.pb(q.front());
	rep(i, s, sz(v)){
		while (!q.empty() && q.back() > v[i]) q.pop_back();
		q.pb(v[i]);
		if (!q.empty() && q.front() == v[i-s]) q.pop_front();
		mini.pb(q.front());
	}
	return mini;
}

void solve(){
	cin >> n >> m >> k >> l;
	t.assign(n+1, vi(m+1));
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			cin >> t[i][j];
		}
	}
	vvi col;
	col.assign(n, vi(m));
	rep(j, 1, m+1){
		vi tmp(n);
		rep(i, 1, n+1) tmp[i-1]=t[i][j];
		int i=0;
		for (auto x: solve1d(tmp, k)) col[i++][j-1] = x;
	}
	rep(i, 0, n-k+1){
		for (auto x: solve1d(col[i], l)) cout << x << " ";
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
