#include <iostream>
#include <cstdio>
using namespace std;

int t;
long long n, k;

int main() {
    scanf("%d", &t);
    
    while (t--) {
        scanf("%lld %lld", &n, &k); 
        long long wynik = n;
        bool g = true;
        
        if (k == 1) {
            printf("%lld\n", n);
            continue;
        }
        
        for (long long i=k; i<=n; i*=k) {
            long long ilePodzielnych = n / i;
            if (g) 
                wynik -= ilePodzielnych;
            else 
                wynik += ilePodzielnych;
            g = !g;
            
            long long nextI = i*k;
            long long checkI = nextI / k;
            if (i != checkI)
                break;
        }
        
        printf("%lld\n", wynik);
    }
    
    return 0;
}