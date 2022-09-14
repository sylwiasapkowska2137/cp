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
#define memo(x) memset(x, 0, sizeof(x))
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

bool check(LD mid, int n, vi&a){
	vld b(n);
	rep(i, 0, n) b[i] = a[i]-mid;
	vector<vld>dp(n+1, vld(2, 0));
	dp[0][1] = b[0];
	rep(i, 1, n){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = max(dp[i-1][0], dp[i-1][1])+b[i];
	}
	LD x = max(dp[n-1][0], dp[n-1][1]);
	return (x>=0);
}

bool check2(LL mid, int n, vi&a){
	vi b(n);
	rep(i, 0, n){
		if (a[i] >= mid) b[i] = 1;
		else b[i] = -1;
	}
	vector<vi>dp(n+1, vi(2, 0));
	dp[0][1] = b[0];
	rep(i, 1, n){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = max(dp[i-1][0], dp[i-1][1])+b[i];
	}
	int x = max(dp[n-1][0], dp[n-1][1]);
	return (x>0);
}

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	LD L = 1, R = 1e18, EPS = 10e-6;
	while (R-L>EPS){
		LD m = (L+R)/2;
		if (check(m, n, a)) L = m;
		else R = m;
	}
	cout << fixed << setprecision(10);
	cout << L << "\n";
	{
		LL L = 1, R = 1e18, ans = 1;
		while (R>=L){
			LL m = (L+R)/2;
			if (check2(m, n, a)) {
				ans = m;
				L = m+1;
			}
			else R = m-1;
		}
		cout << ans << "\n";
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
