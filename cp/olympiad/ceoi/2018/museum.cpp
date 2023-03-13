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

// #define int long long
typedef pair<int, int> T;
const int oo = 2e9+7;

/*
dp[v][k] = minimalny koszt podrozowania zaczynajac w v (byc moze przechodzac kilka razy przez v do roznych poddrzew) i konczac w v, odwiedzajac k wierzcholkow
dp[v][k] = to samo, tylko konczymy gdziekolwiek w poddrzewie v

zlozonosc: przechodzenie po i, j w dfs jest ograniczone z gory przez ilosc sciezek w drzewie, czyli O(n^2)
:333
*/

void solve(){
    int n, k, st; cin >> n >> k >> st;
    vector<vector<T>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    vector<int>sub(n+1);
    vector<vector<int>>dp(n+1, vector<int>(k+1, oo));
    vector<vector<int>>dp2(n+1, vector<int>(k+1, oo));
    function<void(int, int)>dfs = [&](int v, int pa){
        sub[v] = 1;
        dp[v][0] = 0;
        dp[v][1] = 0;
        dp2[v][0] = 0;
        dp2[v][1] = 0;
        for (auto [x, c]: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            for (int i = sub[v]; i>=0; i--){ 
                for (int j = sub[x]; j>=1; j--){ //musimy odwiedzic co najmniej jeden wierzcholek w poddrzewie x, skoro do niego wchodzimy, co nie?
                    //od tylu, by nie robic overcounting
                    if (i + j > k) continue;
                    dp[v][i+j] =  min(dp[v][i+j],  dp[v][i] +  dp[x][j] + 2 * c); 
                    dp2[v][i+j] = min(dp2[v][i+j], dp[v][i] +  dp2[x][j]+ c);
                    dp2[v][i+j] = min(dp2[v][i+j], dp2[v][i]+  dp[x][j] + 2 * c);
                    //1. wchodzimy do jakichs poddrzew dzieci v, zawracamy i wchodzimy do jakiegos poddrzewa x znowu
                    //2. wchodzimy do jakichs poddrzew dzieci x, wchodzimy do v, pozniej do x i nie wracamy juz z v
                    //3. wchodzimy do x, wracamy i to v z idziemy tyyylko w dol
                    //mmm kocham syf na podzbiorach
                }
            }
            sub[v] += sub[x];
        }
    };
    dfs(st, st);
    cout << dp2[st][k] << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}