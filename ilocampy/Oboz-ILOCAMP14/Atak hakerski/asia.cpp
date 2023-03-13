#include <iostream>
#include <cstdio>
using namespace std;
 
long long n, a, b, poziom, wynik, p, k, tyleDodalam, naZapas;
long long iloscWierzcholkow[65];
 
int main() {
        iloscWierzcholkow[1] = 1;
        for (int i = 2; i <= 60; i++)
                iloscWierzcholkow[i] = ((iloscWierzcholkow[i - 1] + 1) * 2) - 1;
       
        scanf("%lld", &n);
        for (int i = 0; i < n; i++) {
                scanf("%lld %lld", &a, &b);
                       
                p = 1;
                k = a;
                while (p <= k) {
                        int s = (p + k) / 2;
                        if (iloscWierzcholkow[s] < b && b <= iloscWierzcholkow[s + 1]) {
                                poziom = s + 1;
                                break;
                        }
                        if (iloscWierzcholkow[s] == b) {
                                poziom = s;
                                break;
                        }
                        if (iloscWierzcholkow[s] > b)
                                k = s - 1;
                       
                        if (iloscWierzcholkow[s] < b)
                                p = s - 1;
                }
                //cout << poziom << endl;
                if (poziom == a)
                        wynik = 1;
                else  {
                        wynik = 3;
                        poziom++;
                        tyleDodalam = 2;
                        while (poziom < a) {
                                tyleDodalam = (tyleDodalam * 2) - 1;
                                wynik += tyleDodalam;
                                poziom++;
                        }
                }
                if (b == 1)
                        printf("%lld\n", iloscWierzcholkow[a] - a);
                else
                        printf("%lld\n", iloscWierzcholkow[a] - wynik);
        }
 
        return 0;
}
