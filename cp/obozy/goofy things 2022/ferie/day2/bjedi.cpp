//Sylwia Sapkowska
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const LL INF = 1e18;

void solve(){
	int n, q; cin >> n >> q;
	vi a(n+1);
	rep(i, 1, n+1) cin >> a[i];
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int pos, val; cin >> pos >> val;
			a[pos] = val;
		} else {
			int l, r; cin >> l >> r;
			LL ans = -INF;
			rep(start, l, r+1){
				vll dp(n+1, -INF);
				dp[start] = a[start];
				rep(i, start+1, r+1){
					rep(j, start, i){
						if ((j+i)%2 == 1){
							dp[i] = max(dp[i], dp[j]+a[i]);
						}
					}
					//debug(dp[i]);
				}
				ans = max(ans, (LL)(*max_element(all(dp))));
			}
			cout << ans << "\n";
		}
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
