/*
	Author: sysia
	31.01.2022 16:16:09
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
const int MAX = 1007;
int dp[MAX];

bool cmp(pii a, pii b){
	if (a.nd == b.nd) return a.st < b.st;
	return a.nd > b.nd;
}

void solve(){
	int n, k; cin >> n >> k;
	vi b(n+1), c(n+1);
	rep(i, 0, n) {
		int x; cin >> x;
		b[i] = dp[x];
	}
	rep(i, 0, n) cin >> c[i];
	k = min(k, 12*MAX+69);
	vll DP(12*MAX+2137, 0);
	rep(i, 0, n){
		repd(j, sz(DP)-1, 0){
			 if (b[i]<=j) DP[j] = max(DP[j], DP[j-b[i]]+c[i]);
		}
	}
	cout << DP[k] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp, 1e9+7, sizeof(dp));
	dp[1] = 0;
	rep(i, 1, MAX){
		rep(j, 1, MAX){
			if (i+i/j < MAX) dp[i+i/j] = min(dp[i]+1, dp[i+i/j]);
		}
	}
	int tmp = 0;
	rep(i, 1, MAX){
		tmp = max(tmp, dp[i]);
	}
	debug(tmp);
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
