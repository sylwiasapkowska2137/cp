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

const int MAX = 2e5+7, K = 20;
string jump[MAX][K+1];

string merge(string a, string b){
	if (a.size() == 2 && b.size() == 2) return a;
	if (a.size() == 2) return b;
	if (b.size() == 2) return a;
	//oba rozmiaru 1
	char c = a[0], d = b[0];
	if (c == d) return "CC";
	if (c == 'C' && d == 'O') return "W";
	if (c == 'C' && d == 'W') return "O";
	if (c == 'W' && d == 'O') return "C";
	swap(c, d);
	if (c == 'C' && d == 'O') return "W";
	if (c == 'C' && d == 'W') return "O";
	if (c == 'W' && d == 'O') return "C";
}

void solve(){
	string s; cin >> s;
	int n = (int)s.size();
	for (int i = 0; i<n; i++) jump[i][0] = s[i];
	for (int j = 1; j<K; j++){
		for (int i = 0; i<n; i++){
			if (i+(1<<j) <= n) {
				jump[i][j] = merge(jump[i][j-1], jump[i+(1<<(j-1))][j-1]);
				//debug(i, j, jump[i][j]);
			}
		}
	}
	int q; cin >> q;
	while (q--){
		int L, R; cin >> L >> R;
		--L;--R;
		string s;
		for (int i = K; i>=0; i--){
			if ((1<<i) <= R-L+1){
				if (s.empty()) s = jump[L][i];
				else s = merge(s, jump[L][i]);
				L += (1<<i);
			}
		}
		if (s == "C") cout << "Y";
		else cout << "N";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
