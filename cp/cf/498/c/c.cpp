/*
	Author: sysia
	17.01.2022 11:28:00
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
#define memo(x, val) memset(x, val, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

const int MAX = 5000;
vpii D[MAX];
vi graf[MAX];
bool vis[MAX];
int mt[MAX];
 
bool dfs(int v){
	vis[v] = 1;
	for(int x:graf[v]){
		if(mt[x] == -1 || (!vis[mt[x]] && dfs(mt[x]))){
			mt[x] = v;
			return 1;
		}
	}
	return 0;
}

void solve(){
	int n, m; cin >> n >> m;
	int k = 0;
	rep(i, 0, n) {
		int x; cin >> x;
		for (int j = 2; j*j<=x; j++){
			while (x%j == 0){
				D[i].pb({j, k++});
				x/=j;
			}
		}
		if (x > 1) D[i].pb({x, k++});
	}
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		--a;--b;
		if (a%2 != 0) swap(a, b);
		for (auto x: D[a]){
			for (auto y: D[b]){
				if (x.st == y.st){
					graf[x.nd].pb(y.nd);
				}
			}
		}
	}
	int ans = 0;
	memo(mt, -1);
	rep(i, 0, k){
		memo(vis, 0);
		if (dfs(i)) ans++;
	}
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
