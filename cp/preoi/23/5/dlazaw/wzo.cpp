//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "spolib.h"
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

typedef pair<int, int> T;

void solve(){
    int n = init();
    vector<int>now;
    for (int i = 1; i<=n; i++) now.emplace_back(i);
    char c = ask(now);
    int q = 1, L = 1, R = n+1;
    while (R > L){
        int mid = (L+R)/2;
        now.clear();
        for (int i = mid; i<mid+n; i++) now.emplace_back(i);
        q++;
        if (ask(now) == c){
            L = mid+1;
        } else {
            R = mid;
        }
    }
    vector<char>ans(n+n+1, 'X');
    // cout << L << " " << R << "\n";
    vector<int>useful, to_check;
    int curr = L+n-1, nxt = L-1;

    now.clear();
    int k = L-1;
    while ((int)now.size() < n){
        now.emplace_back(k);
        k = (k == n+n ? 1 : k+1);
    }
    ans[nxt] = ask(now);
    q++;
    
    // cout << curr << " " << nxt << "\n";
    ans[curr] = (c == 'P' ? 'H': 'P');
    if (curr > nxt) swap(curr, nxt);
    for (int rep = 1; rep <= n+n; rep++){
        if (rep == curr || rep == nxt) continue;
        if (rep > curr && rep < nxt) useful.emplace_back(rep);
        else to_check.emplace_back(rep);
    }
    /*
    for (auto x: useful) cout << x << " ";
    cout << "\n";
    for (auto x: to_check) cout << x << " ";
    cout << "\n";
    */
    for (int rep = 0; rep < 2; rep++){
        for (auto x: to_check){
            useful.emplace_back(x);
            ans[x] = ask(useful);
            q++;
            useful.pop_back();
        }
        useful.swap(to_check);
    }
    string ret;
    for (int i = 1; i<=n+n; i++) ret += ans[i];
    // cout << ret << "\n";
    assert(q <= 210);
    // cout << q << "\n";
    answer(ret);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}