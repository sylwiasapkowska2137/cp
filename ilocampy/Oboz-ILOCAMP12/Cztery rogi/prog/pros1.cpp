#include<iostream>
using namespace std;

int n, poc, kon, wyn, akt;
int t[2001][2001];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int k = 0; k < n; k++) 
       for (int i = 0; i < n; i++) 
          cin >> t[k][i];
    for (int k = 0; k < n; k++) 
       for (int i = k; i < n; i++) {
          poc = n;
          kon = 0;
          for (int j = 0; j < n; j++) 
             if (t[k][j] && t[i][j]) {poc = j; break;}
          for (int j = n-1; j>=0; j--)
             if (t[k][j] && t[i][j]) {kon = j; break;}
          int akt = (kon - poc + 1) * (i - k + 1);
          if (akt > wyn) wyn = akt;
       }
    cout << wyn << endl;
    return 0;   
}
