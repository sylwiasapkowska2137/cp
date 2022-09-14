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

//btw jeest jakis slaby tl do zadania tanie linie, bo na szkopule mi sie wywalilo na dwoch ostatnich paczkach XDDD
//aleee nie poprawiaj prrrrosze, nie chce musiec uzyc aliens trick;))
const int MAX = 1e5+7;
vector<pair<int, int>>graf[MAX];
vector<bool>vis;
vector<int>ans;
int n;

void dfs(int v, int pa){
	vis[v] = 1;
	for (auto [x, c]: graf[v]){
		if (!vis[x]){
			if (ans[v] == c) {
				ans[x] = 1;
				if (ans[x] == c) ans[x]++;
			} else ans[x] = c;
			dfs(x, v);
		}
	}
}

void solve(){
	int m; cin >> n >> m;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
	}
	vis.assign(n+1, 0);
	ans.assign(n+1, 1);
	dfs(1, 1);
	for (int i = 1; i<=n; i++) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
