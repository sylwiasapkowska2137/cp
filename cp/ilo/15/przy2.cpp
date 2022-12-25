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
const int oo = 1e9+7, nax = 101, mx = 1e5+1;
const int mx2 = 5e7+1;
vector<pair<int, int>>g[mx], q[mx2];
int dist[mx][nax];
int n;

inline void read(int &x){
    int c = getchar_unlocked();
    x = 0;
    while(c<48 || c>57) c=getchar_unlocked();
    for (; c>47 && c<58; c = getchar_unlocked()){
        x=(x<<1)+(x<<3)+(c-48);
    }
}

void solve(){
	int m; read(n); read(m);
	if (n == 1){
		cout << "0\n";
		return;
	}
	for (int i = 0; i<m; i++){
		int a, b, c; read(a); read(b); read(c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	
	q[0].emplace_back(1, 0);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<nax; j++){
			dist[i][j] = oo;
		}
	}
	dist[1][0] = 0;
	for (int d = 0; d<=m*nax; d++){
		while (q[d].size()){
			auto [v, mx] = q[d].back();
			q[d].pop_back();
			if (dist[v][mx] < d) continue;
			for (auto [x, c]:g[v]){
				int new_mx = max(mx, c);
				if (dist[x][new_mx] > dist[v][mx] - mx + new_mx + c){
					dist[x][new_mx] = dist[v][mx] - mx + new_mx + c;
					q[dist[x][new_mx]].emplace_back(x, new_mx);
				}
			}
		}
	}
	int ans = oo;
	for (int i = 0; i<nax; i++){
		ans = min(ans, dist[n][i]);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
