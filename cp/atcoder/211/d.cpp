#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define ok cerr << "\n"
#define pb push_back

const int MAX = 2e5+7, INF = 1e9+7, MOD = 1e9+7;
vector<int>graf[MAX], dist;
vector<LL>cnt;

void bfs(){
	dist[1] = 0;
	queue<int>q;
	q.push(1);
	cnt[1] = 1;
	while (!q.empty()){
		int v = q.front();q.pop();
		for (auto x: graf[v]){
			if (dist[x]==INF){
				dist[x] = dist[v]+1;
				cnt[x] = cnt[v];
				if (cnt[x]>=MOD) cnt[x] %= MOD;
				q.push(x);
			} else {
				if (dist[x] == dist[v]+1) {
					cnt[x]+=cnt[v];
					if (cnt[x]>=MOD) cnt[x] %= MOD;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, a, b;
	cin >> n >> m;
	cnt.assign(n+1, 0);
	dist.assign(n+1, INF);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	bfs();
	cout << cnt[n] << "\n";
	
	
	return 0;
}



