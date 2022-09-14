/*
	Author: sysia
	07.01.2022 16:56:03
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
	int n; cin >> n;
	vi a(n+1, 0);
	rep(i, 1, n+1) cin >> a[i];
	vi last(n+1, n+1), next(n+1, n+1);
	repd(i, n, 1){
		next[i] = last[a[i]];
		last[a[i]] = i;
	}
	int x = 0, y = 0, res = 0;
	rep(i, 1, n+1){
		if (a[x] != a[i] && a[y] != a[i]){
			if (next[x] < next[y]) {
				res += (a[x]!=a[i]);
				x = i;
			} else {
				res += (a[y]!=a[i]);
				y = i;
			}
		} else if (a[x] != a[i]){
			res += (a[x]!=a[i]);
			x = i;
		} else if (a[y] != a[i]) {
			res += (a[y]!=a[i]);
			y = i;
		} else{
			res += (a[x]!=a[i]);
			x = i;
		}
	}
	cout << res << "\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
