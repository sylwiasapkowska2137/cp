

#include<iostream>
#include<cstdio>
using namespace std;

int n, z, p[100001], s[100001], t[100001];
long long wynik;

int main() {
    scanf("%d",&z);
    while (z--) {
          scanf("%d",&n);
          wynik = 0;
          for (int k = 1; k < n; k++)
              scanf("%d",&t[k]);
          for (int k = 1; k < n; k++)
              p[k] = p[k-1] + t[k];
          for (int i = n - 1; i >= 1; i--)
              s[i] = s[i+1] + t[i];
          for (int k = 0; k < n; k++)
              for (int i = 1; i <= n; i++)
                  wynik = max(wynik, (long long) p[k] + s[i]);
          cout << wynik << endl;
    }
    return 0;   
}
