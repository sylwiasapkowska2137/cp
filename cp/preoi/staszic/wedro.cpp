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

struct E{
	int a, b, c, i;
	E(){}
	E(int _a, int _b, int _c, int _i){
		a = _a, b = _b, c = _c, i = _i;
	}
};

vector<int>rep, sz;

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return 1;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a]+=sz[b];
	rep[b] = a;
	return 0;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<E>e;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		e.emplace_back(a, b, c, i);
	}
	sort(e.begin(), e.end(), [](auto a, auto b){return a.c > b.c;});
	rep.resize(n+1);
	iota(rep.begin(), rep.end(), 0);
	sz.assign(n+1, 1);
	vector<int>ans;
	for (auto [a, b, c, i]:e){
		if (Union(a, b)){
			ans.push_back(i+1);
		}
	}
	cout << (int)ans.size() << "\n";
	for (auto x: ans) cout << x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
