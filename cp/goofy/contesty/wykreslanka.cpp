#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5;
int a[MAX];
set <int> vis;
map <int, int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, z, k;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) a[i] = (int)(s[i] - 'a');
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        if(vis.find(a[i]) != vis.end()) m[a[i]]++;
        if(vis.find(a[i] - 1) != vis.end()) m[a[i]] = max(m[a[i] - 1] + 1, m[a[i]]);
        res = max(res, m[a[i]]);
        vis.insert(a[i]);
    }
    cout << res+1 << "\n";
    return 0;
}
