//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, K = 31;

namespace IO {
  const int MAXSIZE = 1 << 18 | 1;
  char buf[MAXSIZE], *p1, *p2;
 
  inline int Gc() {
    return p1 == p2 &&
      (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
  }
  template<typename T> inline void read(T& x) {
    x = 0; int f = 0, ch = Gc();
    while (!isdigit(ch)) f |= ch == '-', ch = Gc();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
    if (f) x = -x;
  }
}
using IO::read;

vector<int>rep;
vector<vector<int>>tab;

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (tab[a].size() < tab[b].size()) swap(a, b);
	for (auto x: tab[b]) tab[a].emplace_back(x);
	rep[b] = a;
	return 1;
}

void solve(){
	int n, m; read(n); read(m);
	vector<vector<pair<int, int>>>g(n+1);
	vector<int>b;
	for (int i = 1; i<=n; i++){
		int x; read(x);
		if (x) b.emplace_back(i);
	}
	vector<tuple<int, int, int>>edges;
	set<pair<int, int>>s;
	for (int i = 0; i<m; i++){
		int a, b, c; read(a); read(b); read(c);
		edges.emplace_back(a, b, c);
	}
	int mask = (1LL<<K)-1;
	tab.resize(n+1);
	rep.resize(n+1);
	for (int bit = K-1; bit>=0; bit--){
		mask ^= (1LL<<bit);
		for (int i = 1; i<=n; i++) tab[i].clear();
		for (auto x: b)	tab[x].emplace_back(x);
		iota(rep.begin(), rep.end(), 0);
		for (auto [a, b, c]:edges){
			if ((c&mask) == c){
				Union(a, b);
			}
		}
		//debug(i);
		if (Find(1) != Find(n)){
			for (int i = 1; i<=n; i++){
				if (Find(i) == i){
					for (int j = 1; j<(int)tab[i].size(); j++){
						pair<int, int>d = {tab[i][j], tab[i][0]};
						if (d.first > d.second) swap(d.first, d.second);
						if (s.find(d) == s.end()){
							edges.emplace_back(tab[i][j], tab[i][0], 0);
							s.insert(d);
						}
					}
				}
			}
			mask^=(1LL<<bit);
		}
		// for (auto [a, b, c]:edges){
		// 	debug(a, b, c);
		// }
		// cerr << endl;
	}
	cout << mask << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
