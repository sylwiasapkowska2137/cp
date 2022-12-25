#include <bits/stdc++.h>
#define debug if(0)
 
const int MAX_N = 5e5;
int n;
int t[MAX_N+3];
std::vector<int> pos[MAX_N+3];
int w[MAX_N+3];
 
const int base = 1<<19;
int tree[2*base+5];
const int inf = 1e9;
 
void clear(int low, int high, int v){
    tree[v] = inf;
    if (low == high)
        return;
    int mid = (low+high)/2;
    clear(low, mid, v*2);
    clear(mid+1, high, v*2+1);
}
 
void insert(int low, int high, int p, int v, int x){
    debug{
        if (v == 1){
            std::cout << "Robie insert w punkcie " << p << " wartosci " << x << "\n";
        }
    }
 
    if (low > high)
        return;
    if (p < low || p > high)
        return;
    if (low == high){
        tree[v] = x;
        return;
    }
    int mid = (low+high)/2;
    if (p <= mid)
        insert(low, mid, p, v*2, x);
    else
        insert(mid+1, high, p, v*2+1, x);
    tree[v] = std::min(tree[v*2], tree[v*2+1]);
}
 
int query(int low, int high, int v, int x){
    if (tree[v] >= x)
        return -1;
    // najmniejszy numer liscia, ze wartosc w nim jest < x
    if (low == high)
        return low;
    int mid = (low+high)/2;
    if (tree[v*2] < x)
        return query(low, mid, v*2, x);
    else
        return query(mid+1, high, v*2+1, x);
}
 
void input(){
    std::cin >> n;
    std::vector<int> tmp;
    for (int i = 1; i <= n; i++){
        std::cin >> t[i];
        tmp.push_back(t[i]);
    }
    std::sort(tmp.begin(), tmp.end());
    tmp.resize(std::unique(tmp.begin(), tmp.end())-tmp.begin());
    std::map<int, int> map;
    for (int i = 0; i < tmp.size(); i++)
        map[tmp[i]] = i+1;
    for (int i = 1; i <= n; i++){
        t[i] = map[t[i]];
        pos[t[i]].push_back(i);
    }
    clear(1, n, 1);
}
 
int solve(int x){
    debug std::cout << "Rozwazam wartosc " << x << "\n";
 
    // szukam takich przedzialow o dlugosci >= 2, ze liderem jest x
    int res = 0;
    w[pos[x].front()] =  2 - (pos[x].front());
    insert(1, n, pos[x].front(), 1, w[pos[x].front()]);
    for (int i = 1; i < pos[x].size(); i++){
        int p = pos[x][i];
        w[p] = 2*(i+1) - p;
 
        debug std::cout << "Zadaje pytanie o wartosc < " << w[p] + 1 << "\n";
 
        int q = query(1, n, 1, w[p]+1);
        if (q == -1){
            // nie znalazlem, wrzucam na drzewko i spadam
            insert(1, n, p, 1, w[p]);
            continue;
        }
 
        debug{
            std::cout << "Dla R = " << p << ", znalazlem L = " << q << "\n";
        }
 
        // chce rozszerzyc [q, p] o jak najwiecej
        if (q != pos[x].front()){
            // jest jeszcze jakies x na lewo, dociagam jak najwiecej z lewej
            int adv = w[p] - w[q] + 1;
 
            debug std::cout << "Moge rozszerzyc o adv-1 = " << adv-1 << "\n";
 
            // nie musze sie przejmowac, dociagam az adv - 1
            res = std::max(res, p-q+1 + (adv-1));
        }
        else{
            // sprobuje siegnac az do 1
            int spare = pos[x].front() - 1;
            if (i < pos[x].size()-1){
                // jest cos na prawo
                spare += pos[x][i+1] - pos[x][i];
            }
            else{
                // to ostatni
                spare += n - pos[x][i];
            }
            // spare to o ile maks jestem w stanie rozszerzyc
            int adv = w[p] - w[q] + 1;
 
            debug{
                std::cout << "Moge rozszerzyc o min spare = " << spare << " i adv-1 = " << adv-1 << "\n";
            }
            res = std::max(res, p-q+1 + std::min(spare, adv - 1));
        }
    }
    for (auto p: pos[x])
        insert(1, n, p, 1, inf);
    return res;
}
 
int main(){
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL);
    input();
    int res = 1;
    for (int i = 1; i <= n; i++)
        if (pos[i].size() >= 2)
            res = std::max(res, solve(i));
    std::cout << res << "\n";
}