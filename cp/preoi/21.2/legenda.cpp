#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const LL INF = 1e18+7; 
vector <int> l, r, c;
vector <LL> dist;
vector<bool> vis;
set<int>indeks;

void dijkstra(){
	dist[0] = c[0];
	set <pair <LL, int> > s;
	indeks.erase(0);
	s.insert({c[0], 0});
	while (!s.empty()){
		int v = s.begin()->nd;
		LL d = s.begin()->st;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		
		auto it = indeks.lower_bound(v-r[v]);
		auto end = it;
		while (end != indeks.end() && (*end)<=v-l[v]){
			dist[*end] = d+(LL)c[*end];
			s.insert({dist[*end], (*end)});
			end++;
		}
		indeks.erase(it, end);
		it = indeks.lower_bound(v+l[v]);
		end = it;
		while (end != indeks.end() && (*end)<=v+r[v]){
			dist[*end] = d+(LL)c[*end];
			s.insert({dist[*end], (*end)});
			end++;
		}
		indeks.erase(it, end);
	}
}

void solve(){
	int n;
	cin >> n;
	indeks.clear();
	l.resize(n);
	r.resize(n);
	c.resize(n);
	vis.assign(n, 0);
	dist.assign(n, INF);
	for (int i = 0; i<n; i++) cin >> l[i];
	for (int i = 0; i<n; i++) cin >> r[i];
	for (int i = 0; i<n; i++) cin >> c[i];
	for (int i = 0; i<n; i++) indeks.insert(i);
	dijkstra();
	for (int i = 0; i<n; i++){
		if (dist[i] == INF) cout << "-1 ";
		else cout << dist[i]-(LL)c[i] << " ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}

