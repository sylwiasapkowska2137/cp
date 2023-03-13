#include<iostream>
using namespace std;

int z, p, n;

int main() {
 
 bool pop = true;
    
 scanf("%d",&z);
 if (z > 20) pop = false;
 if (z < 1) pop = false;
 
 while (z--) {
       scanf("%d", &n);
       if (n < 1) pop = false;
       if (n > 100000) pop = false;
       
       for (int i = 0; i < n-1; i++) {
           scanf("%d", &p);
           if (p < -20000) pop = false;
           if (p > 20000) pop = false;
       }     
 }
 
 if (pop) cout << "TRUE :)";
    else cout << "FALSE :(";
    
}
