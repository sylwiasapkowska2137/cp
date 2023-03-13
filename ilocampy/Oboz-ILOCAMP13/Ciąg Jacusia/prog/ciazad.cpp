#include <bits/stdc++.h>
using namespace std;

const int M = 500005;

int n;
int t[M];

int main() {
    scanf("%d", &n);
    
    for (int i=1; i<=n; i++) {
        scanf("%d", &t[i]);
        
        if (t[i] == -1)
            t[i] = t[i-1] + 1;
        else {   
            if (t[i] <= t[i-1]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    
    for (int i=1; i<=n; i++)
        printf("%d ", t[i]);
    printf("\n");
    
    return 0;
}