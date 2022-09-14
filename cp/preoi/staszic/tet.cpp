#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int INF = 1e9+7;

struct node{
	LL val;
	int lx, rx;
	node(): val(0LL), lx(INF), rx(INF) {}
};

struct elem{
	int a, b, h;
};

struct segtree{
	vector<node>tab;
	vector<LL>lazy;
	int size = 1;
	
	void init(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.resize(2*size);
		lazy.assign(2*size, 0LL);
		for (int i = 0; i<n; i++) {
			tab[i+size].lx = a[i];
			tab[i+size].rx = a[i];
		}
		for (int i = size-1; i>0; i--){
			tab[i] = comb(i);
		}
	}
	
	node comb(int x){
		node ans;
		ans.val = max(tab[2*x].val, tab[2*x+1].val);
		ans.lx = tab[2*x].lx;
		ans.rx = tab[2*x+1].rx;
		return ans;
	}
	
	LL mod(LL a, LL b){
		return (b == LLONG_MAX) ? a : b;
	}
	
	void push(int x){
		if (tab[x].lx == tab[x].rx) return;
		tab[2*x].val = mod(tab[2*x].val, lazy[x]);
		tab[2*x+1].val = mod(tab[2*x+1].val, lazy[x]);
		lazy[2*x] = mod(lazy[2*x], lazy[x]);
		lazy[2*x+1] = mod(lazy[2*x+1], lazy[x]);
		lazy[x] = LLONG_MAX;
	}
	
	void update(int x, int l, int r, LL val){
		if (tab[x].lx > r || tab[x].rx < l) return;
		if (tab[x].lx >= l && tab[x].rx <= r){
			tab[x].val = mod(tab[x].val, val);
			lazy[x] = mod(lazy[x], val);
			return;
		}
		push(x);
		update(2*x, l, r, val);
		update(2*x+1, l, r, val);
		tab[x].val = max(tab[2*x].val, tab[2*x+1].val);
	}

	LL query(int x, int l, int r){
		if (tab[x].lx > r || tab[x].rx < l) return 0LL;
		if (tab[x].lx >= l && tab[x].rx <= r) return tab[x].val;
		push(x);
		return max(query(2*x, l, r), query(2*x+1, l, r));
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	// plansza od 0 do n czyli n+1 pól
	vector<int>tab;
	vector<elem>a(m);
	map<int, int>mapa;
	for (int i = 0; i<m; i++){
		cin >> a[i].a >> a[i].b >> a[i].h;
		a[i].b--;
		tab.pb(a[i].a);
		tab.pb(a[i].b);
	}
	segtree seg;
	sort(tab.begin(), tab.end());
	tab.erase(unique(tab.begin(), tab.end()), tab.end());
	//for (auto x: tab) debug(x);
	//cerr << "\n";
	seg.init(tab.size(), tab); //n włącznie
	/*
	for (int i = 1; i<(int)seg.tab.size(); i++){
		debug(i);
		debug(seg.tab[i].lx);
		debug(seg.tab[i].rx);
		cerr << "\n";
	}*/
	for (int i = 0; i<(int)tab.size(); i++){
		mapa[tab[i]] = i;
	}
	for (int i = 0; i<m; i++){
		//debug(a[i].a);
		//debug(a[i].b);
		//cerr << "\n";
		LL x = seg.query(1, mapa[a[i].a], mapa[a[i].b]);
		//debug(x);
		//cerr << "\n";
		seg.update(1, mapa[a[i].a], mapa[a[i].b], (LL)a[i].h+x);
	}
	cout << seg.tab[1].val << "\n";
	return 0;
}
