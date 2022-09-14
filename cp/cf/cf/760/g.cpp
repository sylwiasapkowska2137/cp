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

const int MAX = 4e5+7;
vi graf[MAX], REP;
int cnt = 0;
LL curr;
vpii a;
multiset<int> bst[MAX], wst[MAX];

void dsu_init(int n){
	REP.resize(n);
	rep(i, 0, n){
		REP[i] = i;
		if (a[i].nd) bst[i].insert(a[i].st);
		else wst[i].insert(a[i].st);
	}
}

int Find(int a){
	if (a == REP[a]) return a;
	return REP[a] = Find(REP[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (sz(wst[a]) + sz(bst[a]) < sz(wst[b]) + sz(bst[b])) swap(a, b);
	for (auto x:wst[b]) wst[a].insert(x);
	for (auto x:bst[b]) bst[a].insert(x);
	wst[b].clear(); bst[b].clear();
	while (!bst[a].empty() && !wst[a].empty() && *bst[a].begin() < *wst[a].rbegin()){ 
		//zamieniamy wszystkie pary dopóki nam się to opłaca
		curr -= *bst[a].begin();
		curr += *wst[a].rbegin();
		bst[a].insert(*wst[a].rbegin());
		wst[a].insert(*bst[a].begin());
		bst[a].erase(bst[a].begin());
		wst[a].erase(--wst[a].end());
	}
	REP[b] = a;
}


struct event{
	int x, t, i;
};

bool cmp(event a, event b){
	if (a.x == b.x) return a.t < b.t;
	return a.x < b.x;
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	a.resize(n+m);
	rep(i, 0, n+m) {
		cin >> a[i].st;
		if (i < n) {
			a[i].nd = 1;
			curr += a[i].st;
		}
	}
	sort(all(a));
	dsu_init(n+m+1);
	vector<event>tab;
	vi query(q);
	vll ans(q);
	rep(i, 0, n+m-1) tab.pb(event{a[i+1].st-a[i].st, 0, i});
	rep(i, 0, q){
		cin >> query[i];
		tab.pb({query[i], 1, i});
	}
	sort(all(tab), cmp);
	for (auto x: tab){
		if (x.t) ans[x.i] = curr;
		else Union(x.i, x.i+1);
	}
	rep(i, 0, q) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
