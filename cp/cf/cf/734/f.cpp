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

const int MAX = 107;
const LL MOD = 1e9+7;
vi graf[MAX];
int depth[MAX][MAX]; 

void dfs(int sub, int v, int pa = -1, int d = 1){
	depth[sub][d]++; 
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(sub, x, v, d+1);
		}
	}
}

LL dp(vi a, int k){
	int n = sz(a);
	LL dp[n+1][n+1] = {0};
	LL curr = 0;
	rep(i, 1, n+1){
		dp[1][i] = a[i-1];
		curr+=(LL)a[i-1];
	}
	rep(i, 2, k+1){
		LL tmp = 0;
		rep(j, 1, n+1){
			curr -= dp[i-1][j];
			while (curr < 0) curr+=MOD;
			if (curr >= MOD) curr%=MOD;
			dp[i][j] = a[j-1]*curr;
			if (dp[i][j]>=MOD) dp[i][j] %= MOD;
			tmp+=dp[i][j];
			if (tmp>=MOD) tmp%=MOD;
		}
		curr = tmp;
	}
	return curr;
}

void solve(){
	string s; getline(cin, s);
	LL n, k; cin >> n >> k;
	
	rep(i, 1, n+1) graf[i].clear();
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	if (k == 2){
		LL ans = n*(n-1)/2;
		if (ans >= MOD)ans%=MOD;
		cout << ans << "\n";
		return;
	}
	
	LL ans = 0LL;
	rep(i, 1, n+1){
		if (sz(graf[i])>=k) {
			memo(depth); 
			for (auto x: graf[i]) dfs(x, x, i); 
			
			int ile = 0; 
			repd(d, n, 0){
				vi a;
				for (auto x: graf[i]) if (depth[x][d]>0) a.pb(depth[x][d]);
				if (sz(a)<k) continue;
				//for (auto x: a) debug(x);
				//cerr << "\n";
				ans += dp(a, k);
				if (ans >= MOD) ans%=MOD;
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
