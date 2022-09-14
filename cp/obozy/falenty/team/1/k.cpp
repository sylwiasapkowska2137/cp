//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

// #define int long long
const int mx = 10;
long long nowy[mx];

struct Node{
	int rep[mx];
	long long sum[mx];

	Node(){
		for (int i = 0; i<mx; i++){
			rep[i] = i;
			sum[i] = 0;
		}
	}

	void make_changes(){
		for (int i = 0; i<mx; i++) nowy[i] = 0;
		for (int i = 0; i<mx; i++) nowy[rep[i]] += sum[i];
		for (int i = 0; i<mx; i++) sum[i] = nowy[i];
		for (int i = 0; i<mx; i++) rep[i] = i;
	}

	void d(){
		cerr << "rep: ";
		for (int i = 1; i<mx; i++) cout << rep[i] << " ";
		cout << "\n";
		cerr << "suma: ";
		for (int i = 1; i<mx; i++) cout << sum[i] << " ";
		cout << "\n";
	}

	long long work(){
		for (int i = 0; i<mx; i++) nowy[i] = 0;
		for (int i = 0; i<mx; i++) nowy[rep[i]] += sum[i];
		long long val = 0;
		for (int i = 0; i<mx; i++) val += nowy[i] * i;
		return val;
	}
};

struct Tree{
	vector<Node>tab;
	int size = 1;

	Node f(Node a, Node b){
		a.make_changes();
		b.make_changes();
		// a.d();b.d();
		Node ret;
		for (int i = 0; i<mx; i++) ret.sum[i] = a.sum[i] + b.sum[i];
		return ret;
	}

	Tree (int n){
		while (size < n) size*=2;
		tab.resize(2*size);
	}

	void push(int x, int lx, int rx){
		// tab[x].make_changes();
		if (lx != rx){
			for (int k = 0; k<2; k++){
				for (int i = 0; i < mx; i++){
					tab[2*x+k].rep[i] = tab[x].rep[tab[2*x+k].rep[i]];
				}
			}
		}
		tab[x].make_changes();
	}

	long long query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return 0LL;
		if (lx >= l && rx <= r) return tab[x].work();
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r) + query(2*x+1, m+1, rx, l, r);
	}

	void print(){
		for (int i = 1; i<(int)tab.size(); i++){
			cerr << "----" << i << "----\n";
			tab[i].d();
		}
	}

	void update(int x, int lx, int rx, int l, int r, int a, int b){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x].rep[a] = b;
			push(x, lx, rx);
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, a, b);
		update(2*x+1, m+1, rx, l, r, a, b);
		tab[x] = f(tab[2*x], tab[2*x+1]);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	Tree t(n+1);
	vector<long long>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	long long p = 1;
	for (int b = 0; b <= 10; b++){
		for (int i = 1; i<=n; i++){
			if (a[i]){
				t.tab[i+t.size].sum[a[i]%10] += p;
			}
			a[i]/=10;
		}
		p *= 10;
	}
	for (int i = t.size-1; i>=1; i--) t.tab[i] = t.f(t.tab[2*i], t.tab[2*i+1]);
	// t.print();
	// return;
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int l, r, A, B; cin >> l >> r >> A >> B;
			if (A == B) continue;
			t.update(1, 0, t.size-1, l, r, A, B);
		} else {
			int l, r; cin >> l >> r;
			cout << t.query(1, 0, t.size-1, l, r) << "\n";
		}
		// t.print();
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
