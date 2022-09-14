#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 3e4+7;
vector <int>graf[MAX], last, euler, d;

void dfs(int v, int pa = -1, int depth = 0){
	d[v] = depth;
	euler.pb(v);
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, v, depth+1);
			euler.pb(v);
		}
	}
}

struct segtree{
	vector <int> tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size *=2;
		tab.assign(2*size+1, INT_MAX);
	}
	
	void build(vector<int>&a){
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=0; i--) tab[i] = min(tab[i<<1], tab[i<<1|1]);
	}
	
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int res = INT_MAX;
		while (r-l>1){
			if (!(l&1)) res = min(res, tab[l+1]);
			if (r&1) res = min(res, tab[r-1]);
			l/=2;
			r/=2;
		}
		return res;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, a, b, x;
	cin >> n;
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	last.assign(n+1, 0);
	d.assign(n+1, 0);
	dfs(1);
	int k = euler.size();
	for (int i = 0; i<k; i++){
		last[euler[i]] = i;
		euler[i] = d[euler[i]];
		//debug(euler[i]);
	}
	segtree seg;
	seg.init(k);
	seg.build(euler);
	cin >> m;
	int prev = 1, curr;
	LL res = 0LL;
	for (int i = 0; i<m; i++){
		cin >> curr;
		x = d[prev]+d[curr]-2*seg.query(min(last[prev], last[curr]), max(last[prev], last[curr]));
		//debug(x);
		res += (LL)x;
		prev = curr;
	}
	cout << res << "\n";
	return 0;
}
