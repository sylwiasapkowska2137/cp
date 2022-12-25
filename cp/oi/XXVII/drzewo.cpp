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

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int M; cin >> M;
	string s; cin >> s;
	int n = (int)s.size();
	if (n == 1){
		cout << "1\n1\n";
		return;
	}
	int idx = 0;
	vector<vector<bool>>tab((1<<M)+1, vector<bool>((1<<M)+1));
	function<void(int, int, int, int)>rec = [&](int a, int b, int c, int d){
		// debug(idx, a, b, c, d);
		if (s[idx] == '0') return;
		if (s[idx] == '1'){
			for (int i = a; i<=c; i++){
				for (int j = b; j <= d; j++){
					tab[i][j] = 1;
				}
			}
			return;
		}
		int m = (a+c)/2;
		int m2 = (b+d)/2;
		++idx; rec(a, b, m, m2);
		++idx; rec(a, m2+1, m, d);
		++idx; rec(m+1, b, c, m2);
		++idx; rec(m+1, m2+1, c, d);
	};
	rec(0, 0, (1<<M)-1, (1<<M)-1);
	int ans = 0, ans2 = 1;
	vector<int>X = {-1, 1, 0, 0};
	vector<int>Y = {0, 0, -1, 1};
	for (int i = 0; i<(1<<M); i++){
		for (int j = 0; j<(1<<M); j++){
			cerr << tab[i][j];
			if (tab[i][j]){
				ans++;
				queue<pair<int, int>>q;
				q.push({i, j});
				tab[i][j] = 0;
				int sz = 1;
				while (q.size()){
					pair<int, int>v = q.front();q.pop();
					for (int k = 0; k<4; k++){
						pair<int, int>s = {v.first + X[k], v.second + Y[k]};
						if (s.first >= 0 && s.second >= 0 && s.first < (1<<M) && s.second < (1<<M)){
							if (tab[s.first][s.second]){
								tab[s.first][s.second] = 0;
								sz++;
								q.push(s);
							}
						}
					}
				}
				ans2 = max(ans2, sz);
			}
		}
		cerr << "\n";
	}
	cout << ans << "\n" << ans2 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
