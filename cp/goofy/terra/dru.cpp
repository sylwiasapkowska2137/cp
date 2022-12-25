//Sylwia Sapkowska
#include <bits/stdc++.h>
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

namespace IO {
  const int MAXSIZE = 1 << 18 | 1;
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

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
vector<int>ans;
const int mx = 1e5+7, md = 52;
int32_t a[mx][3], b[mx][3];
int suf[mx][md], pref[mx][md];

int n, d;

void rec(int l, int r, vector<tuple<int, int, int>>&que){
	if (l > r || que.empty()) return;
	// debug(l, r);
	if (l == r){
		int curr = -1;
		for (int k = 0; k<3; k++){
			if (a[l][k] % d == 0){
				curr = max(curr, (int)a[l][k]);
			}
		}
		for (auto [lx, rx, i]:que) ans[i] = curr;
		return;
	}
	int mid = (l+r)/2;
	for (int i = l-1; i<=r+1; i++){
		for (int cd = 0; cd < d; cd++){
			pref[i][cd] = suf[i][cd] = -oo;
		}
	}
	pref[mid][0] = 0;
	for (int i = mid+1; i<=r; i++){
		for (int cd = 0; cd < d; cd++){
			for (int k = 0; k<3; k++){
				int prev = cd-b[i][k]+d;
				if (prev >= d) prev -= d;
				pref[i][cd] = max(pref[i][cd], pref[i-1][prev] + a[i][k]);
			}
			// debug(i, cd, pref[i][cd]);
		}
	}
	suf[mid+1][0] = 0;
	for (int i = mid; i>=l; i--){
		for (int cd = 0; cd < d; cd++){
			for (int k = 0; k<3; k++){
				int prev = cd-b[i][k]+d;
				if (prev >= d) prev -= d;
				suf[i][cd] = max(suf[i][cd], suf[i+1][prev] + a[i][k]);
			}
			// debug(i, cd, suf[i][cd]);
		}
	}
	// debug(l, r, mid);
	vector<tuple<int, int, int>>A, B;
	for (auto [lx, rx, i]:que){
		if (rx <= mid) A.emplace_back(lx, rx, i);
		else if (lx >= mid+1) B.emplace_back(lx, rx, i);
		else {
			for (int cd = 0; cd < d; cd++){
				ans[i] = max(ans[i], suf[lx][cd] + pref[rx][(d-cd)%d]);
			}
		}
	}
	que.clear();
	rec(l, mid, A);
	rec(mid+1, r, B);
}

void solve(){
	read(n); read(d);
	for (int i = 1; i<=n; i++){
		for (int j = 0; j<3; j++){
			read(a[i][j]);
			b[i][j] = a[i][j]%d;
		}
	}
	int q; read(q);
	vector<tuple<int, int, int>>que;
	for (int i = 0; i<q; i++){
		int l, r; read(l); read(r);
		que.emplace_back(l, r, i);
	}
	ans.assign(q, -1);
	rec(1, n, que);
	for (int i = 0; i<q; i++){
		cout << ans[i] << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
