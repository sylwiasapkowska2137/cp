//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "kablib.h"
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

bool parity(vi &tab, int x, int y){
	for (auto &v: tab) v++; 
	int res = wez(tab);
	if (sz(tab) % 2 == 0) res^=x;
	return (res == y);
}

int binsearch(vi &a, int x, int y){
	int bits = 32-__builtin_clz(sz(a));
	if (sz(a) == (1<<(bits-1))) bits--;
	int ans = -1;
	repd(i, bits-1, 0){
		if (ans+(1<<i)<sz(a)) {
			ans += (1<<i);
			vi query;
			rep(j, 0, ans+1){
				query.pb(a[j]);
			}
			if (parity(query, x, y)){
				ans -= (1<<i);
			}
		}
	}
	return a[ans+1];
}

void solve(){
	vi tmp = init();
	int n = tmp[0];
	int x = tmp[1];
	int y = tmp[2];
	tmp.clear();
	int initqueries = 0;
	for (int i = 1; i<n; i*=2){
		vi a[2] = {vi(), vi()};
		rep(j, 0, n) a[(j/i)%2].pb(j);
		bool t = parity(a[0], x, y);
		if (t) break;
		initqueries++;
	}
	int last = (1<<initqueries);
	vi bsrange;
	vb good(n, 1);
	rep(j, 0, n){
		if ((j/last)&1){
			bsrange.pb(j);
			good[j] = 0;
		}
	}
	int a = binsearch(bsrange, x, y);
	rep(i, 0, initqueries){
		int len = (1<<i);
		rep(j, 0, n){
			if ((a/len)%2 != (j/len)%2) {
				good[j] = 0;
			}
		}
	}
	bsrange.clear();
	rep(i, 0, n){
		if (good[i]){
			bsrange.pb(i);
		}
	}
	int b = binsearch(bsrange, x, y);
	if(a > b) swap(a, b);
	odpowiedz(a+1, b+1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
