#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int R(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main(int argc, char *argv[]) {
    srand(time(NULL) * atoi(argv[1]));
    
    int n = 25;
    int m = 70;
    long long s = 1000000000;
    
    bool t[n+5][n+5];
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            t[i][j] = false;
    
    for (int i=2; i<=n; i++) {
        int a = R(1, i-1);
        t[a][i] = true;
        t[i][a] = true;
        m--;
    }
        
    for (int i=1; i<=m; i++) {
        int a = R(1, n);
        int b = R(1, n);
        
        while (t[a][b] == true || a == b) {
            a = R(1, n);
            b = R(1, n);
        }
        
        t[a][b] = true;
        t[b][a] = true;
    }
    
    printf("%d %lld\n", n, s);
    
    for (int i=1; i<=n; i++) {
        int sum = 0;
        vector <int> v;
        for (int j=1; j<=n; j++)
            if (t[i][j]) {
                v.push_back(j);
                sum++;
            }
        printf("%d", sum);
        for (int j=0; j<v.size(); j++)
            printf(" %d", v[j]);
        printf("\n");
    }
    
    
    
    return 0;
}