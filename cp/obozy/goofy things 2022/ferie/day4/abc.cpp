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

const int MAX = 1e6+7;
const LL MOD = 1e9+7;
LL dp[MAX][4];

LL power(LL a, LL b){
	if (!b) return 1LL;
	LL k = power(a, b/2);
	k = (k*k)%MOD;
	if (b&1) k = (k*a) %MOD;
	return k;
}

void solve(){
	int n; cin >> n;
	dp[0][0] = 1;
	rep(i, 1, n+1){
		dp[i][0] = 2*dp[i-1][0];
		dp[i][1] = dp[i-1][0]+2*dp[i-1][1];
		dp[i][2] = dp[i-1][1]+2*dp[i-1][2];
		dp[i][3] = dp[i-1][2]+3*dp[i-1][3];
		dp[i][0] %= MOD;
		dp[i][1] %= MOD;
		dp[i][2] %= MOD;
		dp[i][3] %= MOD;
	}
	cout << (power(3, n)-dp[n][3]+MOD)%MOD << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
