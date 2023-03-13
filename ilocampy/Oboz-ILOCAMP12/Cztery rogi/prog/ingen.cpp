#include<iostream>
using namespace std;

int n, x;

int main() {
    srand(time(NULL));
    
    cin >> n >> x;
    cout << n << endl;
    for (int k = 0; k < n; k++) {
       for (int  i = 0; i < n; i++) {
          int i = rand() % x;
          if (i == 0) cout << "1 "; else cout << "0 ";
       }
       cout << endl;
    }
    return 0;   
}
