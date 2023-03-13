#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

const int M = 1000005;
long long n, k;
long long t[M], a[M];
long long tipSum;
long long result[M];
long long unknownDescribedByUnknown[M];
long long unknownDescribedByRubish[M];
long long unknownValue[M];
bool visited[M];
vector <pair <int, int> > G[M];

int main() {
    scanf("%lld %lld", &n, &k);
    
    for (int i=1; i<=n; i++) {
        scanf("%lld", &t[i]);
        tipSum += t[i];
    }
    
    long long spellSum = tipSum / k;
    
    if (n % k != 0) {
        int nwd = __gcd(n, k);
        for (int i=1; i<=nwd; i++)
            unknownDescribedByUnknown[i] = i;
        
        for (int i=nwd+1; i<=n; i++) {
            unknownDescribedByUnknown[i] = unknownDescribedByUnknown[i-k];
            unknownDescribedByRubish[i] = unknownDescribedByRubish[i-k] + (t[i-k+1] - t[i-k]);
        }
        for (int i=1; i<=nwd; i++) {
            unknownDescribedByUnknown[i] = unknownDescribedByUnknown[n + (i-k)]; 
            unknownDescribedByRubish[i] = unknownDescribedByRubish[n + (i-k)]  + (t[n + (i-k)+1] - t[n + (i-k)]);
        }

        long long rubishSum = 0;
        
        for (int i=1; i<=k; i++) 
            rubishSum += unknownValue[i];
        for (int i=nwd+1; i<=n; i++) {
            unknownValue[i] = unknownValue[unknownDescribedByUnknown[i]] + unknownDescribedByRubish[i];
        }
        
        unknownValue[1] = (spellSum - rubishSum) / n;
        printf("%lld ", unknownValue[1]);
        
        for (int i=2; i<=n; i++) 
            printf("%lld ", unknownValue[i] + unknownValue[1]);
    }
    else {
        for (int i=1; i<k; i++)
            printf("0 ");
        
        result[k] = t[1];
        printf("%lld ", t[1]);
        
        for (int i=k+1; i<=n; i++) {
            result[i] = result[i-k] + (t[i-k+1] - t[i-k]); 
            printf("%lld ", result[i]);
        }
    }
    
    return 0;
}