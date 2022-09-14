#include <bits/stdc++.h>
#include "ranlib.h"

using namespace std;

const int MAXN = 1e3+69;

#define vii vector<pair<int, int>>

vector<int> G[MAXN];
int d[MAXN][MAXN], n;
bool dest[MAXN];

void dfs(int v, int p, int s) {
   d[s][v]=d[s][p]+1;
   for (auto u : G[v]) {
      if (u == p) continue;
      dfs(u, v, s);
   }
}

bool clear(int v, int p, int y, bool leavp) {
   bool leave=leavp;
   if (v == y) leave=true;

   for (auto u : G[v]) {
      if (u == p) continue;
      leave |= clear(u, v, y, (v == y) || leavp);
   }
   if (!leave) dest[v]=true;
   return leave;
}

int findMax() {
   int mxd=INT_MAX, v=-1;
   for (int i=1; i<=n; ++i) {
      if (dest[i]) continue;
      int t=0;
      for (int j=1; j<=n; ++j) {
         if (dest[j]) continue;
         t=max(t, d[i][j]);
      }
      if (mxd > t) mxd=t, v=i;
   }
   return v;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   n=dajN();
   vii x=dajKraw();

   for (auto u : x) {
      int a=u.first, b=u.second;
      G[a].push_back(b);
      G[b].push_back(a);
   }

   for (int i=1; i<=n; ++i) {
      d[i][i]=-1;
      dfs(i, i, i);
   }

   int ans=findMax();
   while (true) {
      int v=pytaj(ans);

      if (v == -1) {
         odpowiedz(ans);
         return 0;
      }

      clear(ans, ans, v, false);
      dest[ans]=true;
      ans=findMax();
   }
}
