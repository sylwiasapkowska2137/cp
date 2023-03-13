#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500000;

bool inRange(int w, int a, int b) {
    return a <= w && w <= b;
}

int main() {
    int n, p, j, m_j, m_p;
    scanf("%d %d %d", &n, &p, &j);
    assert(inRange(n, 1, MAX_N));
    assert(inRange(p, 1, n) && inRange(j, 1, n));
    scanf("%d", &m_p);
    assert(inRange(m_p, 0, MAX_N));
    for (int i = 1; i <= m_p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        assert(a != b);
        assert(inRange(a, 1, n));
        assert(inRange(b, 1, n));
    }
    scanf("%d", &m_j);
    assert(inRange(m_j, 0, MAX_N));
    for (int i = 1; i <= m_j; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        assert(a != b);
        assert(inRange(a, 1, n));
        assert(inRange(b, 1, n));
    }
    return 0;
}