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
const int MAX = 101, D = 51;
LL MOD;
LL ways[MAX][MAX][D];
LL good[MAX][MAX][D];
LL dp[D][2];

void solve(){
	int m; cin >> n >> m >> MOD;
	rep(i, 1, n+1) ways[i][i][0] = 1;
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		ways[a][b][1]++;
	}
	
	rep(K, 2, D) {
		//rep(i, 1, n+1) rep(j, 1, n+1) ways[i][j][K] = (i==j);
		rep(i, 1, n+1){
			rep(j, 1, n+1){
				rep(k, 1, n+1){
					ways[i][j][K] += ways[i][k][K-1]*ways[k][j][1];
					ways[i][j][K]%=MOD;
				}
			}
		}
	}
	/*
	rep(k, 1, 7){
		rep(i, 1, n+1){
			rep(j, 1, n+1){
				cerr << ways[i][j][k] << " ";
			}
			cerr << "\n";
		}
		cerr << "\n";
	}
	return;
	*/
	
	rep(a, 1, n+1){
		rep(b, 1, n+1){
			dp[0][0] = -1;
			rep(i, 1, D){
				dp[i][0] = 0;
				dp[i][1] = 0;
				rep(j, 0, i){
					dp[i][0] -= dp[j][0]*ways[a][a][i-j];
					dp[i][0] %= MOD;
					dp[i][1] -= dp[j][0]*ways[a][b][i-j];
					dp[i][1] %= MOD;
					dp[i][0] -= dp[j][1]*ways[b][a][i-j];
					dp[i][0] %= MOD;
					dp[i][1] -= dp[j][1]*ways[b][b][i-j];
					dp[i][1] %= MOD;
				}
				good[a][b][i] = (dp[i][1]%MOD+MOD)%MOD;
			}
		}
	}
	int q; cin >> q;
	rep(i, 0, q){
		int a, b, d; cin >> a >> b >> d;
		cout << good[a][b][d] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
