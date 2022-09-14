/*
	Author: sysia
	14.01.2022 19:20:48
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

const int MAX = 3e5+5, M = 32*MAX;
int son[M][2], idx;

void init() {
	memset(son, 0, sizeof(int)*2*idx);
	idx = 0;
}

void push(int x) {
	int cur = 0;
	repd(i, 30, 0){
		int &to = son[cur][(x>>i)&1];
		if (!to) to = ++idx;
	    cur = to;
	}
}

int find(int x) {
	int cur = 0, ans = 0;
	repd(i, 30, 0){
		int &to = son[cur][~(x>>i)&1];
		if (to){
			ans += (1<<i);
			cur = to;
		} else{
			cur = son[cur][(x>>i)&1];
		}
	}
	return ans;
}

void solve(){
	int n, k; cin >> n >> k;
	if (k == 0){
		cout << n << "\n";
		rep(i, 0, n){
			int x; cin >> x;
			cout << i+1 << " ";
		}
		return;
	}
	vi a(n+1);
	map<int, int>place;
	int pos = 30;
	while ((k>>pos & 1) == 0) pos --;
	map<int, vi>mapa;
	rep(i, 1, n+1){
		cin >> a[i];
		mapa[a[i]>>pos+1].pb(a[i]);
		place[a[i]] = i;
	}
	
	vi ans;
	for (auto x: mapa){
		init();
		for (auto v: x.nd) push(v);
		int xx = -1;
		for (auto v: x.nd){
			xx = max(xx, find(v));
			if (xx>=k){
				ans.pb(xx^v);
				ans.pb(v);
				break;
			}
		}
		if (xx<k) ans.pb(x.nd[0]);
	}
	if (sz(ans) < 2) cout << "-1\n";
	else {
		cout << sz(ans) << "\n";
		for (auto x: ans) cout << place[x] << " ";
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
