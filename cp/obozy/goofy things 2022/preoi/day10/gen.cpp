#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
    return a+rng()%(b-a+1);
}

int main(){
    int n = p(1, 100);
    int k = p(0, n);
    cout << n << " " << k << "\n";
}