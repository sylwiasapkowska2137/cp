//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const int oo = 1e9, K = 30;

void solve(){
	int n, m, k, q; cin >> n >> m >> k >> q;
	vector<int>cnt(k+1);
	vector<vector<int>>tab(n+2, vector<int>(m+2));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> tab[i][j];
			cnt[tab[i][j]]++;
		}
	}
	vector<int>X = {-1, 1, 0, 0};
	vector<int>Y = {0, 0, -1, 1};
	vector<int>XX = {-1, -1, -1, 0, 0, 1, 1, 1};
	vector<int>YY = {-1, 0, 1, -1, 1, -1, 0, 1};
	vector<vector<bool>>vis(n+2, vector<bool>(m+2));

	auto bfs = [&](pair<int, int>src, pair<int, int>e, int x, int y){
		queue<pair<int, int>>Q;
		for (int i = max(1, x-1); i<=min(n, x+1); i++){
			for (int j = max(1, y-1); j<=min(m, y+1); j++){
				vis[i][j] = 0;
			}
		}
		Q.push(src);
		vis[src.first][src.second] = 1;
		while (Q.size()){
			pair<int,int>v = Q.front();Q.pop();
			for (int i = 0; i<4; i++){
				pair<int, int>s = {v.first+X[i], v.second+Y[i]};
				if (s == make_pair(x, y)) continue;
				if (s.first >= max(1, x-1) && s.second >= max(1, y-1) && s.first <= min(x+1, n) && s.second <= min(m, y+1)){
					if (!vis[s.first][s.second] && tab[s.first][s.second] == tab[x][y]){
						vis[s.first][s.second] = 1;
						Q.push(s);
					}
				}
			}
		}
		return vis[e.first][e.second];
	};

	while (q--){
		int x, y, ck; cin >> x >> y >> ck;
		// for (int i = 1; i<=n; i++){
		// 	for (int j = 1; j<=m; j++){
		// 		cerr << tab[i][j] << " ";
		// 	}
		// 	cerr << "\n";
		// }
		// cerr << "\n";
		int p = tab[x][y];
		if (p == ck) {
			cout << "YES\n";
			continue;
		}
		cnt[p]--;
		if (!cnt[p]){
			;
		} else {
			vector<pair<int, int>>curr;
			for (int i = 0; i<4; i++){
				pair<int, int>s = {x+X[i], y+Y[i]};
				if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
					if (tab[s.first][s.second] == tab[x][y]){
						curr.emplace_back(s);
					}
				}
			}
			if (curr.size() != 1) {
				int ile = 0;
				for (int i = 0; i<8; i++){
					pair<int, int>s = {x+XX[i], y+YY[i]};
					if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
						if (tab[s.first][s.second] == tab[x][y]){
							ile++;
						}
					}
				}
				if (ile == 8){
					// debug(111);
					cout << "NO\n";
					cnt[p]++;
					continue;
				}
				bool ok = 1;
				for (int i = 0; i<(int)curr.size(); i++){
					for (int j = i+1; j<(int)curr.size(); j++){
						ok &= bfs(curr[i], curr[j], x, y);
					}
				}
				if (!ok){
					// debug(222);
					cnt[p]++;
					cout << "NO\n";
					continue;
				}
			}
		}
		cnt[ck]++;
		tab[x][y] = ck;
		if (cnt[ck] == 1){
			int ile = 0;
			for (int i = 0; i<8; i++){
				pair<int, int>s = {x+XX[i], y+YY[i]};
				if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
					if (tab[s.first][s.second] == p){
						ile++;
					}
				}
			}
			// debug(ile);
			if (ile == 8){
				// debug(111);
				cout << "NO\n";
				cnt[p]++;
				cnt[ck]--;
				tab[x][y] = p;
				continue;
			}
		} else {
			vector<pair<int, int>>curr;
			for (int i = 0; i<4; i++){
				pair<int, int>s = {x+X[i], y+Y[i]};
				if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
					if(tab[s.first][s.second] == tab[x][y]){
						curr.emplace_back(s);
					}
				}
			}
			if (curr.empty()){
				// debug(333);
				cout << "NO\n";
				tab[x][y] = p;
				cnt[ck]--;
				cnt[p]++;
				continue;
			}
			bool ok = 1;
			for (int i = 0; i<(int)curr.size(); i++){
				for (int j = i+1; j<(int)curr.size(); j++){
					ok&=bfs(curr[i], curr[j], x, y);
				}
			}
			if (!ok){
				// debug(444);
				cout << "NO\n";
				tab[x][y] = p;
				cnt[ck]--;
				cnt[p]++;
				continue;
			}
		}
		cout << "YES\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
