#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
const int MAX = 1e5+1;

struct dsu{
	vector<int>REP;
	
	void init_dsu(int n){
		REP.resize(n+1);
		rep(i, 1, n+1) REP[i] = i;
	}
	
	int Find(int a){
		if (a == REP[a]) return a;
		return REP[a] = Find(REP[a]);
	}
	
	void Union(int x, int y){
		if (x > y) swap(x, y);
		x = Find(x);
		y = Find(y);
		if (x == y) return;
		REP[y] = x;
	}
};
dsu A, B;

void solve(){
	int n, m1, m2, a, b;
	cin >> n >> m1 >> m2;
	
	A.init_dsu(n);
	B.init_dsu(n);
	rep(i, 0, m1){
		cin >> a >> b;
		A.Union(a, b);
	}
	
	rep(i, 0, m2){
		cin >> a >> b;
		B.Union(a, b);
	}
	
	int ans = n-1-max(m1, m2);
	cout << ans << "\n";
	rep(i, 1, n+1) {
		if (A.Find(1) != A.Find(i) && B.Find(1) != B.Find(i)) {
			A.Union(1, i);
			B.Union(1, i);
			cout << 1 << " " << i << "\n";
			ans--;
		}
	}
	if (!ans) return;
	
	
	vector<int>p1, p2;
	rep(i, 1, n+1){
		if (A.Find(i) != 1) p1.pb(i);
		if (B.Find(i) != 1) p2.pb(i);
	}
	for (auto x: p1){
		for (auto y: p2){
			if (A.Find(x) != A.Find(y) && B.Find(x) != B.Find(y)) {
				A.Union(x, y);
				B.Union(x, y);
				cout << x << " " << y << "\n";
				ans--;
				if (!ans) return;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int t = 1;
	while (t--) solve();
	
	return 0;
}

