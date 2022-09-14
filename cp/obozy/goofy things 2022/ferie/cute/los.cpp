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

const int MAX = 2e5+7, MAXC = 2e5+7;
int cnt[MAXC];
vpii vals[MAXC];

struct segtree{
	vi tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void clear(){
		tab.assign(sz(tab), 0);
	}
	
	void update(int pos, int val){
		pos += size;
		tab[pos] = max(tab[pos], val);
		while (pos > 0){
			pos/=2;
			tab[pos] = max(tab[2*pos], tab[2*pos+1]);
		}
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

int check(vi a, int n){
	debug(a);
	vi first(MAXC, -1), pref(n+1, 0), last(MAXC, -1);
	memo(cnt, 0);
	rep(i, 0, MAXC) vals[i].clear();
	rep(i, 0, n){
		cnt[a[i]]++;
		if (first[a[i]] == -1) first[a[i]] = i;
		last[a[i]] = i;
	}
	int maxi = 0, ile = 0;
	rep(i, 1, MAXC) maxi = max(maxi, cnt[i]);
	rep(i, 1, MAXC)	if (cnt[i] == maxi) ile++;
	if (ile >= 2){
		return n;
	}
	int M;
	rep(i, 1, MAXC){
		if (cnt[i] == maxi){
			M = i;
			break;
		}
	}
	rep(i, 0, n){
		pref[i+1] = pref[i];
		if (a[i] == M) pref[i+1]++;
	}
	rep(i, 0, n){
		if (i == first[a[i]]) vals[cnt[a[i]]].pb({first[a[i]], a[i]});
	}
	segtree seg;
	int res = 0;
	seg.init(n+1);
	rep(i, 1, MAXC){
		if (vals[i].empty() || i == maxi) continue;
		sort(all(vals[i]));
		debug(i, vals[i]);
		seg.clear();
		int ptr = 0;
		rep(left, 0, n){
			int L = left, R = n-1, ans = -1;
			while (R>=L){
				int m = (L+R)/2;
				int s = pref[m+1]-pref[left];
				if (s <= i){
					ans = m;
					L = m+1;
				} else {
					R = m-1;
				} 
			}
			debug(i, left, ans);
			int s = pref[ans]-pref[left];
			if (s == i) seg.update(ans, ans-left+1);
			if (ptr < sz(vals[i]) && vals[i][ptr].st == left){
				int x = seg.query(last[vals[i][ptr].nd], n);
				debug(i, vals[i][ptr].nd, last[vals[i][ptr].nd], x);
				res = max(res, x);
				ptr++;
			}
		}
	}
	return res;
}

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int ans = check(a, n);
	reverse(all(a));
	cerr << "\n";
	ans = max(ans, check(a, n));
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
