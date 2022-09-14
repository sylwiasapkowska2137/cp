/*
	Author: sysia
	15.01.2022 19:13:32
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

const int MAX = 1e5+7;
vpii graf[MAX];
vi ans;

void dfs(int v, int pa = -1, int curr = 0){
	for (auto [x, i]: graf[v]){
		if (x!=pa){
			ans[i] = curr;
			dfs(x, v, curr^1);
		}
	}
}

void solve(){
	int n; cin >> n;
	rep(i, 0, n) graf[i].clear();
	ans.assign(n, 0);
	vi deg(n);
	rep(i, 0, n-1){
		int a, b; cin >> a >> b;
		--a;--b;
		graf[a].pb({b, i});
		graf[b].pb({a, i});
		deg[a]++;deg[b]++;
	}
	rep(i, 0, n){
		if (deg[i] > 2){
			cout << "-1\n";
			return;
		}
	}
	int x = 0;
	rep(i, 1, n){
		if (sz(graf[i]) == 1) {
			x = i;
			break;
		}
	}
	dfs(x);
	rep(i, 0, n-1) cout << ans[i]+2 << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
