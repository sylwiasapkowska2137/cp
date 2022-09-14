#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pii pair<int, int>

const int MAXN = 3e5+1;
const int INF = 1e9;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
pii_set;

pii_set s[MAXN];
set<int> G[MAXN];

ordered_set sx;

int n, x, g[MAXN], tin[MAXN], tout[MAXN], par[MAXN], cc[MAXN], t=1, ct=1;

void dfs(int v, int p) {
   par[v]=p;
   tin[v]=ct++;
   s[t].insert({tin[v], v});

   for (auto u : G[v]) {
      if (u == p) continue;
      dfs(u, v);
   }
   tout[v]=ct++;
}

int findElement(int l) {
   auto p = sx.find_by_order(l-1);
   sx.erase(p);
   return *p;
}

int subtreeSize(int v) {
   int c=cc[v];
   int stout=s[c].order_of_key({tout[v], INF}), stin=s[c].order_of_key({tin[v], 0});
   return stout-stin;
}

void cutSubtree(int v, int p, int nc) {
   s[cc[v]].erase(s[cc[v]].find({tin[v], v}));
   cc[v]=nc;
   s[nc].insert({tin[v], v});

   for (auto u : G[v]) {
      if (u == p) continue;
      cutSubtree(u, v, nc);
   }
}

void rmEdge(int u, int v) {
   G[v].erase(G[v].find(u));
   G[u].erase(G[u].find(v));
}

int solveQuery(int l) {
   int v=findElement(l), p=par[v], sz=s[cc[v]].size();
   int vsz=subtreeSize(v);

   rmEdge(v, p);
   if (vsz >= sz/2) {
      cutSubtree(p, p, ++t);
   } else {
      cutSubtree(v, v, ++t);
   }

   return s[cc[v]].size();
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n>>x;
   for (int i=1; i<=n-2; ++i) cin>>g[i];
   for (int i=1; i<=n; ++i) cc[i]=1;
   for (int i=2; i<=n; ++i) sx.insert(i);
   for (int i=1; i<=n-1; ++i) {
      int a, b;
      cin>>a>>b;
      G[a].insert(b);
      G[b].insert(a);
   }
   dfs(1, 1);

   int l=1;
   for (auto u : sx) {
      if (u == x) break;
      else ++l;
   }

   int i=1, y=1;
   while (!sx.empty()) {
      y=solveQuery(l);
      cout<<y<<"\n";
      if (sx.empty()) break;
      l=(y+g[i])%(n-i-1)+1;
      ++i;
   }
}
