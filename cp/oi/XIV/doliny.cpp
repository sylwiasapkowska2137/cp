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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector a(n+2, vector<int>(n+2));
	map<int, int>cnt;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> a[i][j];
			cnt[a[i][j]]++;
		}
	}
	if (cnt.size() == 1){
		cout << "1 1\n";
		return;
	}
	int A = 0, B = 0;
	typedef pair<int, int> T;
	vector<int>X = {-1, 0, 1, -1, 1, -1, 0, 1};
	vector<int>Y = {-1, -1, -1, 0, 0, 1, 1, 1};
	vector vis(n+1, vector<int>(n+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			if (!vis[i][j]){
				queue<T>q;
				q.push({i, j});
				vis[i][j] = 1;
				bool smaller = 0, bigger = 0;
				while (q.size()){
					T v = q.front();q.pop();
					for (int k = 0; k<8; k++){
						T s = {v.first + X[k], v.second + Y[k]};
						if (min(s.first, s.second) >= 1 && max(s.first, s.second) <= n){
							if (a[v.first][v.second] == a[s.first][s.second]){
								if (!vis[s.first][s.second]){
									vis[s.first][s.second] = 1;
									q.push(s);
								}
							} else {
								if (a[s.first][s.second] < a[v.first][v.second]) smaller = 1;
								if (a[s.first][s.second] > a[v.first][v.second]) bigger = 1;
							}
						}
					}
				}
				if (bigger && smaller) continue;
				A += (int)bigger;
				B += (int)smaller;
			}
		}
	}
	cout << B << " " << A << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
