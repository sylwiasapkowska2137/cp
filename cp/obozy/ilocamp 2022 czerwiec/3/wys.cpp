//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	n*=2;
	vector<vector<int>>a(n+1, vector<int>(2));
	for (int j = 0; j<2; j++){
		for (int i = 1; i<=n; i++){
			cin >> a[i][j];
		}
	}
	vector<vector<int>>dpmin(n+1, vector<int>(2, oo));
	dpmin[1][0] = 1;
	dpmin[1][1] = 0;
	for (int i = 2; i<=n; i++){
		for (int j = 0; j<2; j++){
			for (int k = 0; k<2; k++){
				if (a[i][j] >= a[i-1][k]){
					dpmin[i][j] = min(dpmin[i][j], dpmin[i-1][k]+(j^1));
				}
			}
		}
	}
	vector<vector<int>>dpmax(n+1, vector<int>(2, -oo));
	dpmax[1][0] = 1;
	dpmax[1][1] = 0;
	for (int i = 2; i<=n; i++){
		for (int j = 0; j<2; j++){
			for (int k = 0; k<2; k++){
				if (a[i][j] >= a[i-1][k]){
					dpmax[i][j] = max(dpmax[i][j], dpmax[i-1][k]+(j^1));
				}
			}
		}
	}
	string s;
	int pos = n;
	int m = -1;
	for (int i = 0; i<2; i++){
		if (dpmin[n][i] <= dpmax[n][i]){
			if (dpmin[n][i] <= n/2 && n/2 <= dpmax[n][i]){
				m = i;
				break;
			}
		}
	}
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 0; j<2; j++){
	// 		debug(i, j, dpmin[i][j], dpmax[i][j]);
	// 	}
	// }
	if (m == -1){
		cout << "NIE\n";
		return;
	}
	int cnt = n/2;
	while (pos){
		if (m) s += "B";
		else {
			s += "A";
			cnt--;
		}
		pos--;
		for (int i = 0; i<2; i++){
			if (a[pos][i] <= a[pos+1][m] && dpmin[pos][i] <= dpmax[pos][i]){
				if (dpmin[pos][i] <= cnt && cnt <= dpmax[pos][i]){
					m = i;
					break;
				}
			}
		}
	}
	reverse(s.begin(), s.end());
	cout << s << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
