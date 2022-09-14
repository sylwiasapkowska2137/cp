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
/*
struct segtree{
	vi tab;
	int size = 1;
	
	void init(int n, vi&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		rep(i, 0, n) tab[i+size] = a[i];
		repd(i, size-1, 0) tab[i] = max(tab[2*i], tab[2*i+1]);
	}
	
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};
*/

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	pqg<pii>q;
	LL ans = 0LL;
	rep(i, 0, n){
		while (!q.empty() && q.top().st < a[i]){
			int h = q.top().st;
			int idx = q.top().nd;
			q.pop();
			//debug(idx, i);
			ans += (i-idx+1);
		}
		if (!q.empty()){
			int h = q.top().st;
			int idx = q.top().nd;
			//q.pop();
			//debug(idx, i);
			ans += (i-idx+1);
		}
		q.push({a[i], i});
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
