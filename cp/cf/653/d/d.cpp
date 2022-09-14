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

const int MAX = 51;
const long long INF = 1e18+7;
vector<int>graf[MAX];

long long bfs(int s, int t, vector<int>&parent,vector<vector<long long>>&cap, int n){
	parent.assign(n+1, -1);
	parent[s] = -2;
	queue<pair<int, long long>>q;
	q.push({s, INF});
	while (!q.empty()){
		int v = q.front().first;
		long long flow = q.front().second;
		q.pop();
		for (auto x: graf[v]){
			if (parent[x] == -1 && cap[v][x]){
				parent[x] = v;
				long long newflow = min(flow, cap[v][x]);
				if (x == t) return newflow;
				q.push({x, newflow});
			}
		}
	}
	return 0;
}

bool check(long double mid, vector<vector<long long>>&C, int n, int x){
	vector<vector<long long>>cap(n+1, vector<long long>(n+1, 0));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cap[i][j] = (long long)floor((long double)C[i][j]/mid);
		}
	}
	long long flow = 0;
	vector<int>parent;
	int s = 1, t = n;
	while (1){
		long long newflow = bfs(s, t, parent, cap, n);
		if (!newflow) break;
		flow += newflow;
		int curr = t;
		while (curr != s){
			int prev = parent[curr];
			cap[prev][curr] -= newflow;
			cap[curr][prev] += newflow;
			curr = prev;
		}
	}
	return (flow >= x);
}

void solve(){
	int n, m, x; cin >> n >> m >> x;
	vector<vector<long long>>C(n+1, vector<long long>(n+1, 0));
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		graf[a].push_back(b);
		graf[b].push_back(a);
		C[a][b] += c; 
	}
	long double EPS = 1e-12;
	cout << setprecision(10) << fixed;
	cerr << setprecision(10) << fixed;
	long double L = 0, R = 1e7;
	while (R-L>EPS){
		long double mid = (L+R)/2.0;
		//cerr << mid << " ";
		if (check(mid, C, n, x)) L = mid;
		else R = mid;
	}
	
	cout << L*(long double)x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
