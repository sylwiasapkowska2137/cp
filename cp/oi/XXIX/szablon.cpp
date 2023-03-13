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

void solve(){
    string s; cin >> s;
    int n = (int)s.size();
    string t = s + "#" + string(s.rbegin(), s.rend());
    int N = (int)t.size();
    vector<int>z(N), ans, check;
    for (int i = 1, l = 0, r = 0; i<N; i++){
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i+z[i] < N && t[z[i]] == t[z[i]+i]) z[i]++;
        if (i + z[i] - 1 > r){
            l = i;
            r = i+z[i] - 1;
        }
    }
    vector<T>R, L;
    for (int i = 0, j = N-1; i<n; i++, j--) {
        R.emplace_back(z[i], i);
        L.emplace_back(z[j], i);
        if (z[i] + i == n){
            check.emplace_back(z[i]);
        }
    }
    check.emplace_back(n);
    for (int i = 1; i<=L.back().first; i++) check.emplace_back(i);
    sort(check.rbegin(), check.rend());
    check.erase(unique(check.begin(), check.end()), check.end());
    sort(L.rbegin(), L.rend());
    sort(R.rbegin(), R.rend());

    set<int>secik, rev;
    vector<int>A, B;
    // debug(z);
    debug(check);
    int ptrL = 0, ptrR = 0;
    vector<int>Aused(n+1), Bused(n+1);
    for (int len: check){
        secik.insert(0);
        if (L.back().first >= len) rev.insert(n-1);
        while (ptrL < (int)L.size() && L[ptrL].first >= len){
            rev.insert(L[ptrL++].second);
        }
        while (ptrR < (int)R.size() && R[ptrR].first >= len){
            secik.insert(R[ptrR++].second);
        }
        bool dasie = 1;
        // debug(secik);
        // debug(rev);
        int j = -1; //pokryty jest przedzial [0, j]
        while (j < n-1){
            bool any = 0;
            auto it = secik.upper_bound(j+1);
            if (it != secik.begin()){
                it--;
                if (*it+len-1 > j && !Aused[*it]){
                    A.emplace_back(*it);
                    Aused[*it] = 1;
                    j = max(j, *it+len-1);
                    any = 1;
                }
            }
            if (any) continue;
            it = rev.upper_bound(j+len);
            if (it != rev.begin()){
                it--;
                if (*it > j && !Bused[*it]){
                    B.emplace_back(*it);
                    Bused[*it] = 1;
                    j = max(j, *it);
                    any = 1;
                }
            } 
            if (!any){
                dasie = 0;
                break;
            }
        }
        for (auto x: A) Aused[x] = 0;
        for (auto x: B) Bused[x] = 0;
        A.clear(); B.clear();
        if (dasie) ans.emplace_back(len);
    }
    for (int i = (int)ans.size()-1; i>=0; i--) cout << ans[i] << " ";
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}