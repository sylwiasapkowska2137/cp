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

const LL oo = 1e18;

struct segtree{
	vector<LL>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, oo);
	}
	
	void update(int x, LL v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = min(tab[2*x], tab[2*x+1]);
		}
	}

	pair<int, LL> find(int x, int lx, int rx){
		if (lx == rx) return {lx, tab[x]};
		int m = (lx+rx)/2;
		if (tab[2*x] < tab[2*x+1]) return find(2*x, lx, m);
		else return find(2*x+1, m+1, rx);
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<LL>>a(n, vector<LL>(m, 0));
	vector<int>p(n, 0);
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++) cin >> a[i][j];
		sort(a[i].begin(), a[i].end());
		for (LL j = 0; j<m; j++){
			a[i][j] += (j+1)*(j+1)-j*j;
		}
		a[i].push_back(oo);
	}
	segtree seg(n);
	LL ans = 0LL;
	for (int i = 0; i<n; i++){
		seg.update(i, a[i][0]);
		p[i]++;
		pair<int, LL>x = seg.find(1, 0, seg.size-1);
		seg.update(x.first, a[x.first][p[x.first]]);
		p[x.first]++;
		ans += (LL)x.second;
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
