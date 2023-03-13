#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

int R(int a, int b);

Test myTest(string s) {
    Test test;
    test.addLine(s.size());
    test.addLine(s);
    return test;
}

Test randomTest(int n, int onechanse = 50) {
    Test test;
    test.addLine(n);
    string s;
    for(int i = 0; i < n ; i++) {
        s += '0' + (R(1, 100) <= onechanse);
    }
    test.addLine(s);
    return test;
}

/*
1000
100000
1000000
10000000
50000000
*/


int main() {
    Generator gen("ski");


    // 1
    gen.beginGroup();
    {
        gen.addTest(myTest("1"));
        gen.addTest(myTest("0000"));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        gen.addTest(myTest("0"));
        gen.addTest(myTest("1111"));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        gen.addTest(randomTest(1000000, 50));
        gen.addTest(randomTest(1000000, 5));
        gen.addTest(randomTest(1000000, 99));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        gen.addTest(randomTest(10000000, 50));
        gen.addTest(randomTest(10000000, 5));
        gen.addTest(randomTest(10000000, 99));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        gen.addTest(randomTest(50000000, 51));
        gen.addTest(randomTest(44563566, 3));
        gen.addTest(randomTest(49234324, 97));
    }
    gen.endGroup();

    gen.generate();
}


int R(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

