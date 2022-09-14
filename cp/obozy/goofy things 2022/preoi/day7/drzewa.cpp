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

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>>tab(n+1, vector<int>(m+1, 0));
	for (int i = 0; i<=n; i++){
		for (int j = 0; j<=m; j++){
			if (i == 0 && j == 0) tab[0][0] = 0;
			else if (i == 0 || j == 0) tab[i][j] = 1;
			else tab[i][j] = tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1]+(__gcd(i, j)==1);
		}
	}
	//debug(tab);
	int ans = 0, ile = 0;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			int curr = 0;
			if (i) curr--;
			if (j) curr--;
			if (i != n-1) curr--;
			if (j != m-1) curr--;
			int a = -i, b = -j;
			curr += tab[abs(a)][abs(b)];
			a = -i, b = m-j-1;
			curr += tab[abs(a)][abs(b)];
			a = n-i-1, b = -j;
			curr += tab[abs(a)][abs(b)];
			a = n-i-1, b = m-j-1;
			curr += tab[abs(a)][abs(b)];
			//debug(i, j, curr);
			if (ans == curr) ile++;
			if (ans < curr){
				ans = curr;
				ile = 1;
			}
		}
	}
	cout << ans << " " << ile << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
