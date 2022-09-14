#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
const int S = 316;

struct A{
	int a, b, d;
	A (int a, int b, int d): a(a), b(b), d(d){}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q, a, l, d, koniec;
	cin >> n >> q;
	vector <int> ans(n+1, 0), started, ending;
	vector <A> query;
	for (int i = 0; i<q; i++){
		cin >> a >> l >> d;
		koniec = a+(l-1)*d;
		if (d >= S) for (int s = a; s<=min(n, koniec); s+=d) ans[s]++;
		else query.pb({a, koniec, d});
	}
	for (int d = 1; d<S; d++){
		started.assign(n+d+1, 0);
		ending.assign(n+d+1, 0);
		for (int i = 0; i<(int)query.size(); i++){
			if (query[i].d == d) {
				started[query[i].a]++;
				ending[query[i].b]++;
			}
		}
		for (int x = 1; x<=n; x++){
			started[x+d]+=started[x]-ending[x];
			ans[x]+=started[x];
		}
	}
	for (int i = 1; i<=n; i++)cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
