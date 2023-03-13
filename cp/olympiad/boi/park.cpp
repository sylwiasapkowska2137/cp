#include <bits/stdc++.h>
using namespace std;
template<class A, class B> auto& operator <<(ostream &o, pair<A, B>p){
    return o << "{" << p.first << ", " << p.second << "}";
}
template<class T> auto operator <<(ostream &o, T x) -> decltype(x.end(), o) {
    o << "{"; int i = 0; for (auto e: x) o << "{", "}"+2*!i++ << e; return o << "}";
}
#ifdef LOCAL
#define debug(x...) cerr << "[" #x "]: [", [](auto ... $) {((cerr << $ << ", "), ...);}(x), cerr << "]\n" 
#else
#define debug(x...) {}
#endif

#define int long long
typedef pair<int, int> T;
typedef tuple<int, int, int> F;

void solve(){
    int n, m; cin >> n >> m;
    int w, h; cin >> w >> h;
    debug(n, m, w, h);
    vector<F>cir;
    for (int i = 0; i<n; i++){
        int x, y, r; cin >> x >> y >> r;
        cir.emplace_back(x, y, r);
    }
    for (auto [x, y, r]: cir){
        debug(x, y, r);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}