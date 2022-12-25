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

const int oo = 1e9+7;
typedef pair<int, int> T;
const int mx = 1003;
bool h[mx][mx];

void solve(){
	int n, m, a, b; cin >> n >> m >> a >> b;
	memset(h, 0, sizeof(h));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			char c; cin >> c;
			if (c == 'x') h[i][j] = 1;
		}
	}
	vector<T>nxt;
	T prev = {oo, -1};
	for (int i = 1; i<=a; i++){
		for (int j = 1; j<=b; j++){
			char c; cin >> c;
			if (c == 'x') {
				if (prev.first != oo) nxt.emplace_back(i-prev.first, j-prev.second);
				prev = {i, j};
			}
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (h[i][j]){
				T curr = {i, j};
				h[i][j] = 0;
				for (auto &[dx, dy]:nxt){
					curr.first += dx;
					curr.second += dy;
					if (curr.first < 1 || curr.second < 1 || curr.first > n || curr.second > m || !h[curr.first][curr.second]){
						puts("NIE");
						return;
					}
					h[curr.first][curr.second] = 0;
				}
			}
		}
	}
	puts("TAK");
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
