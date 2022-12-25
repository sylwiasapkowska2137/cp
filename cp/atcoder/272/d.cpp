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

void solve(){
	int n; cin >> n;
	int m; cin >> m;
	queue<pair<int, int>>q;
	q.push({1, 1});
	vector<vector<int>>vis(n+1, vector<int>(n+1, oo));
	vis[1][1] = 0;
	while (q.size()){
		auto v = q.front();q.pop();
		for (int check = 1; check <= n; check++){
			int curr = m - (v.first - check)*(v.first-check);
			if (curr < 0) continue;
			int s = sqrt(curr);
			if (s * s == curr){
				int x = s + v.second;
				if (x >= 1 && x <= n){
					// debug(x);
					if (vis[check][x] == oo) {
						vis[check][x] = vis[v.first][v.second]+1;
						q.push({check, x});
					}
				}
				// continue;
				x = v.second - s;
				if (x >= 1 && x <= n){
					if (vis[check][x] == oo) {
						vis[check][x] = vis[v.first][v.second]+1;
						q.push({check, x});
					}
				}
			}
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			if (vis[i][j] == oo) cout << "-1 ";
			else cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
