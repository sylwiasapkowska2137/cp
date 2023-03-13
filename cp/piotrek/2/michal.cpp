#include <bits/stdc++.h>
using namespace std;
constexpr int maxN = 3e5+7, Base = 512*1024;

/// tree trzymam jaki maks wynik jezeli wezme i-ty

int n,d,a[maxN],tree[2*Base],ans;
stack<pair<int,int>>nowiuskie; /// i, val
pair<int,int>cristianoronaldo[maxN]; /// ai, i

void insert(int v, int val){
    ans = max(ans, val);
    v += Base;
    while(v){
        tree[v] = max(tree[v], val);
        v /= 2;
    }
}

int query(int va, int vb){
    va += Base, vb += Base;
    int res = max(tree[va], tree[vb]);
    while(va/2 != vb/2){
        if(va % 2 == 0)
            res = max(res, tree[va+1]);
        if(vb % 2 == 1)
            res = max(res, tree[vb-1]);
        va /= 2, vb /= 2;
    }
    return res;
}

void add(){
    while(!nowiuskie.empty()){
        insert(nowiuskie.top().first, nowiuskie.top().second);
        nowiuskie.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cristianoronaldo[i] = {a[i],i};
    }
    sort(cristianoronaldo+1, cristianoronaldo+1+n);
    for(int i=1;i<=n;i++){
        int poz = cristianoronaldo[i].second;
        nowiuskie.push({poz, query(max(poz-d, 0), poz-1)+1});
        if(cristianoronaldo[i].first != cristianoronaldo[i+1].first)
            add();
    }
    cout<<ans<<"\n";
}
/*

12 2
2 5 5 3 3 5 10 10 6 8 1 4

*/