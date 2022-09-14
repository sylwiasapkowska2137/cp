/*
	Author: sysia
	30.01.2022 20:21:19
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

struct segtree{
	vi tab;
	int size = 1;
	
	segtree(int n, vi&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		rep(i, 0, sz(a)) tab[i+size] = a[i];
		repd(i, size-1, 1) tab[i] = __gcd(tab[2*i], tab[2*i+1]);
	}
	
	int query(int l, int r){
		int ans = 0;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = __gcd(ans, tab[l+1]);
			if (r&1) ans = __gcd(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vi a(n+1);
	rep(i, 1, n+1) cin >> a[i];
	segtree seg(n+1, a);
	vi bad(n+1, -1);
	rep(i, 1, n+1){
		int L = i, R = n;
		int ans = -1;
		while (R>=L){
			int m = (L+R)/2;
			int x = seg.query(i, m);
			if (x == m-i+1){
				ans = m;
				break;
			} else if (x > m-i+1){
				L = m+1;
			} else {
				R = m-1;
			}
		}
		if (ans != -1 && seg.query(i, ans) == ans-i+1){
			//debug(i);
			//debug(ans);
			bad[ans] = i;
			//cerr << "\n";
		}
	}
	int ans = 0;
	int L = 0, R = -1;
	rep(i, 1, n+1){
		if (bad[i] == -1){
			cout << ans << " ";
			continue;
		}
		if (bad[i] > R) {
			ans++;
			L = bad[i], R = i;
		}
		cout << ans << " ";
		
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
