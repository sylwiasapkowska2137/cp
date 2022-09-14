#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define dbg if(1)
#define debug(x) cerr << x << " "

struct elem{bool xx, xy, yx, yy;};
struct meh {int x, y;};
vector<meh>a;

struct segtree{
	vector<elem>tab;
	int size = 1;
	
	elem combine(int l, int r, int lx, int rx){
		int m = (lx+rx)/2;
		elem ans;
		ans.xx = ((tab[l].xx && tab[r].xx && a[m].x<=a[m+1].x) || (tab[l].xy && tab[r].xx && a[m].y<=a[m+1].x) || (tab[l].xx && tab[r].yx && a[m].x<=a[m+1].y) || (tab[l].xy && tab[r].yx && a[m].y<=a[m+1].y));
		ans.yx = ((tab[l].yx && tab[r].xx && a[m].x<=a[m+1].x) || (tab[l].yy && tab[r].xx && a[m].y<=a[m+1].x) || (tab[l].yx && tab[r].xx && a[m].x<=a[m+1].y) || (tab[l].yy && tab[r].yx && a[m].y<=a[m+1].y));
		ans.xy = ((tab[l].xx && tab[r].xy && a[m].x<=a[m+1].x) || (tab[l].xy && tab[r].xy && a[m].y<=a[m+1].x) || (tab[l].xx && tab[r].yy && a[m].x<=a[m+1].y) || (tab[l].xy && tab[r].yy && a[m].y<=a[m+1].y));
		ans.yy = ((tab[l].yx && tab[r].xy && a[m].x<=a[m+1].x) || (tab[l].yy && tab[r].xy && a[m].y<=a[m+1].x) || (tab[l].yx && tab[r].yy && a[m].x<=a[m+1].y) || (tab[l].yy && tab[r].yy && a[m].y<=a[m+1].y));
		dbg{
			debug(l/2);
			debug(lx);
			debug(rx);
			debug(m);
			debug(ans.xx);
			debug(ans.xy);
			debug(ans.yx);
			debug(ans.yy);
			cerr << "\n";
		}
		return ans;
	}
	
	void build(int x, int lx, int rx){
		if (lx == rx){
			tab[lx+size].xx = 1;
			tab[lx+size].xy = 0;
			tab[lx+size].yx = 0;
			tab[lx+size].yy = 1;
			return;
		}
		int m = (lx+rx)/2;
		build(2*x, lx, m);
		build(2*x+1, m+1, rx);
		tab[x] = combine(2*x, 2*x+1, lx, rx);
	}
	
	void init(int n){
		while (size < n) size*=2;
		tab.resize(2*size+1);
	}
	
	void update(int pos){
		int lx = pos, rx = pos, len = 1;
		pos+=size;
		while (pos > 1){
			if (pos&1)lx -= len;
			else rx += len;
			pos/=2;
			len*=2;
			tab[pos] = combine(2*pos, 2*pos+1, lx, rx);
			
		}
	}
	
	void Swap(int z, int w){
		swap(a[z], a[w]);
		update(z);
		update(w);
	}
	
	bool query(){ return (tab[1].xx || tab[1].xy || tab[1].yx || tab[1].yy);}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, c, d;
	cin >> n;
	segtree seg;
	seg.init(n-1);
	a.assign(seg.size, {INT_MAX, INT_MAX});
	for (int i = 0; i<n; i++) cin >> a[i].x >> a[i].y;
	seg.build(1, 0, seg.size-1);
	//debug(seg.size);
	//debug(seg.query());
	//cerr << "\n";
	cin >> q;
	while (q--){
		cin >> c >> d;
		seg.Swap(c-1, d-1);
		if (seg.query()) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}
