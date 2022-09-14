//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

void solve(){
	int n, m, s, e; cin >> n >> m >> s >> e;
	vector<vector<int>>graf(n+1);
	vector<int>in(n+1, 0);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
		in[b]++;
	}
	queue<int>q;
	for (int i = 1; i<=n; i++) if (!in[i]) q.push(i);
	vector<int>topo;
	while (!q.empty()){
		int v = q.front();q.pop();
		topo.push_back(v);
		for (auto x:graf[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	//for (auto x: topo) cout << x << " ";
	//cout << "\n";
	vector<LL>dp(n+1, 0);
	const LL mod = 1e9+9;
	dp[e] = 1;
	reverse(topo.begin(), topo.end());
	for (auto v: topo){
		for (auto x: graf[v]){
			dp[v] = (dp[v]+dp[x])%mod;	
		}
	}
	cout << dp[s] << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
