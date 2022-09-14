#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    int T = 10000;
    double t = T;
    double sum = 0;
    double sum2 = 0; 
    while (T--){
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        double z = (double)rand()/RAND_MAX;
        sum += min(x, min(y, z));
        sum2 += max(x, max(y, z));
    }
    cout << setprecision(10) << fixed;
    sum /= t;
    sum2 /= t;
    cout << sum << " " << sum2 << "\n";
}