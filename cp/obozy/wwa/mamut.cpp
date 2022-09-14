#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pll pair<LL, LL>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

vector<bool>vis;
vector<int>order;
vector<pll>points;
int n;

LL dist(pll a, pll b){
	return (a.st-b.st)*(a.st-b.st)+(a.nd-b.nd)*(a.nd-b.nd);
}

void dfs(int v){
	vis[v] = 1;
	order.pb(v);
	int ans = v;
	LL best = 0;
	for (int i = 0; i<n+2; i++){
		LL d = dist(points[v], points[i]);
		if (d > best && !vis[i]){
			best = d;
			ans = i;
		}
	}
	if (ans == v) return;
	dfs(ans);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "YES\n";
	cin >> n;
	points.resize(n+2);
	vis.assign(n+2, 0);
	for (int i = 0; i<n+2; i++){
		cin >> points[i].st >> points[i].nd;
	}
	dfs(0);
	for (auto x: order) cout << x+1 << " ";
	cout << "\n";
	return 0;
}

