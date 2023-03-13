#include <bits/stdc++.h>

using namespace std;

double dist(long long xp, long long yp, long long xk, long long yk) {
    return sqrt((xp - xk) * (xp - xk) + (yp - yk) * (yp - yk));
}

int main() {
    int n, xp, yp, xk, yk;
    scanf("%d %d %d %d %d", &n, &xp, &yp, &xk, &yk);

    printf("%.9f\n", dist(xp, yp, xk, yk));

    return 0;
}