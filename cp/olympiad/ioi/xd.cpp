#include <bits/stdc++.h>
using namespace std;

vector<int> coin_flips(vector<int>b, int c){
    int x = 0;
    for (int i = 0; i<64; i++){
        if (b[i]){
            x ^= i;
        }
    }
    x ^= c;
    return vector<int>{x};
}

int find_coin(vector<int>b){
    int x = 0;
    for (int i = 0; i<64; i++){
        if (b[i]){
            x ^= i;
        }
    }
    return x;
}

