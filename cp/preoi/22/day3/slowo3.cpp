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

const int MAX = 130;
const LL MOD = 1e9+7;

inline void addmod(LL &a, LL b){
	a += b;
	a %= MOD;
}

inline void submod(LL &a, LL b){
	a -= b;
	while (a < 0) a += MOD;
	if (a >= MOD) a %= MOD;
}

inline LL mulmod(LL a, LL b){
	//a %= MOD, b%=MOD;
	LL ans = a*b;
	if (ans >= MOD) ans%=MOD;
	return ans;
}

void solve(){
	string s; cin >> s;
	int n = sz(s);
	vll lewo(MAX, 0), sdp(MAX, 0);
	s = "$"+s;
	vector<char>All;
	for (char c = '0'; c<='9'; c++) All.pb(c);
	for (char c = 'a'; c<='z'; c++) All.pb(c);
	for (char c = 'A'; c<='Z'; c++) All.pb(c);
	for (auto x:s) lewo[x]++;
	vector<vector<vll>>dp(MAX, vector<vll>(MAX, vll(5, 0)));
	LL ans = 0LL, sum = 0LL;
	LL inv2 = 5e8+4;
	repd(i, n, 1){
		char a = s[i];
		for (auto c: All){
			if (a == c) continue;
			LL tmp = sum;
			addmod(tmp, dp[a][c][4]+dp[c][a][4]);
			submod(tmp, (sdp[c]+sdp[a]));
			addmod(ans, mulmod(lewo[c], tmp));
		}
		for (auto c: All){
			if (c == a) continue;
			dp[c][a][1]++;
			addmod(dp[a][c][2], dp[a][c][1]);
			addmod(dp[c][a][3], dp[c][a][2]);
			addmod(dp[a][c][4], dp[a][c][3]); 
			addmod(sdp[a], dp[a][c][3]);
			addmod(sdp[c], dp[a][c][3]);
		}
		//debug(sdp);
		lewo[a]--;
		sum = 0LL;
		for (auto c: All) addmod(sum, sdp[c]);
		sum = mulmod(sum, inv2);
		//debug(sum, ans);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
