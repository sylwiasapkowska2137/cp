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
const int oo = 1e18, mod2 = 1e9+7, K = 30;
const int mod = 998244353;
const int base = 2137;

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

void add2(int &a, int b){
	a += b;
	if (a >= mod2) a-=mod2;
}

int mul(int a, int b){
	return (a*b)%mod;
}

int mul2(int a, int b){
	return (a*b)%mod2;
}

void solve(){
	int n, m; cin >> n >> m;
	multiset<pair<int, int>>s, t;
	for (int rep = 0; rep < 2; rep++){
		vector a(n+1, vector<char>(m+1));
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=m; j++){
				cin >> a[i][j];
			}
		}
		for (int col = 1; col <= m; col++){
			int H1 = 0, H2 = 0, p1 = 1, p2 = 1;
			for (int i = 1; i<=n; i++){
				add(H1, mul(p1, a[i][col]));
				add2(H2, mul2(p2, a[i][col]));
				p1 = mul(p1, base);
				p2 = mul(p2, base);
			}
			if (rep == 0){
				s.insert(pair<int, int>{H1, H2});
			} else {
				t.insert({H1, H2});
			}
		}

		
	}
	if (s == t) cout << "Yes\n";
	else cout << "No\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
