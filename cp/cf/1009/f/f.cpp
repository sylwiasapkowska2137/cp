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

const int MAX = 1e6+7;
vector<int>graf[MAX];
map<int, int>cnt[MAX];
vector<int>depth;
vector<pair<int, int>>res;

void dfs(int v, int pa = -1){
	cnt[v][depth[v]] = 1;
	res[v] = {1, -depth[v]};
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
			if ((int)cnt[x].size() > (int)cnt[v].size()){
				swap(cnt[x], cnt[v]);
				res[v] = res[x];
			}
			for (auto i: cnt[x]){
				cnt[v][i.first] += i.second;
				res[v] = max(res[v], {cnt[v][i.first], -i.first});
			}
		}
	}
}

void solve(){
	int n; cin >> n;
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	res.assign(n+1, {0, 0});
	depth.assign(n+1, 0);
	dfs(1);
	for (int i = 1; i<=n; i++) cout << -res[i].second-depth[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
