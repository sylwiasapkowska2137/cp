#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

const int M = 305;

double tests;

int n, won;
pair <int, int> t[M];

double randomDouble(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main() {
    scanf("%d", &n);
    
    tests = (int)(1000000 / n);
    
    for (int i=1; i<=n; i++) {
        scanf("%d %d", &t[i].ff, &t[i].ss);
    }
    
    for (int i=0; i<tests; i++) {
        double fred = randomDouble(t[1].ff, t[1].ss);
        bool success = true;
        
        for (int j=2; j<=n; j++) {
            double score = randomDouble(t[j].ff, t[j].ss);
            
            if (score < fred) {
                success = false;
                break;
            }
        }
        
        if (success)
            won++;
    }
    
    printf("%.6f", won/tests);

    return 0;
}