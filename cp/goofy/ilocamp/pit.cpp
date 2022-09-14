#include <bits/stdc++.h>
int main(){int tab[6][6];std::pair<int, int>p;for (int i = 1; i<=5; i++) for (int j = 1; j<=5; j++) std::cin >> tab[i][j];for (int i = 1; i<=5; i++) for (int j = 1; j<=5; j++) if (tab[i][j]) p = {i, j};std::cout << abs(p.first-3)+abs(p.second-3) << "\n";}
