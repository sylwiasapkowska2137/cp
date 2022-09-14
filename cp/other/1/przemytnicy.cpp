#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define LL long long

const LL INF = 1e18;
const int MAX = 1000007;
vector < pair <int, LL> > graf[MAX];
bool vis[MAX];
vector <LL> dist;

void dijkstra(){
	dist[1] = 0;
	set <pair <LL, int> > s;
	s.insert({0LL, 1});
	while (!s.empty()){
		int v = s.begin()->nd;
		LL d = s.begin()->st;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto x: graf[v]){
			if (d + x.nd < dist[x.st]){
				dist[x.st] = x.nd+d;
				s.insert({dist[x.st], x.st});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m, n, a, b;
	LL c;
	cin >> m;
	vector <LL> arr(m+1);
	for (int i = 1; i<=m; i++){
		cin >> arr[i];
	}
	cin >> n;
	for (int i = 1; i<=n; i++){
		cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[a+n].pb({b+n, c});
	}
	if (n == 0 or n == 1) {
		cout << arr[1]/2;
		return 0;
	}
	for (int i = 1; i<=m; i++){
		graf[i].pb({i+n, arr[i]/2});
	}
	dist.assign(2*n+3, INF);
	dijkstra();
	cout << dist[1+n];
	return 0;
}
