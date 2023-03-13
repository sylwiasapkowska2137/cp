#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

int random(int a, int b);

Test example() {
    Test test;
    test.addLine(4);
    return test;
}

Test normalTest(int n) {
    Test test;
    test.addLine(n);
    return test;
}

int main() {
    Generator gen("dna");

    gen.beginGroup();
    gen.addTest(example());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        gen.addTest(normalTest(3));
        gen.addTest(normalTest(1));
        gen.addTest(normalTest(0));
        gen.addTest(normalTest(4));
        gen.addTest(normalTest(2));
        gen.addTest(normalTest(7));
        gen.addTest(normalTest(10));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        gen.addTest(normalTest(5));
        gen.addTest(normalTest(6));
        gen.addTest(normalTest(15));
        gen.addTest(normalTest(20));
        gen.addTest(normalTest(22));
        gen.addTest(normalTest(19));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        gen.addTest(normalTest(8));
        gen.addTest(normalTest(9));
        gen.addTest(normalTest(121));
        gen.addTest(normalTest(345));
        gen.addTest(normalTest(399));
        gen.addTest(normalTest(682));
        gen.addTest(normalTest(999));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        gen.addTest(normalTest(1));
        gen.addTest(normalTest(10123));
        gen.addTest(normalTest(500403));
        gen.addTest(normalTest(999999));
        gen.addTest(normalTest(444321));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        gen.addTest(normalTest(3));
        gen.addTest(normalTest(12345));
        gen.addTest(normalTest(1000000));
        gen.addTest(normalTest(999666));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        gen.addTest(normalTest(666666));
        gen.addTest(normalTest(730281));
        gen.addTest(normalTest(999982));
        gen.addTest(normalTest(200001));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        gen.addTest(normalTest(787675));
        gen.addTest(normalTest(456789));
        gen.addTest(normalTest(321987));
        gen.addTest(normalTest(432981));
    }
    gen.endGroup();

    gen.generate();
}


int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

