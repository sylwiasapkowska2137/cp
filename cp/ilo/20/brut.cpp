#include<bits/stdc++.h>
using namespace std;
 
struct Edge{
        int v,u;
        bool tree;
 
        Edge(void): tree(false) {}
};
 
struct FU{
        vector<int> rep;
        vector<int> size;
 
        FU(int n=0): rep(n), size(n,0) {
                iota(rep.begin(), rep.end(), 0);
        }
 
        int find(int x){
                if(x != rep[x])
                        rep[x] = find(rep[x]);
                return rep[x];
        }
 
        bool merge(int a, int b){
                a = find(a), b = find(b);
                if(a == b)
                        return false;
                if(size[a] < size[b])
                        swap(a,b);
                if(size[a] == size[b])
                        size[a]++;
                rep[b] = a;
                return true;
        }
};
 
struct Graph{
        vector<int> path;
        int f;
        int d;
        int rep;
        bool vis;
 
        Graph(void): f(-1), d(0), vis(false) {}
};
 
void markRoot(int n, vector<Edge>& e){
        FU f(n);
        for(auto& i : e)
                if(f.merge(i.v,i.u))
                        i.tree = true;
}
 
void dfs(vector<Graph>& g, int v){
        g[v].vis = true;
 
        for(int u : g[v].path)
                if(!g[u].vis){
                        g[u].f = v;
                        g[u].d = g[v].d+1;
                        dfs(g,u);
                }
}
 
int find(vector<Graph>& g, int v){
        if(v != g[v].rep)
                g[v].rep = find(g,g[v].rep);
        return g[v].rep;
}
 
void merge(vector<Graph>& g, int v, int u){
        v = find(g,v);
        u = find(g,u);
        if(g[v].d > g[u].d)
                swap(v,u);
        g[u].rep = v;
}
 
int main(void){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
 
        int n,m;
        cin >> n >> m;
 
        vector<Edge> e(m);
        for(auto& i : e){
                cin >> i.v >> i.u;
                i.v--, i.u--;
        }
 
        markRoot(n,e);
 
        vector<Graph> g(n);
        for(auto& i : e)
                if(i.tree){
                        g[i.v].path.push_back(i.u);
                        g[i.u].path.push_back(i.v);
                }
 
        for(int i=0;i<n;i++)
                if(!g[i].vis)
                        dfs(g,i);
 
        for(int i=0;i<n;i++)
                g[i].rep = i;
 
        int res = 0;
        FU f(n);
 
        for(auto& i : e){
                if(!f.merge(i.v,i.u)){
                        res++;
                        int v = find(g,i.v);
                        int u = find(g,i.u);
                        while(v != u){
                                if(g[v].d > g[u].d)
                                        merge(g,v,g[v].f);
                                else
                                        merge(g,u,g[u].f);
 
                                v = find(g,v);
                                u = find(g,u);
                                res++;
                        }
                }
                cout << res << "\n";
        }
 
        return 0;
}