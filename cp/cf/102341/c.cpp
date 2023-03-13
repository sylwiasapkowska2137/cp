//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;

void solve(){
    int n; cin >> n;
    int lx = 1, rx = n, ly = 1, ry = n;
    int mx = 0, q = 0; 

    auto ask = [&](int a, int b){
        if (a < 1 || b < 1 || a > n || b > n) return -1LL;
        cout << "? " << a << " " << b << "\n"; cout.flush();
        int x; cin >> x;
        q++;
        return x;
    };
    
    auto answer = [&](T x){
        cout << "! " << x.first << " " << x.second << endl;
        exit(0);
    };
    
    vector<int>X = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int>Y = {-1, 0, 1, -1, 1, -1, 0, 1};
    T pos = {1, 1};
    auto neighbors = [&](){
        int mx2 = mx;
        T pos2 = pos;
        bool any = 0;
        for (int k = 0; k<8; k++){
            int tmp = ask(pos.first+X[k], pos.second+Y[k]);
            if (tmp > mx2){
                any = 1;
                mx2 = tmp;
                pos2 = {pos.first+X[k], pos.second+Y[k]};
            }
        }
        if (mx2 > mx){
            mx = mx2;
            pos = pos2;
        }
        debug(pos, mx);
        if (!any) answer(pos);
    };
    int turn = 1;
    while (rx >= lx && ry >= ly){
        debug(lx, rx, ly, ry);
        if (turn){
            int m = (lx+rx)/2;
            for (int i = ly; i<=ry; i++){
                int curr = ask(i, m);
                if (curr > mx){
                    mx = curr;
                    pos = {i, m};
                }
            }
            neighbors();
            if (pos.second < m) rx = m-1;
            else lx = m+1;
        } else { //w poziomie
            int m = (ly+ry)/2;
            for (int i = lx; i<=rx; i++){
                int curr = ask(m, i);
                if (curr > mx){
                    mx = curr;
                    pos = {m, i};
                }
            }
            neighbors();
            if (pos.first < m) ry = m-1;
            else ly = m+1;
        }
        turn ^= 1;
    }
    debug(q);
    answer({lx, ly});
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}