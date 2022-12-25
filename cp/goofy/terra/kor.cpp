//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize ("unroll-loops")
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
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


// void read(int &number){
//     bool negative = false;
//     register int c;
//     number = 0;
//     c = getchar();
//     if (c=='-'){
//         negative = true;
//         c = getchar();
//     }
//     for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
//     if (negative) number *= -1;
// }

namespace IO {
  const int MAXSIZE = 1 << 16 | 1;
  char buf[MAXSIZE], *p1, *p2;
 
  inline int Gc() {
    return p1 == p2 &&
      (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
  }
  template<typename T> inline void read(T& x) {
    x = 0; int f = 0, ch = Gc();
    while (!isdigit(ch)) f |= ch == '-', ch = Gc();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
    if (f) x = -x;
  }
}
using IO::read;

int s;

struct Block{
	vector<int>a;
	unordered_map<int, int>cnt;
	int tmp = 0;

	Block(){
		a.resize(s);
	}

	void add_all(int &c){
		tmp += c;
	}

	void init(int &l, int &c){
		a[l%s] = c;
		cnt[c]++;
	}

	void add(int l, int r, int &c){
		l %= s, r %= s;
		for (int i = l; i<=r; i++){
			cnt[a[i]]--;
			a[i] += c;
			cnt[a[i]]++;
		}
	}

	int query_all(int &c){
		//a[i] + tmp = c
		return cnt[c-tmp];
	}

	int query(int l, int r, int &c){
		l %= s; r %= s;
		int ans = 0;
		for (int i = l; i<=r; i++){
			if (a[i] + tmp == c){
				ans++;
			}
		}
		return ans;
	}
};

void solve(){
	int n; read(n);
	s = (int)(sqrt(n));
	int k = 1;
	while (k * s <= n) k++;
	vector<Block>A(k+1);
	for (int i = 0; i<n; i++) {
		int x; read(x);
		A[i/s].init(i, x);
	}
	// for (int i = 0; i<(int)A.size(); i++){
	// 	debug(i, A[i].a);
	// }
	// debug(s);

	int q; read(q);
	while (q--){
		int t; read(t);
		if (t == 1){
			int l, r, c; read(l); read(r); read(c);
			l--;r--;
			int L = l/s;
			int R = r/s;
			if (L == R)	A[L].add(l, r, c);
			else{
				A[L].add(l, l+s-l%s-1, c);
				for (int i = L+1; i<R; i++) A[i].tmp += c;
				A[R].add(r-r%s, r, c);
			}
		} else {
			int l, r, d; read(l); read(r); read(d);
			l--;r--;
			int L = l/s;
			int R = r/s;
			int ans = 0;
			if (L == R)	ans += A[L].query(l, r, d);
			else{
				ans += A[L].query(l, l+s-l%s-1, d);
				for (int i = L+1; i<R; i++) ans += A[i].cnt[d-A[i].tmp];
				ans += A[R].query(r-r%s, r, d);
			}
			cout << ans << "\n";
		}
		// return;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
