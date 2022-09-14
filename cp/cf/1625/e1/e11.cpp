/*
	Author: sysia
	15.01.2022 10:58:43
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
	int n, q; cin >> n >> q;
	string s; cin >> s;
	stack<int>S;
	vll dp(n+1, 0), pref(n+1, 0);
	rep(i, 0, n){
		if (s[i] == '('){
			S.push(i+1);
		} else if (!S.empty()){
			dp[i+1] = dp[S.top()-1]+1; //number of rbs ending at s[i]
			S.pop();
		}
		pref[i+1] = pref[i]+dp[i+1];
	}
	//rep(i, 0, n) debug(dp[i]);
	//cerr << "\n";
	//rep(i, 1, n+1) debug(pref[i]);
	while (q--){
		int t, l, r; cin >> t >> l >> r;
		LL ans = pref[r]-pref[l-1]-dp[l-1]*(dp[r]-dp[l-1]);
		cout << ans << "\n";
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
