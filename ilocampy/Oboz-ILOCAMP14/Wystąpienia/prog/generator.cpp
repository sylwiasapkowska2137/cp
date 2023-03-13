#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test exampleTest() {
        Test test;
        test.addLine(5, 4);
        test.addLine(3, 1, 2, 2, 1);
        return test;
}

Test s1() {
        Test test;
        test.addLine(5, 3);
        test.addLine(6, 3, 4, 0, 2);
        return test;
}

Test s2() {
        Test test;
        test.addLine(3, 4);
        test.addLine(5, 5, 5);
        return test;
}

Test s3() {
        Test test;
        test.addLine(10, 15);
        test.addLine(1, 1, 1, 4, 4, 1, 4, 4, 1, 4);
        return test;
}

Test s4() {
        Test test;
        test.addLine(5, 100000);
        test.addLine(0, 5, 5, 4, 3);
        return test;
}

Test s5() {
        Test test;
        test.addLine(1, 0);
        test.addLine(0);
        return test;
}

Test s6() {
        Test test;
        test.addLine(7, 999999990);
        test.addLine(999999999, 999999999, 999999999, 3, 4, 2, 1);
        return test;
}

Test s7() {
        Test test;
        test.addLine(10, 1000000000);
        test.addLine(2, 2, 2, 2, 2, 2, 2, 2, 2, 1000000000);
        return test;
}

Test randomTest(int n, int k, int maxVal) {
    Test test;

    test.addLine(n, k);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(random(1, maxVal));
    }
    test.addLine(v);

    return test;
}

Test s8() {
        Test test;
        test.addLine(1, 268900446);
        test.addLine(999999987);
        return test;
}

Test randomTest2(int n, int k, int maxVal, int p) {
    Test test;

    int w = random(0, maxVal);
    test.addLine(n, k);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int tmp = random(0, p);
        if (tmp == 0) {
            v.push_back(w);
        } else {
            v.push_back(random(1, maxVal));
        }
    }
    test.addLine(v);

    return test;
}


int main() {
    Generator gen("wys");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        gen.addTest(s1());
        gen.addTest(s5());
        gen.addTest(s6());
        gen.addTest(s7());
        gen.addTest(s8());
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        gen.addTest(s2());
        gen.addTest(s3());
        gen.addTest(s4());
        Generator::setSeed(2001);
        gen.addTest(randomTest(10, 4, 5));
    }
    gen.endGroup();


    // 3
    gen.beginGroup();
    {
        Generator::setSeed(3001);
        gen.addTest(randomTest(1000, 10, 5));
        Generator::setSeed(3002);
        gen.addTest(randomTest(1000, 1000, 1000));
        Generator::setSeed(3003);
        gen.addTest(randomTest(1000, 1000, 1000000));
        Generator::setSeed(3004);
        gen.addTest(randomTest(1000, 100, 10000));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        int inf = 1e9;
        Generator::setSeed(4001);
        gen.addTest(randomTest(50000, 9999999, 100000));
        Generator::setSeed(4002);
        gen.addTest(randomTest(50000, inf, inf));
        Generator::setSeed(4003);
        gen.addTest(randomTest2(50000, 10000, inf, 3));
        Generator::setSeed(4004);
        gen.addTest(randomTest2(50000, 1000, 100000, 100));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        int inf = 1e9;
        Generator::setSeed(5001);
        gen.addTest(randomTest(100000, 99, 1000000));
        Generator::setSeed(5002);
        gen.addTest(randomTest(100000, 51365, 1683511));
        Generator::setSeed(5003);
        gen.addTest(randomTest2(100000, 20, inf, 1000));
        Generator::setSeed(5004);
        gen.addTest(randomTest(100000, 1000, 1000000000));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        int inf = 1e9;
        Generator::setSeed(6001);
        gen.addTest(randomTest(5e5, 5412, 1000));
        Generator::setSeed(6002);
        gen.addTest(randomTest(5e5, inf, 41155));
        Generator::setSeed(6003);
        gen.addTest(randomTest2(5e5, 100, 25000, 20));
        Generator::setSeed(6004);
        gen.addTest(randomTest2(5e5, 100, 10000, 100));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        int inf = 1e9;
        Generator::setSeed(7001);
        gen.addTest(randomTest(500000, 1000, 10));
        Generator::setSeed(7002);
        gen.addTest(randomTest(500000, inf, inf));
        Generator::setSeed(7003);
        gen.addTest(randomTest2(500000, 10000, inf, 3));
        Generator::setSeed(7004);
        gen.addTest(randomTest2(500000, 0, 10000, 0));
    }
    gen.endGroup();
    gen.generate();
}
