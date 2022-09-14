/*
	Author: sysia
	11.01.2022 17:25:50
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

const int MAX = 1e5+7, INF = 1e9+7;
vi graf[MAX], c;
vll ans;
map<int, LL>cnt[MAX];
//cnt[INF] = suma, cnt[INF+1] = ile;

void add(int v, int where, LL val){
	cnt[v][where]+=val;
	if (cnt[v][where] == cnt[v][INF+1]) cnt[v][INF]+=where;
	else if (cnt[v][where] > cnt[v][INF+1]){
		cnt[v][INF+1] = cnt[v][where];
		cnt[v][INF] = where;
	}
}

void dfs(int v, int pa = -1){
	int sz = 0, big = -1;
	
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, v);
			if (sz(cnt[x]) > sz){
				sz = sz(cnt[x]);
				big = x;
			}
		}
	}
	if (big == -1){
		add(v, c[v], 1);
		ans[v] = cnt[v][INF];
		return;
	}
	swap(cnt[v], cnt[big]);
	add(v, c[v], 1);
	for (auto x: graf[v]){
		if (x!=pa && x!=big){
			for (auto val: cnt[x]){
				if (val.st < INF) add(v, val.st, val.nd);
			}
		}
	}
	ans[v] = cnt[v][INF];
}

void solve(){
	int n; cin >> n;
	c.assign(n+1, 0);
	ans.assign(n+1, 0);
	rep(i, 1, n+1) cin >> c[i];
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(1);
	rep(i, 1, n+1) cout << ans[i] << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
