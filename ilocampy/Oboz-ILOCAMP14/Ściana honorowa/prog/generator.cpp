#include "generator.h"

#include <memory>
#include <map>
#include <set>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

int random(int a, int b);

Test s1() {
        Test test;
        test.addLine(3, 4, 3);
        test.addLine(2, 2, 1);
        test.addLine(1, 2, 0);
        test.addLine(2, 3, 1);
        return test;
}

Test s2() {
        Test test;
        test.addLine(5, 5, 4);
        test.addLine(1, 1, 0);
        test.addLine(1, 2, 0);
        test.addLine(2, 1, 0);
        test.addLine(2, 2, 0);
        return test;
}

Test s3() {
        Test test;
        test.addLine(5, 5, 4);
        test.addLine(1, 1, 0);
        test.addLine(1, 2, 0);
        test.addLine(2, 1, 0);
        test.addLine(2, 2, 1);
        return test;
}

Test s4() {
        Test test;
        test.addLine(5, 5, 4);
        test.addLine(1, 1, 0);
        test.addLine(1, 5, 0);
        test.addLine(5, 1, 0);
        test.addLine(5, 5, 0);
        return test;
}

Test s5() {
        Test test;
        test.addLine(5, 5, 4);
        test.addLine(1, 1, 0);
        test.addLine(1, 5, 0);
        test.addLine(5, 1, 0);
        test.addLine(5, 5, 1);
        return test;
}

Test s6() {
        Test test;
        test.addLine(5, 5, 4);
        test.addLine(1, 1, 0);
        test.addLine(1, 5, 1);
        test.addLine(5, 1, 0);
        test.addLine(5, 5, 0);
        return test;
}

Test s7() {
        Test test;
        test.addLine(4, 4, 7);
        test.addLine(1, 1, 0);
        test.addLine(1, 2, 0);
        test.addLine(1, 3, 0);
        test.addLine(1, 4, 0);
        test.addLine(2, 1, 0);
        test.addLine(3, 1, 0);
        test.addLine(4, 1, 0);
        return test;
}

Test s8() {
        Test test;
        test.addLine(5, 5, 0);
        return test;
}

Test s9() {
        Test test;
        test.addLine(5, 4, 3);
        test.addLine(4, 3, 1);
        test.addLine(2, 1, 0);
        test.addLine(5, 3, 1);
        return test;
}

Test s10() {
        Test test;
        test.addLine(5, 5, 5);
        test.addLine(3, 1, 0);
        test.addLine(5, 5, 0);
        test.addLine(5, 2, 0);
        test.addLine(3, 4, 0);
        test.addLine(1, 2, 0);
        return test;
}

Test s11() {
        Test test;
        test.addLine(1, 1, 0);
        return test;
}

Test s12() {
        Test test;
        test.addLine(1, 1, 1);
        test.addLine(1, 1, 1);
        return test;
}

Test s13() {
        Test test;
        test.addLine(2, 1, 0);
        return test;
}

Test s14() {
        Test test;
        test.addLine(1, 3, 2);
        test.addLine(1, 2, 0);
        test.addLine(1, 1, 0);
        return test;
}

Test s15() {
        Test test;
        test.addLine(2, 2, 0);
        return test;
}

Test s16() {
        Test test;
        test.addLine(2, 2, 1);
        test.addLine(1, 1, 0);
        return test;
}

Test s17() {
        Test test;
        test.addLine(2, 2, 2);
        test.addLine(2, 2, 0);
        test.addLine(1, 1, 1);
        return test;
}

Test s18() {
        Test test;
        test.addLine(2, 2, 3);
        test.addLine(1, 1, 0);
        test.addLine(1, 2, 1);
        test.addLine(2, 2, 1);
        return test;
}

Test s19() {
        Test test;
        test.addLine(2, 2, 4);
        test.addLine(1, 2, 0);
        test.addLine(2, 2, 0);
        test.addLine(1, 1, 0);
        test.addLine(2, 1, 1);
        return test;
}

Test s20() {
        Test test;
        test.addLine(3, 2, 3);
        test.addLine(3, 1, 0);
        test.addLine(1, 2, 1);
        test.addLine(2, 1, 1);
        return test;
}

Test s21() {
        Test test;
        test.addLine(3, 3, 5);
        test.addLine(2, 1, 0);
        test.addLine(2, 3, 1);
        test.addLine(3, 3, 0);
        test.addLine(1, 1, 0);
        test.addLine(1, 3, 1);
        return test;
}

Test s22() {
        Test test;
        test.addLine(3, 3, 6);
        test.addLine(2, 2, 0);
        test.addLine(2, 3, 0);
        test.addLine(3, 1, 1);
        test.addLine(3, 3, 1);
        test.addLine(1, 3, 0);
        test.addLine(1, 1, 0);
        return test;
}

Test s23() {
        Test test;
        test.addLine(3, 3, 7);
        test.addLine(3, 1, 0);
        test.addLine(1, 2, 1);
        test.addLine(2, 1, 1);
        test.addLine(3, 3, 1);
        test.addLine(2, 3, 0);
        test.addLine(3, 2, 0);
        test.addLine(1, 1, 1);
        return test;
}

Test s24() {
        Test test;
        test.addLine(4, 2, 3);
        test.addLine(3, 1, 0);
        test.addLine(3, 2, 1);
        test.addLine(2, 2, 0);
        return test;
}

Test s25() {
        Test test;
        test.addLine(4, 2, 5);
        test.addLine(4, 2, 0);
        test.addLine(1, 1, 0);
        test.addLine(4, 1, 0);
        test.addLine(1, 2, 1);
        test.addLine(2, 1, 0);
        return test;
}

Test s26() {
        Test test;
        test.addLine(3, 5, 0);
        return test;
}

Test s27() {
        Test test;
        test.addLine(3, 5, 7);
        test.addLine(3, 3, 0);
        test.addLine(3, 4, 0);
        test.addLine(1, 2, 0);
        test.addLine(3, 5, 1);
        test.addLine(1, 3, 1);
        test.addLine(3, 2, 1);
        test.addLine(1, 5, 0);
        return test;
}

Test s28() {
        Test test;
        test.addLine(3, 6, 8);
        test.addLine(3, 4, 0);
        test.addLine(1, 6, 1);
        test.addLine(3, 1, 1);
        test.addLine(3, 3, 0);
        test.addLine(3, 6, 0);
        test.addLine(1, 5, 1);
        test.addLine(1, 1, 0);
        test.addLine(3, 5, 1);
        return test;
}

Test s29() {
        Test test;
        test.addLine(4, 5, 9);
        test.addLine(1, 5, 1);
        test.addLine(3, 5, 0);
        test.addLine(1, 3, 1);
        test.addLine(1, 4, 0);
        test.addLine(3, 4, 1);
        test.addLine(4, 5, 1);
        test.addLine(4, 4, 1);
        test.addLine(3, 1, 0);
        test.addLine(4, 1, 1);
        return test;
}

Test s30() {
        Test test;
        test.addLine(6, 7, 10);
        test.addLine(4, 7, 1);
        test.addLine(4, 2, 1);
        test.addLine(5, 7, 0);
        test.addLine(6, 1, 1);
        test.addLine(6, 2, 1);
        test.addLine(1, 7, 1);
        test.addLine(4, 6, 1);
        test.addLine(2, 6, 0);
        test.addLine(6, 6, 0);
        test.addLine(5, 6, 0);
        return test;
}

Test s31() {
        Test test;
        test.addLine(7, 6, 15);
        test.addLine(4, 1, 1);
        test.addLine(4, 5, 1);
        test.addLine(3, 4, 0);
        test.addLine(7, 1, 0);
        test.addLine(3, 2, 0);
        test.addLine(6, 4, 1);
        test.addLine(3, 1, 0);
        test.addLine(6, 5, 0);
        test.addLine(2, 2, 0);
        test.addLine(4, 4, 0);
        test.addLine(6, 1, 0);
        test.addLine(4, 2, 0);
        test.addLine(2, 1, 1);
        test.addLine(6, 2, 1);
        test.addLine(2, 5, 1);
        return test;
}

Test s32() {
        Test test;
        test.addLine(8, 5, 33);
        test.addLine(2, 5, 0);
        test.addLine(6, 2, 0);
        test.addLine(3, 5, 1);
        test.addLine(2, 1, 0);
        test.addLine(6, 5, 0);
        test.addLine(1, 1, 1);
        test.addLine(6, 1, 1);
        test.addLine(5, 1, 1);
        test.addLine(6, 4, 1);
        test.addLine(5, 2, 1);
        test.addLine(8, 2, 0);
        test.addLine(1, 2, 0);
        test.addLine(4, 4, 0);
        test.addLine(7, 5, 0);
        test.addLine(6, 3, 0);
        test.addLine(1, 3, 1);
        test.addLine(5, 5, 0);
        test.addLine(2, 4, 0);
        test.addLine(3, 2, 0);
        test.addLine(7, 2, 0);
        test.addLine(5, 3, 1);
        test.addLine(3, 3, 0);
        test.addLine(1, 5, 1);
        test.addLine(8, 4, 0);
        test.addLine(7, 1, 0);
        test.addLine(3, 1, 0);
        test.addLine(8, 5, 0);
        test.addLine(8, 3, 0);
        test.addLine(3, 4, 1);
        test.addLine(1, 4, 1);
        test.addLine(7, 3, 0);
        test.addLine(4, 5, 1);
        test.addLine(4, 2, 1);
        return test;
}

Test s33() {
        Test test;
        test.addLine(5, 8, 34);
        test.addLine(1, 8, 1);
        test.addLine(4, 3, 0);
        test.addLine(3, 4, 0);
        test.addLine(1, 4, 0);
        test.addLine(4, 8, 1);
        test.addLine(4, 5, 0);
        test.addLine(5, 2, 0);
        test.addLine(5, 8, 0);
        test.addLine(2, 7, 1);
        test.addLine(2, 2, 1);
        test.addLine(4, 6, 0);
        test.addLine(1, 7, 0);
        test.addLine(1, 6, 0);
        test.addLine(3, 7, 0);
        test.addLine(1, 5, 1);
        test.addLine(1, 1, 0);
        test.addLine(2, 5, 0);
        test.addLine(1, 3, 1);
        test.addLine(3, 2, 1);
        test.addLine(5, 5, 0);
        test.addLine(4, 2, 1);
        test.addLine(4, 1, 1);
        test.addLine(4, 4, 0);
        test.addLine(3, 6, 0);
        test.addLine(2, 1, 1);
        test.addLine(5, 7, 1);
        test.addLine(5, 4, 1);
        test.addLine(5, 3, 0);
        test.addLine(3, 3, 1);
        test.addLine(5, 6, 1);
        test.addLine(2, 3, 0);
        test.addLine(3, 1, 0);
        test.addLine(4, 7, 1);
        test.addLine(1, 2, 1);
        return test;
}

Test s34() {
        Test test;
        test.addLine(7, 7, 22);
        test.addLine(5, 6, 0);
        test.addLine(5, 2, 0);
        test.addLine(3, 5, 0);
        test.addLine(1, 5, 1);
        test.addLine(1, 7, 0);
        test.addLine(3, 2, 1);
        test.addLine(4, 5, 0);
        test.addLine(6, 4, 1);
        test.addLine(5, 4, 1);
        test.addLine(1, 6, 1);
        test.addLine(1, 3, 0);
        test.addLine(6, 2, 1);
        test.addLine(1, 2, 1);
        test.addLine(3, 7, 1);
        test.addLine(7, 2, 0);
        test.addLine(6, 7, 1);
        test.addLine(7, 4, 1);
        test.addLine(7, 6, 0);
        test.addLine(7, 3, 0);
        test.addLine(7, 7, 1);
        test.addLine(5, 5, 1);
        test.addLine(7, 5, 0);
        return test;
}

Test s35() {
        Test test;
        test.addLine(9, 8, 40);
        test.addLine(7, 7, 0);
        test.addLine(8, 3, 1);
        test.addLine(6, 2, 0);
        test.addLine(6, 7, 0);
        test.addLine(8, 2, 0);
        test.addLine(9, 3, 0);
        test.addLine(8, 1, 0);
        test.addLine(4, 2, 0);
        test.addLine(9, 1, 1);
        test.addLine(2, 3, 0);
        test.addLine(4, 1, 0);
        test.addLine(4, 6, 1);
        test.addLine(7, 2, 1);
        test.addLine(5, 6, 1);
        test.addLine(2, 1, 1);
        test.addLine(8, 7, 0);
        test.addLine(1, 2, 1);
        test.addLine(7, 5, 1);
        test.addLine(2, 5, 0);
        test.addLine(2, 2, 1);
        test.addLine(6, 6, 1);
        test.addLine(4, 8, 1);
        test.addLine(8, 6, 1);
        test.addLine(7, 1, 0);
        test.addLine(5, 7, 1);
        test.addLine(1, 3, 1);
        test.addLine(4, 5, 1);
        test.addLine(1, 1, 0);
        test.addLine(1, 8, 0);
        test.addLine(2, 7, 1);
        test.addLine(4, 7, 0);
        test.addLine(6, 1, 0);
        test.addLine(4, 3, 1);
        test.addLine(1, 5, 1);
        test.addLine(6, 5, 1);
        test.addLine(7, 6, 0);
        test.addLine(7, 8, 0);
        test.addLine(1, 6, 0);
        test.addLine(6, 3, 1);
        test.addLine(9, 7, 1);
        return test;
}

Test s36() {
        Test test;
        test.addLine(8, 9, 39);
        test.addLine(2, 7, 1);
        test.addLine(6, 2, 0);
        test.addLine(1, 3, 0);
        test.addLine(4, 7, 0);
        test.addLine(5, 6, 1);
        test.addLine(3, 7, 0);
        test.addLine(8, 7, 1);
        test.addLine(7, 5, 0);
        test.addLine(2, 1, 0);
        test.addLine(3, 1, 0);
        test.addLine(1, 6, 0);
        test.addLine(5, 7, 1);
        test.addLine(5, 4, 1);
        test.addLine(6, 8, 0);
        test.addLine(6, 6, 0);
        test.addLine(6, 1, 0);
        test.addLine(2, 3, 0);
        test.addLine(3, 6, 1);
        test.addLine(2, 2, 1);
        test.addLine(7, 2, 1);
        test.addLine(4, 5, 0);
        test.addLine(4, 6, 1);
        test.addLine(8, 1, 0);
        test.addLine(6, 4, 0);
        test.addLine(7, 4, 1);
        test.addLine(4, 8, 1);
        test.addLine(8, 5, 0);
        test.addLine(5, 2, 0);
        test.addLine(7, 3, 0);
        test.addLine(8, 3, 1);
        test.addLine(3, 5, 1);
        test.addLine(8, 4, 0);
        test.addLine(7, 1, 1);
        test.addLine(6, 5, 1);
        test.addLine(4, 3, 0);
        test.addLine(2, 5, 1);
        test.addLine(2, 4, 1);
        test.addLine(5, 5, 1);
        test.addLine(1, 4, 0);
        return test;
}

Test s37() {
        Test test;
        test.addLine(9, 9, 25);
        test.addLine(4, 4, 1);
        test.addLine(9, 5, 0);
        test.addLine(7, 6, 1);
        test.addLine(5, 8, 1);
        test.addLine(7, 2, 0);
        test.addLine(9, 1, 1);
        test.addLine(9, 4, 1);
        test.addLine(3, 8, 0);
        test.addLine(2, 2, 1);
        test.addLine(8, 5, 0);
        test.addLine(4, 7, 1);
        test.addLine(7, 5, 1);
        test.addLine(8, 9, 1);
        test.addLine(5, 4, 1);
        test.addLine(1, 4, 1);
        test.addLine(7, 1, 0);
        test.addLine(1, 1, 1);
        test.addLine(1, 9, 1);
        test.addLine(9, 7, 0);
        test.addLine(8, 4, 0);
        test.addLine(9, 8, 1);
        test.addLine(1, 8, 1);
        test.addLine(4, 5, 1);
        test.addLine(3, 9, 0);
        test.addLine(2, 5, 1);
        return test;
}

Test s38() {
        Test test;
        test.addLine(10, 3, 18);
        test.addLine(4, 3, 0);
        test.addLine(7, 3, 0);
        test.addLine(3, 3, 1);
        test.addLine(9, 1, 1);
        test.addLine(8, 3, 0);
        test.addLine(9, 2, 1);
        test.addLine(8, 2, 0);
        test.addLine(6, 1, 0);
        test.addLine(6, 3, 0);
        test.addLine(10, 1, 1);
        test.addLine(9, 3, 0);
        test.addLine(1, 3, 0);
        test.addLine(4, 2, 1);
        test.addLine(10, 3, 1);
        test.addLine(7, 1, 1);
        test.addLine(6, 2, 1);
        test.addLine(3, 1, 0);
        test.addLine(4, 1, 1);
        return test;
}

Test s39() {
        Test test;
        test.addLine(4, 10, 20);
        test.addLine(3, 10, 1);
        test.addLine(2, 9, 0);
        test.addLine(2, 4, 1);
        test.addLine(3, 4, 1);
        test.addLine(2, 10, 1);
        test.addLine(1, 7, 0);
        test.addLine(2, 5, 0);
        test.addLine(3, 7, 0);
        test.addLine(1, 8, 1);
        test.addLine(3, 1, 0);
        test.addLine(2, 7, 1);
        test.addLine(1, 5, 1);
        test.addLine(3, 2, 0);
        test.addLine(3, 9, 1);
        test.addLine(2, 6, 0);
        test.addLine(2, 2, 0);
        test.addLine(1, 10, 1);
        test.addLine(1, 2, 0);
        test.addLine(1, 4, 1);
        test.addLine(3, 6, 0);
        return test;
}

Test s40() {
        Test test;
        test.addLine(5, 9, 25);
        test.addLine(5, 9, 0);
        test.addLine(5, 7, 0);
        test.addLine(5, 3, 0);
        test.addLine(5, 4, 1);
        test.addLine(5, 2, 1);
        test.addLine(4, 2, 1);
        test.addLine(5, 1, 1);
        test.addLine(3, 1, 1);
        test.addLine(4, 4, 1);
        test.addLine(3, 5, 0);
        test.addLine(1, 3, 0);
        test.addLine(1, 9, 0);
        test.addLine(3, 6, 0);
        test.addLine(4, 6, 1);
        test.addLine(4, 9, 0);
        test.addLine(4, 5, 0);
        test.addLine(1, 2, 0);
        test.addLine(3, 4, 1);
        test.addLine(4, 1, 0);
        test.addLine(1, 6, 1);
        test.addLine(3, 7, 1);
        test.addLine(5, 6, 0);
        test.addLine(3, 9, 0);
        test.addLine(3, 2, 1);
        test.addLine(1, 4, 0);
        return test;
}

Test s41() {
        Test test;
        test.addLine(7, 10, 24);
        test.addLine(4, 7, 1);
        test.addLine(4, 9, 0);
        test.addLine(1, 2, 0);
        test.addLine(7, 4, 1);
        test.addLine(3, 4, 0);
        test.addLine(7, 6, 0);
        test.addLine(3, 10, 0);
        test.addLine(3, 8, 0);
        test.addLine(1, 4, 1);
        test.addLine(4, 8, 0);
        test.addLine(2, 9, 1);
        test.addLine(7, 5, 1);
        test.addLine(6, 1, 0);
        test.addLine(2, 3, 0);
        test.addLine(7, 7, 1);
        test.addLine(5, 7, 0);
        test.addLine(2, 6, 0);
        test.addLine(1, 7, 1);
        test.addLine(3, 5, 0);
        test.addLine(5, 3, 0);
        test.addLine(2, 10, 1);
        test.addLine(4, 6, 1);
        test.addLine(7, 9, 0);
        test.addLine(1, 9, 0);
        return test;
}

Test s42() {
        Test test;
        test.addLine(8, 9, 0);
        return test;
}

Test s43() {
        Test test;
        test.addLine(9, 10, 0);
        return test;
}

Test s44() {
        Test test;
        test.addLine(9, 10, 10);
        test.addLine(5, 7, 1);
        test.addLine(7, 1, 0);
        test.addLine(7, 5, 1);
        test.addLine(5, 9, 0);
        test.addLine(6, 6, 1);
        test.addLine(7, 2, 1);
        test.addLine(1, 4, 1);
        test.addLine(4, 3, 1);
        test.addLine(5, 5, 1);
        test.addLine(1, 6, 1);
        return test;
}

Test s45() {
        Test test;
        test.addLine(10, 8, 20);
        test.addLine(7, 4, 0);
        test.addLine(5, 4, 0);
        test.addLine(9, 4, 0);
        test.addLine(1, 3, 1);
        test.addLine(4, 2, 0);
        test.addLine(6, 6, 0);
        test.addLine(7, 6, 0);
        test.addLine(10, 2, 1);
        test.addLine(1, 4, 1);
        test.addLine(6, 4, 1);
        test.addLine(6, 2, 1);
        test.addLine(7, 3, 1);
        test.addLine(2, 3, 1);
        test.addLine(1, 7, 0);
        test.addLine(1, 2, 1);
        test.addLine(6, 7, 1);
        test.addLine(9, 3, 0);
        test.addLine(10, 3, 1);
        test.addLine(10, 7, 1);
        test.addLine(10, 6, 0);
        return test;
}

Test s46() {
        Test test;
        test.addLine(10, 10, 0);
        return test;
}

Test s47() {
        Test test;
        test.addLine(10, 10, 1);
        test.addLine(6, 1, 1);
        return test;
}

Test s48() {
        Test test;
        test.addLine(10, 10, 10);
        test.addLine(4, 9, 0);
        test.addLine(5, 6, 1);
        test.addLine(2, 3, 0);
        test.addLine(10, 3, 0);
        test.addLine(3, 2, 1);
        test.addLine(5, 1, 1);
        test.addLine(4, 3, 0);
        test.addLine(4, 6, 0);
        test.addLine(5, 2, 1);
        test.addLine(10, 6, 0);
        return test;
}

Test s49() {
        Test test;
        test.addLine(10, 10, 19);
        test.addLine(10, 7, 1);
        test.addLine(5, 8, 1);
        test.addLine(8, 9, 0);
        test.addLine(5, 7, 1);
        test.addLine(5, 9, 0);
        test.addLine(10, 1, 0);
        test.addLine(9, 7, 1);
        test.addLine(5, 5, 1);
        test.addLine(10, 9, 0);
        test.addLine(8, 8, 0);
        test.addLine(10, 2, 1);
        test.addLine(9, 2, 0);
        test.addLine(10, 5, 1);
        test.addLine(4, 9, 1);
        test.addLine(9, 9, 0);
        test.addLine(3, 8, 0);
        test.addLine(3, 9, 1);
        test.addLine(8, 2, 1);
        test.addLine(4, 1, 1);
        return test;
}

Test s50() {
        Test test;
        test.addLine(10, 10, 40);
        test.addLine(9, 1, 0);
        test.addLine(8, 9, 0);
        test.addLine(6, 8, 0);
        test.addLine(5, 5, 1);
        test.addLine(5, 9, 1);
        test.addLine(9, 5, 1);
        test.addLine(4, 5, 1);
        test.addLine(10, 9, 1);
        test.addLine(4, 8, 1);
        test.addLine(5, 1, 1);
        test.addLine(9, 4, 0);
        test.addLine(2, 5, 0);
        test.addLine(4, 2, 0);
        test.addLine(8, 10, 0);
        test.addLine(10, 1, 1);
        test.addLine(4, 9, 0);
        test.addLine(7, 4, 0);
        test.addLine(5, 10, 0);
        test.addLine(4, 4, 1);
        test.addLine(7, 9, 1);
        test.addLine(6, 1, 0);
        test.addLine(7, 2, 1);
        test.addLine(2, 10, 1);
        test.addLine(4, 7, 0);
        test.addLine(6, 5, 1);
        test.addLine(6, 4, 0);
        test.addLine(10, 7, 0);
        test.addLine(9, 7, 0);
        test.addLine(7, 1, 1);
        test.addLine(9, 8, 0);
        test.addLine(8, 7, 1);
        test.addLine(2, 1, 1);
        test.addLine(6, 7, 0);
        test.addLine(2, 4, 0);
        test.addLine(2, 2, 1);
        test.addLine(9, 2, 0);
        test.addLine(8, 5, 0);
        test.addLine(10, 10, 1);
        test.addLine(10, 5, 1);
        test.addLine(6, 10, 0);
        return test;
}

Test s51() {
        Test test;
        test.addLine(10, 10, 42);
        test.addLine(6, 8, 0);
        test.addLine(2, 4, 1);
        test.addLine(1, 3, 0);
        test.addLine(4, 4, 1);
        test.addLine(3, 4, 1);
        test.addLine(4, 9, 1);
        test.addLine(3, 8, 0);
        test.addLine(8, 5, 1);
        test.addLine(4, 7, 1);
        test.addLine(6, 2, 1);
        test.addLine(10, 8, 1);
        test.addLine(7, 3, 0);
        test.addLine(6, 5, 1);
        test.addLine(6, 9, 1);
        test.addLine(4, 5, 1);
        test.addLine(10, 5, 0);
        test.addLine(1, 9, 1);
        test.addLine(2, 9, 1);
        test.addLine(2, 2, 1);
        test.addLine(8, 8, 0);
        test.addLine(7, 7, 1);
        test.addLine(8, 2, 1);
        test.addLine(5, 8, 0);
        test.addLine(2, 7, 1);
        test.addLine(5, 7, 0);
        test.addLine(3, 7, 0);
        test.addLine(3, 9, 0);
        test.addLine(4, 2, 1);
        test.addLine(4, 3, 0);
        test.addLine(10, 7, 0);
        test.addLine(8, 7, 1);
        test.addLine(6, 3, 0);
        test.addLine(10, 9, 0);
        test.addLine(2, 8, 0);
        test.addLine(6, 7, 1);
        test.addLine(10, 4, 0);
        test.addLine(1, 2, 0);
        test.addLine(3, 2, 1);
        test.addLine(8, 9, 1);
        test.addLine(4, 8, 0);
        test.addLine(1, 4, 0);
        test.addLine(7, 9, 1);
        return test;
}

Test s52() {
        Test test;
        test.addLine(10, 10, 57);
        test.addLine(6, 4, 0);
        test.addLine(2, 5, 0);
        test.addLine(5, 10, 0);
        test.addLine(3, 3, 1);
        test.addLine(5, 4, 1);
        test.addLine(1, 8, 0);
        test.addLine(3, 2, 0);
        test.addLine(6, 9, 0);
        test.addLine(10, 5, 0);
        test.addLine(5, 3, 1);
        test.addLine(10, 3, 1);
        test.addLine(7, 5, 1);
        test.addLine(6, 6, 0);
        test.addLine(2, 10, 1);
        test.addLine(4, 4, 1);
        test.addLine(7, 3, 0);
        test.addLine(10, 10, 1);
        test.addLine(10, 8, 1);
        test.addLine(1, 3, 1);
        test.addLine(1, 9, 0);
        test.addLine(2, 7, 0);
        test.addLine(7, 10, 1);
        test.addLine(4, 10, 0);
        test.addLine(4, 2, 0);
        test.addLine(4, 9, 1);
        test.addLine(10, 9, 0);
        test.addLine(5, 7, 0);
        test.addLine(6, 3, 1);
        test.addLine(3, 7, 0);
        test.addLine(5, 8, 0);
        test.addLine(10, 6, 0);
        test.addLine(6, 5, 0);
        test.addLine(3, 6, 1);
        test.addLine(4, 3, 0);
        test.addLine(4, 5, 1);
        test.addLine(5, 2, 0);
        test.addLine(1, 4, 1);
        test.addLine(3, 9, 0);
        test.addLine(1, 2, 0);
        test.addLine(7, 7, 1);
        test.addLine(5, 9, 0);
        test.addLine(7, 8, 1);
        test.addLine(2, 6, 0);
        test.addLine(7, 6, 0);
        test.addLine(10, 2, 1);
        test.addLine(10, 4, 0);
        test.addLine(5, 5, 0);
        test.addLine(10, 7, 0);
        test.addLine(3, 5, 0);
        test.addLine(7, 9, 1);
        test.addLine(2, 2, 1);
        test.addLine(2, 9, 0);
        test.addLine(6, 8, 1);
        test.addLine(6, 2, 1);
        test.addLine(2, 4, 0);
        test.addLine(6, 10, 1);
        test.addLine(3, 8, 0);
        return test;
}

Test s53() {
        Test test;
        test.addLine(10, 15, 5);
        test.addLine(3, 2, 0);
        test.addLine(1, 1, 0);
        test.addLine(2, 1, 1);
        test.addLine(1, 2, 0);
        test.addLine(3, 1, 1);
        return test;
}

Test s54() {
        Test test;
        test.addLine(100, 100, 15);
        test.addLine(76, 3, 1);
        test.addLine(16, 5, 0);
        test.addLine(2, 55, 0);
        test.addLine(56, 92, 0);
        test.addLine(74, 96, 0);
        test.addLine(56, 33, 0);
        test.addLine(57, 52, 0);
        test.addLine(89, 66, 1);
        test.addLine(30, 33, 1);
        test.addLine(86, 94, 1);
        test.addLine(24, 60, 0);
        test.addLine(64, 89, 0);
        test.addLine(99, 92, 0);
        test.addLine(81, 49, 1);
        test.addLine(73, 31, 1);
        return test;
}

Test s55() {
        Test test;
        test.addLine(100, 100, 15);
        test.addLine(54, 32, 1);
        test.addLine(45, 13, 0);
        test.addLine(47, 57, 1);
        test.addLine(66, 62, 1);
        test.addLine(100, 89, 1);
        test.addLine(41, 86, 0);
        test.addLine(86, 89, 0);
        test.addLine(89, 99, 0);
        test.addLine(46, 74, 1);
        test.addLine(23, 21, 0);
        test.addLine(18, 28, 0);
        test.addLine(19, 85, 1);
        test.addLine(56, 28, 0);
        test.addLine(5, 19, 0);
        test.addLine(7, 17, 1);
        return test;
}

Test s56() {
        Test test;
        test.addLine(10, 50, 25);
        test.addLine(1, 28, 1);
        test.addLine(9, 8, 1);
        test.addLine(3, 40, 1);
        test.addLine(4, 19, 1);
        test.addLine(10, 24, 0);
        test.addLine(5, 33, 0);
        test.addLine(7, 50, 1);
        test.addLine(10, 49, 1);
        test.addLine(2, 39, 1);
        test.addLine(2, 42, 0);
        test.addLine(2, 14, 0);
        test.addLine(6, 4, 1);
        test.addLine(6, 6, 0);
        test.addLine(1, 29, 0);
        test.addLine(2, 8, 0);
        test.addLine(3, 25, 1);
        test.addLine(7, 8, 0);
        test.addLine(8, 49, 0);
        test.addLine(8, 43, 1);
        test.addLine(9, 5, 0);
        test.addLine(3, 14, 1);
        test.addLine(7, 5, 1);
        test.addLine(1, 25, 0);
        test.addLine(6, 43, 1);
        test.addLine(9, 19, 0);
        return test;
}

Test s57() {
        Test test;
        test.addLine(15, 35, 25);
        test.addLine(6, 5, 1);
        test.addLine(4, 7, 1);
        test.addLine(1, 12, 0);
        test.addLine(5, 14, 0);
        test.addLine(12, 7, 1);
        test.addLine(9, 17, 0);
        test.addLine(3, 9, 0);
        test.addLine(8, 1, 0);
        test.addLine(14, 34, 1);
        test.addLine(7, 22, 1);
        test.addLine(11, 9, 1);
        test.addLine(10, 20, 1);
        test.addLine(3, 7, 1);
        test.addLine(10, 31, 0);
        test.addLine(10, 7, 0);
        test.addLine(12, 20, 0);
        test.addLine(11, 27, 0);
        test.addLine(4, 35, 0);
        test.addLine(7, 6, 1);
        test.addLine(4, 26, 0);
        test.addLine(15, 18, 1);
        test.addLine(11, 25, 0);
        test.addLine(8, 6, 0);
        test.addLine(2, 29, 1);
        test.addLine(1, 33, 1);
        return test;
}

Test s58() {
        Test test;
        test.addLine(5000, 5000, 25);
        test.addLine(10, 1, 0);
        test.addLine(7, 1, 1);
        test.addLine(2, 4, 1);
        test.addLine(7, 14, 0);
        test.addLine(11, 6, 1);
        test.addLine(13, 15, 0);
        test.addLine(8, 1, 0);
        test.addLine(5, 1, 1);
        test.addLine(5, 4, 0);
        test.addLine(4, 14, 0);
        test.addLine(9, 3, 1);
        test.addLine(9, 14, 0);
        test.addLine(9, 2, 0);
        test.addLine(10, 12, 0);
        test.addLine(2, 10, 0);
        test.addLine(2, 13, 1);
        test.addLine(3, 9, 0);
        test.addLine(14, 5, 1);
        test.addLine(13, 9, 0);
        test.addLine(8, 8, 0);
        test.addLine(1, 7, 1);
        test.addLine(1, 9, 1);
        test.addLine(11, 3, 1);
        test.addLine(6, 4, 1);
        test.addLine(9, 13, 0);
        return test;
}

Test s59() {
        Test test;
        test.addLine(100000, 100000, 0);
        return test;
}

Test s60() {
        Test test;
        test.addLine(100000, 100000, 1);
        test.addLine(86543, 82331, 1);
        return test;
}

Test s61() {
        Test test;
        test.addLine(100000, 100000, 4);
        test.addLine(92424, 50624, 0);
        test.addLine(92424, 35889, 1);
        test.addLine(91451, 35889, 0);
        test.addLine(91451, 50624, 1);
        return test;
}

Test s62() {
        Test test;
        test.addLine(100000, 100000, 4);
        test.addLine(22107, 68336, 1);
        test.addLine(60389, 52995, 1);
        test.addLine(60389, 68336, 0);
        test.addLine(22107, 52995, 0);
        return test;
}


Test example() {
    Test test;
    test.addLine(5, 3, 5);
    test.addLine(2, 1, 0);
    test.addLine(5, 1, 1);
    test.addLine(1, 2, 1);
    test.addLine(4, 2, 0);
    test.addLine(3, 3, 0);
    return test;
}

namespace sol {
    const int N = 200005, M = 1e9 + 7;

    int n, m, k, a, b, c, erased, contradiction;
    vector<pair<int, int> > V[N];
    int vis[N];
    bool pref[N], prefX[N], prefY[N];
    bool prefArea[N];

    void DFS(int w, int par, int parX, int parY, bool area, bool weightsSum) {
        if (vis[w]) {
            area ^= parY & (prefX[w] ^ parX);
            if ((weightsSum ^ pref[w]) != (area ^ prefArea[w])) contradiction = true;
            erased++;
            return;
        }
        pref[w] = weightsSum;
        vis[w] = true;
        for (int i = 0; i < V[w].size(); i++) {
            int u = V[w][i].first;
            int weight = V[w][i].second;
            if (u != par && vis[u] != 2) {
                int x, y;
                if (u > n) {
                    x = parX;
                    y = u - n;
                } else {
                    x = u;
                    y = parY;
                }
                x &= 1, y &= 1;
                long long newArea = area;
                if (parX != -1 && parY != -1) {
                    newArea ^= y && (x ^ parX);
                }
                prefArea[w] = newArea;
                prefX[w] = x, prefY[w] = y;
                DFS(u, w, x, y, newArea, weightsSum ^ weight);
            }
        }

        vis[w] = 2;
    }

    int solve(int _n, int _m, int _k, vector<int> &A, vector<int> &B, vector<int> &C) {
        n = _n;
        m = _m;
        k = _k;
        erased = 0;
        contradiction = false;
        for (int i = 1; i <= n + m; i++) {
            V[i].clear();
            vis[i] = false;
            pref[i] = prefX[i] = prefY[i] = prefArea[i] = false;
        }

        for (int i = 0; i < k; i++) {
            int a = A[i];
            int b = B[i];
            int c = C[i];
            b += n;
            V[a].push_back({b, c});
            V[b].push_back({a, c});
        }

        for (int i = 1; i <= n + m; i++) {
            if (vis[i] == false) {
                int x = -1, y = -1;
                if (i > n) {
                    y = i - n;
                } else {
                    x = i;
                }
                DFS(i, -1, x, y, 0, 0);
            }
        }

        if (contradiction) {
            return 0;
        }

        return n + m - 1 - k + erased;
    }
}

Test randomWithAns(int n, int m, int expectedAns) {
    Test test;

    vector<int> A, B, C;
    int ans = sol::solve(n, m, A.size(), A, B, C);
    set<pair<int, int> > bylo;
    while (ans > expectedAns) {
//         if (ans > 114)
//         cerr << "ans = " << ans << endl;
        int x = random(1, n);
        int y = random(1, m);
        while (bylo.find({x, y}) != bylo.end()) {
            x = random(1, n);
            y = random(1, m);
        }
        A.push_back(x);
        B.push_back(y);
        C.push_back(random(0, 1));
        int newAns = sol::solve(n, m, A.size(), A, B, C);
        if (newAns != 0) {
            bylo.insert({x, y});
            ans = newAns;
        } else {
            A.pop_back();
            B.pop_back();
            C.pop_back();
        }
    }

    test.addLine(n, m, A.size());
    for (int i = 0; i < A.size(); i++) {
        test.addLine(A[i], B[i], C[i]);
    }

    return test;
}


Test randomValid(int n, int m, int k) {
    Test test;

    vector<int> col, row;

    for (int i = 1; i <= n; i++) {
        row.push_back(random(0, 1));
    }

    col.push_back(row[0]);
    for (int i = 2; i <= m; i++) {
        col.push_back(random(0, 1));
    }

    map<pair<int, int>, int> bylo;
    for (int i = 1; i <= k; i++) {
        int x = random(1, n);
        int y = random(1, m);
        while (bylo.count({x, y})) {
            x = random(1, n);
            y = random(1, m);
        }
        int area = ((x - 1) % 2) & ((y - 1) % 2);
        test.addLine(x, y, area ^ row[x - 1] ^ row[0] ^ col[y - 1]);
        bylo[{x, y}] = true;
    }

    return test;
}


int main() {
    Generator gen("sci");

    gen.beginGroup();
    gen.addTest(example());
    gen.endGroup();

    gen.beginGroup();
    {
        test.addTest(s1());
        test.addTest(s2());
        test.addTest(s3());
        test.addTest(s4());
        test.addTest(s5());
        test.addTest(s6());
        test.addTest(s7());
        test.addTest(s8());
        test.addTest(s9());
        test.addTest(s10());
        test.addTest(s11());
        test.addTest(s12());
        test.addTest(s13());
        test.addTest(s14());
        test.addTest(s15());
        test.addTest(s16());
        test.addTest(s17());
        test.addTest(s18());
        test.addTest(s19());
        test.addTest(s20());
        Generator::setSeed(1001);
        test.addTest(randomValid(5, 5, 6));
        Generator::setSeed(1002);
        test.addTest(randomWithAns(5, 5, 2));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        test.addTest(s21());
        test.addTest(s22());
        test.addTest(s23());
        test.addTest(s24());
        test.addTest(s25());
        test.addTest(s26());
        test.addTest(s27());
        test.addTest(s28());
        test.addTest(s29());
        test.addTest(s30());
        test.addTest(s31());
        test.addTest(s32());
        test.addTest(s33());
        test.addTest(s34());
        test.addTest(s35());
        test.addTest(s36());
        test.addTest(s37());
        test.addTest(s38());
        test.addTest(s39());
        test.addTest(s40());
        Generator::setSeed(2001);
        test.addTest(randomValid(13, 15, 39));
        Generator::setSeed(2002);
        test.addTest(randomWithAns(15, 16, 10));
        Generator::setSeed(2003);
        test.addTest(randomValid(15, 15, 150));
    }
    gen.endGroup();

    gen.beginGroup();
    {
        test.addTest(s41());
        test.addTest(s42());
        test.addTest(s43());
        test.addTest(s44());
        test.addTest(s45());
        test.addTest(s46());
        test.addTest(s47());
        test.addTest(s48());
        test.addTest(s49());
        test.addTest(s50());
        test.addTest(s51());
        test.addTest(s52());
        test.addTest(s53());
        test.addTest(s54());
        test.addTest(s55());
        test.addTest(s56());
        test.addTest(s57());
        test.addTest(s58());
        test.addTest(s59());
        test.addTest(s60());
        Generator::setSeed(3001);
        test.addTest(randomValid(30, 30, 23));
        Generator::setSeed(3002);
        test.addTest(randomWithAns(30, 30, 10));
    }
    gen.endGroup();


    gen.generate();
}


int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

