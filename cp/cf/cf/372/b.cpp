//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

struct E{
	int a, b, c;
	E() {}
	E(int a, int b, int c): a(a), b(b), c(c) {}
};

const int MAX = 1007;
const LL INF = 1e18;
vpii graf[MAX];
vector<E>bad;
vll dist;
vb vis;
int n, k;


void print(){
	cout << "YES\n";
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			if (v>x.st) cout << v << " " << x.st << " " << x.nd << "\n";
		}
	}
}

void dijkstra(int S, int t, int L, int BAD, E added = {0, 0, 0}){
	dist.assign(n+1, INF);
	vis.assign(n+1, 0);
	dist[S] = 0;
	set<pll>s;
	s.insert({0LL, S});
	while (!s.empty()){
		int v = s.begin()->nd;
		LL d = s.begin()->st;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto x: graf[v]){
			if (d+x.nd < dist[x.st]){
				dist[x.st] = d+x.nd;
				s.insert({dist[x.st], x.st});
			}
		}
	}
	
	if (!BAD){
		if (dist[t] < L){
			cout << "NO\n";
			exit(0);
		}
		if (dist[t] == L){
			print();
			for (auto x: bad){
				cout << x.a << " " << x.b << " " << INF << "\n";
			}
			exit(0);
		}
	} else if (BAD == 1){
		if (dist[t] < L){
			graf[added.a].back().nd = L-dist[t]+1;
			graf[added.b].back().nd = L-dist[t]+1;
		}
		if (dist[t] == L){
			print();
			rep(i, k+1, sz(bad)){
				cout << bad[i].a << " " << bad[i].b << " " << INF << "\n";
			}
			exit(0);
		}
	} else if (BAD == 2){
		if (dist[t] != L){
			cout << "NO\n";
			exit(0);
		}
		print();
		exit(0);
	}
}

void solve(){
	int m, L, s, t;
	cin >> n >> m >> L >> s >> t;
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		if (!c)	bad.pb({a, b, c});
		else {
			graf[a].pb({b, c});
			graf[b].pb({a, c});
		}
	}
	dijkstra(s, t, L, 0);
	for (k = 0; k<sz(bad); k++){
		E x = bad[k];
		graf[x.a].pb({x.b, 1});
		graf[x.b].pb({x.a, 1});
		dijkstra(s, t, L, 1, x);
		//print();
		//cerr << "\n";
	}
	bad.clear();
	dijkstra(s, t, L, 2);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
