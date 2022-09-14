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
const int oo = 1e18, K = 62;
const int N = 3e5+1;

void solve(){
	int n, c, k; cin >> n >> c >> k;
	vector<vector<int>>color(c);
	for (int i = 0; i<n; i++){
		int d, v; cin >> d >> v;
		d--;
		color[d].emplace_back(v);
	}
	sort(color.begin(), color.end(), [&](auto a, auto b){return (int)a.size() > (int)b.size();});
	int x = 1;
	vector<int>A, B;
	for (int i = 0; i<c; i++){
		int y = (int)color[i].size();
		if (x*y<=N){
			x*=y;
			A.emplace_back(i);
		} else {
			B.emplace_back(i);
		}
	}
	vector<int>a = {0}, b = {0};
	for (auto x: A){
		vector<int>tmp;
		for (auto v: a){
			for (auto y: color[x]){
				tmp.emplace_back(v^y);
			}
		}
		a = tmp;
	}
	for (auto x: B){
		vector<int>tmp;
		for (auto v: b){
			for (auto y: color[x]){
				tmp.emplace_back(v^y);
			}
		}
		b = tmp;
	}
	sort(a.begin(), a.end());
	
	int mask = 0, ans = 0;
	for (int i = K-1; i>=0; i--){
		mask |= (1LL<<i);
		map<int, int>cnt;
		for (auto v: b) cnt[v&mask]++;
		ans ^= (1LL<<i);
		int tmp = 0;
		for (auto v: a){
			tmp += cnt[(v&mask)^ans];
		}
		if (tmp < k){
			ans ^= (1LL<<i);
			k-=tmp;
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
