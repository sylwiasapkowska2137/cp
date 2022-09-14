#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

vector<LD>tab;
vector<pair<LD, LD>>q;
map<LD, int>m;
LD dist(LD x, LD y){
	return (LD)sqrt((LD)(x*x+y*y));
}


struct segtree{
	vector<int>tab;
	int size = 1;
	
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void update(int l, int r){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1]++;
			if (r&1) tab[r-1]++;
			l/=2;
			r/=2;
		}
	}
	
	
	int query(int pos){
		pos+=size;
		int ans = tab[pos];
		while (pos>1){
			pos/=2;
			ans+=tab[pos];
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, t;
	LD x, y, r;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> t;
		if (t == 1){
			cin >> x >> y >> r;
			tab.pb(abs(dist(x, y)-r));
			tab.pb(abs(dist(x, y)+r));
			q.pb({dist(x, y), r});
		} else {
			cin >> r;
			tab.pb(r);
			q.pb({r, -1});
		}
	}
	sort(tab.begin(), tab.end());
	tab.erase(unique(tab.begin(), tab.end()), tab.end());
	//for (auto x: tab) debug(x);
	//cerr << "\n";
	for (int i = 0; i<(int)tab.size(); i++){
		m[tab[i]] = i;
	}
	segtree seg;
	seg.init(tab.size()+1);
	for (auto x: q){
		if (x.nd != -1){
			seg.update(m[abs(x.st-x.nd)], m[abs(x.st+x.nd)]);
		} else{
			cout << seg.query(m[x.st]) << "\n";
		}
	}
	return 0;
}
