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

struct T{
	int v, idx, sz;
	T(int _v = 0, int _idx = 0, int _sz = 0){
		v = _v, idx = _idx, sz = _sz;
	}
};

bool cmp(T a, T b){
	if (a.v == b.v) return a.sz < b.sz;
	return a.v < b.v;
}

void solve(){
	int n; cin >> n;
	vector<deque<int>>a(n+1);
	priority_queue<T, vector<T>, function<bool(T, T)>>up, down;
	for (int i = 1; i<=n; i++){
		int s; cin >> s;
		for (int j = 0; j<s; j++){
			int x; cin >> x;
			a[i].push_back(x);
		}
		up.push({a[i].front(), i, s});
		down.push({a[i].back(), i, s});
	}
	while (up.size()){
		auto [v, idx, sz] = up.top();
		up.pop();
	}

	
	
	
	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
