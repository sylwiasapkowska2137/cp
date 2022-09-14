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

int p(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n; cin >> n;
	vpii a(n);
	int sum = 0, suma = 0;
	rep(i, 0, n) {
		cin >> a[i].st;
		sum += a[i].st;
	}
	rep(i, 0, n) {
		cin >> a[i].nd;
		suma += a[i].nd;
	}
	sort(all(a), [](auto x, auto y){return x.nd > y.nd;});
	int k = 0;
	int sum2 = sum;
	for (auto [x, y]:a){
		k++;
		sum2 -= y;
		if (sum2 <= 0) break;
	}
	//debug(k, suma, sum);
	vector<vector<vi>> dp(suma+2, vector<vi>(k+2, vi(n+1, -1)));
	int ans = 0;
	dp[0][0][0] = 0;
	
	rep(s, 0, suma+1){
		rep(ile, 0, k+1){
			rep(i, 0, n){
				if (i) dp[s][ile][i] = max(dp[s][ile][i], dp[s][ile][i-1]);
				if (dp[s][ile][i] == -1) continue;
				if (s+a[i].nd <= suma) dp[s+a[i].nd][ile+1][i+1] = max(dp[s+a[i].nd][ile+1][i+1], dp[s][ile][i]+a[i].st);
			}
		}
	}
	rep(s, sum, suma+1){
		rep(i, 0, n+1){
			ans = max(ans, dp[s][k][i]);
			//debug(s, i, dp[s][k][i]);
		}
	}
	
	cout << k << " " << sum-ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
