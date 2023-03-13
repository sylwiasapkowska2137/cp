#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int M = 30;

int n;
long long s;
vector <int> G[M];
int shots[M];
vector <int> special;
long long result;
bool check[M][M];

int main() {
   int m;
    scanf("%d %d %lld", &n, &m, &s);
   
//     for (int i=1; i<=n; i++) {
//         int m;
//         scanf("%d", &m);
//         
//         while (m--) {
//             int a;
//             scanf("%d", &a);
//             matrix[i].set(a-1, 1);
//         }
//     }
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        a++;
        b++;
        if (!check[a][b]) {
            G[a].push_back(b);
            G[b].push_back(a);
            check[a][b] = true;
            check[b][a] = true;
        }
    }
    
    special.push_back(1);

    while (s--) {
        for (int i=1; i<=n; i++)
            shots[i] = 0;
        
        for (int i=0; i<special.size(); i++) {
            for (int j=0; j<G[special[i]].size(); j++) {
                shots[G[special[i]][j]]++;
            }
        }
            
        special.clear();
            
        for (int i=1; i<=n; i++)
            if (shots[i] % 2 == 1)
                special.push_back(i);
        
        result += special.size();
    }
    
    printf("%lld\n", result);
    
    return 0;
}