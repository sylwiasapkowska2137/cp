#include <iostream>
#include <vector>

using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define LL long long

const int MAX = 3e3+2137;
vector <int> graf[MAX];
vector <bool> vis;
int n;

bool dfs(int v){
    if (v == n) return true;
    vis[v] = true;
    bool s = false;
    int i = 0;
    while (!s && i<graf[v].size()){
        if (!vis[graf[v][i]]) s = dfs(graf[v][i]);
        i++;
    }
    return s;
}

int calc(){
    int res = 0;
    if (graf[1].back() == n) {
        res++;
        graf[1].pop_back();
    }
    while (dfs(1)) {
        res++;
        vis[n] = false;
    }
    // cerr << dfs(1);
    return res;
}

int main(){
    fastio;
    int ile, a;
    cin >> n;
    for (int i = 1; i<n; i++){
        cin >> ile;
        while (ile--){
            cin >> a;
            graf[i].push_back(a);
        }
    }
    vis.assign(n+1, false);
    cout << calc();
    return 0;
}