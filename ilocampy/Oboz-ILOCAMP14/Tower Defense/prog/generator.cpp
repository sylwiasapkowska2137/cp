#include "generator.h"

#include <set>
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
    test.addLine(6, 9, 3);
    test.addLine(2, 2);
    test.addLine(5, 6);
    test.addLine(6, 8);
    return test;
}

Test randomTest(int n, int m, int k) {
    Test test;
    test.addLine(n, m, k);
    
    assert(k <= min(n, m));
    assert(n <= 1000000000);
    assert(m <= 1000000000);
    assert(k <= 1000000);
    
    set <int> columns;
    set <int> rows;
    set <int>::iterator it;
    
    for (int i=0; i<k; i++) {
        int r = random(1, n);
        it = rows.find(r);
        while (*it == r) 
            r = random(1, n);
        rows.insert(r);
        
        int c = random(1, m);
        it = columns.find(c);
        while (*it == c)
            c = random(1, m);
        columns.insert(c);
        
        test.addLine(r, c);
    }
    
    return test;
}

Test manual1() {
    Test test;
    
    test.addLine(1, 1, 1);
    test.addLine(1, 1);
    
    return test;
}

Test manual2() {
    Test test;
    
    test.addLine(2, 2, 1);
    test.addLine(2, 2);
    
    return test;
}

Test manual3() {
    Test test;
    
    test.addLine(3, 3, 3);
    test.addLine(3, 1);
    test.addLine(2, 2);
    test.addLine(1, 3);
    
    return test;
}

Test manual4() {
    Test test;
    
    test.addLine(4, 5, 1);
    test.addLine(2, 2);
    
    return test;
}

int main() {
    Generator gen("tow");

    gen.beginGroup();
    gen.addTest(example());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        gen.addTest(manual1());
        gen.addTest(manual2());
        gen.addTest(manual3());
        gen.addTest(manual4());
        
        Generator::setSeed(101);
        gen.addTest(randomTest(5, 5, 2));
        Generator::setSeed(102);
        gen.addTest(randomTest(6, 6, 3));
        Generator::setSeed(103);
        gen.addTest(randomTest(6, 10, 2));
        Generator::setSeed(104);
        gen.addTest(randomTest(20, 20, 1));
        Generator::setSeed(105);
        gen.addTest(randomTest(20, 25, 2));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        Generator::setSeed(201);
        gen.addTest(randomTest(30, 10, 2));
        Generator::setSeed(202);
        gen.addTest(randomTest(30, 20, 3));
        Generator::setSeed(203);
        gen.addTest(randomTest(30, 30, 5));
        Generator::setSeed(204);
        gen.addTest(randomTest(30, 50, 10));
        Generator::setSeed(205);
        gen.addTest(randomTest(30, 61, 7));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        Generator::setSeed(301);
        gen.addTest(randomTest(1000, 1000, 2));
        Generator::setSeed(302);
        gen.addTest(randomTest(3000, 1000, 50));
        Generator::setSeed(303);
        gen.addTest(randomTest(20, 3000, 12));
        Generator::setSeed(304);
        gen.addTest(randomTest(1000, 100, 30));
        Generator::setSeed(305);
        gen.addTest(randomTest(2000, 1997, 972));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        Generator::setSeed(401);
        gen.addTest(randomTest(300200, 100800, 20));
        Generator::setSeed(402);
        gen.addTest(randomTest(300100, 206000, 35));
        Generator::setSeed(403);
        gen.addTest(randomTest(300987, 3000, 500));
        Generator::setSeed(404);
        gen.addTest(randomTest(3000, 500000, 100));
        Generator::setSeed(405);
        gen.addTest(randomTest(500123, 61000, 7));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        Generator::setSeed(501);
        gen.addTest(randomTest(543200, 10800, 1));
        Generator::setSeed(502);
        gen.addTest(randomTest(323100, 226987, 207891));
        Generator::setSeed(503);
        gen.addTest(randomTest(521987, 3000, 10));
        Generator::setSeed(504);
        gen.addTest(randomTest(30, 1000000, 28));
        Generator::setSeed(505);
        gen.addTest(randomTest(500123, 123456, 98712));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        Generator::setSeed(601);
        gen.addTest(randomTest(543200000, 10800444, 4));
        Generator::setSeed(602);
        gen.addTest(randomTest(123100123, 206987999, 100123));
        Generator::setSeed(603);
        gen.addTest(randomTest(521987765, 3123, 3000));
        Generator::setSeed(604);
        gen.addTest(randomTest(30918, 1000000000, 28));
        Generator::setSeed(605);
        gen.addTest(randomTest(500123555, 1000000000, 1000000));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        Generator::setSeed(701);
        gen.addTest(randomTest(543200000, 10800444, 11));
        Generator::setSeed(702);
        gen.addTest(randomTest(1000000000, 1000000000, 343000));
        Generator::setSeed(703);
        gen.addTest(randomTest(1000000000, 3000, 2900));
        Generator::setSeed(704);
        gen.addTest(randomTest(1000000000, 1000000000, 28));
        Generator::setSeed(705);
        gen.addTest(randomTest(99999999, 1000000000, 1000000));
    }
    gen.endGroup();

    gen.generate();
}


int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

