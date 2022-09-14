//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

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
const int oo = 1e18, K = 30;

struct P{
	int x, y;
	void read(){
		cin >> x >> y;
	}
	int operator*(const P &he) {
		return x*he.y-y*he.x;
	}
	P operator -(const P &he){
		return {x-he.x, y-he.y};
	}
};

void solve(){
	int n; cin >> n;
	vector<P>poly(n);
	for (auto &i: poly) i.read();
	int area = 0;
	for (int i = 0; i<n; i++){
		int nxt = (i == n-1?0:i+1);
		area += (poly[i]-poly[0])*(poly[nxt]-poly[0]);
	}
	area = abs(area);
	int r = 1, currarea = 0;
	int ans = LLONG_MAX;
	for (int l = 0; l<n; l++){
		ans = min(ans, abs(area-4*currarea));
		while (currarea*4 < area){
			int nxt = (r == n-1?0:r+1);
			currarea += abs((poly[r]-poly[l])*(poly[nxt]-poly[l]));
			ans = min(ans, abs(area-4*currarea));
			r = nxt;
		}
		int nl = (l == n-1?0:l+1);
		currarea -= abs((poly[r]-poly[l])*(poly[nl]-poly[l]));
	}
	cout << (int)ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
