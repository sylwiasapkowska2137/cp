#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int M = 500005;
queue <int> Q;
vector <vector <int> > G;
bool odw[M];
int odl[M];
int parent[M];
int indInSr[M];
vector <int> sr;
vector <int> S;
vector <vector <int> > wsk;
int pot[20];
bool special[M];
int superParent[M];
int n, a, b, naj, q;

void BFS(int w) {
    odl[w] = 0;
    odw[w] = true;
    parent[w] = w;
    Q.push(w);
    
    while (!Q.empty()) {
        w = Q.front();
        naj = w;
        Q.pop();
        
        for (int i=0; i<G[w].size(); i++) {
            if (odw[G[w][i]] == false) {
                odw[G[w][i]] = true;
                odl[G[w][i]] = odl[w] + 1;
                parent[G[w][i]] = w;
                Q.push(G[w][i]);
            }
        }
    }
}

void addParents(int w) {
    int jump = 1;
    int poz = S.size() - 1;
    wsk[w].push_back(w);
    
    while (poz - jump >= 0) {
        wsk[w].push_back(S[poz - jump]);
        jump *= 2;
    }
}

void DFS(int w, int root) {
    odw[w] = true;
    S.push_back(w);
    addParents(w);
    superParent[w] = root;
    
    for (int i=0; i<G[w].size(); i++) {
        int s = G[w][i];
        if (odw[s] == false) {
            odl[s] = odl[w] + 1;
            parent[s] = w;
            DFS(s, root);
        }
    }
    
    S.pop_back();
}

void preproc() {
    for (int i=1; i<=n; i++)
        odw[i] = false;
    for (int i=0; i<sr.size(); i++)
        odw[sr[i]] = true;
    
    pot[0] = 0;
    pot[1] = 1;
    for (int i=2; i<20; i++)
        pot[i] = pot[i-1] * 2;
    
    for (int i=0; i<sr.size(); i++) {
        odl[sr[i]] = 0;
        DFS(sr[i], sr[i]);
    }
}

int distanceForSpecial(int a, int d) {
    if (indInSr[a] - d >= 0)
        return sr[indInSr[a] - d];
    if (indInSr[a] + d < sr.size())
        return sr[indInSr[a] + d];
    return -1;
}

int answer(int a, int d) {
    if (special[a]) 
        return distanceForSpecial(a, d);
    
    if (odl[a] < d)
        return distanceForSpecial(superParent[a], d - odl[a]);
    
    int last = wsk[a].size() - 1;
    
    while (d > 0) {
        for (int i=min(last, (int)(wsk[a].size()-1)); i>=0; i--) {
            last = i;
            if (pot[i] <= d) 
                break;
        }
        d -= pot[last];
        a = wsk[a][last];
    }
    
    return a;
}

int main() {
    scanf("%d %d", &n, &q);
    G.resize(n+1);
    wsk.resize(n+1);
    
    for (int i=0; i<n-1; i++) {
        scanf("%d %d", &a, &b);
        
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    BFS(1);
    for (int i=1; i<=n; i++)
        odw[i] = false;
    BFS(naj);
   
    while (special[parent[naj]] == false) {
        special[naj] = true;
        sr.push_back(naj);
        indInSr[naj] = sr.size() - 1;
        naj = parent[naj];
    }
    
    preproc();
    
    while (q--) {
        int a, d;
        scanf("%d %d", &a, &d);
        printf("%d\n", answer(a, d));
    }
    
    return 0;
}