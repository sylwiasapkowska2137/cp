#include <iostream>
#include <cassert>
#include <cstring>

const int MAX_N = 1e6;
const int MIN_N = 1;

const char WHITE = 'B';
const char RED = 'C';

using lld = long long int;

char balls[MAX_N + 6];
lld moveBeforeCost[MAX_N + 6];

void prepareBeforeCost(int n) {
    lld cost = 0;
    int redCount = 0;
    for (int i = 0; i < n; i++) {
        moveBeforeCost[i] = cost;
        
        if (balls[i] == RED) {
            redCount++;
        } else {
            cost += redCount;
        }
    }
    moveBeforeCost[n] = cost;
}

lld solve(int n) {
    lld res = moveBeforeCost[n];
    lld cost = 0;
    int redCount = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        if (balls[i] == RED) {
            redCount++;
        } else {
            cost += redCount;
        }
        
        res = std::min(res, moveBeforeCost[i] + cost);
    }
    
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    assert(MIN_N <= n && n <= MAX_N);
    
    scanf("%s", balls);
    assert(strlen(balls) == n);
    
    for (int i = 0; i < n; i++) {
        assert(balls[i] == RED || balls[i] == WHITE);
    }

    prepareBeforeCost(n);
    printf("%lld\n", solve(n));
    
}