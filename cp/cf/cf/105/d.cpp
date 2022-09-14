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

bool check(vi a, int maska, int n){
	//debug(maska);
	for (int mask = 0; mask<(1<<n); mask++){
		int x = 0;
		rep(j, 0, n){
			if (maska&(1<<j)){
				if (mask&(1<<j)) x+=a[j];
				else x-=a[j];
			}
		}
		//debug(x);
		if (!x) return 1;
	}
	return 0;
}

void solve(){
	int n; cin >> n;
	vi a(n);
	bool ok = 0;
	rep(i, 0, n) cin >> a[i];
	for (int maska = 1; maska<(1<<n); maska++){
		ok |= check(a, maska, n);
		//cerr << "\n";
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
