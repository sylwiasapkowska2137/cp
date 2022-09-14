#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
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

void solve(){
	int n;cin >> n;
	
	if (n == 2){
		cout << "? 1 2 \n";cout.flush();
		int x; cin >> x;
		if (x == 1) cout << "! 2\n";
		else cout << "! 1\n";
		cout.flush();
		return;
	}
	
	cout << "? " << 1 << " " << n << "\n";cout.flush();
	int x, y; cin >> x;
	if (x!=1) {
		cout << "? " << 1 << " " << x << "\n";cout.flush();
		cin >> y;
	} else y = x+1;
	if (x == y)	{
		int start = 1, koniec = x;
		while (koniec - start > 1){
			int m = (start+koniec)/2;
			cout << "? " << m << " " << x << "\n";cout.flush();
			int val; cin >> val;
			if (val == x) start = m;
			else koniec = m;
		}
		cout << "! " << start << "\n";cout.flush();
	}
	else {
		int start = x, koniec = n, ans = n;
		while (koniec - start > 1){
			int m = (start+koniec)/2;
			cout << "? " << x << " " << m << "\n";cout.flush();
			int val; cin >> val;
			if (val == x) koniec = m;
			else start = m+1;
		}
		cout << "! " << koniec << "\n";cout.flush();
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
