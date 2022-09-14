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

const int MOD = 1e9+7;

struct segtree{
	int size = 1<<17;
	vector <LL> tab;
	
	void init(){
		tab.assign(2*size+1, 1);
	}
	
	int query(int pos){
		pos=pos+size;
		LL res = tab[pos];
		while (pos>0){
			pos/=2;
			res*=tab[pos];
			res %= MOD;
		}
		return res;
	}
	
	void set(int a, int b, int val){
		a = a+size-1;
		b = b+size+1;
		while (b-a>1){
			if (!(a&1)) tab[a+1]=(tab[a+1]*val+MOD)%MOD;
			if (b&1) tab[b-1]=(tab[b-1]*val+MOD)%MOD;
			a/=2;
			b/=2;
		}
	}
};

int main(){
	fastio;
	int q, t, a, b, pos;
	LL val;
	cin >> q;
	segtree seg;
	seg.init();
	while(q--){
		cin >> t;
		if (t == 0) {
			cin >> a >> b >> val;
			seg.set(a, b, val);
			//for (auto x: seg.tab) debug(x);
			//cerr << "\n";
		} else {
			cin >> pos;
			cout << seg.query(pos) << "\n";
		}
	}
	return 0;
}
