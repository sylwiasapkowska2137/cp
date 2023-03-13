#include<iostream>
using namespace std;
int main() {
    
srand(time(NULL));
int z = 20;
cout << z << endl;

z--;
// jeden test dla long longów
   int n = 100000;
   cout << n << endl;
   n--;
   while (n--) {
         cout << "20000 ";      
   }
   cout << endl;
// koniec testu

while (z--) {
      int n = 100000;
      cout << n << endl;
      n--;
      while (n--) {
            int x = rand()%30001;
            x -= 10000;
            cout << x << " ";
            }
      cout << endl;
      }   
    
}
