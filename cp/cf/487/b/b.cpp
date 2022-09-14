/*
	Author: sysia
	13.01.2022 19:12:12
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

const int INF = 1e9+7;

void solve(){
	int n, s, l; cin >> n >> s >> l;
	multiset<int>S, P;
	vi a(n+1), dp(n+1);
	int j = 1;
	rep(i, 1, n+1){
		cin >> a[i];
		S.insert(a[i]);
		while (*S.rbegin()-*S.begin()>s){
			S.erase(S.find(a[j]));
			if (i-j >= l) P.erase(P.find(dp[j-1]));
			j++;
		}
		if (i-j+1>=l) P.insert(dp[i-l]);
		if (P.empty()) dp[i] = INF;
		else dp[i] = *P.begin()+1;
	}
	//rep(i, 0, n) debug(dp[i]);
	//cerr << "\n";
	if (dp[n] >= INF) cout << "-1\n";
	else cout << dp[n] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
