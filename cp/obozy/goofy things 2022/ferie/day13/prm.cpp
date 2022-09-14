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

struct segtree{
	vi tab;
	int size = 1;
	
	segtree(int n, vi&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, INF);
		rep(i, 0, n) tab[i+size] = a[i];
		repd(i, size-1, 1) tab[i] = min(tab[2*i], tab[2*i+1]);
	}
	
	void update(int pos, int val){
		pos+=size;
		tab[pos] = val;
		while (pos>0){
			pos/=2;
			tab[pos] = min(tab[2*pos], tab[2*pos+1]);
		}
	}
	
	int query(int l, int r){
		int ans = INF;
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


struct segtreesum{
	vi tab;
	int size = 1;
	
	segtreesum(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		rep(i, 0, n) tab[i+size] = 1;
		repd(i, size-1, 1) tab[i] = tab[2*i]+tab[2*i+1];
	}
	
	void update(int pos){
		pos+=size;
		while (pos>0){
			tab[pos]--;
			pos/=2;
		}
	}
	
	int query(int l, int r){
		int ans = 0;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2; 
		}
		return ans;
	}
};

void f(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void solve(){
	int n, k; 
	f(n); f(k);
	vi a(n), b(k);
	rep(i, 0, n) f(a[i]);
	vb vis(n+1, 0);
	rep(i, 0, k) {
		f(b[i]);
		vis[b[i]] = 1;
	}
	LL res = 0LL;
	segtree seg(n, a);
	segtreesum segsum(n);
	vpii c(n);
	rep(i, 0, n) c[i] = {a[i], i};
	sort(all(c));
	rep(i, 0, n){
		if (vis[c[i].st]) {
			//seg.update(c[i].nd, INF);
			//segsum.update(c[i].nd);
			continue;
		}
		int L = 0, R = c[i].nd-1, ans = c[i].nd, ans2 = c[i].nd;
		while (R>=L){
			int m = (L+R)/2;
			if (seg.query(m, c[i].nd) < c[i].st){
				L = m+1;
			} else {
				ans = m;
				R = m-1;
			}
		}
		L = c[i].nd+1, R = n-1;
		while (R>=L){
			int m = (L+R)/2;
			if (seg.query(c[i].nd, m) < c[i].st){
				R = m-1;
			} else {
				ans2 = m;
				L = m+1;
			}
		}
		//debug(c[i].st, ans, ans2, segsum.query(ans, ans2));
		res += segsum.query(ans, ans2);
		seg.update(c[i].nd, INF);
		segsum.update(c[i].nd);
	}
	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
