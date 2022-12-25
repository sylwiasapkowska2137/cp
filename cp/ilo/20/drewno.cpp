#include <bits/stdc++.h>
using namespace std;
const int mx = 1e4+3;

struct T{
	int a, b, d; 
	T(){}
	T(int _a, int _b, int _d): a(_a), b(_b), d(_d) {}
};

struct Tree{
	vector<int>tab;
	int size = 1;
	
	Tree(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}

	void clear(vector<int>&a){
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = tab[2*i] + tab[2*i+1];
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
		}
		return ans;
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = tab[2*x] + tab[2*x+1];
		}
	}

	void d(){
		for (int i = size+1; i<(int)tab.size(); i++){
			cerr << tab[i] << " ";
		}
		cerr << "\n";
	}
};

void solve(){
	int n; cin >> n;
	vector<vector<int>>change(mx+1);
	for (int k = 1; k<mx; k++){
		for (int i = 1, j; i<=k; i=j+1){
			j = k/(k/i);
			change[i].emplace_back(k);
		}
		change[k+1].emplace_back(k);
	}
	vector<int>a(n+1);
	vector<vector<int>>cnt(mx+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		cnt[a[i]].emplace_back(i);
	}
	int m; cin >> m;
	vector<T>que;
	Tree t(n+1);
	vector<int>L(m, 1), R(m, mx), ans(m, -1);
	for (int i = 0; i<m; i++){
		int a, b; long long d; cin >> a >> b >> d;
		if (d > 1e8){ L[i] = 1, R[i] = 0;}
		que.emplace_back(a, b, d);
	}
	while (1){
		bool any = 0;
		for (int i = 0; i<m; i++) any |= (L[i] <= R[i]);
		if (!any) break;
		vector<vector<int>>at(mx+1);
		for (int i = 0; i<m; i++){
			if (L[i] <= R[i]){
				at[(L[i]+R[i])/2].emplace_back(i);
			}
		}
		t.clear(a);
		for (int i = 1; i<=mx; i++){
			// if (at[i].empty()) continue;
			for (auto val: change[i]){
				for (auto idx: cnt[val]){
					t.update(idx, val/i);
				}
			}
			// cerr << i << " ";
			// t.d();
			for (auto idx: at[i]){
				if (t.query(que[idx].a, que[idx].b) >= que[idx].d){
					ans[idx] = i;
					L[idx] = i+1;
				} else {
					R[idx] = i-1;
				}
			}			
		}
	}
	for (int i = 0; i<m; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
