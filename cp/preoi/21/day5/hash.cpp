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

struct H {
    typedef uint64_t ull;
    ull x;
    H(ull x = 0) : x(x) {}
#define OP(O, A, B)                         \
    H operator O(H o)                       \
    {                                       \
        ull r = x;                          \
        asm(A "addq %%rdx, %0\n adcq $0,%0" \
            : "+a"(r)                       \
            : B);                           \
        return r;                           \
    }
    OP(+, , "d"(o.x))
    OP(*, "mul %1\n", "r"(o.x)
       : "rdx")
    H operator-(H o)
    {
        return *this + ~o.x;
    }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (long long)1e11 + 3;

struct HashInterval {
    vector<H> ha, pw;
    HashInterval() {}
    void init(string &str)
    {
        ha.resize(sz(str) + 1);
        pw.resize(sz(str) + 1);
        pw[0] = 1;
        rep(i, 0, sz(str))
            ha[i + 1] = ha[i] * C + str[i],
                   pw[i + 1] = pw[i] * C;
    }
    H operator()(int a, int b)
    {
        b++;
        return ha[b] - ha[a] * pw[b - a];
    }
};

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vi a(n+1, 0);
	rep(i, 1, n+1) {
		char c; cin >> c;
		if (c == '1') a[i] = 1;
	}
	s = "$"+s;
	HashInterval hasz;
	hasz.init(s);
	vector<pair<LL, int>>h;
	rep(i, 1, n+1){
		rep(j, i, n+1){
			if (a[j]) continue;
			h.pb({hasz(i, j).x, j-i+1});
		}
	}
	sort(all(h));
	LL ans = 0, ile = 1;
	rep(i, 1, sz(h)){
		if (h[i] == h[i-1]) ile++;
		else {
			ans = max(ans, ile*h[i-1].nd);
			ile = 1;
		}
	}
	ans = max(ans, ile*(LL)h.back().nd);
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
