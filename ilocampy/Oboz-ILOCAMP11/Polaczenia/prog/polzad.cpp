#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>

const int MIN_N = 3;
const int MAX_N = 100 * 1000;

using lld = long long int;

std::vector<int> graph[MAX_N + 1];

struct Result {
    int odd;
    int even;
    lld res;
};

Result calculate(int node, int parent = -1) {
    Result result{0, 0, 0};
    
    if (graph[node].size() == 1) {
        result.odd = 1;
    } else {
        std::vector<Result> childrenResults;
        for (auto child : graph[node]) {
            if (child != parent) {
                auto childRes = calculate(child, node);
                
                std::swap(childRes.even, childRes.odd);
                result.even += childRes.even;
                result.odd += childRes.odd;
                result.res += childRes.res;
                
                childrenResults.push_back(childRes);
            }
        }
        
        for (const auto &res : childrenResults) {
            result.even -= res.even;
            result.odd -= res.odd;
            
            result.res += lld(res.odd) * result.odd;
            result.res += lld(res.even) * result.even;
            
            result.even += res.even;
            result.odd += res.odd;
        }
    }
    
    graph[node].clear();
    
    return result;
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

    for (int i = 1; i <= n; i++) {
        // root which is not leaf
        if (graph[i].size() > 1) {
            printf("%lld\n", calculate(i).res / 2);
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        assert(graph[i].empty());
    }
}