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
const int oo = 1e9+7;

int ch(char c){
	if (c == 'P' || c == 'L') return 0;
	return 1;
}

vector<char>dd = {'P', 'L', 'G', 'D'};
int dir(char c){for (int i = 0; i<4; i++) if (dd[i] == c) return i;}

string merge(string s){
	int n = (int)s.size();
	string t;
	int R = 0;
	for (int L = 0; L<n; ){
		while (R + 1 < n && ch(s[L]) == ch(s[R+1])) R++;
		t += s[R];
		R++;
		L = R;
	}
	if (t.size() <= 2) return t;
	n = t.size();
	s.clear();
	s += t[0]; s += t[1];
	for (int i = 2; i<(int)t.size(); i++){
		if (ch(t[i]) == ch(s.back())) s.pop_back();
		s += t[i]; 
		while (s.size() >= 3 && s.back() == s[s.size()-3]) s.pop_back();
	}
	return s;
}

template<typename T>
void move(vector<vector<T>>&a, int &n, int&m, char curr){
	vector<vector<T>>b(max(n, m)+1);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j] == a[0][0]) continue;
			b[(curr == 'L' || curr == 'P') ? i : j].emplace_back(a[i][j]);
		}
	}
	vector<vector<T>>c(n+1, vector<T>(m+1, a[0][0]));
	if (curr == 'G' || curr == 'D'){
		for (int j = 1; j<=m; j++){
			if (curr == 'G'){
				for (int i = 0; i<(int)b[j].size(); i++){
					c[i+1][j] = b[j][i];
				}
			} else {
				int ptr = (int)b[j].size()-1;
				for (int i = n; i>=1; i--){
					if (ptr < 0) break;
					c[i][j] = b[j][ptr];
					ptr--;
				}
			}
		}
	} else {
		for (int i = 1; i<=n; i++){
			if (curr == 'L'){
				for (int j = 0; j<(int)b[i].size(); j++){
					c[i][j+1] = b[i][j];
				}
			} else {
				int ptr = (int)b[i].size()-1;
				for (int j = m; j>=1; j--){
					if (ptr < 0) break;
					c[i][j] = b[i][ptr];
					ptr--;
				}
			}
		}
	}
	a = c;
}

void solve(){
	int n, m; cin >> n >> m;
	vector a(n+1, vector<char>(m+1, '.'));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
		}
	}
	int k; cin >> k;
	string s; cin >> s;
	s = merge(s);
	k = (int)s.size();
	int x = (k-2)/4;
	int left = (k+2)%4;

	auto print = [&](){
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=m; j++){
				cout << a[i][j];
			}
			cout << "\n";
		}
		exit(0);
	};
	

	if (s.size() <= 6){
		for (auto c: s)	move(a, n, m, c);
		print();
	}
	move(a, n, m, s[0]);
	move(a, n, m, s[1]);
	vector<vector<int>>b(n+1, vector<int>(m+1, 0));
	int cnt = 0;
	vector<pair<int, int>>curr;
	curr.emplace_back(0, 0);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j] == '.') continue;
			b[i][j] = ++cnt;
			curr.emplace_back(i, j);
		}
	}
	vector<vector<int>>c = b;
	for (int i = 2; i<=5; i++) move(b, n, m, s[i]);
	vector<int>g(cnt+3, -1);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (b[i][j] == 0) continue;
			assert(c[i][j] != 0);
			g[c[i][j]] = b[i][j];
		}
	}
	vector<int>cycle;
	vector<int>vis(cnt+3);
	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		cycle.emplace_back(v);
		if (!vis[g[v]]) dfs(g[v]);
	};
	vector<vector<char>>ans(n+1, vector<char>(m+1, '.'));
	for (int i = 1; i<=cnt; i++){
		if (g[i] != -1 && !vis[i]){
			cycle.clear();
			dfs(i);
			for (int j = 0; j<(int)cycle.size(); j++){
				int tmp = cycle[(j+x)%(int)cycle.size()];
				ans[curr[cycle[j]].first][curr[cycle[j]].second] = a[curr[tmp].first][curr[tmp].second];
			}
		}
	}
	a = ans;
	for (int i = s.size()-left; i<k; i++) move(a, n, m, s[i]);
	print();
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
