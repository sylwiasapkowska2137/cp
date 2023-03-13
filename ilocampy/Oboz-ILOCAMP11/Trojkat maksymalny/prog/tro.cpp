#include<iostream>
#include<algorithm>
using namespace std;

int n, t[1000001];
long long wynik;

int main() {    
    cin >> n;
    for (int k = 0; k < n; k++)
        cin >> t[k];
    sort(t, t+n);
    wynik = 0;
    for (int k = 0; k+2 < n; k++) 
        if (t[k] + t[k+1] >= t[k+2])
            wynik = (long long) t[k] + t[k+1] + t[k+2];
    cout << wynik << endl;
    return 0;   
}
