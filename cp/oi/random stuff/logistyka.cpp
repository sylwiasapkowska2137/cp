#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define pll pair<LL, LL>
#define st first
#define nd second
#define pb push_back

vector<LL>u, val;
struct q{
	bool query; //1- query, 0 - update
	LL a, b;
};

struct segtree{
	vector<pll>tab;//x_i, w_i
	int size = 1;
	
	pll combine(pll a, pll b){
		return {a.st+b.st, a.nd+b.nd};
	}
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, {0LL, 0LL});
	}
	
	void update(LL prev, LL curr, int posa, int posb){
		posa+=size;posb+=size;
		if (prev){
			tab[posa].st-=prev;
			tab[posa].nd--;
		}
		tab[posb].st+=curr;
		tab[posb].nd++;
		while (posa>1){
			posa/=2;
			tab[posa] = combine(tab[posa*2], tab[2*posa+1]);
		}
		while (posb>1){
			posb/=2;
			tab[posb] = combine(tab[posb*2], tab[2*posb+1]);
		}
	}
	
	pll sum(int l, int r){
		l = l+size-1;
		r = r+size+1;
		pll ans = {0LL,0LL};
		while (r-l>1){
			if (!(l&1)) ans = combine(ans, tab[l+1]);
			if (!(l&1)) ans = combine(ans, tab[r-1]);
			r/=2;l/=2;
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	char c;
	cin >> n >> m;
	vector<q>a(m);
	segtree seg;
	val.assign(n+1, 0);
	u.pb(0);
	for (int i = 0; i<m; i++){
		cin >> c >> a[i].a >> a[i].b;//k,a lub c,s
		if (c == 'Z') a[i].query = 1;
		else {
			a[i].query = 0;
			u.pb(a[i].b);
		}
	}
	sort(u.begin(), u.end());
	unique(u.begin(), u.end());
	//for (auto x: u)	debug(x);
	//cerr << "\n";
	seg.init(u.size()+1);
	for (int i = 0; i<m; i++){
		if (a[i].query){//a, b = c,s
			int change = upper_bound(u.begin(), u.end(), a[i].b) - u.begin();
			debug(change);
			LL left = seg.sum(0, change-1).st;
			debug(left);
			left+= a[i].b * seg.sum(change, seg.size).nd;
			debug(left);
			LL right = a[i].a * a[i].b;
			debug(right);
			cerr << "\n";
			if (left >= right) cout << "TAK\n";
			else cout << "NIE\n";
		} else {
			LL prev = val[a[i].a];
			LL curr = a[i].b;
			int posa = find(u.begin(), u.end(), prev)-u.begin();
			int posb = find(u.begin(), u.end(), curr)-u.begin();
			/*debug(prev);
			debug(curr);
			debug(posa);
			debug(posb);
			cerr << "\n";*/
			seg.update(prev, curr, posa, posb);
			/*
			cerr << "\n";
			for (auto x: seg.tab){
				debug(x.st);
				debug(x.nd);
				cerr << "\n";
			}*/
			//val - poprzednia wartosc pod danym indeksem
			val[a[i].a] = a[i].b;
		}
	}
	
	return 0;
}
