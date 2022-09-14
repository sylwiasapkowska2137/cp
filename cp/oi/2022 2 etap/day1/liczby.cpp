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

const int MAX = 1e6+7;
vi prime(MAX, 1);

void sito(){
	prime[0] = prime[1] = 0;
	for (LL d = 2; d<MAX; d++){
		if (prime[d] && d*d < (LL) MAX){
			for (LL j = d*d; j<MAX; j+=d){
				prime[j] = 0;
			}
		}
	}
}

LL PHI(LL n){
	LL res = n;
	for (LL d = 2; d*d<=n; d++){
		if (n%d == 0){
			while (n%d == 0) n/=d;
			res -= res/d;
		}
	}
	if (n > 1) res -= res/n;
	return res;
}

void solve(){
	LL n, k, c; cin >> n >> k >> c;
	set<LL>s;
	sito();
	for (LL d = 2; d<=n; d++){
		//if (__gcd(n, d) == 1 || (d < MAX && !prime[d])) continue;
		if (n%d == 0 && (d<MAX || prime[d])){
			for (LL i = d; i<=n; i+=d){
				s.insert(i);
			}
		}
	}
	s.insert(n);
	//debug(s);
	vpll tab;
	LL ile = 0;
	tab.pb({0, 0});
	for (auto x: s){
		tab.pb({x, x-1-ile});
		ile++;
	}
	debug(tab);
	LL phi = PHI(n);
	LL x = (k%phi);
	bool ok = 0;
	if (x == 0) {
		x = phi;
		ok = 1;
	}
	LL first = 1;
	rep(i, 1, sz(tab)){
		if (tab[i].nd >= x){
			first = tab[i-1].st+(x-tab[i-1].nd);
			break;
		}
	}
	debug(((n-phi) <= 1e6));
	//return;
	debug(first);
	first += (k/phi)*n;
	if (ok) first -= n;
	int i = 0;
	while (i < c){
		if (__gcd(first, n) == 1) {
			cout << first << " ";
			i++; 
		}
		first++;
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
