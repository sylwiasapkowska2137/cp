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
#define memo(x, val) memset(x, val, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

const int MAX = 3e4+7, MAXD = 507;
const int M = 250;
int dp[MAX][MAXD];


void solve(){
	int n, m, d; cin >> n >> m >> d;
	vi cnt(n+1, 0);
	rep(i, 1, m+1){
		int x; cin >> x;
		cnt[x]++;
	}
	memo(dp, -1);
	dp[d][M] = cnt[d];
	int ans = 0;
	rep(i, d, n+1){
		rep(j, -M, M+1){
			//dp[i][j] = max wynik, skoczylismy na wyspe i skokiem rozniącym się o j względem d
			//teraz mozemy skoczyc o j+d-1, j+d, j+d+1
			int shift = M+j;
			if (j+d <= 0) continue;
			if (dp[i][shift] == -1) continue;
			
			rep(k, -1, 2){
				if (i+(d+j-k) <= n && i+(d+j-k) > 0) dp[i+d+j-k][shift-k] = max(dp[i+d+j-k][shift-k], dp[i][shift]+cnt[i+d+j-k]);
			}
			ans = max(ans, dp[i][shift]);
			/*
			debug("wyspa");
			debug(i);
			debug("skok");
			debug(j+d);
			debug("dp");
			debug(dp[i][shift]);
			cerr << "\n";
			*/
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
