#include <iostream>
#include <cstdio>
using namespace std;

const int M = 3003;
int n, m;
long long t[M][M];
long long result;

int main() {
    scanf("%d %d", &n, &m);

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            scanf("%lld", &t[i][j]);
        
    for (int j=1; j<=m; j++) {
        long long column = 0;
        long long sum = 0;
        
        for (int i=n; i>=1; i--) {
            sum += t[i][j];
            column = max(column, sum);
        }
            
        result += column;
    }
    
    printf("%lld\n", result);
    
    return 0;
}