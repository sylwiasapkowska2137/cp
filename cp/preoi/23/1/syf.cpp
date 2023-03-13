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

typedef pair<int, int> T;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
const int oo2 = 1e9+7, K = 30;

int X, Y, Z;
struct state{
    int x, y, z;
    bool up = 0;
    void read(){cin >> x >> y >> z;}
};

void __print(state x){
    cerr << x.x << ", " << x.y << ", " << x.z;
}

bool inside(state &curr){
    return (1 <= curr.x && 1 <= curr.y && 1 <= curr.z && curr.x <= X && curr.y <= Y && curr.z <= Z);
}

int xx[] = {-1, 1, 0, 0, 0, 0};
int yy[] = {0, 0, -1, 1, 0, 0};
int zz[] = {0, 0, 0, 0, -1, 1};

void solve(){
    cin >> X >> Y >> Z;
    vvvi tab(X+2, vvi(Y+2, vi(Z+2)));
    vvvi winda(X+2, vvi(Y+2, vi(Z+2)));
    vvvi dist(X+2, vvi(Y+2, vi(Z+2, oo2)));
    
    for (int k = 1; k<=Z; k++){
        for (int j = Y; j>=1; j--){
            for (int i = 1; i<=X; i++){
                char c; cin >> c;
                if (c == 'X') tab[i][j][k] = 1;
            }
        }
    }
    /*
    for (int k = 1; k<=Z; k++){
        for (int j = 1; j<=Y; j++){
            for (int i = 1; i<=X; i++){
                cerr << tab[i][j][k];
            }
            cerr << "\n";
        }
        cerr << "\n";
    }
    */
    int m; cin >> m;
    for (int i = 1; i<=m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        for (int k = c; k <= d; k++){
            winda[a][b][k] = i;
        }
    }
    state A, B; A.read(); B.read();
    deque<state>q;
    dist[A.x][A.y][A.z] = 0;
    q.push_front(A);
    while (q.size()){
        state v = q.front(); q.pop_front();
        int mx = (winda[v.x][v.y][v.z] ? 6 : 4);
        for (int rep = 0; rep < mx; rep++){
            state s = {v.x + xx[rep], v.y + yy[rep], v.z + zz[rep], (rep >= 4 ? true : false)};
            if (inside(s) && dist[s.x][s.y][s.z] == oo2 && ((winda[s.x][s.y][s.z] == winda[v.x][v.y][v.z] && rep >= 4) || (rep < 4 && tab[s.x][s.y][s.z] == 0 && (v.up == 0 || tab[v.x][v.y][v.z] == 0)))){
                // debug(s);
                dist[s.x][s.y][s.z] = dist[v.x][v.y][v.z] + (rep >= 4 ? 0 : 1);
                if (rep >= 4) q.push_front(s);
                else q.push_back(s);
            }
        }
    }
    if (dist[B.x][B.y][B.z] == oo2) cout << "-1\n";
    else cout << dist[B.x][B.y][B.z] << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}