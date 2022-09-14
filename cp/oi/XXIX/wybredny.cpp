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

const int mx = 5;
int nowy[mx];

struct Node{
	int rep[mx], sum[mx];

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

	Tree (int n, string &s){
		while (size < n) size*=2;
		tab.resize(2*size);
		for (int i = 1; i<(int)s.size(); i++) tab[i+size].sum[s[i]-'a']++;
		for (int i = size-1; i>=1; i--) {
			for (int j = 0; j<mx; j++) {
				tab[i].sum[j] = tab[2*i].sum[j] + tab[2*i+1].sum[j];
			}
		}
	}

	void push(int x){
		// tab[x].make_changes();
		for (int k = 0; k<2; k++){
			for (int i = 0; i < mx; i++){
				tab[2*x+k].rep[i] = tab[x].rep[tab[2*x+k].rep[i]];
			}
			// tab[2*x+k].make_changes();
		}
		tab[x].make_changes();
	}

	Node query(int x, int lx, int rx, int l, int r){
		if (lx != rx) push(x);
		if (lx > r || rx < l) return Node();
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return f(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}

	void print(){
		for (int i = 1; i<(int)tab.size(); i++){
			cerr << "----" << i << "----\n";
			tab[i].d();
		}
	}

	void work(){
		for (int i = 1; i<size; i++) push(i);
		for (int i = size; i<(int)tab.size(); i++) tab[i].make_changes();
	}

	void update(int x, int lx, int rx, int l, int r, int a, int b){
		// push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x].make_changes();
			tab[x].rep[a] = b;
			if (lx != rx) push(x);
			// tab[x].make_changes();
			// debug(x, lx, rx, a, b);
			// tab[x].d();
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, a, b);
		update(2*x+1, m+1, rx, l, r, a, b);
		tab[x] = f(tab[2*x], tab[2*x+1]);
	}

	int find(int x, int lx, int rx, int ile, int A){
		// debug(x, lx, rx);
		if (lx == rx) return lx;
		push(x);
		int m = (lx+rx)/2;
		if (lx != m){ 
			push(2*x);
			push(2*x+1);
		} else {
			tab[2*x].make_changes();
			tab[2*x+1].make_changes();
		}
		if (tab[2*x].sum[A] >= ile) return find(2*x, lx, m, ile, A);
		return find(2*x+1, m+1, rx, ile-tab[2*x].sum[A], A);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	string s; cin >> s;
	s = "$" + s;
	Tree t(n+2, s);
	while (q--){
		int x; char a, b; cin >> x >> a >> b;
		if (a == b) continue;
		int A = (int)(a - 'a');
		int B = (int)(b - 'a');
		int pos = t.find(1, 0, t.size-1, x, A);
		t.update(1, 0, t.size-1, 1, pos, A, B);
	}
	t.work();
	for (int i = 1; i<=n; i++){
		for (int j = 0; j<mx; j++){
			if (t.tab[i+t.size].sum[j]){
				cout << (char)(j+'a');
			}
		}
	}
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
