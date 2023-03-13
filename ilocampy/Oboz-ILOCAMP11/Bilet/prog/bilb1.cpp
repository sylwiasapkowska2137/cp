
#include<iostream>
#include<cstdio>
using namespace std;

int z, sum, mpod, n, t[100001], akt;

int main() {
    scanf("%d",&z);
    while (z--) {
          sum = 0;
          scanf("%d",&n);
          for (int k = 1; k < n; k++) {
              scanf("%d",&t[k]);
              sum = sum + t[k];
          }
          
          // znajduje minimalny podci¹g
          akt = 0;
          mpod = 0;
          for (int k = 1; k < n; k++) {
              akt = akt + t[k];
              mpod = min(akt, mpod);
              if (akt > 0) akt = 0;
          }
          
          cout << (long long) sum - mpod << endl;
    }
    return 0;   
}
