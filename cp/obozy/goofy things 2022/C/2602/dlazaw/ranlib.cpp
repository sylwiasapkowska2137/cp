#include "ranlib.h"
#include <bits/stdc++.h>
#include <random>
#include <stdio.h>
#include <tuple>
#include <vector>

bool initialized = 0;
int xyz, e, cnt=0;
std::vector<std::pair<int, int>> kraw;
std::vector<std::vector<int>> graph;
std::vector<int> dep, par;
std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
void dfz(int u, int p)
{
    for (int i = 0; i < (int)graph[u].size(); i++) {
        if (graph[u][i] != p) {
            par[graph[u][i]] = u;
            dep[graph[u][i]] = dep[u] + 1;
            dfz(graph[u][i], u);
        }
    }
}

void initialize()
{
    scanf("%d", &xyz);
    scanf("%d", &e);
    graph.resize(xyz + 1);
    dep.resize(xyz + 1);
    par.resize(xyz + 1);
    for (int i = 2; i <= xyz; i++) {
        int u, v;
        scanf("%d", &u);
        scanf("%d", &v);
        kraw.push_back({u, v});
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfz(1, 1);
    initialized = 1;
}

int dajN()
{
    if (!initialized)
        initialize();
    return xyz;
}

std::vector<std::pair<int, int>> dajKraw()
{
    if (!initialized)
        initialize();
    return kraw;
}

int pytaj(int x) {
   ++cnt;
    if (!initialized)
        initialize();
    if (x == e) return -1;
    int a = x, b = e;
    if (dep[a] > dep[b]) std::swap(a, b);
    std::vector<int> path_a{a}, path_b{b};
    while (dep[a] < dep[b]) {
        b = par[b];
        path_b.push_back(b);
    }
    while (a != b) {
        a = par[a], b = par[b];
        path_a.push_back(a), path_b.push_back(b);
    }
    path_a.pop_back();
    for (auto i : path_b)
        path_a.push_back(i);
    int ret = -1;
    do {
        ret = path_a[gen() % path_a.size()];
    } while (ret == x);
    return ret;
}

void odpowiedz(int wynik)
{
   if (!initialized) initialize();
   if (wynik == e) {
      if (cnt <= 12) printf("gites\n");
      else printf("za duzo zapytan %d\n", cnt);
   } else printf("zły wynik\n");
}
