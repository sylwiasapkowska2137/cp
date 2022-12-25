#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
#define X first
#define Y second
 
int n;
int a[1000007];
vector<ii> GT;
int l[1000007], r[1000007];
int scc[1000007];
int scc_size[1000007];
int scc_num;
vector<int> topo;
bool vis[1000007];
int res;
int dp[1000007];
 
void dfs(int w) {
        if(vis[w])
                return ;
        vis[w] = true;
       
        dfs(a[w]);
        topo.push_back(w);
}
 
void dfs2(int w) {
        for(int x = l[w] ; x <= r[w] ; x++) {
                if(!scc[GT[x].Y]) {
                        scc[GT[x].Y] = scc[w];
                        scc_size[scc[GT[x].Y]]++;
                        dfs2(GT[x].Y);
                }      
        }
}
 
void dfs3(int w) {
        if(vis[w])
                return ;
        vis[w] = true;
       
        int max1 = 0, max2 = 0;
        for(int x = l[w] ; x <= r[w] ; x++) {
                dfs3(GT[x].Y);
                dp[w] = max(dp[w], dp[GT[x].Y] + 1);
               
                int v = dp[GT[x].Y] + 1;
                if(v >= max1) {
                        max2 = max1;
                        max1 = v;
                } else if(v > max2)
                        max2 = v;
        }      
}
 
int main() {
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i++) {
                scanf("%d", &a[i]);
                GT.emplace_back(a[i], i);
        }
       
        sort(GT.begin(), GT.end());
       
        int i = 0;
        for(int w = 1 ; w <= n ; w++) {
                int j = i - 1;
                while(j + 1 < GT.size() && GT[j + 1].X == w)
                        j++;
                l[w] = i;
                r[w] = j;
                i = j + 1;
        }
       
        /*for(ii x : GT)
                cout << x.X << " " << x.Y << " ; ";
        cout << endl;
        for(int x = 1 ; x <= n ; x++)
                cout << x << " " << l[x] << " " << r[x] << endl;*/
               
        for(int i = 1 ; i <= n ; i++)
                dfs(i);
        reverse(topo.begin(), topo.end());
       
        for(int x : topo) {
                if(!scc[x]) {
                        scc_num++;
                        scc[x] = scc_num;
                        scc_size[scc_num]++;
                        dfs2(x);
                }
        }
               
        for(int x = 1 ; x <= scc_num ; x++)
                res = max(res, scc_size[x]);
               
        GT.clear();
        for(int i = 1 ; i <= n ; i++) {
                if(scc_size[scc[i]] > 2)
                        continue;
                if(scc_size[scc[a[i]]] > 2)
                        continue;
                if(scc[i] == scc[a[i]])
                        continue;
                       
                GT.emplace_back(a[i], i);
        }
       
        sort(GT.begin(), GT.end());
        GT.resize(distance(GT.begin(), unique(GT.begin(), GT.end())));
        i = 0;
        for(int w = 1 ; w <= n ; w++) {
                int j = i - 1;
                while(j + 1 < GT.size() && GT[j + 1].X == w)
                        j++;
                l[w] = i;
                r[w] = j;
                i = j + 1;
        }      
       
        memset(vis, 0, sizeof vis);
        for(int x = 1 ; x <= n ; x++)
                dfs3(x);
               
        int res2= 0;
        for(int x = 1 ; x <= n ; x++) {
                if(scc[x] == scc[a[x]] && scc_size[scc[x]] == 2 && x < a[x])
                        res2 +=  dp[x] + dp[a[x]] + 2;
        }      
               
        printf("%d\n", max(res, res2));
        return 0;
}
 