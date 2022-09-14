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

#define int long long
const int oo = 1e18, K = 30;



void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>>g(n+1);
	map<pair<int, int>, int>used;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		if (a > b) swap(a, b);
		used[{a, b}]++;
	}
	string t; cin >> t;
	t = "$"+t;
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= n; i++){
		if (((int)g[i].size())&1){
			cout << "NO\n";
			return;
		}
		if (t[i] == '(') s1 += (int)g[i].size();
		else s2 += (int)g[i].size();
	}
	if (s1 != s2){
		cout << "NO\n";
		return;
	}
	vector<int>vis(n+1);
	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		for (auto x: g[v]){
			if (!vis[x]) dfs(x);
		}
	};

	int v = 1;
	for (int i = 1; i<=n; i++) if (g[i].size()) v = i;
	dfs(v);
	int cnt = 0;
	for (int i = 1; i<=n; i++) if (g[i].size()) cnt++;
	int q = accumulate(vis.begin(), vis.end(), 0);
	if (q != cnt){
		cout << "NO\n";
		return;
	}
	// cout << "YES\n";
	vector<int>euler;
	function<void()>eulerian = [&](){
		vector<int>edge(n+1, 0);
		for (int i = 1; i<=n; i++) edge[i] = (int)g[i].size();
		stack<int>s;
		int curr = 1;
		for (int i = 1; i<=n; i++) {
			if (edge[i]) {
				curr = i;
				break;
			}
		}
		s.push(curr);
		while (!s.empty()){
			// debug(euler);
			if (edge[curr]){
				s.push(curr);
				while (edge[curr]){
					int nxt = g[curr].back();
					g[curr].pop_back();
					pair<int, int>e = {curr, nxt};
					if (e.first > e.second) swap(e.first, e.second);
					if (used[e] == 0) continue;
					used[e]--;
					edge[curr]--;
					edge[nxt]--;
					curr = nxt;
					break;
				}
			} else {
				euler.emplace_back(curr);
				curr = s.top();s.pop();
			}
		}
	};
	eulerian();
	euler.pop_back();
	// debug(euler);
	int pref = 0, mm = oo;
	for (auto v: euler){
		if (t[v] == '(') pref++;
		else pref--;
		mm = min(pref, mm);
	}
	if (mm == 0){
		cout << "YES\n";
		for (auto x: euler) cout << x << " ";
		cout << "\n";
		return;
	}
	int pos = -1;
	for (int i = (int)euler.size()-1; i>=0; i--){
		mm -= (t[euler[i]] == ')'?1:-1);
		if (!mm){
			pos = i;
			break;
		}
	}
	if (pos != -1){
		debug(2137);
		cout << "YES\n";
		rotate(euler.begin(), euler.begin()+pos, euler.end());
		for (auto x: euler) cout << x << " ";
		cout << "\n";
		return;
	}
	cout << "NO\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}