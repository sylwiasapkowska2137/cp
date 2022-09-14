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

const int INF = 1e9+7;

struct segtree{
	vector <int> tab, star;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		star.assign(2*size, 0);
	}
	
	void insert(int l, int r, int val){
		l += size;
		r += size;
		tab[l]+=val;
		star[l]+=val;
		if (r!=l){
			tab[r]+=val;
			star[r]+=val;
		}
		while (l>0){
			if (r-l>1){
				if (!(l&1)) {
					tab[l+1]+=val;
					star[l+1]+=val;
				}
				if (r&1){
					tab[r-1]+=val;
					star[l-1]+=val;
				}
			}
			
			if (r < size){
				star[l] = max(star[l<<1],star[l<<1|1])+tab[l];
				star[r] = max(star[r<<1],star[r<<1|1])+tab[r];
			}
			l/=2;
			r/=2;
		}
	}
	
	int query(int l, int r){
		l+=size;
		r+=size;
		int res = -INF;
		while (l>0){
			res = max(res, max(tab[l], tab[r]));
			if (r-l>1){
				if (!(l&1)) res = max(res, star[l+1]);
				if (r&1) res = max(res, star[r-1]);
			}
			l/=2;
			r/=2;
		}
		return res;
	}
};

int main(){
	fastio;
	int n, q, a, b;
	cin >> n >> q;
	segtree seg;
	seg.init(n);
	while (q--){
		cin >> a >> b;
		seg.insert(b, b+a, 1);
		//for (auto x: seg.tab) debug(x);
		//cerr << "\n";
	}
	cout << seg.query(1, seg.size);
	return 0;
}

