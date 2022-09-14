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

vll D;

LL PHI(LL n){
	LL res = n;
	for (LL d = 2; d*d<=n; d++){
		if (n%d == 0){
			D.pb(d);
			while (n%d == 0) n/=d;
			res -= res/d;
		}
	}
	if (n > 1) {
		res -= res/n;
		D.pb(n);
	}
	return res;
}

LL check(LL &n, LL &C){
	LL ans = 0LL;
	rep(mask, 1, (1<<(sz(D)))){
		int x = __builtin_popcount(mask);
		LL prod = 1LL;
		rep(i, 0, sz(D)) {
			if (mask&(1<<i)){
				prod*=D[i];
			}
		}
		if (x&1) ans += (C/prod);
		else ans -= (C/prod);
	}
	return C-ans;
}

LL binsearch(LL kth, LL &n, LL &phi){
	LL X = (kth%phi);
	bool ok = 0;
	if (X == 0) {
		X = phi;
		ok = 1;
	}
	//debug(X);
	LL L = 1, R = n, ans = n;
	while (R>=L){
		LL m = (L+R)/2;
		LL x = check(n, m);
		//debug(kth, m, x);
		if (x > X){
			R = m-1;
		} else {
			ans = m; 
			L = m+1;
		}
	}
	LL l = 1, r = ans;
	while (r>=l){
		LL m = (l+r)/2;
		if (check(n, m) >= X){
			r = m-1;
			ans = m;
		} else l = m+1;
	}
	ans += (kth/phi)*n;
	if (ok) ans-=n;
	return ans;
}

bool coprime(LL a){
	for (auto x: D){
		if (a%x == 0) return 0;
	}
	return 1;
}

void solve(){
	LL n, k, c; cin >> n >> k >> c;
	LL phi = PHI(n);
	//debug(phi);
	debug(n-phi);
	return;
	sort(all(D));
	D.erase(unique(all(D)), D.end());
	//debug(D);
	LL first = binsearch(k, n, phi);
	//debug(first);
	int i = 0;
	while (i < c){
		if (coprime(first)) {
			cout << first << " ";
			i++; 
		}
		first++;
	}
	cout << "\n"; 
	return;
	rep(i, 0, c){
		LL x = binsearch(k+i, n, phi);
		cout << x << " ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
