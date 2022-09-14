#include <bits/stdc++.h>
 
using namespace std;
 
#define pii pair<int, int>
 
const int MAXN = 5e5+1;
 
struct Edge {
   int a, b, w;
};
 
struct Q {
   int u, k, i;
};
 
int n, q, x, par[MAXN], sz[MAXN], ans[MAXN];
 
vector<Edge> e;
vector<Q> que;
 
int findx(int x) {
   if (par[x] == x) return x;
   return par[x]=findx(par[x]);
}
 
void merge(int x, int y) {
   int fx=findx(x), fy=findx(y);
   if (fx == fy) return;
   par[fx]=fy;
   sz[fy]+=sz[fx];
}
 
bool cmp(Edge a, Edge b) {
   return a.w < b.w;
}
 
bool cmp2(Q a, Q b) {
   return a.k < b.k;
}
 
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n>>q>>x;
 
   for (int i=0; i<MAXN; ++i) par[i]=i, sz[i]=1;
 
   if (x > 1) {
      cout<<"Nah\n";
      return 0;
   }
 
   for (int i=1; i<=n-1; ++i) {
      int a, b, w;
      cin>>a>>b>>w;
      e.push_back({a, b, w});
   }
   sort(e.begin(), e.end(), cmp);
 
   for (int i=1; i<=q; ++i) {
      int d, u, k;
      cin>>d>>u>>k;
      que.push_back(Q{u, k, i});
   }
   sort(que.begin(), que.end(), cmp2);
 
   int idx=0;
   for (int i=0; i<q; ++i) {
      while (idx < n-1) {
         if (e[idx].w <= que[i].k) {
            merge(e[idx].a, e[idx].b);
            ++idx;
         } else break;
      }
      ans[que[i].i]=sz[findx(que[i].u)];
   }
 
   for (int i=1; i<=q; ++i) cout<<ans[i]<<"\n";
}