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

// #define int long long
// const int oo = 1e18, oo2 = 1e9+7, K = 30;
// const int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector a(n+1, vector<char>(n+1));
	vector b(n+1, vector<char>(n+1));

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

	auto check = [&](){
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=n; j++){
				if (a[i][j] != b[i][j]) return 0;
		}
			}
		return 1;	
	};

	vector c(n+1, vector<char>(n+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			c[i][n-j+1] = a[i][j];
		}
	}

	bool ok = 1;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			if (b[i][j] != c[i][j]) ok = 0;
			// cerr << c[i][j] << " ";
		}
		// cerr << "\n";
	}
	
	if (ok){
		cout << "TAK\n";
		return;
	}
	ok = 1;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			c[n-i+1][j] = a[i][j];
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			if (b[i][j] != c[i][j]) ok = 0;
			// cerr << c[i][j] << " ";
		}
		// cerr << "\n";
	}
	if (ok){
		cout << "TAK\n";
		return;
	}

	auto rotate = [&](){
		vector d(n+1, vector<char>(n+1));
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=n; j++){
				d[j][n-i+1] = a[i][j];
			}
		}
		// for (int i = 1; i<=n; i++){
		// 	for (int j = 1; j<=n; j++){
		// 		cerr << c[i][j] << " ";
		// 	}
		// 	cerr << "\n";
		// }
		// cerr << "\n";
		a = d;
	};

	for (int i = 0; i<=4; i++){
		if (check()){
			cout << "TAK\n";
			return;
		}
		rotate();
	}
	cout << "NIE\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}