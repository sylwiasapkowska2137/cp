#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 1e5+7;
vector < pair <int, int> > tab;
int res[MAX];
bool ss(pair <int, int> e1, pair <int, int> e2){
    return e1.first < e2.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, ile, x;
    cin >> n >> m >> t;
    for (int i = 0; i<n; i++){
        cin >> ile;
        for (int j = 0; j<ile; j++){
            cin >> x;
            tab.push_back(make_pair(x,i));
        }
    }
    sort(tab.begin(), tab.end(), ss);
    // for (auto x: tab) cout << x.first << " ";
    if (n == 1) res[0] = ile;
    else {
        for (int i = tab.size()-1; i>=0; i--){
            x = tab[i].second; //dp
            if (x != n-1){
                res[x+1] = min(res[x+1], res[x]+1);
                res[x] = min(res[x]+1, res[x+1]);
            } else {
                res[x]++;
            }
        }
    }
    while (t--){
        cin >> x;
        x--;
        cout << res[x] << "\n";
    }
    return 0;
}