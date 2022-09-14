#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
    return a+rng()%(b-a+1);
}

int main(){
    int n = p(1, 100);
    cout << n << "\n";  
    for (int i = 0; i<n; i++){
        int ile = p(1, 100);
        int c = p(1, ile);
        cout << ile << " " << c << "\n";
        for (int j = 0; j<ile; j++){
            cout << p(1, 200) << " ";
        }
        cout << "\n";
    }
    int q = p(1, 100);
    cout << q << "\n";
    while (q--){
        cout << p(0, 200) << "\n";
    }
}