//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
const int M = 15;
vector<int>d[M];

void solve(){
	int L, R; cin >> L >> R;
	int all = (R-L+1)*(R-L)*(R-L-1)/6;
	auto pairs = [&](int k){return k*(k-1)/2;};
	auto lcm = [&](int a, int b, int c){
		int x = a * b / __gcd(a, b);
		return x * c / __gcd(x, c);
	};
	int bad = 0;
	for (int k = L+2; k<=R; k++){
		for (int i: d[2*k]){
			for (int j: d[2*k]){
				if (i >= j) continue;
				if (k <= j) continue;
				if (lcm(i, j, k) == k || (lcm(i, j, k) == 2*k && i + j > k)){
					bad++;
					debug(i, j, k);
				}
			}
		}
	}
	cout << all-bad << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i<M; i++){
		for (int j = i; j<M; j+=i){
			d[j].emplace_back(i);
		}
	}
	for (int i = 1; i<M; i++){
		debug(i, d[i]);
	}
	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}