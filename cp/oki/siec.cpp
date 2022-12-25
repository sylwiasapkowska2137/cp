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

void solve(){
	int n; cin >> n;
	vector dist(n+1, vector<int>(n+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> dist[i][j];
		}
	}
	vector<pair<int, int>>ans;
	for (int a = 1; a <= n; a++){
		for (int b = a+1; b <= n; b++){
			bool ok = 1;
			for (int c = 1; c <= n; c++){
				if (c == a || c == b) continue;
				if (dist[a][c] + dist[b][c] <= dist[a][b]){
					ok = 0;
					break;
				}
			}
			if (ok){
				ans.emplace_back(a, b);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (auto [x, y]:ans) cout << x << " " << y << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
