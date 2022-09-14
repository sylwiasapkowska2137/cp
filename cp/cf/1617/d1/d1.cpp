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

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n; cin >> n;

	auto query = [&](int a, int b, int c){
		cout << "? " << a << " " << b << " " << c << "\n";
		cout.flush();
		int x; cin >> x;
		return x;
	};

	auto answer = [&](vector<int>x){
		cout << "! " << (int)x.size() << " ";
		for (auto v: x) cout << v << " ";
		cout << "\n";
		cout.flush();
	};

	auto nxt = [&](int x){return (x == n ? 1 : x+1);};
	vector<int>ans(n+1);
	for (int i = 1; i<=n; i++){
		int a = i, b = nxt(a), c = nxt(b);
		ans[i] = query(a, b, c);
	}
	int X, Y;
	vector<int>bad(n+1);
	for (int i = 1; i<=n; i++){
		if (ans[i] != ans[nxt(i)]){
			if (ans[i]){
				X = i;
				Y = nxt(nxt(nxt(i)));
				bad[Y] = 1;
			} else {
				Y = i;
				X = nxt(nxt(nxt(i)));
				bad[Y] = 1;
			}
		}
	}
	debug(X, Y);
	for (int i = 1; i<=n; i++){
		if (i == X || i == Y) continue;
		int c = query(i, X, Y);
		if (!c) bad[i] = 1; 
	}
	vector<int>ret;
	for (int i = 1; i<=n; i++){
		if (bad[i]){
			ret.emplace_back(i);
		}
	}
	answer(ret);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}