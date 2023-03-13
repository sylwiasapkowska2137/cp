#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

Test exampleTest();


int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test s1() {
        Test test;
        test.addLine(4);
        test.addLine(1, 1, 0, 0);
        return test;
}

Test s2() {
        Test test;
        test.addLine(4);
        test.addLine(1, 1, 1, 1);
        return test;
}

Test c1() {
        Test test;
        test.addLine(1);
        test.addLine(1);
        return test;
}

Test c2() {
        Test test;
        test.addLine(1);
        test.addLine(0);
        return test;
}

Test s4() {
        Test test;
        test.addLine(2);
        test.addLine(0, 1);
        return test;
}

Test s6() {
        Test test;
        test.addLine(9);
        test.addLine(1, 0, 1, 0, 1, 0, 1, 0, 1);
        return test;
}

Test s7() {
        Test test;
        test.addLine(27);
        test.addLine(0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
        return test;
}

Test s8() {
        Test test;
        test.addLine(10);
        test.addLine(1, 0, 0, 0, 0, 1, 0, 0, 0, 1);
        return test;
}

Test s9() {
        Test test;
        test.addLine(71);
        test.addLine(0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
        return test;
}



Test randomTest(int n, int p) {
    Test test;
    test.addLine(n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x = random(0, abs(p));
        if ((p >= 0 && x == 0) || (p < 0 && x != 0)) {
            v.push_back(1);
        } else {
            v.push_back(0);
        }
    }
    test.addLine(v);
    return test;
}

Test zeros(int n) {
    Test test;
    test.addLine(n);
    vector<int> v;
    for (int i = 0; i < n; i++) {

        v.push_back(0);

    }
    test.addLine(v);
    return test;
}
int main() {
    Generator gen("skr");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        gen.addTest(c1());
        gen.addTest(c2());
        gen.addTest(s1());
        gen.addTest(s2());
        Generator::setSeed(1001);
        gen.addTest(randomTest(10, 1));
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        gen.addTest(s4());
        gen.addTest(s6());
        gen.addTest(s7());
        gen.addTest(s8());
        Generator::setSeed(2001);
        gen.addTest(randomTest(20, 1));
        Generator::setSeed(2002);
        gen.addTest(randomTest(20, -2));
    }
    gen.endGroup();

    //3
    gen.beginGroup();
    {
        gen.addTest(s9());
        Generator::setSeed(3001);
        gen.addTest(randomTest(1000, 1));
        Generator::setSeed(3002);
        gen.addTest(randomTest(1000, -2));
        Generator::setSeed(3003);
        gen.addTest(randomTest(1000, 2));
        Generator::setSeed(3004);
        gen.addTest(randomTest(1000, -3));
    }
    gen.endGroup();


    //4
    gen.beginGroup();
    {
        Generator::setSeed(4001);
        gen.addTest(randomTest(20000, 1));
        Generator::setSeed(4002);
        gen.addTest(randomTest(20000, -2));
        Generator::setSeed(4003);
        gen.addTest(randomTest(20000, 3));
    }
    gen.endGroup();

    //5
    gen.beginGroup();
    {
        Generator::setSeed(5001);
        gen.addTest(randomTest(100000, 1));
        Generator::setSeed(5002);
        gen.addTest(randomTest(100000, -4));
        Generator::setSeed(5003);
        gen.addTest(randomTest(100000, -10));
    }
    gen.endGroup();

    //6
    gen.beginGroup();
    {
        Generator::setSeed(6001);
        gen.addTest(randomTest(1000000, 1));
        Generator::setSeed(6003);
        gen.addTest(randomTest(1000000, 1));
        Generator::setSeed(6004);
        gen.addTest(randomTest(1000000, -3));
    }
    gen.endGroup();

    //7
    gen.beginGroup();
    {
        Generator::setSeed(7001);
        gen.addTest(randomTest(1000000, 1));
        Generator::setSeed(7002);
        gen.addTest(randomTest(1000000, -2));
        Generator::setSeed(7003);
        gen.addTest(randomTest(1000000, 0));
        Generator::setSeed(7004);
        gen.addTest(zeros(1000000));
    }
    gen.endGroup();

    gen.generate();
}

Test exampleTest() {
        Test test;
        test.addLine(5);
        test.addLine(1, 1, 0, 0, 1);
        return test;
}
