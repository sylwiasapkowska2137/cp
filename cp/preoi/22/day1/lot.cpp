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
	n--;
	if (n == 0){
		cout << "TAK\n1 1\n";
		return;
	}
	if ((n%4) == 0 || (n%4) == 3){
		cout << "TAK\n";
		int X = (n+1)/4;
		int a = 2*X-1;
		int b = 4*X-2;
		int c = 4*X-1;
		int d = 4*X;
		vi p, q, r, s;
		rep(i, 1, a){
			if (i&1) p.pb(i);
			else q.pb(i);
		}
		rep(i, a+1, b){
			if (i&1) r.pb(i);
			else s.pb(i);
		}
		//debug(X, a, b, c, d, p, q, r, s);
		if ((n%4) == 0){
			
			reverse(all(s));
			for (auto x: s) cout << x+1 << " ";
			reverse(all(s));
			reverse(all(p));
			for (auto x: p) cout << x+1 << " ";
			reverse(all(p));
			cout << b+1 << " ";
			for (auto x: p) cout << x+1 << " ";
			cout << c+1 << " ";
			for (auto x: s) cout << x+1 << " ";
			cout << d+1 << " ";
			reverse(all(r));
			for (auto x: r) cout << x+1 << " ";
			reverse(all(r));
			reverse(all(q));
			for (auto x: q) cout << x+1 << " ";
			reverse(all(q));
			cout << b+1 << " " << a+1 << " ";
			for (auto x: q) cout << x+1 << " ";
			cout << c+1 << " ";
			for (auto x: r) cout << x+1 << " ";
			cout << a+1 << " " << d+1 << " ";
			cout << "1 1\n";
		} else {
			reverse(all(s));
			for (auto x: s) cout << x+1 << " ";
			reverse(all(s));
			reverse(all(p));
			for (auto x: p) cout << x+1 << " ";
			reverse(all(p));
			cout << b+1 << " ";
			for (auto x: p) cout << x+1 << " ";
			cout << c+1 << " ";
			for (auto x: s) cout << x+1 << " ";
			cout << a+1 << " ";
			reverse(all(r));
			for (auto x: r) cout << x+1 << " ";
			reverse(all(r));
			reverse(all(q));
			for (auto x: q) cout << x+1 << " ";
			reverse(all(q));
			cout << b+1 << " " << a+1 << " ";
			for (auto x: q) cout << x+1 << " ";
			cout << c+1 << " ";
			for (auto x: r) cout << x+1 << " ";
			cout << "1 1\n";
		}
	} else {
		cout << "NIE\n";
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
