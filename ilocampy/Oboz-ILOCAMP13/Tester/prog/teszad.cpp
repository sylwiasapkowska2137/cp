#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>

const int MIN_N = 1;
const int MAX_N = 500 * 1000;

std::vector<int> graph[MAX_N + 1];
int sizeAsRoot[MAX_N + 1];

struct Trio {
    int vals[3];
    Trio() : vals{0, 0, 0} {
    }

    void add(int x) {
        if (x > vals[2]) {
            vals[0] = vals[1];
            vals[1] = vals[2];
            vals[2] = x;
        } else if (x > vals[1]) {
            vals[0] = vals[1];
            vals[1] = x;
        } else if (x > vals[0]) {
            vals[0] = x;
        }
    }
};

int calculate(int node, int parent = -1) {
    int maxResult = 1;
    Trio trio;

    for (auto child : graph[node]) {
        if (child != parent) {
            maxResult = std::max(maxResult, calculate(child, node));
            trio.add(sizeAsRoot[child]);
        }
    }

    sizeAsRoot[node] = 1 + trio.vals[2] + trio.vals[1];
    return std::max(maxResult, trio.vals[0] + trio.vals[1] + trio.vals[2] + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    assert(n >= MIN_N && n <= MAX_N);

    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        assert(a >= 1 && a <= n);
        assert(b >= 1 && b <= n);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    printf("%d\n", n - calculate(1));

    for (int i = 1; i <= n; i++) {
        assert(sizeAsRoot[i] > 0);
    }
}