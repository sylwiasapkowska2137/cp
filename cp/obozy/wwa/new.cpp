//Jakub Misiaszek
//szablon czesciowo skopiowany z profilu https://codeforces.com/profile/Geothermal
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
  
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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}

void solve(){
	LL q; cin >> q;
	
	vll prim;
	vi isp(1e7+2,0);
	prim.pb(2);
	for(LL i = 2; i<sz(isp); i++){
		if(!isp[i]){
			isp[i] = i;
			prim.pb(i);
			for(LL k=i*i; k<sz(isp); k+=i) isp[k] = i;
		}
	}
	
	
	while(q--){
		LL n; cin >> n;
		map<int, int>cnt;
		for (auto x: prim){
			if (n%x == 0){
				while (n%x == 0){
					cnt[x]++;
					n/=x;
				}
			}
		}
		//debug(cnt);
		if (n > 1) cnt[n]++;
		LL ans = 1LL;
		
		for (auto x: cnt) ans *= (LL)(x.nd+1);
		//debug(ans);
		ans-=2;
		if(ans==2) cout << "Brian\n";
		else cout << "Jessica\n";
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
