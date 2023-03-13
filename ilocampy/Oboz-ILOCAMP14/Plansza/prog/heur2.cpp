#include <bits/stdc++.h>

int main() {
    int a, b, s;
    scanf("%d %d %d", &a, &b, &s);
    printf(abs((a + b) % 2) != s % 2 ? "NIE\n" : "TAK\n");
    return 0;
}