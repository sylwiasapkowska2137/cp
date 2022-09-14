/*
	Author: sysia
	16.01.2022 10:58:05
*/

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

struct Edge{
	pii from, to;
	LL health;
};

const int MAX = 1e5+7;
const LL INF = 1e18+7, INF2 = 1e15;
map<int, vll>mapa, dp;
map<int, vi>isway;
map<int, vector<Edge>>edge;

void clear(int n){
	mapa.clear();
	dp.clear();
	edge.clear();
	isway.clear();
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	clear(n+1);
	vll lost(n+1);
	rep(i, 1, n+1) cin >> lost[i];
	mapa[1].pb(1);
	mapa[n].pb(m);
	rep(i, 0, k){
		pii a, b; int h;
		cin >> a.st >> a.nd >> b.st >> b.nd >> h;
		mapa[a.st].pb(a.nd);
		mapa[b.st].pb(b.nd);
		edge[a.st].pb({a, b, h});
	}
	rep(i, 1, n+1) {
		sort(all(mapa[i]));
		mapa[i].erase(unique(all(mapa[i])), mapa[i].end());
		dp[i].assign(sz(mapa[i]), INF);
		isway[i].assign(sz(mapa[i]), 0);
	}
	
	for (auto x: mapa){
		int row = x.st;
		
		if (row == 1) {
			dp[1].front() = 0;
			isway[1].front() = 1;
		}
		rep(i, 1, sz(x.nd)){
			dp[row][i] = min(dp[row][i], dp[row][i-1]+lost[row]*(x.nd[i]-x.nd[i-1]));
			isway[row][i] |= isway[row][i-1];
		}
		repd(i, sz(x.nd)-2, 0){
			dp[row][i] = min(dp[row][i], dp[row][i+1]+lost[row]*(x.nd[i+1]-x.nd[i]));
			isway[row][i] |= isway[row][i+1];
		}
		for (auto [a, b, h]: edge[row]){
			int pos = lb(all(mapa[b.st]), b.nd)-mapa[b.st].begin();
			int pos2 = lb(all(mapa[a.st]), a.nd)-mapa[a.st].begin();
			dp[b.st][pos] = min(dp[b.st][pos], dp[a.st][pos2]-h);
			isway[b.st][pos]|=isway[a.st][pos2];
		}
	}
	/*
	for (auto x: dp){
		rep(i, 0, sz(x.nd)){
			debug(x.st);
			debug(mapa[x.st][i]);
			debug(dp[x.st][i]);
			cerr << "\n";
		}
	}
	*/
	if (!isway[n].back()) cout << "NO ESCAPE\n";
	else cout << dp[n].back() << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
