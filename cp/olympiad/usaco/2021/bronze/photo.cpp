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

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	LL ans = 0LL;
	s = "%"+s;
	vll right(n+2, 0), left(n+2, 0);
	rep(i, 1, n+1){
		if (s[i] == 'G') left[i] = 0;
		else left[i] = left[i-1]+1;
	}
	repd(i, n, 1){
		if (s[i] == 'G') right[i] = 0;
		else right[i] = right[i+1]+1;
	}
	rep(i, 1, n+1){
		if (s[i] == 'G'){
			ans += (LL)(left[i-1]*right[i+1]);
			ans += (LL)(max(0LL, left[i-1]-1));
			ans += (LL)(max(0LL, right[i+1]-1));
		}
		
	}
	rep(i, 1, n+1){
		if (s[i] == 'H') s[i] = 'G';
		else s[i] = 'H';
	}
	right.assign(n+2, 0);
	left.assign(n+2, 0);
	rep(i, 1, n+1){
		if (s[i] == 'G') left[i] = 0;
		else left[i] = left[i-1]+1;
	}
	repd(i, n, 1){
		if (s[i] == 'G') right[i] = 0;
		else right[i] = right[i+1]+1;
	}
	rep(i, 1, n+1){
		if (s[i] == 'G'){
			ans += (LL)(left[i-1]*right[i+1]);
			ans += (LL)(max(0LL, left[i-1]-1));
			ans += (LL)(max(0LL, right[i+1]-1));
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
