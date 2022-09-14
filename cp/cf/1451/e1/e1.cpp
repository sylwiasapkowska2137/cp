//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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

int query(int t, int a, int b){
	if (t == 1) cout << "AND ";
	if (t == 2) cout << "OR ";
	if (t == 3) cout << "XOR ";
	cout << a << " " << b << "\n";
	cout.flush();
	int x; cin >> x;
	return x;
}

void solve(){
	int n; cin >> n;
	int x = query(3, 1, 2);
	int y = query(3, 1, 3);
	int z = x^y;
	int ab = x + 2 * query(1, 1, 2);
	int bc = z + 2 * query(1, 2, 3);
	int ac = y + 2 * query(1, 1, 3);
	int s = (ab+bc+ac)/2;
	vector<int>a(n+1);
	a[1] = s-bc;
	a[2] = s-ac;
	a[3] = s-ab;
	for (int i = 4; i<=n; i++){
		a[i] = a[1] ^ query(3, 1, i);
	}
	cout << "! ";
	for (int i = 1; i<=n; i++) cout << a[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}