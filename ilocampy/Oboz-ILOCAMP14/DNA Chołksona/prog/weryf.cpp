#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 100000005;
const long long MOD = 1000000007LL;
long long t[M];
long long t2[M];
int n;

int main() {
    scanf("%d", &n);
    
    t[1] = 1;
    
    int len = 1;
    
    for (int i=0; i<n; i++) {
        for (int j=1; j<=len; j++)
            t2[j] = t[j];
        for (int j=1; j<=len; j++) {
            t[j*2-1] = -t2[j];
            t[j*2] = t2[j];
        }
        len *= 2;
    }
    
    long long result = 0;
    for (int i=2; i<=len; i++)
        if (t[i] == -1 && t[i-1] == -1)
            result++;
    
    printf("%lld\n", result);
    
    return 0;
}