//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "art.h"
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

void solve(int n){
    vector<int>curr(n);
    iota(curr.begin(), curr.end(), 1);
    int ans1 = publish(curr);
    vector<int>ans(n);
    int fst = ans1;
    for (int i = 1; i<n; i++){
        rotate(curr.begin(), curr.begin()+1, curr.end());
        int ans2 = publish(curr);
        int inv = (ans1 - ans2 + n - 1)/2;
        ans[inv] = curr.back();
        ans1 = ans2;
    }
    rotate(curr.begin(), curr.begin()+1, curr.end());
    int ans2 = fst;
    int inv = (ans1 - ans2 + n - 1)/2;
    ans[inv] = curr.back();
    answer(ans);
}