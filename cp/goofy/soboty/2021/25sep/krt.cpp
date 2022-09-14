#include <bits/stdc++.h>
using namespace std;
 
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

void solve(){
	int n; cin >> n;
	vpii a(n);
	map<int, int>cnt;
	rep(i, 0, n){
		cin >> a[i].st >> a[i].nd;
		cnt[a[i].st]++;
		cnt[a[i].nd]++;
	}
	int half = n/2+n%2;
	int ans = INT_MAX;
	for (auto x: cnt){
		if (x.nd >= half){
			
			int tmp = 0, ile = 0;
			rep(i, 0, n){
				if (a[i].st == x.st) ile++;
			}
			if (ile >= half) ans = 0;
			else {
				rep(i, 0, n){
					if (a[i].st != x.st && a[i].nd == x.st) {
						tmp++;
						ile++;
					}
					if (ile >= half){
						ans = min(ans, tmp);
					}
				}
				
			}
		}
	}
	if (ans == INT_MAX) cout << "-1\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
