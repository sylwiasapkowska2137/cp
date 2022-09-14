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

const int MAX = 1e5+7;
vector<pair<int, char>>graf[MAX];


void solve(){
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i<=n; i++){
		int x; char c; cin >> x >> c;
		graf[x].emplace_back(i, c);
	}
	string s; cin >> s;
	while (q--){
		int a, b; cin >> a >> b;
		string t = s.substr(a-1, b-a+1);
		//debug(t);
		int v = 0, ans = 0;
		for (int i = 0; i<(int)t.size(); i++){
			bool ok = 0;
			for (auto [x, c]: graf[v]){
				if (c == t[i]){
					v = x;
					ok = 1;
					break;
				}
			}
			if (!ok){
				v = 0;
				ans++;
			}
		}
		cout << ans << " " << v << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
