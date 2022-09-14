//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

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

const int oo = 1e9+7, K = 30;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
pair<int, int>start, koniec;
vector<pair<int, int>>dres;
int n, m;

void bfs1(int mid, vector<vector<char>>&tab2){
	queue<pair<int, int>>q;
	vector<vector<int>>d(n+1, vector<int>(m+1, oo));
	for (auto x: dres) {
		q.push(x);
		if (mid >= 0) tab2[x.first][x.second] = '#';
		d[x.first][x.second] = 0;
	}
	while (!q.empty()){
		pair<int, int>v = q.front(); q.pop();
		if (d[v.first][v.second] >= mid) continue;
		for (int i = 0; i<4; i++){
			pair<int, int> s = {v.first+x[i], v.second+y[i]};
			if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
				if (d[s.first][s.second] != oo) continue;
				d[s.first][s.second] = d[v.first][v.second]+1;
				if (d[s.first][s.second] <= mid) {
					tab2[s.first][s.second] = '#';
					q.push(s);
				}
			}
		}
	}
}

bool bfs3(vector<vector<char>>&tab, vector<pair<int, int>>&src, pair<int, int>K){
	vector<vector<bool>>vis(n+1, vector<bool>(m+1, 0));
	queue<pair<int, int>>q;
	for (auto x:src){
		if (tab[x.first][x.second] == '#') continue;
		q.push(x);
		vis[x.first][x.second] = 1;
	}
	while (!q.empty()){
		pair<int, int>v = q.front(); q.pop();
		for (int i = 0; i<4; i++){
			pair<int, int> s = {v.first+x[i], v.second+y[i]};
			if (tab[s.first][s.second] != '#'){
				if (vis[s.first][s.second]) continue;
				vis[s.first][s.second] = 1;
				q.push(s);
			}
		}
	}
	return (vis[K.first][K.second]);
}

void solve(){
	cin >> n >> m;
	vector<vector<char>>tab(n+2, vector<char>(m+2, '#')), tab2;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> tab[i][j];
			if (tab[i][j] == 'J') start = {i, j};
			if (tab[i][j] == 'S') koniec = {i, j};
			if (tab[i][j] == 'D') dres.emplace_back(i, j);
		}
	}
	vector<pair<int, int>>s = {start};
	if (!bfs3(tab, s, koniec)){
		cout << "NIE\n";
		return;
	}
	if (!bfs3(tab, dres, start)){
		cout << "OK\n";
		return;
	}
	int L = -1, R = n+69, ans = oo;
	while (R>=L){
		int mid = (L+R)/2;
		tab2 = tab;
		bfs1(mid, tab2);
		if (bfs3(tab2, s, koniec)){
			ans = mid;
			L = mid+1;
		} else R = mid-1;
	}
	if (ans == oo) cout << "NIE\n";
	else cout << ans+1 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
