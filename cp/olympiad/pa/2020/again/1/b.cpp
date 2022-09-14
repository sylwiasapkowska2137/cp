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

const int MAX = 1e6+7;
int pref[MAX][3];

void solve(){
	int n, m; cin >> n >> m; 
	while (m--){
		int l, r, t; cin >> l >> r >> t;
		t--;
		pref[l][t]++;
		pref[r+1][t]--;
	}
	rep(i, 1, n+1){
		rep(j, 0, 3){
			pref[i][j] += pref[i-1][j];
		}
	}
	int ans = 0;
	rep(i, 1, n+1){
		if (pref[i][0] && pref[i][1] && !pref[i][2]){
			ans++;
			//debug(i);
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
