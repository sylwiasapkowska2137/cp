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

LL p(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

void solve(){
	const int M = 15;
	int n = p(10, 15), k = p(10, M);
	cout << n << " " << k << "\n";
	vi c(n);
	rep(i, 0, n) {
		c[i] = p(1, k);
		cout << c[i] << " ";
	}
	cout << "\n";
	vi curr;
	while (sz(curr) < 3){
		int x = c[p(1, n)-1];
		if (curr.empty()) curr.pb(x);
		else if (!curr.empty() && x != curr.back()) curr.pb(x);
	}
	sort(all(curr));
	curr.erase(unique(all(curr)), curr.end());
	random_shuffle(all(curr));
	int x = p(1, sz(curr)-1);
	int y = (sz(curr)-x+1);
	cout << x << " " << y << "\n";
	rep(i, 0, x) cout << curr[i] << " ";
	cout << "\n";
	vi b;
	rep(i, x-1, sz(curr)) b.pb(curr[i]);
	reverse(all(b));
	for (auto x: b) cout << x << " ";
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
