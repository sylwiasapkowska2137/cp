#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 1000005;
const long long MOD = 1000000007LL;
long long t[M];
int n;

int main() {
    scanf("%d", &n);
    
    t[0] = 0;
    t[1] = 0;
    t[2] = 1;
    
    for (int i=3; i<=1000000; i++)
        t[i] = (t[i-1] + t[i-2] * 2LL) % MOD;
    
    printf("%lld\n", t[n]);
    
    return 0;
}