#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>

const int MAX = 3e5+69;
struct q{int l, r, a;} opady[MAX];
int n, m, k;
vector<int>panstwa[MAX];
int probki[MAX], ans[MAX];

struct segtree{
	LL tab[1<<21];
	int size = 1<<20;
	
	void add(int l, int r, int val){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1]+=(LL)val;
			if (r&1) tab[r-1]+=(LL)val;
			l/=2;r/=2;
		}
	}
	
	void add(int index, int mnoznik){
		int v = opady[index].a * mnoznik;
		if (opady[index].l <= opady[index].r){
			add(opady[index].l, opady[index].r, v);
		} else {
			add(opady[index].l, size-1, v);
			add(0, opady[index].r, v);
		}
	}
	
	LL get(int pos){
		LL res = 0LL;
		pos += size;
		while (pos>0){
			res+=tab[pos];
			pos/=2;
		}
		return res;
	}
} seg;

void solve(int start, int koniec, vector<int>& queries, int &ptr){
	if (queries.empty()) return;
	int m = (start+koniec)/2;
	while (ptr < m) seg.add(++ptr, 1);
	while (ptr > m) seg.add(ptr--, -1);
	
	vector <int> right, left;
	for (auto x: queries){
		LL val = 0LL;
		for (auto y: panstwa[x]){
			val+=seg.get(y);
			if (val>=probki[x]) break;
		}
		if (val>=probki[x]){
			left.pb(x);
			ans[x] = koniec;
		} else right.pb(x);
	}
	queries.clear();
	if (start < koniec){
		solve(start, m, left, ptr);
		solve(m+1, koniec, right, ptr);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int x, ptr = 0;
	cin >> n >> m;
	for (int i = 1; i<=m; i++){
		cin >> x;
		panstwa[x].pb(i);
	}
	for (int i = 1; i<=n; i++)cin >> probki[i];
	cin >> k;
	for (int i = 1; i<=k; i++) cin >> opady[i].l >> opady[i].r >> opady[i].a;
	
	vector<int>queries;
	for (int i = 1; i<=n; i++) queries.pb(i);
	
	solve(1, k, queries, ptr);
	
	for (int i = 1; i<=n; i++){
		if (ans[i]) cout << ans[i] << "\n";
		else cout << "NIE\n";
	}
	return 0;
}
