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
const int mod = 998244353;

//osiagalnych stanow jest bardzo malo, poniewaz za kazdym razem dzielimy przez 2, 3 lub 5
//n -> n/(2^a * 3^b * 5^c), 0≤a, b, c≤30, wiec mozliwych stanow jest log(A)^6 (bo mamy pary liczb), A=max n
bool backtrack(int n, int m, int turn){ //jaka to jest sytuacja dla bitka (gracza 1) -> przegrywajaca czy wygrywajaca
    if (!n && !m) {
        return !turn;
    }
    if (turn){
        if (n){
            for (auto k: {2, 3, 5}){
                if (backtrack(n/k, m, turn^1)){
                    return 1;
                }
            }
        }
        if (m){
            for (auto k: {2, 3, 5}){
                if (backtrack(n, m/k, turn^1)){
                    return 1;
                }
            }
        }
        return 0;
    } else {
        if (n){
            for (auto k: {2, 3, 5}){
                if (!backtrack(n/k, m, turn^1)){
                    return 0;
                }
            }
        }
        if (m){
            for (auto k: {2, 3, 5}){
                if (!backtrack(n, m/k, turn^1)){
                    return 0;
                }
            }
        }
        return 1;
    }

}

void solve(){
    int a, b; cin >> a >> b;
    if (backtrack(a, b, 1)) cout << "Bitek\n";
    else cout << "Bajtek\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}