#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "

struct E{
	int a, b, c;
};

LL ans = 0LL;

bool cmp(E a, E b){
	return a.c < b.c;
}

struct DSU{
	vi REP, SIZE;
	
	DSU(int n) {
		REP.resize(n+1);
		SIZE.resize(n+1);
		rep(i, 1, n+1) {
			REP[i] = i;
			SIZE[i] = 1;
		}
	}
	
	int Find(int a){
		if (a == REP[a]) return a;
		return REP[a] = Find(REP[a]);
	}
	
	void Union(int x, int y, LL c){
		int a = Find(x);
		int b = Find(y);
		if (a == b) {
			if (c < 0) ans-=c;
			return;
		}
		if (SIZE[a]<SIZE[b]) swap(a, b);
		SIZE[a]+=SIZE[b];
		REP[b] = a;
		//if (c < 0) c = -c;
		ans-=c;
	}
};


void solve(){
	int n, m; cin >> n >> m;
	vector<E>edges;
	rep(i, 0, m){
		int a, b, c; 
		cin >> a >> b >> c;
		edges.pb({a, b, c});
		ans+=(LL)c;
	}
	sort(all(edges), cmp);
	DSU dsu(n);
	rep(k, 0, m) dsu.Union(edges[k].a, edges[k].b, edges[k].c);
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
