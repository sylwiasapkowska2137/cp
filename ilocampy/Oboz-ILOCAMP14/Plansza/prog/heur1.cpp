#include <bits/stdc++.h>

int main() {
    int a, b, s;
    scanf("%d %d %d", &a, &b, &s);
    printf(abs(a) + abs(b) > s ? "NIE\n" : "TAK\n");
    return 0;
}