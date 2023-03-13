#include<iostream>
using namespace std;
int main() {
    
srand(time(NULL));
int z = 20;
cout << z << endl;
while (z--) {
      int n = 100000;
      cout << n << endl;
      n--;
      while (n--) {
            int x = rand()%40001;
            x -= 20000;
            cout << x << " ";
            }
      cout << endl;
      }   
    
}
