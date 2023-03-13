#include "generator.h"

#include <memory>
#include <assert.h>
using namespace std;

long long M = 1000005;
long long MAX_V = 1000000000;

int R(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test exampleTest() {
  Test test;
  test.addLine(3);
  test.addLine(2, 4);
  test.addLine(2, 8);
  test.addLine(6, 7);
  return test;
}
  
Test randomTest(int n, int minL, int maxR, int div) {
    Test test;
    int a, b, za, zb;
    
    test.addLine(n);
    
    za = R(minL, (minL + maxR) / div);
    zb = R(za, maxR);

    assert(za <= zb);
    assert(za <= 1000000000 && zb <= 1000000000);
    
    test.addLine(za, zb);
    
    n--;
    while (n--) {
        int x = R(0, 3);
        if (x != 0)
            a = R(minL, maxR);
        else 
            a = R(za, maxR);
        
        b = R(max(a, za), maxR);
        

        assert(a <= b);
        assert(a <= 1000000000 && b <= 1000000000);
        
        test.addLine(a, b);
    }

    return test;
}

Test corner1() {
    Test test;
    
    test.addLine(3);
    test.addLine(5, 10);
    test.addLine(4, 6);
    test.addLine(5, 15);
    
    return test;
}

Test corner2() {
    Test test;
    
    test.addLine(3);
    test.addLine(6, 9);
    test.addLine(7, 11);
    test.addLine(7, 10);
    
    return test;
}

Test corner3() {
    Test test;
    
    test.addLine(3);
    test.addLine(4, 4);
    test.addLine(4, 7);
    test.addLine(4, 4);
    
    return test;
}

Test corner4() {
    Test test;
    
    test.addLine(4);
    test.addLine(2, 3);
    test.addLine(1, 4);
    test.addLine(1, 4);
    test.addLine(1, 4);
    
    return test;
}

Test corner5() {
    Test test;
    
    test.addLine(2);
    test.addLine(0, 24);
    test.addLine(9, 12);
    
    return test;
}

Test corner6() {
    Test test;
    
    test.addLine(1);
    test.addLine(0, 1000000000);
    
    return test;
}

Test corner7() {
    Test test;
    
    test.addLine(6);
    test.addLine(11, 13);
    test.addLine(10, 18);
    test.addLine(5, 19);
    test.addLine(4, 20);
    test.addLine(2, 23);
    test.addLine(0, 24);
    
    return test;
}

Test corner8() {
    Test test;
    
    test.addLine(6);
    test.addLine(10, 13);
    test.addLine(10, 18);
    test.addLine(5, 19);
    test.addLine(4, 23);
    test.addLine(2, 23);
    test.addLine(0, 24);
    
    return test;
}

Test corner9() {
    Test test;
    
    test.addLine(4);
    test.addLine(3, 3);
    test.addLine(4, 4);
    test.addLine(5, 5);
    test.addLine(6, 6);
    
    return test;
}

Test corner10() {
    Test test;
    
    test.addLine(4);
    test.addLine(3, 3);
    test.addLine(2, 3);
    test.addLine(5, 5);
    test.addLine(6, 6);
    
    return test;
}

Test corner11() {
    Test test;
    
    test.addLine(10);
    test.addLine(1, 10);
    test.addLine(1, 10);
    test.addLine(1, 10);
    test.addLine(1, 10);
    test.addLine(1, 10);
    test.addLine(1, 10);
    test.addLine(1, 10);
    test.addLine(1, 10);
    test.addLine(1, 10);
    test.addLine(1, 10);
    
    return test;
}



int main() {
    Generator gen("zgr");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        Generator::setSeed(1982755341);
        
        gen.addTest(corner1());
        gen.addTest(corner2());
        gen.addTest(corner3());
        gen.addTest(corner4());
        gen.addTest(corner5());
        gen.addTest(corner6());
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        Generator::setSeed(2942755341);

        gen.addTest(corner7());
        gen.addTest(randomTest(5, 1, 20, 2));
        gen.addTest(randomTest(10, 0, 30, 2));
        gen.addTest(randomTest(10, 100, 1000, 2));
        gen.addTest(randomTest(20, 100, 110, 2));
        gen.addTest(randomTest(20, 100, 120, 2));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        Generator::setSeed(1982734123);

        gen.addTest(corner8());
        gen.addTest(randomTest(5, 1, 20, 2));
        gen.addTest(randomTest(50, 0, 1000, 2));
        gen.addTest(randomTest(50, 0, 1000, 2));
    }
    gen.endGroup();
    
    
    // 4 
    gen.beginGroup();
    {
        Generator::setSeed(3382755341);

        gen.addTest(corner2());
        gen.addTest(randomTest(5, 1, 20, 2));
        gen.addTest(randomTest(100, 0, 1000000, 2));
        gen.addTest(randomTest(300, 0, 1000000, 2));
    }
    gen.endGroup();

    //5 
    gen.beginGroup();
    {
        Generator::setSeed(29487547);

        gen.addTest(corner9());
        gen.addTest(randomTest(5, 1, 20, 2));
        gen.addTest(randomTest(100, 0, 1000000000, 2));
        gen.addTest(randomTest(300, 100000, 1000000000, 2));
    }
    gen.endGroup();

    //6
    gen.beginGroup();
    {
        Generator::setSeed(94933833);
        
        gen.addTest(corner10());
        gen.addTest(randomTest(5, 1, 20, 2));
        gen.addTest(randomTest(300, 0, 1000000, 2));
        gen.addTest(randomTest(300, 999990, 1000000, 2));
    }

    gen.endGroup();

    //7
    gen.beginGroup();
    {
        Generator::setSeed(303022939);

        gen.addTest(corner11());
        gen.addTest(corner3());
        gen.addTest(randomTest(5, 1, 20, 2));
        gen.addTest(randomTest(300, 0, 1000000000, 2));
        gen.addTest(randomTest(300, 999999900, 1000000000, 2));
    }
    gen.endGroup();


    gen.generate();
}