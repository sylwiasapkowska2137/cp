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


int n;
const int MAX = 3;
const LL MOD = 1e9+7;
LL p1[MAX][MAX], pw[MAX][MAX], pp[MAX][MAX];

void kwadrat(){
	memo(pp);
	
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			rep(k, 1, n+1){
				pp[i][j] += p1[i][k]*p1[k][j];
				if (pp[i][j]>=MOD) pp[i][j]%=MOD;
			}
		}
	}
	
	rep(i, 1, n+1) rep(j, 1, n+1) p1[i][j] = pp[i][j];
}

void wymnoz(){
	memo(pp);
	
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			rep(k, 1, n+1){
				pp[i][j] += pw[i][k]*p1[k][j];
				if (pp[i][j]>=MOD) pp[i][j]%=MOD;
			}
		}
	}
	
	rep(i, 1, n+1) rep(j, 1, n+1) pw[i][j] = pp[i][j];
}

void power(LL b){
	rep(i, 1, n+1) rep(j, 1, n+1) pw[i][j] = (i==j);
	while (b){
		if (b&1) wymnoz();
		kwadrat();
		b/=2;
	}
}

void solve(){
	n = 2;
	p1[1][1] = 1;
	p1[2][1] = 1;
	p1[1][2] = 1;
	p1[2][2] = 0;
	LL k; cin >> k;
	power(k-1);
	cout << pw[1][1] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
