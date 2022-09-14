#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define debug(x) cerr << x << " "

struct point{
	LD x, y;
	point() {}
    point(LD x, LD y): x(x), y(y) {}
};

const int MAX = (1<<21)+1;
const LD M = 1e6;

struct segtree{
	int size = (1<<20);
	vector <int> tab;
	
	void init(){tab.resize(MAX, 0);}
	
	void update(int pos){
		pos+=size;
		tab[pos] = 1;
		while (pos>0){
			pos/=2;
			tab[pos] = tab[2*pos]+tab[2*pos+1];
		}
	}
	
	int suma(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int sum = 0;
		while (r-l>1){
			if (!(l&1)) sum+=tab[l+1];
			if (r&1) sum+=tab[r-1];
			l/=2;
			r/=2;
		}
		return sum;
	}
};

segtree seg;
point a, b;

void solve(){
	int n, m, pos;
	LL res = 0LL;
	seg.init();
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> pos;
		seg.update(pos);
	}
	cin >> m;
	for (int i = 0; i<m; i++){
		cin >> a.x >> a.y >> b.x >> b.y;
		LD dista = sqrt(a.x*a.x+a.y*a.y);
		LD distb = sqrt(b.x*b.x+b.y*b.y);
		if (dista == distb) continue;
		else if (dista > distb) swap(dista, distb);
		//dista < distb
		dista = ceil(dista);
		distb = floor(distb);
		dista = min(dista, M);
		distb = min(distb, M);
		res+=(LL)seg.suma(dista, distb);
		//debug(res);
	}
	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)solve();
	
	return 0;
}
