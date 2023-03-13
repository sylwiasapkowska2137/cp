#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int M = 100005;
queue <int> Q;
vector <int> G[M];
int odl[M];
bool odw[M];
vector <int> odwiedzone;

int n, m, a, b, d;

int BFS(int w) {
    odl[w] = 0;
    odw[w] = true;
    Q.push(w);
    odwiedzone.push_back(w);
    
    while (!Q.empty()) {
        w = Q.front();
        Q.pop();
        
        for (int i=0; i<G[w].size(); i++) {
            if (odw[G[w][i]] == false) {
                odw[G[w][i]] = true;
                odwiedzone.push_back(G[w][i]);
                odl[G[w][i]] = odl[w] + 1;
                
                if (odl[w] + 1 == d) 
                    return G[w][i];
                
                Q.push(G[w][i]);
            }
        }
    }
    
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i=0; i<n-1; i++) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    while (m--) {
        scanf("%d %d", &a, &d);
        
        if (d == 0) {
            printf("%d\n", a);
            continue;
        }
        
        printf("%d\n", BFS(a));
        
        for (int i=0; i<=n; i++) {
            odw[i] = false;
            odl[i] = 0;
        }
        odwiedzone.clear();
        
        
        while (!Q.empty()) Q.pop();
    }

    return 0;
}