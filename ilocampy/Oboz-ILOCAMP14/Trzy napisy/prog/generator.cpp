#include "generator.h"

#include <memory>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>
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

Test example1() {
        Test test;
        test.addLine("nap");
        test.addLine("pma");
        return test;
}

Test example2() {
        Test test;
        test.addLine("ilocamo");
        test.addLine("ilocamp");
        return test;
}

Test c1() {
        Test test;
        test.addLine("a");
        test.addLine("c");
        return test;
}

Test c2() {
        Test test;
        test.addLine("q");
        test.addLine("z");
        return test;
}

Test c3() {
        Test test;
        test.addLine("x");
        test.addLine("z");
        return test;
}

Test c4() {
        Test test;
        test.addLine("y");
        test.addLine("z");
        return test;
}


Test c5() {
        Test test;
        test.addLine("a");
        test.addLine("b");
        return test;
}


Test s1() {
        Test test;
        test.addLine("aaa");
        test.addLine("zzz");
        return test;
}


Test s2() {
        Test test;
        test.addLine("abcdefg");
        test.addLine("abcdefh");
        return test;
}

Test s3() {
        Test test;
        test.addLine("abcdefg");
        test.addLine("abcfefg");
        return test;
}

Test s4() {
        Test test;
        test.addLine("vklldrxnfgyorgfpfezvhbouyzzzzz");
        test.addLine("vklldrxnfgyorgfpfezvhbouzaaadv");
        return test;
}

Test s5() {
        Test test;
        test.addLine("pkjlxzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
        test.addLine("pkjlyaaaaaaaaaaaaaaaaaaaaaaaaaaaahr");
        return test;
}

Test s6() {
        Test test;
        test.addLine("uqyugulumzwlxsjnxxkutzqayskrbjoaaekbhckjryhjjllzzz");
        test.addLine("uqyugulumzwlxsjnxxkutzqayskrbjoaaekbhckjryhjjlmaaa");
        return test;
}

Test s7() {
        Test test;
        test.addLine("hceslswecf");
        test.addLine("nmxshuymaa");
        return test;
}

Test s8() {
        Test test;
        test.addLine("az");
        test.addLine("bz");
        return test;
}

Test s9() {
        Test test;
        test.addLine("azzz");
        test.addLine("baac");
        return test;
}

Test randomTest(int n) {
    Test test;

    string s, t;
    do {
        for (int i = 1; i <= n; i++) {
            s += ((char)random(0, 25) + 97);
        }

        for (int i = 1; i <= n; i++) {
            t += ((char)random(0, 25) + 97);
        }
    } while (s == t);
    if (s > t) swap(s, t);

    test.addLine(s);
    test.addLine(t);

    return test;
}

#define pb push_back
Test goodRandomTestNIE(int n) {
    Test test;

    string s, t;
    for (int i = 1; i <= n; i++) {
        s += ((char)random(0, 25) + 97);
    }

    int ind = n - 1;
    while (ind >= 0 && s[ind] == 'z') {
        ind--;
    }

    if (ind == -1) {
        exit(1);
    }

    string s3;
    for (int i = 0; i < ind; ++i) {
        s3.pb(s[i]);
    }
    s3.pb(s[ind] + 1);
    for (int i = ind + 1; i < n; ++i) {
        s3.pb('a');
    }

    t = s3;

    test.addLine(s);
    test.addLine(t);
    return test;
}

Test goodRandomTest(int n) {
    Test test;

    string s, t;
    for (int i = 1; i <= n; i++) {
        s += ((char)random(0, 25) + 97);
    }

    int ind = n - 1;
    while (ind >= 0 && s[ind] == 'z') {
        ind--;
    }

    if (ind == -1) {
        exit(1);
    }

    string s3;
    for (int i = 0; i < ind; ++i) {
        s3.pb(s[i]);
    }
    s3.pb(s[ind] + 1);
    for (int i = ind + 1; i < n; ++i) {
        s3.pb('a');
    }

    t = s3;

    s3.clear();
    ind = n - 1;
    while (ind >= 0 && t[ind] == 'z') {
        ind--;
    }

    if (ind == -1) {
        exit(1);
    }

    for (int i = 0; i < ind; ++i) {
        s3.pb(t[i]);
    }
    s3.pb(t[ind] + 1);
    for (int i = ind + 1; i < n; ++i) {
        s3.pb('a');
    }
    t = s3;

    test.addLine(s);
    test.addLine(t);
    return test;
}

Test verygoodRandomTest(int n) {
    Test test;

    string s, t;
    int k = random(1, n - 1);
    s.pb('z');
    t.pb('b');
    for (int i = 1; i < k; i++) {
        s.pb('z');
        t.pb('a');
    }

    char x = random(1, 25) + 97;
    s.pb(x - 1);
    t.pb(x);
    for (int i = k + 1; i < n; i++) {
        x = random(0, 25) + 97;
        s.pb(x);
        t.pb(x);
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    test.addLine(s);
    test.addLine(t);
    return test;
}

Test maxTest1() {
    int n = 1e5;
    Test test;

    string s, t;
    for (int i = 0; i < n; i++) {
        s += 'a';
    }

    for (int i = 0; i < n; i++) {
        t += 'z';
    }

    test.addLine(s);
    test.addLine(t);
    return test;
}

Test maxTest2() {
    int n = 1e5;
    Test test;

    string s, t;
    s += 'y';
    for (int i = 1; i < n; i++) {
        s += 'z';
    }

    t += 'z';
    for (int i = 1; i < n - 1; i++) {
        t += 'a';
    }
    t += 'b';

    test.addLine(s);
    test.addLine(t);
    return test;
}

int main() {
    Generator gen("trz");

    gen.beginGroup();
    gen.addTest(example1());
    gen.addTest(example2());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        gen.addTest(c1());
        gen.addTest(c2());
        gen.addTest(c3());
        gen.addTest(c4());
        gen.addTest(c5());
        gen.addTest(s1());
        gen.addTest(s2());
        gen.addTest(s3());
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        gen.addTest(s4());
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
        Generator::setSeed(3001);
        gen.addTest(randomTest(1000));
        Generator::setSeed(3002);
        gen.addTest(goodRandomTest(1000));
        Generator::setSeed(3003);
        gen.addTest(verygoodRandomTest(1000));
        Generator::setSeed(3004);
        gen.addTest(randomTest(1000));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        Generator::setSeed(4001);
        gen.addTest(randomTest(20000));
        Generator::setSeed(4002);
        gen.addTest(goodRandomTest(20000));
        Generator::setSeed(4003);
        gen.addTest(goodRandomTestNIE(20000));
        Generator::setSeed(4004);
        gen.addTest(randomTest(20000));
    }
    gen.endGroup();


    // 5
    gen.beginGroup();
    {
        Generator::setSeed(5001);
        gen.addTest(randomTest(50000));
        Generator::setSeed(5002);
        gen.addTest(goodRandomTest(50000));
        Generator::setSeed(5003);
        gen.addTest(goodRandomTest(50000));
        Generator::setSeed(5004);
        gen.addTest(randomTest(50000));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        Generator::setSeed(6001);
        gen.addTest(randomTest(100000));
        Generator::setSeed(6002);
        gen.addTest(verygoodRandomTest(100000));
        Generator::setSeed(6003);
        gen.addTest(verygoodRandomTest(100000));
        Generator::setSeed(6004);
        gen.addTest(goodRandomTestNIE(100000));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        Generator::setSeed(7001);
        gen.addTest(randomTest(100000));
        Generator::setSeed(7002);
        gen.addTest(randomTest(100000));
        gen.addTest(maxTest1());
        gen.addTest(maxTest2());
    }
    gen.endGroup();

    gen.generate();
}
