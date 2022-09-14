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

struct segtree{
	vector<long long>tab, lazy;
	const LL oo = 1e18;
	int size = 1;

	void init(int n, vector<LL>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, oo);
		lazy.assign(2*size+1, 0);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = (LL)(a[(i+1)%((int)a.size())]-a[i]);
		for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	void update(int x, int lx, int rx, int l, int r, int v){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] += v;
			lazy[x] += v;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, v);
		update(2*x+1, m+1, rx, l, r, v);
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}

	void push(int x, int lx, int rx){
		if (lx == rx || !lazy[x]) return;
		tab[2*x] += lazy[x];
		tab[2*x+1] += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}

	pair<int, long long>find(int x, int lx, int rx){
		if (lx == rx) return {lx, tab[x]};
		push(x, lx, rx);
		int m = (lx+rx)/2;
		if (tab[2*x] < tab[2*x+1]) return find(2*x, lx, m);
		return find(2*x+1, m+1, rx);
	}
};

void solve(){
	LL n; cin >> n;
	if (n == 1){
		cout << "OK\n";
		return;
	}
	vector<LL>a(n);
	LL s = 0;
	for (int i = 0; i<n; i++) cin >> a[i], s+=(LL)a[i];
	if (n == 2){
		int x = a[0];
		int y = a[1];
		if ((x+y)%3 != 0){
			cout << "WYCIEK\n";
		} else {
			int A = x-(x+y)/3;
			int B = y-(x+y)/3;
			if (A >= 0 && B>=0) cout << "OK\n";
			else cout << "WYCIEK\n";
		}
		return;
	}
	segtree seg;
	seg.init(n, a);
	LL p = (LL)n*(LL)(n+1)/2LL;
	if (s%p != 0){
		cout << "WYCIEK\n";
		return;
	}
	vector<LL>tab(n, 0);
	LL sum = 0LL;
	while (seg.tab[1] < 0){
		pair<int, long long>x = seg.find(1, 0, seg.size-1);
		LL ile = (LL)ceil((double)(abs(x.second))/(double)n);
		//debug(x, ile);
		tab[x.first]+=ile;
		sum += ile;
		if (sum > (s/p)){
			cout << "WYCIEK\n";
			return;
		}
		seg.update(1, 0, seg.size-1, x.first, x.first, ile*n);
		seg.update(1, 0, seg.size-1, 0, n-1, -ile);
		//debug(tab);
	}
	//debug(tab);
	LL f = 0;
	for (int i = 0; i<n; i++) f += (LL)tab[i]*(i==0?n:((n-i)%n));
	//debug(f);
	a[0]-=f;
	LL m = accumulate(tab.begin(), tab.end(), 0LL);
	for (int i = 1; i<n; i++){
		f += m-tab[i-1]*n;
		a[i]-=f;
	}
	//debug(a);
	for (int i = 0; i<n; i++){
		if (a[i]%p != 0 || a[i]!=a[(i+1)%n] || a[i]<0){
			cout << "WYCIEK\n";
			return;
		}
	}
	cout << "OK\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
