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
	int a, b, c;
	E(){}
	E(int _a, int _b, int _c){a = _a, b = _b, c = _c;}
};

vector<int>rep, sz;
int ans = 0;

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b, int c){
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a]+=sz[b];
	rep[b] = a;
	ans += c;
}

void solve(){
	int n; cin >> n;
	vector<pair<LL, LL>>tab;
	for (int i = 0; i<n; i++){
		LL x, y; cin >> x >> y;
		tab.emplace_back(x, y);
	}
	int m; cin >> m;
	vector<LL>mask(n, 0);
	for (int i = 0; i<m; i++){
		LL a, b, c; cin >> a >> b >> c;
		for (int j = 0; j<n; j++){
			if (a*tab[j].first + b*tab[j].second + c > 0) mask[j] += (1LL<<i);
		}
	}
	sort(mask.begin(), mask.end());
	mask.erase(unique(mask.begin(), mask.end()), mask.end());
	vector<E>e;
	for (int i = 0; i<(int)mask.size(); i++){
		for (int j = 0; j<(int)mask.size(); j++){
			e.emplace_back(i, j, __builtin_popcountll((mask[i]^mask[j])));
		}
	}
	int N = (int)mask.size()+2;
	rep.assign(N+1, 0);
	iota(rep.begin(), rep.end(), 0);
	sz.assign(N+1, 1);
	sort(e.begin(), e.end(), [](auto a, auto b){return a.c < b.c;});
	for (auto [a, b, c]:e){
		//debug(a, b, c);
		Union(a, b, c);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}