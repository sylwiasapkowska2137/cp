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
	vector<vector<int>>a(n+1, vector<int>(n+1, 1));
	vector vis(n+1, vector<int>(n+1));
	for (int rep = n; rep >= 1; rep--){
		queue<pair<int, int>>q;
		vis[rep][rep] = 1;
		q.push({rep, rep});
		a[rep][rep] = rep;
		while (q.size()){
			pair<int, int>v = q.front();q.pop();
			pair<int, int>s = {v.first+v.second, v.second};
			if (s.first <= n && s.second <= n && !vis[s.first][s.second]) {
				vis[s.first][s.second] = 1;
				a[s.first][s.second] = a[v.first][v.second];
				q.push(s);
			}
			s = {v.first, v.first+v.second};
			if (s.first <= n && s.second <= n && !vis[s.first][s.second]){
				vis[s.first][s.second] = 1;
				a[s.first][s.second] = a[v.first][v.second];
				q.push(s);
			}
		}
	}
	
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=n; j++){
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
