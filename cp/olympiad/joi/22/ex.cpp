// while (clock()<=69*CLOCKS_PER_SEC)
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                                    \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<(c i) \
    {
sim > struct rge {
    c b, e;
};
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef XOX
    ~debug()
    {
        cerr << endl;
    }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
    ris << "" << d.first << " --> " << d.second << "";
}
sim dor(rge<c> d)
{
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c &)
    {
        ris;
    }
#endif
}
;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#ifdef XOX
#warning Times may differ!!!
#endif
 
#define endl '\n'
#define pb emplace_back
#define vt vector
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int nax = 1000 * 1007, mod = 1e9 + 7;
 

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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


struct RollbackUF {
    vt<int> e;
    vt<pii> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t)
    {
        for (int i = time(); i-- > t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.pb(a, e[a]);
        st.pb(b, e[b]);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    vt<pii> edges(m);
    for (auto &[a, b] : edges) {
        cin >> a >> b;
    }
    RollbackUF uf(2 * n + 12);
    vt<int> last(m, -1);
    auto lacz = [&](int i) {
        if (i == m) {
            return;
        }
        uf.join(edges[i].first, edges[i].second + n);
        uf.join(edges[i].first + n, edges[i].second);
    };
    auto same = [&](int i) {
        if (i == m) {
            return false;
        }
        return uf.find(edges[i].first) == uf.find(edges[i].first + n);
    };
    function<void(int, int, int, int)> rek = [&](int l, int r, int a, int b) {
        int mid = (l + r) / 2;
        int t = uf.time();
        // debug() << imie(l) imie(mid) imie(r) imie(a) imie(b);
        for (int i = l; i < mid; i++) {
            lacz(i);
            if (same(i)) {
                last[mid] = m;
                break;
            }
        }
        if (last[mid] == -1) {
            for (int i = b; i >= mid; i--) {
                lacz(i);
                if (same(i)) {
                    last[mid] = i;
                    break;
                }
            }
            if (last[mid] == -1) {
                last[mid] = mid;
            }
        }
        uf.rollback(t);
        {
            int flag = 0;
            for (int i = b; i > last[mid]; i--) {
                lacz(i);
                if (same(i)) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                // debug() << imie(l) imie(mid - 1) imie(last[mid]);
                for (int i = l; i < mid; i++) {
                    last[i] = last[mid];
                }
            }
            else if (l < mid) {
                rek(l, mid - 1, a, last[mid]);
            }
            uf.rollback(t);
        }
        {
            int flag = 0;
            for (int i = l; i <= mid; i++) {
                lacz(i);
                if (same(i)) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                // debug() << imie(mid + 1) imie(r) imie(last[mid]);
                for (int i = mid + 1; i <= r; i++) {
                    last[i] = m;
                }
            }
            else if (mid < r) {
                rek(mid + 1, r, last[mid], b);
            }
            uf.rollback(t);
        }
    };
    rek(0, m - 1, 0, m);
    debug(last);
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << (last[a] <= b ? "NO" : "YES") << endl;
    }
}