/*
	Author: sysia
	10.01.2022 20:00:05
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
#define memo(x) memset(x, -1, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

vector<string>tab;
vector<vll> Hash;
const LL P = 2137, MOD = 1e9+7;

vll make_hash(string &s){
	LL BASE = 1;
	vll H(sz(s));
	H[0] = 0LL;
	rep(i, 1, sz(s)){
		H[i] = (H[i-1]+s[i]*BASE)%MOD;
		BASE = (BASE*P)%MOD;
	}
	return H;
}

void solve(){
	int n, m; cin >> n >> m;
	tab.resize(n);
	rep(i, 0, n) cin >> tab[i];
	rep(i, 0, n) tab[i] = "%"+tab[i];
	string s; cin >> s;
	Hash.resize(n);
	rep(i, 0, n) Hash[i] = make_hash(tab[i]);
	int dp[n+1][m+1];
	memo(dp);
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
