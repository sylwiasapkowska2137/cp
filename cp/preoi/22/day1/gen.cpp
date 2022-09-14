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
	int n = p(1, 5);
	int m = p(1, 5);
	int k = p(0, min(n*m, 5));
	set<pii>s;
	cout << n << " " << m << " " << k << "\n";
	if (!k) return;
	while (1){
		rep(i, 1, n+1){
			rep(j, 1, m+1){
				int a = p(0, 1);
				if (a && s.find({i, j}) == s.end()){
					s.insert({i, j});
					cout << i << " " << j << "\n";
					k--;
					if (!k) return;
				}
			}
		}
	}
}
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

void solve2(){
	int n = p(200, 500), m = p(200, 500), k = p(1, min(200, n*m/2));
	cout << n << " " << m << " " << k << "\n";
	map<pii, vpii>q;
	while (k>0){
		int a = p(1, n);
		int b = p(1, m);
		//debug(a, b);
		rep(X, 0, 4){
			pii s = {a+x[X],b+y[X]};
			bool ok = 1;
			for (auto v: q[{a, b}]){
				if (v == s) ok = 0;
			}
			for (auto v:q[s]){
				if (v == make_pair(a, b)) ok = 0; 
			}
			if (!ok) continue;
			if (s.st >= 1 && s.nd >= 1 && s.st <= n && s.nd <= m){
				cout << a << " " << b << " ";
				cout << s.st << " " << s.nd << "\n";
				k--;
				q[{a, b}].pb(s);
				q[s].pb({a, b});
				break;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
