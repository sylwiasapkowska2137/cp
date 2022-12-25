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

struct T{
	int x, y, c;
	T(){}
	T(int _x, int _y, int _c){x = _x, y = _y, c = _c;}
};

vector<T>tab;

int rec(int a, int b, int c, int d){
	if (a >= c) return 0;
	vector<int>p = {0, 1, 2, 3};
	int ans = oo;
	int lm = (c+a)/2;
	int rm = (b+d)/2;
	vector<vector<int>>div(4, vector<int>(4));
	bool any = 0;
	for (auto [x, y, e]: tab) {
		if (x >= a && y >= b && x <= c && y <= d){
			any = 1;
			if (x <= lm && y <= rm) div[0][e]++;
			else if (y <= rm) div[1][e]++;
			else if (x <= lm) div[2][e]++;
			else div[3][e]++;
		}
	}
	if (!any) return 0;
	int tmp[4];
	tmp[0] = rec(a, b, lm, rm);
	tmp[1] = rec(lm+1, b, c, rm);
	tmp[2] = rec(a, rm+1, lm, d);
	tmp[3] = rec(lm+1, rm+1, c, d);
	do{
		int curr = 0;
		for (int i = 0; i<4; i++){
			if (p[i] == 3) {
				curr += tmp[i];
			} else {
				for (int j = 0; j<3; j++) {
					if (j == p[i]) continue;
					curr += div[i][j];
				}
			}
		}
		ans = min(ans, curr);
	} while (next_permutation(p.begin(), p.end()));
	div.clear();
	div.shrink_to_fit();
	return ans;
}

int ch(char c){
	if (c == 'J') return 0;
	if (c == 'O') return 1;
	if (c == 'I') return 2;
	assert(false);
}

void solve(){
	int k, n; cin >> k >> n;
	for (int i = 0; i<n; i++){
		int x, y; char c; cin >> x >> y >> c;
		tab.emplace_back(x, y, ch(c));
	}
	cout << rec(1, 1, (1LL<<k), (1LL<<k)) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
