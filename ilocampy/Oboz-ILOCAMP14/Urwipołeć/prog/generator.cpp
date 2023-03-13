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
        test.addLine(5, 2);
        test.addLine(1, 5, 1, 4, 2);
        return test;
}

Test randomTest(int n, int m, int maxValue) {
    Test test;
    test.addLine(n, m);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(random(1, maxValue));
    }
    test.addLine(v);
    return test;
}

Test s1() {
    Test test;
    test.addLine(6, 4);
    test.addLine(1, 1, 2, 2, 3, 3);
    return test;
}

Test s2() {
        Test test;
        test.addLine(7, 3);
        test.addLine(6, 1, 5, 4, 2, 3, 1);
        return test;
}

Test s3() {
        Test test;
        test.addLine(10, 5);
        test.addLine(2, 7, 3, 6, 2, 5, 1, 3, 4, 5);
        return test;
}

Test s4() {
        Test test;
        test.addLine(9, 3);
        test.addLine(9, 5, 2, 3, 7, 1, 8, 4, 6);
        return test;
}

Test s5() {
        Test test;
        test.addLine(20, 10);
        test.addLine(58, 4, 32, 10, 73, 7, 30, 39, 47, 6, 59, 21, 24, 66, 79, 79, 46, 13, 29, 58);
        return test;
}

Test c1() {
        Test test;
        test.addLine(1, 3);
        test.addLine(5);
        return test;
}

Test c2() {
        Test test;
        test.addLine(1, 1);
        test.addLine(1000000000);
        return test;
}

Test c3() {
        Test test;
        test.addLine(2, 3);
        test.addLine(4, 2);
        return test;
}

Test s6() {
        Test test;
        test.addLine(3, 4);
        test.addLine(7, 5, 2);
        return test;
}

Test s7() {
        Test test;
        test.addLine(3, 50);
        test.addLine(47, 86, 51);
        return test;
}

Test s8() {
        Test test;
        test.addLine(2, 2);
        test.addLine(6, 4);
        return test;
}

Test s9() {
        Test test;
        test.addLine(5, 2);
        test.addLine(6, 4, 4, 1, 1);
        return test;
}

Test s10() {
        Test test;
        test.addLine(5, 1);
        test.addLine(5, 1, 1, 1, 1);
        return test;
}

Test maxTest() {
        Test test;

        test.addLine(1000000, 1000 * 1000 * 1000);
        vector<int> v;
        for (int i = 1; i <= 1000000; i++) {
            v.push_back(1000 * 1000 * 1000);
        }
        test.addLine(v);
        return test;
}

Test inc(int n, int m, int maxValue) {
    Test test;
    test.addLine(n, m);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(random(1, maxValue));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    test.addLine(v);
    return test;
}

int main() {
    Generator gen("dzc");

    gen.beginGroup();
    gen.addTest(example());
    gen.endGroup();

    gen.beginGroup();
    {
        gen.addTest(c1());
        gen.addTest(c2());
        gen.addTest(s1());
        gen.addTest(s2());
        gen.addTest(s3());
    }
    gen.endGroup();

    gen.beginGroup();
    {
        gen.addTest(s4());
        gen.addTest(s5());
        gen.addTest(s6());
        gen.addTest(s7());
        gen.addTest(c3());
    }
    gen.endGroup();

    gen.beginGroup();
    {
        gen.addTest(s8());
        gen.addTest(s9());
        gen.addTest(s10());
        Generator::setSeed(301);
        gen.addTest(randomTest(20, 10, 40));
        gen.addTest(inc(20, 10, 40));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        Generator::setSeed(401);
        gen.addTest(randomTest(100, 50, 100));
        Generator::setSeed(402);
        gen.addTest(randomTest(100, 20, 100));
        Generator::setSeed(403);
        gen.addTest(randomTest(100, 100, 100));
        Generator::setSeed(404);
        gen.addTest(randomTest(100, 10, 100));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        Generator::setSeed(501);
        gen.addTest(randomTest(1000, 10000, 100000));
        Generator::setSeed(502);
        gen.addTest(randomTest(1000, 100, 100000));
        Generator::setSeed(503);
        gen.addTest(randomTest(1000, 1000, 100000));
        Generator::setSeed(504);
        gen.addTest(randomTest(1000, 10000, 100000));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        Generator::setSeed(601);
        gen.addTest(randomTest(1000000, 1000000, 1000000000));
        Generator::setSeed(602);
        gen.addTest(randomTest(1000000, 100000, 1000000000));
        Generator::setSeed(603);
        gen.addTest(randomTest(1000000, 10000, 1000000000));
        Generator::setSeed(604);
        gen.addTest(randomTest(1000000, 1000, 1000000000));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        Generator::setSeed(701);
        gen.addTest(randomTest(1000000, 1000000, 1000000000));
        Generator::setSeed(702);
        gen.addTest(inc(1000000, 100000, 1000000000));
        Generator::setSeed(703);
        gen.addTest(maxTest());
    }
    gen.endGroup();

    gen.generate();
}


int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

