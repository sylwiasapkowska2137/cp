#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)


vector<int>ans;

void rec(priority_queue<pii>pq, int depth = 0){
	if (pq.empty()) return;
	ans[pq.top().nd] = depth;
	int v = pq.top().nd;
	pq.pop();
	priority_queue<pii>p1, p2;
	while (!pq.empty()){
		if (pq.top().nd < v) p1.push(pq.top());
		else p2.push(pq.top());
		pq.pop();
	}
	rec(p1, depth+1);
	rec(p2, depth+1);
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	ans.assign(n+1, 0);
	rep(i, 0, n) cin >> a[i];
	priority_queue<pii>pq;
	rep(i, 0, n) pq.push({a[i], i});
	
	rec(pq, 0);
	rep(i, 0, n) cout << ans[i] << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
