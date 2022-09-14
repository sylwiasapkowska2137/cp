#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, int>

const int MAXN = 1e6+1;
const int GSIZE = 2*MAXN;
const ll INF = 1e18;

ll dist[GSIZE];
vector<pii> G[GSIZE];

int n, m, z, d;

void dijkstra(int s) {
   priority_queue<pll, vector<pll>, greater<pll>> pq;
   pq.push({0, s});
   dist[s]=0;

   while (!pq.empty()) {
      pll v=pq.top();
      pq.pop();

      if (v.first > dist[v.second]) continue;
      for (auto u : G[v.second]) {
         if (dist[u.second] > (ll)(u.first)+dist[v.second]) {
            dist[u.second]=(ll)(u.first)+dist[v.second];
            pq.push({dist[u.second], u.second});
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n>>m;
   for (int i=0; i<GSIZE; ++i) dist[i]=INF;
   for (int i=0; i<m; ++i) {
      int x, y, s;
      cin>>x>>y>>s;
      G[x].push_back({s, y+MAXN});
      G[y].push_back({s, x+MAXN});

      G[x+MAXN].push_back({s, y});
      G[y+MAXN].push_back({s, x});
   }
   cin>>z>>d;
   dijkstra(z);

   if (dist[d] < INF) cout<<dist[d]<<" ";
   else cout<<-1<<" ";
   if (dist[d+MAXN] < INF) cout<<dist[d+MAXN]<<"\n";
   else cout<<-1<<"\n";
}
