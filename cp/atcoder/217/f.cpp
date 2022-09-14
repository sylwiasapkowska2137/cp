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

const int MAX = 407, MAXN = 3e5+7;
LL dp[MAX][MAX];
LL silnia[MAXN], inverse[MAXN];
bool good[MAX][MAX], vis[MAX][MAX];
const LL MOD = 998244353;

LL pow(LL a, LL b) {
	LL ans = 1;
	while(b) {
		if(b&1) ans = (1ll*ans*a)%MOD;
		b /= 2;
		a = (1ll*a*a)%MOD;
	}
	return ans;
}

LL inv(LL a){
	return pow(a, MOD-2);
}

LL choose(LL n, LL k){
	if (n < 0 || k < 0 || k>n) return 0;
	return (((silnia[n]*inverse[k])%MOD)*inverse[n-k])%MOD;
}

LL DP(int L, int R){
	if (L > R) return 1;
	if (vis[L][R]) return dp[L][R];
	for (int x = L+1; x<=R; x+=2){
		if (!good[L][x]) continue;
		LL left = DP(L+1, x-1);
		LL right = DP(x+1, R);
		LL LEFT = (x-L-1)/2;
		LL RIGHT = (R-x)/2;
		LL ways = choose(LEFT+RIGHT+1, LEFT+1);
		dp[L][R] = (dp[L][R]+((left*right)%MOD*ways)%MOD)%MOD;
	}
	vis[L][R] = 1;
	return dp[L][R];
}

void preprocess(){
	silnia[0] = 1;
	rep(i, 1, MAXN) silnia[i] = (silnia[i-1]*i)%MOD;
	inverse[MAXN-1] = inv(silnia[MAXN-1]);
	repd(i, MAXN-2, 0) inverse[i] = (inverse[i+1]*(i+1))%MOD;
}

void solve(){
	preprocess();
	int n, m; cin >> n >> m;
	rep(i, 0, m){
		int a, b;
		cin >> a >> b;
		good[a][b] = 1;
		good[b][a] = 1;
	}
	
	LL x = DP(1, 2*n);
	cout << x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
