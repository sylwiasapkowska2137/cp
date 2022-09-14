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
const int oo = 1e18, K = 30;

const int M = 3e5+7;
int tab[M*K][2];
int lvl[K+1], lvl2[K+1];
vector<int>ends_here[M*K];
int sz;

void add(int x, int pos){
	int v = 0;
	for (int i = K; i>=0; i--){
		bool s = (x&(1<<i));
		if (tab[v][s] == -1) tab[v][s] = ++sz;
		v = tab[v][s];
	}
	ends_here[v].emplace_back(pos);
}

vector<int>dfs(int v = 0, int k = K){
	if (tab[v][0] == -1 && tab[v][1] == -1) return ends_here[v];
	if (tab[v][0] == -1) return dfs(tab[v][1], k-1);
	if (tab[v][1] == -1) return dfs(tab[v][0], k-1);
	//both sons exist
	vector<int>A = dfs(tab[v][0], k-1);
	vector<int>B = dfs(tab[v][1], k-1);
	//debug(v, A, B);
	if (A.empty()) return B;
	if (B.empty()) return A;
	int ptr = -1, tmp = 0;
	for (int i = 0; i<(int)B.size(); i++){
		while (ptr+1 < (int)A.size() && A[ptr+1] < B[i]) ptr++;
		if (ptr == -1 || ptr == (int)A.size() || (ptr+1 < (int)A.size() && A[ptr+1] > B[i])) tmp += ((int)A.size()-ptr-1);
	}
	vector<int>C(A.size()+B.size());
	merge(A.begin(), A.end(), B.begin(), B.end(), C.begin());
	lvl[k] += tmp;
	lvl2[k] += (int)(A.size())*(int)(B.size())-tmp;
	return C;
}

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}

	void update(int x){
		x += size;
		while (x){
			tab[x]++;
			x/=2;
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	memset(tab, -1, sizeof(tab));
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++) add(a[i], i);
	
	dfs();
	int x = 0;
	for (int i = K; i>=0; i--){
		if (lvl[i] > lvl2[i]){
			x+=(1<<i);
		}
	}
	for (auto &i: a) i^=x;
	vector<int>scaler;
	for (auto v: a) scaler.emplace_back(v);
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	segtree seg((int)scaler.size()+1);
	int inv = 0;
	for (auto v: a){
		int l = (upper_bound(scaler.begin(), scaler.end(), v)-scaler.begin());
		inv += seg.query(l, seg.size-1);
		seg.update(l-1);
	}
	cout << inv << " " << x << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; //cin >> t;
	while (t--) solve();
	
	return 0;
}
