#include<iostream>
using namespace std;

int n, x, p, w, ile, wyn, akt, poc, kon;
int t[2001][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    //scanf("%d",&n);
    for (int k = 0; k < n; k++) {
       p = 0;
       ile = 0;   
       for (int i = 0; i < n; i++) {
          cin >> x;
          //scanf("%d",&x);
          ile++;
          if (x) w = w * 2 + 1; else w = w * 2;
          if (ile == 30) {
             p++; t[k][p] = w; w = 0; ile = 0;
          }
       }
       while (ile < 30) {ile++; w = w * 2;}
       p++; t[k][p] = w; w = 0;
    }
    for (int k = 0; k < n; k++) {
       for (int i = k; i < n; i++) {
          int poc = 0;
          for (int j = 1; j <= p; j++) {
             poc += 30;
             int v = (t[k][j] & t[i][j]);
             if (v) {
                while (v > 1) {poc--; v = v >> 1;}
                break; 
             }
          }
          int kon = p * 30;
          for (int j = p; j >= 1; j--) {
             int v = (t[k][j] & t[i][j]);
             if (v) {
                while (v%2 == 0) {kon--; v = v >> 1;}
                break;
             }
             else kon -= 30;
          }
          int akt = (i - k + 1) * (kon - poc + 1);
          //cout << k << " " << i << " " << akt << endl;
          if (wyn < akt)
             wyn = akt;
       }
    }
    cout << wyn << endl;
    return 0;   
}
