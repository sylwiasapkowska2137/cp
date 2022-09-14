#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define ULL unsigned LL
#define st first
#define nd second
#define pii pair <int, int>
#define pb push_back
#define debug(x) cerr << x << " "


const int MAX = 1e6+7;
LL INF = 1e18;
vector <pair<int, LL>> graf[MAX];
vector <LL> dist;
vector <bool> vis;

void dijkstra(){
	dist[1] = 0LL;
	set <pair <LL, int> > s;
	s.insert({0LL, 1});
	while (!s.empty()){
		int v = s.begin()->nd;
		LL d = s.begin()->st;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto u: graf[v]){
			if (d + u.nd < dist[u.st]){
				dist[u.st] = d+u.nd;
				s.insert({dist[u.st], u.st});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, a, b;
	LL c, val, maxi = -1;
	cin >> n >> m;
	dist.assign(MAX, INF);
	vis.assign(MAX, 0);
	for (int i = 0; i<m; i++){
		cin >> a >> b >> c;
		if (c&1){
			graf[a].pb({b+n, c});
			graf[b+n].pb({a, c});
			graf[a+n].pb({b, c});
			graf[b].pb({a+n, c});
		} else {
			graf[a].pb({b, c});
			graf[b].pb({a, c});
			graf[a+n].pb({b+n, c});
			graf[b+n].pb({a+n, c});
		}
	}
	dijkstra();
	vector <int> ans;
	for (int i = 1; i<=n; i++){
		val = dist[i]+dist[n+i];
		if (val > INF) continue;
		if (val&1){
			if (maxi == val) ans.pb(i);
			else if (val > maxi){
				ans.clear();
				maxi = val;
				ans.pb(i);
			}
		}
	}
	if (maxi == -1) {
		cout << "BRAK\n";
		return 0;
	}
	for (auto x: ans)cout << x << " ";
	cout << "\n" << maxi << "\n";	
	return 0;
}
