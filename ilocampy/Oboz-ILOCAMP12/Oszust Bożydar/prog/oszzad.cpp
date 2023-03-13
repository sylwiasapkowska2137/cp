#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const long double INF = 2000000000LL * 2000000000LL;
const int M = 1000005;
int n, x, k;
int t[M];

long double middle(int first) {
    int m;
    
    if (k % 2 == 1) 
        m = t[first + (k/2)];
    else 
        m = (t[first + (k/2) - 1] + t[first + (k/2 + 1) - 1]) / 2;
    
    return m;
}

int main() {
    scanf("%d %d %d", &n, &x, &k);
    
    for (int i=0; i<n; i++)
        scanf("%d", &t[i]);
    
    sort(t, t + n);
    
    long double result = 0, answer = INF;
    
    for (int i=0; i<k; i++)
        result += fabs(middle(0) - t[i]);
    
    answer = result;
    
    for (int i=k; i<n; i++) {
        result -= (middle(i - k) - t[i - k]);
        result += (t[i] - middle(i - k + 1));
        answer = min(answer, result);
    }
    
    printf("%lld\n", (long long)answer);
    
    return 0;
}