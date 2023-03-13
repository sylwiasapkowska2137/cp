// while (clock()<=69*CLOCKS_PER_SEC)
// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define int long long
 
const int oo = 1e18 + 213;
 
int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(1 + all(a), [&](auto &i, auto &j) {
        return i.second < j.second;
    });
    int ret = -oo;
    multiset<int> small, big;
    int sum = 0, L = 1, R = n;
    auto balance = [&]() {
        if (!size(small) || !size(big)) return;
        if (size(big) < m) {
            int dod = *small.rbegin();
            small.erase(small.find(dod));
            sum += dod;
            big.insert(dod);
            return;
        }
        if (*small.rbegin() > *big.begin()) {
            int usu_1 = *small.rbegin();
            int usu_2 = *big.begin();
            big.erase(big.find(usu_2));
            small.erase(small.find(usu_1));
            big.insert(usu_1);
            small.insert(usu_2);
            sum += usu_1 - usu_2;
        }
    };
    auto dod = [&](int x) {
        if (size(big) < m) {
            big.insert(x);
            sum += x;
        }
        else small.insert(x);
        balance();
    };
    auto usu = [&](int x) {
        if (small.find(x) != small.end()) small.erase(small.find(x));
        else {
            big.erase(big.find(x));
            sum -= x;
        }
        balance();
    };
    auto napraw = [&](int new_l, int new_r) {
        while (new_l < L)
            dod(a[--L].first);
        while (R < new_r)
            dod(a[++R].first);
        while (L < new_l)
            usu(a[L++].first);
        while (new_r < R)
            usu(a[R--].first);
    };
    for (int i = 1; i <= n; i++)
        dod(a[i].first);
    function<void(int, int, int, int)> rek = [&](int l, int r, int lo, int hi) {
        debug() << imie(l) imie(r) imie(lo) imie(hi);
        if (l > r || lo > hi) return;
        int ans = LLONG_MIN, pos = hi;
        int mid = (l + r) / 2;
        for (int i = max(lo, mid + m - 1); i <= hi; i++) {
            napraw(mid, i);
            int maybe = sum - 2 * (a[i].second - a[mid].second);
            debug() << imie(mid) imie(i) imie(maybe);
            if (maybe > ans) {
                ans = maybe;
                pos = i;
            }
        }
        ret = max(ret, ans);
        rek(l, mid - 1, lo, pos);
        rek(mid + 1, r, pos, hi);
    };
    rek(1, n, m, n);
    cout << ret << endl;
}
