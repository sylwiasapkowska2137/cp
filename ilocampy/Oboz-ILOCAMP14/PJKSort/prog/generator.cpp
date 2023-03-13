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
    test.addLine(6, 2);
    test.addLine(1, 1, 0, 0, 1, 0);
    test.addLine(4);
    test.addLine(1);
    return test;
}

Test c1() {
    Test test;
    test.addLine(1, 2);
    test.addLine(0);
    test.addLine(1);
    test.addLine(1);
    return test;
}

Test c2() {
    Test test;
    test.addLine(2, 4);
    test.addLine(0, 0);
    test.addLine(1);
    test.addLine(2);
    test.addLine(1);
    test.addLine(2);
    return test;
}

Test s1() {
    Test test;

    test.addLine(5, 3);

    return test;
}

Test allCases() {
    Test test;
    test.addLine(5, 31);
    test.addLine(0, 0, 0, 0, 0);
    int tab[] = {5, 4, 5, 3, 5, 4, 5, 2, 5, 4, 5, 3, 5, 4, 5, 1, 5, 4, 5, 3, 5, 4, 5, 2, 5, 4, 5, 3, 5, 4, 5};
    for (int i = 0; i < 31; i++) {
        test.addLine(tab[i]);
    }
    return test;
}

Test permutation(int n, int val) {
    Test test;
    test.addLine(n, n);
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(val);
    test.addLine(v);
    vector<int> per;
    for (int i = 0; i < n; i++) {
        per.push_back(i + 1);
    }
    random_shuffle(per.begin(), per.end());
    for (int i = 0; i < per.size(); i++) {
        test.addLine(per[i]);
    }
    return test;
}



Test randomTest(int n, int m) {
    Test test;
    test.addLine(n, m);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(random(0, 1));
    }
    test.addLine(v);
    while (m--) {
        int w = random(1, n);
        test.addLine(w);
    }
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
    Generator gen("pjk");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        gen.addTest(c1());
        gen.addTest(c2());
        gen.addTest(s1());
        Generator::setSeed(1001);
        gen.addTest(randomTest(10, 10));
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        gen.addTest(allCases());
        Generator::setSeed(2001);
        gen.addTest(randomTest(1000, 10));
        Generator::setSeed(3003);
        gen.addTest(randomTest(1000, 10));
        Generator::setSeed(3004);
        gen.addTest(randomTest(1000, 30));
    }
    gen.endGroup();


    //3
    gen.beginGroup();
    {
        Generator::setSeed(3001);
        gen.addTest(permutation(1000, 0));
        Generator::setSeed(3002);
        gen.addTest(permutation(1000, 1));
        Generator::setSeed(3001);
        gen.addTest(randomTest(1000, 1000));
        Generator::setSeed(3002);
        gen.addTest(randomTest(1000, 1000));
    }
    gen.endGroup();

    //4
    gen.beginGroup();
    {
        int n = 5e5;
        Generator::setSeed(5001);
        gen.addTest(randomTest(n, 20));
        Generator::setSeed(5002);
        gen.addTest(randomTest(n, 20));
        Generator::setSeed(5003);
        gen.addTest(randomTest(n, 10));
        Generator::setSeed(5004);
        gen.addTest(randomTest(n, 10));
    }
    gen.endGroup();

    //6
    gen.beginGroup();
    {
        int n = 1e5;
        Generator::setSeed(6001);
        gen.addTest(permutation(n, 0));
        Generator::setSeed(6002);
        gen.addTest(permutation(n, 1));
        Generator::setSeed(6003);
        gen.addTest(randomTest(n, n));
        Generator::setSeed(6004);
        gen.addTest(randomTest(n, n));
    }
    gen.endGroup();


    //6
    gen.beginGroup();
    {
        int n = 5e5;
        Generator::setSeed(6001);
        gen.addTest(permutation(n, 0));
        Generator::setSeed(6002);
        gen.addTest(permutation(n, 1));
        Generator::setSeed(6003);
        gen.addTest(randomTest(n, n));
        Generator::setSeed(6004);
        gen.addTest(randomTest(n, n));
    }
    gen.endGroup();


    //7
    gen.beginGroup();
    {
        int n = 5e5;
        Generator::setSeed(7001);
        gen.addTest(permutation(n, 0));
        Generator::setSeed(7002);
        gen.addTest(permutation(n, 1));
        Generator::setSeed(7003);
        gen.addTest(randomTest(n, n));
        Generator::setSeed(7004);
        gen.addTest(randomTest(n, n));
    }
    gen.endGroup();


    //8
    gen.beginGroup();
    {
        int n = 5e5;
        Generator::setSeed(8001);
        gen.addTest(permutation(n, 0));
        Generator::setSeed(8002);
        gen.addTest(permutation(n, 1));
        Generator::setSeed(8003);
        gen.addTest(randomTest(n, n));
        Generator::setSeed(8004);
        gen.addTest(randomTest(n, n));
    }
    gen.endGroup();

    gen.generate();
}


int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

