#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

const int M = 1000005;
long long n, k;
long long t[M], a[M];
long long tipSum;
long long result[M];
bool visited[M];

int main() {
    scanf("%lld %lld", &n, &k);
    
    for (int i=1; i<=n; i++) {
        scanf("%lld", &t[i]);
    }

    long long nwd = __gcd(n, k);
    
    for (int i=1; i<=nwd; i++) {
        visited[i] = true;
        printf("0 ");
    }
    
    int pos = nwd + k;
    
    while (!visited[pos]) {
        visited[pos] = true;
        
        int ind = pos - k;
        if (ind < 1)
            ind = n - ind; 
        result[pos] = result[ind] + t[ind + 1] - t[ind];
        
        pos = (pos + k) % n;
    }
    
    for (int i=1; i<=n; i++)
        printf("%lld ", result[i]);
    
    return 0;
}