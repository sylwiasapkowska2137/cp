#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = p(1, 5);
    cout << n << "\n";
    const int M = 100;
    for (int i = 0;i<n; i++){
        cout << p(0, M) << " " << p(0, M) << " " << p(-M, M) << "\n";
    }
}

void solve2(){
    int n = p(1, 11);
    cout << n << "\n";
    for (int i = 1; i<=n; i++) cout << p(1, 20) << " ";
    cout << "\n";
}


int main(){
   solve2();
}