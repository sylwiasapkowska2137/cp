/*
	Author: sysia
	13.01.2022 17:59:11
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

const int MAX = 1e5+7, INF = 1e9+7;
int a[MAX][5];
int n, m, k;

struct segtree{
	int size = 1;
	vi tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void build(int x){
		rep(i, 0, n){
			tab[i+size] = a[i][x];
		}
		repd(i, size-1, 0){
			tab[i] = max(tab[2*i], tab[2*i+1]);
		}
	}
	
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
} seg[5];

vi check(int len){
	vi ans(m, INF);
	int mini = INF;
	rep(r, len, n){
		int curr = 0;
		vi t(m, 0);
		rep(j, 0, m){
			t[j] = seg[j].query(r-len, r);
			curr += t[j];
		}
		if (curr < mini){
			mini = curr;
			ans = t;
		}
	}
	return ans;
}

void solve(){
	cin >> n >> m >> k;
	rep(i, 0, n){
		rep(j, 0, m){
			cin >> a[i][j];
		}
	}
	rep(i, 0, m){
		seg[i].init(n);
		seg[i].build(i);
	}
	int l = 0, r = n;
	vi ans(m, 0);
	while (r>=l){
		int mid = (l+r)/2;
		vi t = check(mid);
		int sum = accumulate(all(t), 0);
		if (sum <= k){
			ans = t;
			l = mid+1;
		} else r = mid-1;
	}
	rep(i, 0, m) cout << ans[i] << " ";
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
