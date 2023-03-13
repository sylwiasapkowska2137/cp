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
const int mx = 2500007;
const int oo2 = 1e9+1;
int prime[mx+2];

int len(long long a){
    int r = 0;
    while (a){
        r++;
        a/=10;
    }
    return r;
}

int divs(int x){
    if (x < mx){
        int prev = -1, cnt = 0, ans = 1;
        while (x > 1){
            if (prime[x] == prev){
                cnt++;
            } else{
                ans *= (cnt+1);
                cnt = 1;
                prev = prime[x];
            }
            x/=prime[x];
        }
        ans *= (cnt+1);
        return ans;
    } else {
        int ans = 2;
        for (int d = 2; d*d <= x; d++){
            if (x%d == 0){
                if (x/d != d) ans+=2;
                else ans++;
            }
        }
        return ans;
    }
}

int divs2(int x){
    if (x == 1) return 1;
    int ans = 2;
    for (int d = 2; d*d <= x; d++){
        if (x%d == 0){
            if (x/d != d) ans+=2;
            else ans++;
        }
    }
    return ans;
}

void solve(){
    vector<int>p;
    vector<T>que;
    int _; cin >> _;
    bool sub3 = 1;
    bool sub4 = 1;
    int wow = 1e7;
    for (int i = 0; i<_; i++){
        int a, b; cin >> a >> b;
        que.emplace_back(a, b);
        sub3 &= (len(a) == len(b) && len(a) % 2 == 1);
        sub4 &= (b <= wow);
    }
    if (!sub4){
        for (auto [a, b]: que){
            int ans = 0;
            int t = len(a);
            for (int i = a; i<=b; i++){
                if (i % 10 == 0) t = len(i);
                if (divs2(i) == t){
                    ans++;
                }
            }
            cout << ans << "\n";
        }
        return;
    }
    for (long long i = 2; i<mx; i++){
        if (!prime[i]){
            p.emplace_back(i);
            prime[i] = i;
            for (long long j = i*i; j<mx; j+=i){
                if (!prime[j]){
                    prime[j] = i;
                }
            }
        }
    }
    vector<int>all;
    int mx2 = 1e7+7;
    for (int x = 1; x*x <= mx2; x++){
        int t = x*x;
        int l = len(t);
        if (l&1){
            if (divs(t) == l){
                all.emplace_back(t);
            }
        }
    }
    debug((int)p.size());
    if (!sub3){
        //2cyfrowe
        for (auto &x: p){
            int t = len(x);
            if (t > 2) break;
            if (t == 2) all.emplace_back(x);
        }
        //4 cyfrowe
        for (int i = 0; i<(int)p.size(); i++){
            if (len(p[i]) > 2) break;
            long long tt = (long long)p[i] * p[i] * p[i];
            if (len(tt) == 4){
                all.emplace_back(tt);
            }
        }
        for (int i = 0; i<(int)p.size(); i++){
            if (len(p[i]) > 3) break;
            for (int j = i+1; j<(int)p.size(); j++){
                int t = p[i] * p[j];
                int x = len(t);
                if (x > 4) break;
                if (x == 4) all.emplace_back(t);
            }
        }
        //6 cyfrowe
        for (int i = 0; p[i] <= 37; i++){
            long long tt = p[i] * p[i] * p[i] * p[i] * p[i];
            int xx = len(tt);
            if (xx == 6){
                all.emplace_back(tt);
            }
        }
        for (int i = 0; i<(int)p.size(); i++){
            if (len(p[i]) > 2) break;
            for (int j = i+1; j<(int)p.size(); j++){
                long long t = (long long)p[i] * p[i] * p[j];
                int x = len(t);
                if (x > 6) break;
                if (x == 6) all.emplace_back(t);
                t = (long long)p[i] * p[j] * p[j];
                x = len(t);                
                if (x == 6) all.emplace_back(t);
            }
        }
    }
    /*
    //8 cyfrowe
    for (int i = 0; i<(int)p.size(); i++){
        if (len(p[i]) > 8) break;
        for (int j = i+1; j<(int)p.size(); j++){
            if (len(p[i] * p[j]) > 8) break;
            for (int k = j+1; k < (int)p.size(); k++){
                int t = p[i] * p[j] * p[k];
                int x = len(t);
                if (x > 8) break;
                if (x == 8){
                    all.emplace_back(t);
                }
            }
        }
    }
    */
    all.emplace_back(0);
    stable_sort(all.begin(), all.end());
    debug((int)all.size());
    for (auto [a, b]: que){
        cout << upper_bound(all.begin(), all.end(), b) - upper_bound(all.begin(), all.end(), a-1) << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}