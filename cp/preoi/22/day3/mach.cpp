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

const int INF = 1e9+7; 



void solve(){
	int n, m, k, l; cin >> n >> m >> k >> l;
	vector<vector<vector<vi>>> tab(2+log2(n), vector<vector<vi>>(n+1, vector<vi>(2+log2(m), vi(m+1, INF))));
	rep(i, 0, n){
		rep(j, 0, m){
			cin >> tab[0][i][0][j];
		}
	}
	rep(ir, 0, n){
		rep(jc, 1, (int)log2(m)+1){
			for (int ic = 0; ic+(1<<(jc-1))<m; ic++){
				tab[0][ir][jc][ic] = min(tab[0][ir][jc-1][ic],tab[0][ir][jc-1][ic+(1<<(jc-1))]);
			}
		}
	}
	rep(jr, 1, (int)log2(n)+1){
		rep(ir, 0, n){
			rep(jc, 1, (int)log2(m)+1){
				rep(ic, 0, m){
					if (ir+(1<<(jr-1))<n) tab[jr][ir][jc][ic] = min(tab[jr-1][ir][jc][ic],tab[jr-1][ir+(1<<(jr-1))][jc][ic]);
				}
			}
		}
	}

	rep(i, 0, n-k+1){
		rep(j, 0, m-l+1){
			int x1 = i, x2 = i+k-1;
			int y1 = j, y2 = j+l-1;
			int lenx = x2-x1+1;
			int kx = log2(lenx);
			int leny = y2-y1+1;
			int ky = log2(leny);
			//debug(x1, y1, x2, y2, lenx, leny, kx, ky);
			int min_R1 = min(tab[kx][x1][ky][y1], tab[kx][x1][ky][y2+1-(1<<ky)]); 
			int min_R2 = min(tab[kx][x2+1-(1<<kx)][ky][y1], tab[kx][x2+1-(1<<kx)][ky][y2+1-(1<<ky)]);
			cout << min(min_R1, min_R2) << " ";
			
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
