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

struct segtree{
	vll tab;
	int size = 1;
	LL INF = 1e18;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, INF);
	}
	
	void update(int pos, LL val){
		pos += size;
		tab[pos] = min(tab[pos], val);
		while (pos > 0){
			pos/=2;
			tab[pos] = min(tab[2*pos], tab[2*pos+1]);
		}
	}
	
	LL query(int l, int r){
		LL ans = INF;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vll a(n+1), pref(n+1), scaler;
	scaler.pb(0);
	rep(i, 1, n+1){
		cin >> a[i];
		pref[i] = pref[i-1]+a[i];
		scaler.pb(pref[i]);
	}
	if (pref[n] < 0){
		cout << "-1\n";
		return;
	}
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<LL, int>mapa;
	rep(i, 0, sz(scaler)){
		mapa[scaler[i]] = i;
	}
	segtree seg;
	seg.init(sz(scaler)+1);
	vll dp(n+1, 0);
	seg.update(mapa[0], 0);
	rep(i, 1, n+1){
		dp[i] = i+seg.query(0, mapa[pref[i]])-1;
		seg.update(mapa[pref[i]], dp[i]-i);
	}
	cout << dp[n] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
