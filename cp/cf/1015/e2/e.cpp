//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>>a(n+2, vector<int>(m+2, 0));
	for (int i = 1; i<=n; i++) {
		for (int j = 1; j<=m; j++){
			char c; cin >> c;
			a[i][j] = (c=='*');
		}
	}
	vector<tuple<int, int, int>>ans;
	for (int i = 2; i<n; i++){
		for (int j = 2; j<m; j++){
			if (!a[i][j]) continue;
			int mn = min({i, j, n-i, m-j});
			int s = 0;
			while (s < mn && a[i+s+1][j] && a[i-s-1][j] && a[i][j+s+1] && a[i][j-s-1]){
				s++;
				a[i][j] = a[i+s][j] = a[i-s][j] = a[i][j-s] = a[i][j+s] = 2;
			}
			if (s) ans.emplace_back(i, j, s);
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j] == 1){
				cout << "-1\n";
				return;
			}
		}
	}
	cout << (int)ans.size() << "\n";
	for (auto [a, b, c]:ans) {
		cout << a << " " << b << " " << c << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
