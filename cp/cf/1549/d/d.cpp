//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops") 
using namespace std;
typedef long long LL;


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


#define int long long
int n;

struct segtree{
	vector<LL>tab;
	int size = 1;

	void init(int n){
		size = 1;
		while (size < n) size <<= 1;
		tab.clear();
		tab.assign(2*size+1, 1);
	}

	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = __gcd(ans, tab[l+1]);
			if (r&1) ans = __gcd(ans, tab[r-1]);
			l>>=1, r>>=1;
		}
		return ans;
	}
} seg;


LL read() {
	bool minus = false;
	LL result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; 
	else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result* 10LL + (ch - '0');
	}
	if (minus) result = -result;
	return result;
}

bool check(int m){
	int l = 0;
	while (l+m < n-1){
		if (seg.query(l, l+m) > 1) return 1;
		l++;
	}
	return 0;
}

void solve(){
	n = read();
	LL prev = -1;
	seg.init(n-1);
	for (int i = 1; i<=n; i++){
		LL x = read();
		if (prev != -1)	seg.tab[i+seg.size-2] = abs(prev-x);
		prev = x;
	}
	for (int i = seg.size-1; i>=1; i--) seg.tab[i] = __gcd(seg.tab[2*i], seg.tab[2*i+1]);
	int L = 0, R = n-1;
	int ans = -1;
	while (R>=L){
		int m = (L+R)>>1;
		//debug(m);
		if (check(m)) {
			ans = m;
			L = m+1;
		} else R = m-1;
	}
	cout << ans+2 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = read();
	while (t--) solve();
	
	return 0;
}
