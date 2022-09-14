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

void solve(){
	int n; cin >> n;
	vector<vector<int>>d(4, vector<int>(4));
	cin >> d[1][2];
	cin >> d[2][3];
	cin >> d[3][1];
	d[2][1] = d[1][2];
	d[3][2] = d[2][3];
	d[1][3] = d[3][1];
	vector<vector<int>>dist = d;
	int root = -1;
	for (int x = 1; x <= 3; x++){
		for (int y = 1; y <= 3; y++){
			for (int z = 1; z <= 3; z++){
				if (x == y || x == z || y == z) continue;
				//check if z on path
				if (d[x][z] + d[z][y] == d[x][y]){
					root = z;
				}
			}
		}
	}
	vector<pair<int, int>>edges;
	auto check = [&](){
		// debug(edges);
		vector<vector<int>>g(n+1);
		for (auto [x, y]:edges){
			g[x].emplace_back(y);
			g[y].emplace_back(x);
		}
		vector<int>depth(n+1);

		function<void(int, int)>dfs = [&](int v, int pa){
			for (auto x: g[v]){
				if (x == pa) continue;
				depth[x] = depth[v]+1;
				dfs(x, v);
			}
		};

		dfs(1, 1);
		if (dist[1][2] != depth[2] || dist[1][3] != depth[3]) return 0;
		depth.assign(n+1, 0);
		dfs(2, 2);
		if (dist[2][3] != depth[3]) return 0;
		return 1;
	};


	if (root != -1){
		int cnt = 4;
		
		for (int x = 1; x<=3; x++){
			if (x == root) continue;
			int last = root;
			while (d[root][x] > 1){
				edges.emplace_back(last, cnt);
				last = cnt;
				cnt++;
				d[root][x]--;
			}
			edges.emplace_back(last, x);
		}
		while (cnt <= n){
			edges.emplace_back(root, cnt);
			cnt++;
		}
		for (auto [x, y]:edges){
			if (x > n || y > n){
				cout << "NO\n";
				return;
			}
		}
		if (!check()){
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		for (auto [x, y]:edges){
			cout << x << " " << y << "\n";
		}
		return;
	}
	int xy = d[1][2];
	int yz = d[2][3];
	int xz = d[1][3];
	if ((xy + yz + xz ) % 2 == 1){
		cout << "NO\n";
		return;
	}
	int s = (xy+yz+xz)/2;
	int x = s-yz;
	int y = s-xz;
	int z = s-xy;
	if (x <= 0 || y <= 0 || z <= 0){
		cout << "NO\n";
		return;
	}
	vector<int>curr = {x, y, z};
	root = 4;
	// debug(curr);
	int cnt = 5;
	for (int x = 0; x<3; x++){
		int last = root;
		while (curr[x] > 1){
			edges.emplace_back(last, cnt);
			last = cnt;
			cnt++;
			curr[x]--;
		}
		edges.emplace_back(last, x+1);
	}
	while (cnt <= n){
		edges.emplace_back(root, cnt);
		cnt++;
	}
	for (auto [x, y]:edges){
		if (x > n || y > n){
			cout << "NO\n";
			return;
		}
	}
	if (!check()){
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
	for (auto [x, y]:edges){
		cout << x << " " << y << "\n";
	}
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}