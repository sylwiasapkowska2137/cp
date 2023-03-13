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

    
const int sz = (1<<21);
int tab[2*sz+1];

void update(int x, int v){
    x += sz;
    tab[x] = max(tab[x], v);
    while (x){
        x/=2;
        tab[x] = max(tab[2*x], tab[2*x+1]);
    }
}

int query(int l, int r){
    int ans = 0;
    for (l += sz-1, r += sz+1; r-l>1; l/=2, r/=2){
        if (!(l&1)) ans = max(ans, tab[l+1]);
        if (r&1) ans = max(ans, tab[r-1]);
    }
    return ans;
}

void clear(){ memset(tab, 0, sizeof(tab));}

struct film{
    int a, b, c;
    film(){}
    film(int _a, int _b, int _c){a = _a, b = _b, c = _c;}
};

// https://judge.yosupo.jp/submission/68439
namespace fastio {
 
static constexpr int SZ = 1 << 17;
char ibuf[SZ], obuf[SZ];
int pil = 0, pir = 0, por = 0;
 
inline void load()
{
    memmove(ibuf, ibuf + pil, pir - pil);
    pir = pir - pil +
          fread_unlocked(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
    pil = 0;
}
 
inline void rd(char &c)
{
    if (pil + 32 > pir) load();
    c = ibuf[pil++];
}
template <typename T>
inline void rd(T &x)
{
    if (pil + 32 > pir) load();
    char c;
    do
        c = ibuf[pil++];
    while (c < '-');
    [[maybe_unused]] bool minus = false;
    if constexpr (std::is_signed<T>::value == true) {
        if (c == '-') minus = true, c = ibuf[pil++];
    }
    x = 0;
    while (c >= '0') {
        x = x * 10 + (c & 15);
        c = ibuf[pil++];
    }
    if constexpr (std::is_signed<T>::value == true) {
        if (minus) x = -x;
    }
}
inline void rd() {}
template <typename Head, typename... Tail>
inline void rd(Head &head, Tail &...tail)
{
    rd(head);
    rd(tail...);
}
 
inline void skip_space()
{
    if (pil + 32 > pir) load();
    while (ibuf[pil] <= ' ')
        pil++;
}
 
inline void flush()
{
    fwrite_unlocked(obuf, 1, por, stdout);
    por = 0;
}
 
struct Pre {
    char num[40000];
    constexpr Pre() : num()
    {
        for (int i = 0; i < 10000; i++) {
            int n = i;
            for (int j = 3; j >= 0; j--) {
                num[i * 4 + j] = n % 10 + '0';
                n /= 10;
            }
        }
    }
} constexpr pre;
 
struct Post {
    Post() { std::atexit(flush); }
} post;
 
inline void wt(char c)
{
    if (por > SZ - 32) flush();
    obuf[por++] = c;
}
inline void wt(bool b)
{
    if (por > SZ - 32) flush();
    obuf[por++] = b ? '1' : '0';
}
template <typename T>
inline void wt(T x)
{
    if (por > SZ - 32) flush();
    if (!x) {
        obuf[por++] = '0';
        return;
    }
    if constexpr (std::is_signed<T>::value == true) {
        if (x < 0) obuf[por++] = '-', x = -x;
    }
    int i = 12;
    char buf[16];
    while (x >= 10000) {
        memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
        x /= 10000;
        i -= 4;
    }
    if (x < 100) {
        if (x < 10) {
            obuf[por] = '0' + x;
            ++por;
        }
        else {
            uint32_t q = (uint32_t(x) * 205) >> 11;
            uint32_t r = uint32_t(x) - q * 10;
            obuf[por] = '0' + q;
            obuf[por + 1] = '0' + r;
            por += 2;
        }
    }
    else {
        if (x < 1000) {
            memcpy(obuf + por, pre.num + (x << 2) + 1, 3);
            por += 3;
        }
        else {
            memcpy(obuf + por, pre.num + (x << 2), 4);
            por += 4;
        }
    }
    memcpy(obuf + por, buf + i + 4, 12 - i);
    por += 12 - i;
}
 
inline void wt() {}
template <typename Head, typename... Tail>
inline void wt(Head &&head, Tail &&...tail)
{
    wt(head);
    wt(std::forward<Tail>(tail)...);
}
template <typename... Args>
inline void wtn(Args &&...x)
{
    wt(std::forward<Args>(x)...);
    wt('\n');
}
 
} // namespace fastio
using fastio::rd;
using fastio::wtn;

void solve(){
    int n, k; rd(n, k);
    vector<film>tab;
    vector<int>ss;
    for (int i = 0; i<n; i++){
        int a, b, c; rd(a, b, c);
        tab.emplace_back(a, b, c);
        ss.emplace_back(c);
    }
    stable_sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());
    stable_sort(tab.begin(), tab.end(), [](auto x, auto y){return x.b == y.b ? x.c > y.c : x.b < y.b;});
    auto check = [&](int mid){
        clear();
        for (auto [l, r, c]: tab){
            if (c < mid) continue;
            int dp = query(1, l-1) + 1;
            if (dp >= k) return true;
            update(r, dp);
        }
        return false;
    };
    int l = 0, r = (int)ss.size()-1, ans = -1;
    while (r >= l){
        int mid = (l+r)/2;
        if (check(ss[mid])){
            ans = ss[mid];
            l = mid+1;
        } else r = mid-1;
    }
    wtn(ans);
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