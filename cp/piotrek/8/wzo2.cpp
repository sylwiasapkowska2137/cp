/*
____________________________________$$$$
__________________________________$$____$
_________________________________$_______$
___$$$$_________________________$_________$
__$____$$______________________$____$_____$
_$_______$$___________________$____$$$____$
_$_________$$_____$$$$_$$$___$____$$$$$___$
$____________$_$$$__$$$__$$_$____$$$$$$___$
$____$$_______$_$$__$$$__$$$____$$$$$$$___$
$___$$$$_______$$$$_$$$___$$_____$$$$$$___$
$___$$$$$$_____$$$$_$$$$__$$$______$$$$$__$
$___$$$$$$$____$$$$_$$$$__$$$________$$$__$
$___$$$$$______$$$$_$$$$__$$$$____________$
$___$$$$_______$$$$_$$$$__$$$$____________$
$___$$$________$$$$_$$$$__$$$$____________$
$___$$_________$$$$__$$$__$$$$____________$
$______________$$$___$$$___$$$____________$
$_______________$_____$_____$_____________$
_$_________________________________________$
$________________________________$$$$_______$
$_______________________________$__$$$______$
$__________$$$$________________$$__$$$$_____$
$_________$$$__$_______________$$$$$$$$_____$
$________$$$$__$_______________$$$$$$$$_____$
$________$$$$$$$$______________$$$$$$$$_____$
$________$$$$$$$$_______________$$$$$$______$
$________$$$$$$$$_______$___$____$$$$_______$
$_________$$$$$$_____$__$$_$________________$
$__________$$$$_______$$__$________________$
_$_____________________$__$_______________$
__$_____________________$$_______________$
___$______________________________$$$___$
____$$___________________________$___$_$
______$$$_______________________$_____$
_________$$$$_____________$$$$$$______$
___$$________$$$$$$$$$$$$$____________$
__$__$________$___$_________________$$
__$___$_______$____$_____________$$$
__$___$________$____$___________$$
__$$$$$$_______$____$__________$__$
___$___$$_______$___$_________$____$
___$$$$$$$___$$$_$$$_________$_____$
____$___$$$$$__$_____$_______$_____$
_____$__$______$_____$_______$_____$
______$$$$$$$$$$_____$_______$____$
________________$$$$$_________$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/
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
const int oo = 1e18, K = 30;

void solve(){
	int n, m; cin >> n >> m;
	vector<int>rep(n+1), sz(n+1, 1);
	iota(rep.begin(), rep.end(), 0);
	int ans = 0;
	vector<set<int>>out(n+1);
	vector<set<int>>in(n+1);
	for (int i = 1; i<=n; i++){
		out[i].emplace(i);
		in[i].emplace(i);
	}
	vector<pair<int, int>>q;
	function<int(int)>f = [&](int a){return rep[a] == a ? a : rep[a] = f(rep[a]);};
	function<void(int, int)>Union = [&](int a, int b){
		a = f(a); b = f(b);
		if (a == b) return;
		//-=pomiedzy
		if (sz[a] < sz[b]) swap(a, b);
		// debug(sz[a], sz[b]);
		ans -= sz[a] * (int)(in[a].size());
		ans -= sz[b] * (int)(in[b].size());
		// debug(ans);
		sz[a] += sz[b];
		rep[b] = a;
		// debug(in[b], out[b]);
		for (auto x: in[b]){ //krawedzie od wierzcholka x do spojnej b
			in[a].insert(x);
			out[f(x)].insert(a);
			// debug(x, f(x));
			if (f(x) != a && out[a].find(f(x)) != out[a].end()){
				//A --> x -- > B
				q.emplace_back(a, x);
			}
		}
		for (auto x: out[b]){
			out[a].insert(x);
			// debug(x, f(x));
			if (f(x) != a && out[f(x)].find(a) != out[f(x)].end()){
				// B --> x --> A
				q.emplace_back(a, x);
			}
		}
		ans += sz[a] * (int)(in[a].size());
	};
	
	while (m--){
		auto merge = [&](int a, int b){
			int A = f(a); int B = f(b);
			if (A == B){
				return;
			}
			if (in[B].find(a) != in[B].end()) { //jest juz krawedz od a do spojnej b
				return;
			}
			if (out[B].find(A) != out[B].end()){ //jest krawedz od spojnej b do spojnej a => merge
				//
				q.emplace_back(a, b);
				while (q.size()){
					auto [x, y] = q.back();q.pop_back();
					Union(x, y);
				}
			} else { //nie ma zadnej krawedzi
				out[A].insert(B);
				in[B].insert(a);
				ans += sz[B];
			}
		};
		int a, b; cin >> a >> b;
		merge(a, b);
		cout << ans << "\n";
		// debug(rep);
		// for (int i = 1; i<=n; i++){
			// debug(in[i], out[i]);
		// }
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
