//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
 
typedef vector<int> vi;
typedef vector<bool> vb;
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

#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define all(x) x.begin(), x.end()

const int MAX = 21;

void solve(){
	int n; cin >> n;
	vpll a;
	pll t; cin >> t.st >> t.nd;
	
	rep(i, 0, n){
		int x, y; cin >> x >> y;
		a.emplace_back(x, y);
	}
	
	int left = n/2;
	int right = n-left;
	map<pll, int>mapa[MAX+1];
	mapa[0][{0, 0}] = 1;
	rep(mask, 1, (1<<left)){
		pll curr = {0, 0};
		rep(j, 0, left){
			if (mask&(1<<j)){
				curr.st += a[j].st;
				curr.nd += a[j].nd;
			} 
		}
		mapa[__builtin_popcount(mask)][curr]++;
	}
	vll ans(n+1, 0);
	rep(mask, 0, (1<<right)){
		pll curr = {0, 0};
		rep(j, 0, right){
			if (mask&(1<<j)){
				curr.st += a[j+left].st;
				curr.nd += a[j+left].nd;
			}
		}
		int x = __builtin_popcount(mask);
		curr = {t.st-curr.st, t.nd-curr.nd};
		for (int i = 0; i+x<=n && i<=MAX; i++){
			ans[i+x] += (LL)mapa[i][curr];
		}
		//debug(mask, curr, __builtin_popcount(mask));
	}
	rep(i, 1, n+1) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
