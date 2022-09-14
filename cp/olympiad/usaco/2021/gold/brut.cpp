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

int B;
const int MAX = 1e5+7;
vector<int>graf[MAX];
vector<pair<int, int>>bound;

void solve(){
	#warning istnieje wiecej niz jedno przypisanie(!) -> B = 1
	int n; cin >> n;
	for (int i = 1; i<=n; i++) graf[i].clear();
	for (int i = 2; i<=n; i++){
		int j; cin >> j;
		graf[i].emplace_back(j);
		graf[j].emplace_back(i);
	}
	bound.clear();
	bound.emplace_back(0, 0);
	for (int i = 1; i<=n; i++){
		int l, r; cin >> l >> r;
		bound.emplace_back(l, r);
	}
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t >> B;
	while (t--) solve();
	
	return 0;
}
