#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

struct segtree{
	int size = 1;
	vector<LL>tab;
	
	void init(int n){
		while (size <n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void update(int pos){
		pos+=size;
		tab[pos]++;
		while (pos>0){
			pos/=2;
			tab[pos] = tab[2*pos]+tab[2*pos+1];
		}
	}
	
	LL suma(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL res = 0;
		while (r-l>1){
			if (!(l&1)) res+=tab[l+1];
			if (r&1) res+=tab[r-1];
			r/=2;l/=2;
		}
		return res;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	LL ans = 0LL;
	cin >> n;
	segtree seg;
	seg.init(n+1);
	vector<pii>tab(n);
	vector<int>lewo(n), prawo(n);
	for (int i = 0; i<n; i++){
		cin >> tab[i].st;
		tab[i].nd = i;
	}
	sort(tab.begin(), tab.end());
	for (int i = n-1; i>=0; i--){
		seg.update(tab[i].nd);
		if (tab[i].nd > 0) lewo[tab[i].nd] = seg.suma(0, tab[i].nd-1);
	}
	seg.tab.assign(2*seg.size, 0);
	for (auto x: tab){
		seg.update(x.nd);
		prawo[x.nd] = seg.suma(x.nd+1, seg.size-1);
	}
	for (int i = 0; i<n; i++){
		ans += (LL)lewo[i]*(LL)prawo[i];
	}
	cout << ans;
	return 0;
}
