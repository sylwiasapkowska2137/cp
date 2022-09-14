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
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
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
#define PI 3.14159265359

LL p(LL a, LL b){
	return a+rng()%(b-a+1);
}

const LL INF = 1e18+7;
unordered_map<LL, LL>vis;

LL solve(LL n, LL &a, LL &b){
	if (n == 1) return 0;
	if (vis.find(n) != vis.end()) return vis[n];
	//debug(n);
	LL ans = INF;
	for (LL d = 1; d*d<=n; d++){
		if (n%d == 0){
			if (d!=1) ans = min(ans, solve(n/d, a, b)+a+(d-1)*b);
			ans = min(ans, solve(d, a, b)+a+(n/d-1)*b);
		}
	}
	vis[n] = ans;
	return ans;
}

void solve(){
	LL n, a, b; cin >> n >> a >> b;
	if (n <= 1e6){
		vll dp(2*n+1, INF);
		LL ans = INF;
		dp[1] = 0;
		rep(i, 1, n+1){
			for (LL j = 2*i; j<sz(dp); j+=i){
				dp[j] = min(dp[j], dp[i]+a+(LL)(j/i-1)*b);
			}
		}
		rep(i, n+1, sz(dp)) ans = min(ans, dp[i]);
		//debug(dp);
		cout << ans << "\n";
	} else{
		if (a == b){
			LL ans = INF;
			for (int cnt3 = 0; cnt3 < 40; cnt3++){
				__int128 x = 1;
				LL tmp = cnt3*3;
				rep(i, 0, cnt3) x*=3;
				while (x <= (__int128)n){
					x*=2;
					tmp+=2;
				}
				ans = min(ans, tmp); 
			}
			cout << ans*a << "\n";
			return;
		}
		LL ans = INF;
		rep(i, 0, 10000){
			LL R = 1e9+1000;
			LL x = p(n+1, R);
			ans = min(ans, solve(x, a, b));
		}
		cout << ans << "\n";
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
