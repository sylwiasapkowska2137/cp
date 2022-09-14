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

void solve(){
	LL n; cin >> n;
	vll b(n), a(n);
	LL pairs = (LL)n*(LL)(n+1)/2;
	LL sum = 0LL;
	rep(i, 0, n) {
		cin >> b[i];
		sum+=b[i];
	}
	if (sum%pairs != 0){
		cout << "NO\n";
		return;
	}
	sum/=pairs;
	//debug(sum);
	rep(i, 0, n){
		LL curr = b[i], prev = b[i-1];
		if (i == 0) prev = b[n-1];
		LL x = prev-curr+sum;
		if (x%n != 0){
			cout << "NO\n";
			return;
		}
		a[i] = x/n;
		if (a[i]<1){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (auto x: a) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
