
#include<iostream>
#include<cstdio>
using namespace std;

int mxpod, z, sum, mpod, n, t[100001], akt;

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
          
          // znajduje maksymalny podci¹g
          akt = 0;
          mxpod = 0;
          for (int k = 1; k < n; k++) {
              akt = akt + t[k];
              mxpod = max(akt, mxpod);
              if (akt < 0) akt = 0;
          }
          
          cout << max((long long) sum - mpod, (long long) sum + mxpod) << endl;
    }
    return 0;   
}
