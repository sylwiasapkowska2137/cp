#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct segtree{
	vector <int> tab;
	int size;
	void init(int siz){
		size = siz;
		tab.assign(2*size, INT_MAX);
	}
	
	void build(vector <int> a){
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=0; i--) tab[i] = min(tab[i<<1], tab[i<<1|1]);
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int res = 1e9+7;
		while (r-l>1){
			if (!(l&1)) res = min(res, tab[l+1]);
			if (r&1) res = min(res, tab[r-1]);
			r/=2;
			l/=2;
		}
		return res;
	}

};

int main(){
	fastio;
	int q, t, n, m, x1,x2,y1,y2;
	cin >> n >> m >> q;
	vector <segtree> tab(n+1);
	int siz = 1;
	while (siz < m) siz*=2;
	vector <int> a(m);
	for (int i = 0; i<n; i++){
		for (int i = 0; i<m; i++) cin >> a[i];
		tab[i].init(siz);
		tab[i].build(a);
	}
	while (q--){
		cin >> x1 >> y1 >> x2 >> y2;
		int mini = 1e9+7;
		for (int i = x1-1; i<x2; i++) mini = min(mini, tab[i].query(y1-1, y2-1));
		cout << mini << "\n";
	}
	return 0;
}
