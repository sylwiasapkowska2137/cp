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

void solve(){
	int m, p, n; cin >> m >> p >> n;
	vector<vector<int>>a(m+1, vector<int>(m+1, -oo));
	vector<vector<int>>b(m+1, vector<int>(m+1, -oo));
	for (int i = 0; i<p; i++){
		int x, y, c; cin >> x >> y >> c;
		b[x][y] = c;
	}
	vector<int>curr = {0};
	int t = 0;
	a[1][1] = 0;
	vector<int>Y = {1, 0, -1, 0};
	vector<int>X = {0, -1, 0, 1};
	vector<char>mv = {'P', 'G', 'L', 'D'};
	pair<int, int>pos = {1, 1};
	while (n--){
		char c; cin >> c;
		if (c == 'Z'){
			int x, y; cin >> x >> y;
			if (a[x][y] == -oo){
				cout << "-1\n";
				continue;
			}
			int diff = t-a[x][y];
			if ((int)curr.size()-1-diff >= 0) cout << curr[(int)curr.size()-1-diff] << "\n";
			else cout << "-1\n";
		} else {
			t++;
			for (int k = 0; k<4; k++){
				if (c == mv[k]){
					pos.first += X[k];
					pos.second += Y[k];
					break;
				}
			}
			if (b[pos.first][pos.second] != -oo) {
				curr.emplace_back(b[pos.first][pos.second]);
				b[pos.first][pos.second] = -oo;
			}
			a[pos.first][pos.second] = t;
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
