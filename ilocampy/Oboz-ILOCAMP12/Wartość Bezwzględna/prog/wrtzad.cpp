#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int t[1000005];

int main() {
    scanf("%d", &n);

    for (int i=0; i<n; i++)
        scanf("%d", &t[i]);

    sort(t, t + n);

    double sum1 = t[0] + t[1] + t[n - 1];
    double sum2 = t[0] + t[n - 2] + t[n - 1];
    
    double result1 = fabs(sum1 / 3 - t[1]);
    double result2 = fabs(sum2 / 3 - t[n - 2]);
    
    printf("%.2f\n", max(result1, result2));
    
    return 0;
}