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

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
const int mx = 1000;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
	return a+rng()%(b-a+1);
}

bool check(int x, vector<int>&a, int n){
	if (x <= 2 || x > 3e9) return 0;
	unordered_map<int, int>cnt;
	for(int i = 1; i<=n; i++){
		int curr = a[i]%x;
		cnt[curr]++;
		if (2 * cnt[curr] > n) return 1;
	}
	return 0;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	unordered_set<int>checked;
	for (int rep = 0; rep < 50; rep++){
		int L = p(1, n);
		int R = p(1, n);
		while (R == L) R = p(1, n);
		int d = abs(a[L]-a[R]);
		for (int p = 1; p * p <= d; p++){
			if (d % p == 0){
				if (checked.find(p) == checked.end()){
					if (check(p, a, n)){
						cout << p << "\n";
						return;
					}
					checked.insert(p);
				}
				if (checked.find(d/p) == checked.end()){
					if (check(d/p, a, n)){
						cout << d/p << "\n";
						return;
					}
					checked.insert(d/p);
				}
			}
		}
	}
	cout << "-1\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
