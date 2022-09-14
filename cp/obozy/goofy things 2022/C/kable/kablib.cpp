#include "kablib.h"

namespace kablib
{

int QUERIES = 19;

bool initialized = false;

int n, x, y, P1, P2;
int queries = 0;

void initialize()
{
    initialized = true;
    std::cin >> n >> x >> y >> P1 >> P2;
}

std::vector<int> init()
{
    if (!initialized) initialize();
    return std::vector<int>{n, x, y};
}

int wez(std::vector<int> a)
{
    if (!initialized) initialize();
    queries++;
    if (queries > QUERIES) {
        std::cout << "za duzo zapytan\n";
        exit(1);
    }
    int ret = 0;
    for (auto i : a) {
        if (not(1 <= i and i <= n)) {
            std::cout << "niewlasciwe argumenty\n";
            exit(1);
        }
        if (i == P1 or i == P2)
            ret ^= y;
        else
            ret ^= x;
    }
    return ret;
}

void odpowiedz(int p1, int p2)
{
    if (!initialized) initialize();
    bool ok = (p1 == P1 and p2 == P2);
    std::cout << (ok ? "OK\n" : "zla odpowiedz\n");
    exit(0);
}
}; // namespace kablib

std::vector<int> init()
{
    return kablib::init();
}

int wez(std::vector<int> a)
{
    return kablib::wez(a);
}

void odpowiedz(int p1, int p2)
{
    kablib::odpowiedz(p1, p2);
}
