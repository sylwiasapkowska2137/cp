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

struct E{
	int a, b;LL c; 
	E(){}
	E(int _a, int _b, LL _c){
		a = _a, b = _b, c = _c;
	}
};

const int MAX = 307;
const LL INF = 1e18;
LL dist[MAX][MAX];
int n;

void floyd_warshall(){
	for (int k = 1; k<=n; k++){
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
}

void solve(){
	int m; cin >> n >> m;
	vector<E>e;
	for (int i = 1; i<=n; i++) for (int j = 1; j<=n; j++) dist[i][j] = INF;
	//for (int i = 1; i<=n; i++) dist[i][i] = 0;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = c;
		e.emplace_back(a, b, c);
	}
	floyd_warshall();
	int ans = 0;
	for (auto [a, b, c]:e){
		for (int i = 1; i<=n; i++){
			if (i == a || i == b) continue;
			if (dist[a][i]+dist[i][b] <= (LL)c){
				ans++;
				break;
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
