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
vll a;

LL check(LL m, int n){
	if (m < 0) return -1;
	//debug(m);
	rep(i, 0, n){
		if (a[i] < m) {
			return -1;
		}
	}
	LL pushleft = 0;
	rep(i, 0, n){
		LL x = (a[i]-pushleft)-m;
		if (x < 0) {
			return -1;
		}
		pushleft = x;
	}
	//debug(m, pushleft);
	if (!pushleft) {
		LL ans = 0LL;
		rep(i, 0, n){
			ans += (a[i]-m);
		}
		return ans;
	}
	return -1;
}

bool check2(LL m, int n){
	if (m < 0) return 0;
	//debug(m);
	LL pushleft = 0;
	rep(i, 0, n-1){
		LL x = (a[i]-pushleft)-m;
		if (x < 0) return 0;
		pushleft = x;
	}
	LL last = a.back()-pushleft;
	//debug(m, last);
	return (last >= m);
}

void solve(){
	int n; cin >> n;
	a.resize(n);
	rep(i, 0, n) cin >> a[i];
	if (*min_element(all(a)) == *max_element(all(a))){
		cout << "0\n";
		return;
	}
	LL sum = accumulate(all(a), 0LL);
	if (n&1){
		LL L = 0, R = *min_element(all(a));
		LL ans = -1;
		while (R>=L){
			LL m = (L+R)/2;
			if (check2(m, n)){
				ans = m;
				L = m+1;
			} else {
				R = m-1;
			}
		}
		//debug(ans);
		cout << check(ans, n) << "\n";
	} else {
		if (sum&1) {
			cout << "-1\n";
			return;
		}
		//n i suma parzysta
		LL L = 0, R = 1e9;
		LL ans = -1;
		while (R>=L){
			LL m = (L+R)/2;
			LL x = check(m, n);
			if (x == -1) {
				R = m-1;
			} else {
				ans = x;
				L = m+1;
			}
		}
		//debug(L);
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
