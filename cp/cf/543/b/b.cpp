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

const int MAX = 3007, INF = 1e9+7;
vector<int>graf[MAX];
int dist[MAX][MAX];
int n;


void bfs(int from){
	queue<int>q;
	q.push(from);
	for (int i = 1; i<=n; i++) dist[from][i] = INF;
	dist[from][from] = 0;
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (auto x: graf[v]){
			if (dist[from][x] == INF){
				dist[from][x] = dist[from][v]+1;
				q.push(x);
			}
		}
	}
}

void solve(){
	int  m; cin >> n >> m;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i = 1; i<=n; i++) bfs(i);
	int s[2], t[2], l[2];
	for (int i = 0; i<2; i++) cin >> s[i] >> t[i] >> l[i];
	if (dist[s[0]][t[0]] > l[0] || dist[s[1]][t[1]] > l[1]){
		cout << "-1\n";
		return;
	}
	int ans = dist[s[0]][t[0]]+dist[s[1]][t[1]];
	for (int A = 1; A<=n; A++){
		for (int B = 1; B<=n; B++){
			if (dist[s[0]][A]+dist[A][B]+dist[B][t[0]] <= l[0] && dist[s[1]][A]+dist[A][B]+dist[B][t[1]] <= l[1])
				ans = min(ans, dist[s[0]][A]+dist[A][B]+dist[B][t[0]]+dist[s[1]][A]+dist[B][t[1]]);
			if (dist[s[0]][A]+dist[A][B]+dist[B][t[0]] <= l[0] && dist[s[1]][B]+dist[A][B]+dist[A][t[1]] <= l[1])
				ans = min(ans, dist[s[0]][A]+dist[A][B]+dist[B][t[0]]+dist[s[1]][B]+dist[A][t[1]]);
		}
	}
	cout << m-ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
