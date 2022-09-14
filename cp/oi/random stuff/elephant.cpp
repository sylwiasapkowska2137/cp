//https://codeforces.com/contest/220/submission/140645270
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define pii pair<int, int>

map <int, int> m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << "Zrobione\n";
	return 0;
	int n, q, x,y;
	cin >> n >> q;
	vector <int> ok, a(n), pre, ans(q);
	vector <pii> queries;
	for (int i = 0; i<n; i++){
		cin >> a[i];
		//if (m.find(a) == m.end()) m.insert({a, 0});
		m[a[i]]++;
	}
	for (auto x: m){
		if (x.nd >= x.st) ok.pb(x.st);
	}
	for (int i = 0; i<q; i++){
		cin >> x >> y;
		queries.pb({x, y});
	}
	for (auto x: ok){
		pre.assign(n+1, 0);
		for (int i = 1; i<=n; i++){
			pre[i] = pre[i-1];
			if (a[i-1] == x) pre[i]++;
		}
		for (int i = 0; i<q; i++){
			if (pre[queries[i].nd]-pre[queries[i].st-1]==x) 
				ans[i]++;
		}
	}
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
	return 0;
}
