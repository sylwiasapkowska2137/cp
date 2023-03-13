#include<iostream>
#include<cstdio>
using namespace std;

int z, msuf, mpref, pref, suf, n, t[100001];

int main() {
    scanf("%d",&z);
    while (z--) {
          scanf("%d",&n);
          for (int k = 1; k < n; k++)
              scanf("%d",&t[k]);
          pref = 0; mpref = 0;
          suf = 0; msuf = 0;
          for (int k = 1; k < n; k++) {
              pref = pref + t[k];
              mpref = max(mpref, pref);
          }
          for (int k = n - 1; k >= 1; k--) {
              suf = suf + t[k];
              msuf = max(msuf, suf);
          }
          cout << (long long) msuf + mpref << endl;
    }
    return 0;   
}
