#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 1000005;
int n, m, k;
int xs[M];
int ys[M];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    
    xs[k+1] = m + 1;
    ys[k+1] = n + 1;
    
    for (int i=1; i<=k; i++) {
        int y, x;
        scanf("%d %d", &y, &x);
        xs[i] = x;
        ys[i] = y;
    }

    sort(xs, xs+k+1);
    sort(ys, ys+k+1);
    
    long long maxWidth = 0, maxHeight = 0;

    for (int i=1; i<=k+1; i++)
        maxWidth = max(maxWidth, xs[i] - xs[i-1] - 1LL);
    
    for (int i=1; i<=k+1; i++)
        maxHeight = max(maxHeight, ys[i] - ys[i-1] - 1LL);
    
    printf("%lld\n", maxWidth * maxHeight);
    
    return 0;
}