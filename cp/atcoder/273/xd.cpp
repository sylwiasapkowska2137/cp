#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>ok = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    int n = 12;
    int ret = 0;
    for (int mask = 0; mask<(1<<n); mask++){
        int b = __builtin_popcountll(mask);
        if (b != 5) continue;
        int black = 0, white = 0;
        for (int i = 0; i<n; i++){
            if (!(mask&(1<<i))){
                if (ok[i]) black++;
                else white++;
            }
        }
        long double now = (long double)(black)/(long double)(white);
        if (now > 0.5){
            ret++;
        }
    }
    cout << ret << "\n";
}