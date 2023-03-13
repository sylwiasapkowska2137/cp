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

Test exampleTest() {
        Test test;
        test.addLine(2);
        test.addLine(-1, -100, -1);
        return test;
}

Test randomTest(int n, int maxValue) {
    Test test;
    test.addLine(n);
    vector<int> v;
    for (int i = 1; i <= 2 * n - 1; i++) {
        v.push_back(random(-maxValue, maxValue));
    }
    test.addLine(v);
    return test;
}

Test s1() {
        Test test;
        test.addLine(5);
        test.addLine(0, 0, 0, 0, 0, -1, -1, -1, -1);
        return test;
}

Test s2() {
        Test test;
        test.addLine(4);
        test.addLine(0, 0, 0, 0, 0, -1, -1);
        return test;
}


Test s3() {
        Test test;
        test.addLine(5);
        test.addLine(0, 0, 0, 0, 0, -1, -1, 1, 1);
        return test;
}


Test s4() {
        Test test;
        test.addLine(4);
        test.addLine(0, 0, 0, 0, 0, -1, 1);
        return test;
}

Test s5() {
        Test test;
        test.addLine(2);
        test.addLine(-1, -1, 1);
        return test;
}

Test s6() {
        Test test;
        test.addLine(3);
        test.addLine(-1, 1, 1, 1, 1);
        return test;
}

Test s7() {
        Test test;
        test.addLine(5);
        test.addLine(-1, -1, -1, 2, 2, 2, 2, 2, 2);
        return test;
}

Test s8() {
        Test test;
        test.addLine(3);
        test.addLine(-100, 100, 100, 100, 100);
        return test;
}

Test s9() {
        Test test;
        test.addLine(5);
        test.addLine(-1, -2, -3, -4, -5, -6, -7, 8, 9);
        return test;
}

Test s10() {
        Test test;
        test.addLine(5);
        test.addLine(-1, -1, -1, -1, -1, -1, -1, -1, -1);
        return test;
}

Test s11() {
        Test test;
        test.addLine(3);
        test.addLine(-1, -1, -1, -1, -1);
        return test;
}

Test s12() {
        Test test;
        test.addLine(4);
        test.addLine(-1, -1, -1, 0, 1, 1, 1);
        return test;
}

Test s13() {
        Test test;
        test.addLine(1);
        test.addLine(-1);
        return test;
}



int main() {
    Generator gen("zab");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    gen.beginGroup();
    {
        gen.addTest(s1());
        gen.addTest(s2());
        gen.addTest(s3());
        gen.addTest(s4());
        gen.addTest(s5());
        gen.addTest(s6());
        gen.addTest(s7());
    }
    gen.endGroup();

    gen.beginGroup();
    {
        gen.addTest(s8());
        gen.addTest(s9());
        gen.addTest(s10());
        gen.addTest(s11());
        gen.addTest(s12());
        gen.addTest(s13());
        Generator::setSeed(2001);
        gen.addTest(randomTest(20, 100));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        Generator::setSeed(3001);
        gen.addTest(randomTest(1000, 10));
        Generator::setSeed(3002);
        gen.addTest(randomTest(1000, 100));
        Generator::setSeed(3003);
        gen.addTest(randomTest(1000, 1000));
        Generator::setSeed(3004);
        gen.addTest(randomTest(1000, 1000000000));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        Generator::setSeed(4001);
        gen.addTest(randomTest(20000, 1000));
        Generator::setSeed(4002);
        gen.addTest(randomTest(20000, 100));
        Generator::setSeed(4003);
        gen.addTest(randomTest(20000, 1000));
        Generator::setSeed(4004);
        gen.addTest(randomTest(20000, 100000));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        Generator::setSeed(5001);
        gen.addTest(randomTest(50000, 10000));
        Generator::setSeed(5002);
        gen.addTest(randomTest(50000, 100));
        Generator::setSeed(5003);
        gen.addTest(randomTest(50000, 10));
        Generator::setSeed(5004);
        gen.addTest(randomTest(50000, 10000));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        Generator::setSeed(6001);
        gen.addTest(randomTest(500000, 100));
        Generator::setSeed(6002);
        gen.addTest(randomTest(500000, 10));
        Generator::setSeed(6003);
        gen.addTest(randomTest(500000, 100));
        Generator::setSeed(6004);
        gen.addTest(randomTest(500000, 1000));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        Generator::setSeed(7001);
        gen.addTest(randomTest(500000, 1000000));
        Generator::setSeed(7002);
        gen.addTest(randomTest(500000, 10000));
        Generator::setSeed(7003);
        gen.addTest(randomTest(500000, 100));
        Generator::setSeed(7004);
        gen.addTest(randomTest(500000, 1000000000));
    }
    gen.endGroup();

    gen.generate();
}


int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

