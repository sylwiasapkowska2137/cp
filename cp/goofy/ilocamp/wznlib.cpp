#include "wznlib.h"

namespace wznlib
{

int QUERIES = 0;

bool initialized = false;

int n;
std::vector<std::vector<int>> H;
int queries = 0;
int mx, mxi, mxj;

void initialize()
{
    initialized = true;
    std::cin >> n;
    QUERIES = 3 * n + 210;
    H.resize(n);
    mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            std::cin >> a;
            if (a > mx) mx = a, mxi = i + 1, mxj = j + 1;
            H[i].push_back(a);
        }
    }
}

int wezN()
{
    if (!initialized) initialize();
    return n;
}

int kto(int i, int j)
{
    if (!initialized) initialize();
    queries++;
    if (queries > QUERIES) {
        std::cout << "za duzo zapytan\n";
        exit(1);
    }
    if (not(1 <= i and i <= n) or not(1 <= j and j <= n)) {
        std::cout << "niewlasciwe argumenty\n";
        exit(1);
    }
    return H[i - 1][j - 1];
}

void odpowiedz(int i, int j)
{
    if (!initialized) initialize();
    bool ok = (i == mxi && j == mxj);
    std::cout << (ok ? "OK\n" : "zla odpowiedz\n");
    exit(0);
}
}; // namespace wznlib

int wezN()
{
    return wznlib::wezN();
}

int kto(int i, int j)
{
    return wznlib::kto(i, j);
}

void odpowiedz(int i, int j)
{
    wznlib::odpowiedz(i, j);
}
