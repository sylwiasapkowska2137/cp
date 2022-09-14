#include <bits/stdc++.h>

using i64 = long long;

constexpr int V = 200000;
template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        points.emplace_back(x - y + 100000, x + y);
    }
    std::sort(points.begin(), points.end());
    
    int q;
    std::cin >> q;
    
    std::vector<int> a(q), b(q), k(q);
    for (int i = 0; i < q; i++) {
		int x, y;
        std::cin >> x >> y >> k[i];
        a[i] = x-y+10000;
        b[i] = x+y;
        //std::tie(a[i], b[i]) = std::pair(a[i] - b[i] + 100000, a[i] + b[i]);
    }
    
    std::vector<int> l(q, 0), r(q, V);
    
    while (true) {
        bool finish = true;
        std::vector<int> cnt(q);
        std::vector<std::tuple<int, int, int, int, int>> queries;
        for (int i = 0; i < q; i++) {
            if (l[i] < r[i]) {
                int m = (l[i] + r[i]) / 2;
                int L = std::max(0, a[i] - m);
                int R = std::min(V, a[i] + m);
                int D = std::max(0, b[i] - m);
                int U = std::min(V, b[i] + m);
                
                queries.emplace_back(L, i, -1, D, U);
                queries.emplace_back(R + 1, i, 1, D, U);
                
                finish = false;
            }
        }
        
        if (finish) {
            break;
        }
        
        std::sort(queries.begin(), queries.end());
        
        Fenwick<int> fen(V + 1);
        int j = 0;
        for (auto [v, i, c, d, u] : queries) {
            while (j < n && points[j].first < v) {
                fen.add(points[j].second, 1);
                j++;
            }
            cnt[i] += c * fen.rangeSum(d, u + 1);
        }
        
        for (int i = 0; i < q; i++) {
            if (l[i] < r[i]) {
                int m = (l[i] + r[i]) / 2;
                if (cnt[i] >= k[i]) {
                    r[i] = m;
                } else {
                    l[i] = m + 1;
                }
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        std::cout << l[i] << "\n";
    }
    
    return 0;
}
