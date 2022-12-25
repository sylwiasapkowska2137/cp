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

unordered_set<int>was;
vector<int>X = {-1, -1, 1, 1, 2, -2, 0, 0};
vector<int>Y = {-1, 1, -1, 1, 0, 0, -2, 2};
int n, m, ans = 0;

int ch(vector<vector<char>>&a){
	int ck = 0, mask = 0;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j] == 'O'){
				mask += (1LL<<ck);
			}
			ck++;
		}
	}
	return mask;
}

void rek(vector<vector<char>>a){
	int mask = ch(a);
	if (was.find(mask) != was.end()) return;
	was.insert(mask);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j] == 'O'){
				for (int k = 0; k<(int)X.size(); k++){
					pair<int, int>s = {i+X[k], j+Y[k]};
					if (s.first >= 1 && s.second >= 1 && s.first <= n && s.second <= m){
						if (a[s.first][s.second] == '.'){
							swap(a[s.first][s.second], a[i][j]);
							ans++;
							rek(a);
							swap(a[s.first][s.second], a[i][j]);
						}
					}
				}
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	int A0 = 0, A1 = 0, B0 = 0, B1 = 0;
	vector<vector<char>>a(n+1, vector<char>(m+1));
	vector<vector<char>>b(n+1, vector<char>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
			if (a[i][j] == 'O'){
				if ((i+j)&1) A0++;
				else A1++;
			}
		}
	}
	string s; getline(cin, s);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j<=m; j++){
			cin >> b[i][j];
			if (b[i][j] == 'O'){
				if ((i+j)&1) B0++;
				else B1++;
			}
		}
	}
	if ((A0-B0)%2 != 0 || (A1-B1)%2 != 0){
		cout << "0\n";
		return;
	}
	rek(a);
	cout << fixed << setprecision(15) << 1.0/(long double)(ans) << "\n";
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
