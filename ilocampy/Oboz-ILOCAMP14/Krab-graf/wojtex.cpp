#include <bits/stdc++.h>
using namespace std;
int n, i, a, b, odl_kon;
vector<int> adj[500005];

pair<int, int> st_wpair[500005];
int st_w[500005];
int odw[500005];
int shpath[500005];
queue<int> Q;
bool czyjeszczetak = true;

int zlicz2, zlicz1;

void BFS(int);

int main(){
    scanf("%d", &n);
    for( i = 1; i <= n-1; i++ ){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        st_wpair[a].second = a;
        st_wpair[b].second = b;
        st_wpair[a].first++;
        st_wpair[b].first++;
        st_w[a]++;
        st_w[b]++;
    }
    if(n == 2 ){
        printf("TAK");
        return 0;
    }
    for( i = 1; i <= n; i++ ){
        if( st_w[i] == 2 )
            zlicz2++;
        if( st_w[i] == 1 )
            zlicz1++;
    }
    if( zlicz1 == 2 && zlicz2 + zlicz1 == n ){
        printf("TAK");
        return 0;
    }

    sort( st_wpair+1, st_wpair+n+1);
    if( st_wpair[n].first >= 2 && st_wpair[n-1].first >= 2 && st_wpair[n-2].first <= 2 ){



        odl_kon = -1;
        BFS( st_wpair[n].second );
        if( !czyjeszczetak ){
            printf("NIE");
            return 0;
        }

        odl_kon = -1;
        BFS( st_wpair[n-1].second );
        if( !czyjeszczetak ){
            printf("NIE");
            return 0;
        }

        printf("TAK");
    }else{
        printf("NIE");
    }
}

void BFS(int w ){
    Q.push(w);
    shpath[w] = 0;
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        if( odw[u] == 0 ){      //printf("U: %d\n", u);
            odw[u] = 1;
            for( int x = 0; x < adj[u].size(); x++ ){
                int v = adj[u][x]; //printf("\tv: %d\n", v);
                if( shpath[v] == 0 && st_w[v] <= 2 ){
                    shpath[v] = shpath[u] + 1;
                    if( st_w[v] == 1 && odl_kon != -1 && shpath[v] != odl_kon ){
                        czyjeszczetak = false;
                        break;
                    }else if( st_w[v] == 1 && odl_kon == -1 ){
                        odl_kon = shpath[v];
                    }
                    Q.push(v);
                }
            }
        }
    }
}
