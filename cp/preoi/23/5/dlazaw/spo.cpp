//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "spolib.h"
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
typedef pair<int, int> T;

void solve(){
    int n = init();
    vector<char>adj(n+n+1);
    vector<int>now;
    for (int first = 1; first <= n; first++){
        now.clear();
        for (int i = 0; i<n; i++) now.emplace_back(first+i);
        int last = first + n - 1;
        // cout << (first == 1 ? n+n : first - 1) << " " << last << "\n";
        adj[last] = ask(now);
        adj[first == 1 ? n+n : first - 1] = (adj[last] == 'H' ? 'P' : 'H');
        // for (auto x: now) cout << x << " ";
        // cout << "\n";
    }  
    vector<char>ans(n+n+1, 'X');
    vector<int>useful, to_check;
    for (int i = 1; i<=n+n; i++){
        if (adj[i] != adj[i == 1 ? n+n : i-1]){
            int j = (i-n < 1 ? i+n : i-n);
            int k = i;
            ans[i] = adj[i];
            ans[j] = (adj[i] == 'P' ? 'H': 'P');
            if (k > j) swap(k, j);
            for (int rep = 1; rep <= n+n; rep++){
                if (rep == j || rep == k) continue;
                if (rep > k && rep < j) useful.emplace_back(rep);
                else to_check.emplace_back(rep);
            }
            break;
        }
    }
    for (int i = 1; i<=n+n; i++){
        cout << adj[i];
    }
    cout << "\n";
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
            useful.pop_back();
        }
        useful.swap(to_check);
    }
    string ret;
    for (int i = 1; i<=n+n; i++){
        // cout << ans[i];
        ret += ans[i];
    }
    // cout << "\n";
    answer(ret);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}