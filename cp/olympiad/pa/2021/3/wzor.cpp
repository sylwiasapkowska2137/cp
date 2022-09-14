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

const LL MOD = 1e9+7;

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

struct segtree{
	vll tab;
	int size = 1;
	
	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0LL);
	}
	
	LL query(int l, int r){
		LL ans = 0LL;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = (ans + tab[l+1])%MOD;
			if (r&1) ans = (ans + tab[r-1])%MOD;
			l/=2;
			r/=2;
		}
		return ans;
	}
	
	void update(int pos, LL val){
		pos+=size;
		tab[pos] = (tab[pos]+val)%MOD;
		while (pos>0){
			pos/=2;
			tab[pos] = (tab[2*pos]+tab[2*pos+1])%MOD;
		}
	}
};

void solve(){
	int n; cin >> n;
	vll a(n+1), pref(n+1, 0LL), scaler, dp(n+1, 0LL);
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) {
		pref[i] = (pref[i-1]+a[i])%MOD;
		scaler.pb(pref[i]);
	}
	scaler.pb(0);
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	segtree even(n+2), odd(n+2);
	map<int, int>seven;
	rep(i, 0, sz(scaler)) seven[scaler[i]] = i;
	even.update(seven[0], 1);
	rep(i, 1, n+1){
		if (pref[i]&1){ 
			dp[i] = (odd.query(0, seven[pref[i]]) + even.query(seven[pref[i]]+1, even.size-1))%MOD;
			odd.update(seven[pref[i]], dp[i]);
		} else {
			dp[i] = (even.query(0, seven[pref[i]]) + odd.query(seven[pref[i]]+1, odd.size-1))%MOD;
			even.update(seven[pref[i]], dp[i]);
		}
		//debug(dp[i]);
	}
	cout << dp[n] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
