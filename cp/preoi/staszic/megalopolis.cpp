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

const int MAX = 2.5e5+7;
vector <int> graf[MAX], depth, preorder, postorder;
int czas = -1, last;

void dfs(int v, int p = -1, int _depth = 0){
	depth[v] = _depth;
	preorder[v] = ++czas;
	for (auto x: graf[v]){
		if (x == p) continue;
		dfs(x, v,_depth+1);
	}
	postorder[v] = ++czas;
}

struct segtree{
	int size = 1;
	vector <int> tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	int value(int pos){
		pos = pos+size;
		int res = tab[pos];
		while (pos > 0){
			pos/=2;
			res+=tab[pos];
		}
		return res;
	}
	
	void minus(int l, int r){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1]++;
			if (r&1) tab[r-1]++;
			r/=2;
			l/=2;
		}
	}
};

int main(){
	fastio;
	string t;
	int n, a, b, q;
	cin >> n;
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	depth.assign(n+1, 0);
	postorder.assign(n+1, 0);
	preorder.assign(n+1, 0);
	dfs(1);
	cin >> q;
	segtree seg;
	seg.init(2*n);
	//for (auto x: preorder) debug(x);
	//cerr << "\n";
	//for (auto x: postorder) debug(x);
	//cerr << "\n";
	while (cin >> t){
		if (t[0]=='W'){
			cin >> a;
			cout << depth[a] - seg.value(preorder[a]) << "\n";
		} else {
			cin >> a >> b;
			if (depth[a]>depth[b]) swap(a, b);
			seg.minus(preorder[b], postorder[b]);
		}
	}
	return 0;
}
