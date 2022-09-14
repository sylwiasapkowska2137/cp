/*
	Author: sysia
	31.01.2022 16:02:08
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

void solve(){
	LL hc, dc; cin >> hc >> dc;
	LL hm, dm; cin >> hm >> dm;
	LL k, w, a; cin >> k >> w >> a;
	rep(i, 0, k+1){
		LL left = k-i;
		LL h1 = hc+(LL)(i)*a;
		LL a1 = dc+(LL)(left)*w;
		LL a = (h1/dm);
		LL b = (hm/a1);
		a = max(0LL, min(a-1, b-1));
		LL mocc = h1 - dm*a;
		LL moch = hm - a*a1;
		if (mocc <= 0) continue;
		/*
		debug(k);
		debug(h1);
		debug(a1);
		debug(mocc);
		debug(moch);
		cerr << "\n";
		*/
		while (1){
			moch -= a1;
			if (moch <= 0){
				cout << "YES\n";
				return;
			}
			mocc -= dm;
			if (mocc <= 0){
				break;
			}
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
