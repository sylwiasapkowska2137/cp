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

const int MAX = 1001;
int graf[MAX][MAX];

void solve(){
	int n, m, k; cin >> n >> m >> k;	
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		graf[a][b] = 1;
		graf[b][a] = 1;
	}
	while (k--){
		int v; cin >> v;
		vector<int>tab(v);
		for (int i = 0; i<v; i++){
			cin >> tab[i];
		}
		for (int i = 0; i<v; i++){
			for (int j = 0; j<v; j++){
				if (i == j) continue;
				graf[tab[i]][tab[j]] ^= 1;
			}
		}
		int ans = 0;
		for (int i = 1; i<=n; i++){
			bool ile = 0;
			for (int j = 1; j<=n; j++){
				if (i == j) continue;
				ile += (graf[i][j]);
			}
			if (ile == 0) ans++;
		}
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
