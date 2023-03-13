#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll sq(int x)
{
    return (ll)x * x;
}
 
struct C {
    int x, y, r;
    void read() { cin >> x >> y >> r; }
    bool inter(const C &he) const { return sq(x - he.x) + sq(y - he.y) <= sq(r + he.r); }
};
 
struct T {
    int x, y, id;
    T(int xx, int yy, int iid) : x(xx), y(yy), id(iid) {}
    bool operator<(const T &he) const { return tie(x, y) < tie(he.x, he.y); }
};
 
const int oo = 1e9 + 7;
 
int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> ans(n, -1), ord(n);
    vector<C> c(n);
    for(int i = 0; i < n; i++) {
        c[i].read();
        ord[i] = i;
    }
    sort(ord.begin(), ord.end(), [&](auto a, auto b) {
        return c[a].r == c[b].r ? a < b : c[a].r > c[b].r;
    });
    for(int rep = 30; rep >= 1; rep--) {
        vector<T> aa;
        for(int i = 0; i < n; i++) {
            if(ans[i] == -1) {
                aa.emplace_back(c[i].x >> rep, c[i].y >> rep, i);
            }
        }
        sort(aa.begin(), aa.end());
        auto zrob = [&](int i) {
            for(int k = -2; k <= 2; k++) {
                int x = (c[i].x >> rep) - k;
                int lo = (c[i].y >> rep) - 2;
                int hi = (c[i].y >> rep) + 2;
                auto it = lower_bound(aa.begin(), aa.end(), T{x, lo, -1});
                while(it != aa.end() && tie(it->x, it->y) <= tie(x, hi)) {
                    if(ans[it->id] == -1 && c[i].inter(c[it->id])) {
                        ans[it->id] = i;
                    }
                    it++;
                }
            }
        };
        int p = 0;
        while(p < n && c[ord[p]].r >= (1 << (rep - 1))) {
            if(ans[ord[p]] == -1) {
                zrob(ord[p]);
            }
            p++;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << '\n';
}