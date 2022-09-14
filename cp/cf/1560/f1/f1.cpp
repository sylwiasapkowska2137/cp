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

void solve(){
	int n, k; cin >> n >> k;
	int N = n;
	vector<int>d;
	while (n){
		d.emplace_back(n%10);
		n/=10;
	}
	reverse(d.begin(), d.end());
	vector<int>e = d;
	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.end());
	if (e.size() <= k){
		cout << N << "\n";
		return;
	}
	int D = oo, ans = oo;
	set<int>diff;
	for (int i = 0; i<(int)d.size(); i++){
		if (i) diff.insert(d[i-1]);
		int curr = 0;
		for (int j = 0; j<i; j++) {
			curr *= 10;
			curr += d[j];
		}
		int prev = curr;
		for (int check = d[i]+1; check<=9; check++){
			bool ok = 0;
			if (diff.find(check) == diff.end()){
				diff.insert(check);
				ok = 1;
			}
			curr*=10;
			curr += check;
			if (diff.size() < k){
				for (int j = i+1; j<(int)d.size(); j++){
					curr*=10;
				}
			} else if (diff.size() == k){
				int v = *diff.begin();
				for (int j = i+1; j<(int)d.size(); j++){
					curr*=10;
					curr += v;
				}
			}

			if (diff.size() <= k && curr >= n){
				if (D > curr-n){
					ans = curr;
					D = curr-n;
				}
			}
			if (ok) diff.erase(check);
			curr = prev;
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}