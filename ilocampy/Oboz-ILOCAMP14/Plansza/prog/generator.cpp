#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;


Test example1() {
    Test test;
    test.addLine(5, 5, 11);
    return test;
}

Test example2() {
    Test test;
    test.addLine(10, 15, 25);
    return test;
}

Test small1() {
        Test test;
        test.addLine(0, 5, 1);
        return test;
}

Test s2() {
        Test test;
        test.addLine(-1, -1, 3);
        return test;
}

Test s3() {
        Test test;
        test.addLine(-1, -3, 2);
        return test;
}

Test s4() {
        Test test;
        test.addLine(-2, -2, 2);
        return test;
}

Test s5() {
        Test test;
        test.addLine(0, 0, 1);
        return test;
}

Test s6() {
        Test test;
        test.addLine(0, 1, 7);
        return test;
}

Test s7() {
        Test test;
        test.addLine(1, 2, 7);
        return test;
}

Test s8() {
        Test test;
        test.addLine(0, 5, 6);
        return test;
}

Test s9() {
        Test test;
        test.addLine(0, 4, 2);
        return test;
}

Test s10() {
        Test test;
        test.addLine(-5, 5, 2);
        return test;
}

Test s11() {
        Test test;
        test.addLine(-5, -2, 7);
        return test;
}

Test s12() {
        Test test;
        test.addLine(5, -5, 2);
        return test;
}

Test corner1() {
        Test test;
        test.addLine(0, 0, 2);
        return test;
}

Test large1() {
        Test test;
        test.addLine(999999999, 999999999, 2000000000);
        return test;
}

Test large2() {
        Test test;
        test.addLine(-606037695, 998320124, 820674098);
        return test;
}

Test large3() {
        Test test;
        test.addLine(948253616, -83299062, 1031552680);
        return test;
}

Test large4() {
        Test test;
        test.addLine(711980199, 216568284, 928548487);
        return test;
}

Test large5() {
        Test test;
        test.addLine(-453961301, 271150176, 725111473);
        return test;
}

Test large6() {
        Test test;
        test.addLine(0, 0, 2000000000);
        return test;
}

Test large7() {
        Test test;
        test.addLine(0, 0, 1999999999);
        return test;
}

Test large8() {
        Test test;
        test.addLine(1000000000, 1000000000, 2000000000);
        return test;
}

Test large9() {
        Test test;
        test.addLine(-1000000000, 1000000000, 2000000000);
        return test;
}

Test l10() {
        Test test;
        test.addLine(-1000000000, -1000000000, 2000000000);
        return test;
}

Test l11() {
        Test test;
        test.addLine(-1000000000, -1000000000, 1000000000);
        return test;
}

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test randomTest(int isLarge) {
    Test test;
    if (isLarge) {
        test.addLine(random(-1000000000, 1000000000), random(-1000000000, 1000000000), random(0, 2000000000));
    } else {
        test.addLine(random(-20, 20), random(-20, 20), random(-40, 40));
    }
    return test;
}

int main() {
    Generator gen("pla");

    gen.beginGroup();
    gen.addTest(example1());
    gen.addTest(example2());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        gen.addTest(small1());
        gen.addTest(corner1());
        gen.addTest(s2());
        gen.addTest(s3());
        gen.addTest(s4());
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        gen.addTest(s5());
        gen.addTest(s6());
        gen.addTest(s7());
        gen.addTest(s8());
        gen.addTest(s9());
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        gen.addTest(s10());
        gen.addTest(s11());
        gen.addTest(s12());
        Generator::setSeed(3001);
        gen.addTest(randomTest(0));
        Generator::setSeed(3002);
        gen.addTest(randomTest(0));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        gen.addTest(large1());
        gen.addTest(large2());
        gen.addTest(large3());
        Generator::setSeed(4001);
        gen.addTest(randomTest(1));
        Generator::setSeed(4002);
        gen.addTest(randomTest(1));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        gen.addTest(large4());
        gen.addTest(large5());
        gen.addTest(large6());
        Generator::setSeed(5001);
        gen.addTest(randomTest(1));
        Generator::setSeed(5003);
        gen.addTest(randomTest(1));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        gen.addTest(large7());
        gen.addTest(large8());
        gen.addTest(large9());
        Generator::setSeed(6001);
        gen.addTest(randomTest(1));
//        Generator::setSeed(6003);
//        gen.addTest(randomTest(1));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        gen.addTest(l10());
        gen.addTest(l11());
        Generator::setSeed(7001);
        gen.addTest(randomTest(1));
        Generator::setSeed(7002);
        gen.addTest(randomTest(1));
    }
    gen.endGroup();
    gen.generate();
}
