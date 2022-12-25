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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int n, m; cin >> n >> m;
	set<T>edge;
	map<T, char>mp;
	vector<vector<pair<int, char>>>g(n+1);
	vector<vector<pair<int, char>>>gt(n+1);
	for (int i = 0; i<m; i++){
		int a, b; char c; cin >> a >> b >> c;
		edge.insert({a, b});
		g[a].emplace_back(b, c);
		mp[{a, b}] = c;
		gt[b].emplace_back(a, c);
	}
	int d; cin >> d;
	vector<int>s(d);
	for (int i = 0; i<d; i++) cin >> s[i];
	auto count = [&](int a, int b){
		// debug(a, b);
		queue<T>q;
		vector<vector<T>>dp(n+1, vector<T>(n+1, {-1, -1}));
		dp[a][b] = {a, b};
		q.push({a, b});
		T found = {-1, -1};
		while (q.size()){
			T v = q.front();q.pop();
			if (v.first == v.second){
				found = v;
				break;
			}
			if (edge.find({v.first, v.second}) != edge.end()){
				found = v;
				break;
			}
			// debug(v);
			for (auto [x1, c1]: g[v.first]){
				for (auto [x2, c2]: gt[v.second]){
					if (c1 == c2){
						if (dp[x1][x2].first == -1){
							dp[x1][x2] = v;
							q.push({x1, x2});
						}
					}
				}
			}
		}
		// debug(found);
		
		if (found.first == -1){
			cout << "-1\n";
			return;
		}
		T f = found;
		string ans;
		while (found != make_pair(a, b)){
			ans += mp[{dp[found.first][found.second].first, found.first}];
			found = dp[found.first][found.second];
		}
		string tmp = ans;
		reverse(ans.begin(), ans.end());
		if (found.first != found.second) ans += mp[{f.first, f.second}];
		ans += tmp;
		cout << (int)ans.size() << " " << ans << "\n";
	};
	for (int i = 1; i<d; i++) count(s[i-1], s[i]);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
