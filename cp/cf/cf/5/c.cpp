//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const int INF = 1e9+7;
map<int, vi>mapa;


const int Size = (1<<20);
int tab[2*Size+1];
	
void init(int n, vi a){
	rep(i, 0, 2*Size) tab[i] = INF;
	rep(i, 0, sz(a)) tab[i+Size] = a[i];
	repd(i, Size-1, 0) tab[i] = min(tab[i<<1], tab[(i<<1)|1]);
}

int query(int l, int r){
	l = l+Size-1;
	r = r+Size+1;
	int ans = INF;
	while (r-l>1){
		if (!(l&1)) ans = min(ans, tab[l+1]);
		if (r&1) ans = min(ans, tab[r-1]);
		l>>=1;r>>=1;
	}
	return ans;
}


void solve(){
	string s; cin >> s;
	s = "%"+s;
	int n = sz(s)-1;
	vi pref(n+1, 0);
	rep(i, 1, n+1){
		if (s[i] == '(') pref[i] = pref[i-1]+1;
		else pref[i] = pref[i-1]-1;
		//debug(pref[i]);
	}
	init(n+1, pref);
	rep(i, 0, n+1) mapa[pref[i]].pb(i);
	map<int, int>ans;
	
	for (auto x: mapa){
		rep(i, 1, sz(x.nd)){
			int r = i, l = 0;
			while (r>=l) {
				int m = (l+r)>>1;
				if (query(x.nd[m]+1, x.nd[i]) >= x.st) {
					r = m-1;
				} else l = m+1;
			}
			++ans[x.nd[i]-x.nd[l]];
		}
	}
	ans[0] = 1;
	auto it = ans.rbegin();
	cout << it->st << " " << it->nd << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
