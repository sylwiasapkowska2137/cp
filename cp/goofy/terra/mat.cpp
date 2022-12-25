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

void solve(){
	int n; cin >> n;
	vector a(n+1, vector<int>(n+1)), b(n+1, vector<int>(n+1)), c(n+1, vector<int>(n+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> b[i][j];
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> c[i][j];
		}
	}
	int k = 10;
	while (k--){
		vector<int>p(n+1);
		for (int i = 1; i<=n; i++) p[i] = random()%2;
		// debug(p);
		vector<int>A(n+1), B(n+1), C(n+1);
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=n; j++){
				B[i] += b[i][j] * p[j];
				C[i] += c[i][j] * p[j];
			}
		}
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=n; j++){
				A[i] += a[i][j] * B[j];
			}
		}
		for (int i = 1; i<=n; i++){
			if (A[i] != C[i]){
				cout << "NIE\n";
				return;
			}
		}
	}
	cout << "TAK\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
