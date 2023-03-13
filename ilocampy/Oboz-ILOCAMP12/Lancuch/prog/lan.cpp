#include<iostream>
using namespace std;

const int MAX_INT = 2000000001;
int n, wynik;
int t[1000009], s[1000009], p[1000009];

int main() {
    cin >> n;
    for (int k = 1; k <= n; k++)
        cin >> t[k];
    p[0] = p[1] = MAX_INT;
    for (int k = 2; k <= n; k++)
        p[k] = min(t[k], p[k-1]);
    s[n+1] = s[n] = MAX_INT;
    for (int k = n - 1; k >= 1; k--)
        s[k] = min(t[k], s[k+1]);
    wynik = MAX_INT;
    for (int k = 2; k < n; k++)
        wynik = min(wynik, t[k] + min(p[k-2], s[k+2]));
    cout << wynik << endl;
    return 0;   
}
