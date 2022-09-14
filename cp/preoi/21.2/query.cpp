#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
const int MAX = 2e6+7;
struct query {int l, r, k; };
vector <bool> done;
vector <pii> a;
vector <query> z;
vector <LL> ans;
vector <int> ile;

struct segtree{
	int size = 1;
	vector<vector<int> > tab;
	
	void init(int n){ 
		while (size < n) size*=2; 
		tab.resize(2*size+1);
	}
	
	void add(int l, int r, int val){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1].pb(val);
			if (r&1) tab[r-1].pb(val);
			l/=2;
			r/=2;
		}
	}
	
	void update(pii ai){
		int pos = ai.nd+size;
		//debug(pos);
		//cerr << "\n";
		while (pos>0){
			for (auto x: tab[pos]) {
				//debug(x);
				if (!done[x]){
					ans[x]+=(LL)ai.st;
					ile[x]++;
				}
				if (ile[x] == z[x].k) done[x] = 1;
			}
			//cerr << "\n";
			pos/=2;
		}
	}
	
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	a.resize(n);
	z.resize(q);
	ile.resize(q, 0);
	ans.resize(q);
	done.resize(q, 0);
	for (int i = 0; i<n; i++){
		cin >> a[i].st;
		a[i].nd = i;
	}
	sort(a.begin(), a.end());
	segtree seg;
	seg.init(n);
	for (int i = 0; i<q; i++){
		cin >> z[i].l >> z[i].r >> z[i].k;
		seg.add(z[i].l-1, z[i].r-1, i);
	}
	for (int i = n-1; i>=0; i--) seg.update(a[i]);
	//for (int i = 0; i<q; i++) cout << ans[i] << "\n";
	return 0;
}
