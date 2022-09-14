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

const int MAX = (1<<17);
int val[MAX+7];
int dp[MAX][21];

void compute(int v, int k, int level){
	if (!k) return;
	dp[v][1] = val[v];
	if (level == 1) return;
	compute(2*v, k-1, level-1);
	compute(2*v+1, k-1, level-1);
	
	rep(i, 2, k+1){
		rep(j, 0, i) dp[v][i] = max(dp[v][i], dp[2*v][j] + dp[2*v+1][i-j-1] + val[v]);
	}
}

void solve(){
	int n, k; cin >> n >> k;
	k/=2;
	int v = 0;
	rep(i, 0, n){
		rep(j, 0, (1<<i)){
			v++;
			int a, b; cin >> a >> b;
			val[v] = a+b;
		}
	}
	compute(1, k, n);
	cout << dp[1][k] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
