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
	int n;
	cin >> n;
	vi a(n+1);
	rep(i, 1, n+1) cin >> a[i];
	int k = 0;
	while (1){
		bool ok = 1;
		rep(i, 1, n+1){
			if (a[i]!=i){
				ok = 0;
				break;
			}
		}
		if (ok) break;
		k++;
		//debug(k);
		if (k&1){
			for (int i = 1; i<=n-2; i+=2){
				if (a[i]>a[i+1]) swap(a[i], a[i+1]);
			}
		} else {
			for (int i = 2; i<=n-1; i+=2){
				if (a[i]>a[i+1]) swap(a[i], a[i+1]);
			}
		}
	}
	cout << k << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
