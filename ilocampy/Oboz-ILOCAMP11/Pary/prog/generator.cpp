#include "generator.h"

#include <memory>
//#include <bits/stdc++.h>

using graph_t = std::vector<std::pair<int, int>>;

Test exampleTest();
Test randomSequence(int n, int k, int minValue, int maxValue);
Test sortedSequence(int n, int k, int minValue, int maxValue, bool ascending);
Test fromOldFile(const std::string &filename);
Test randomTest(int n);
Test longCycle(int n, int cycleLength);

int main() {
    Generator gen("par");
 
    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
    
    gen.beginGroup(); //1
    gen.addTest(fromOldFile("par0.0.in"));
    gen.addTest(fromOldFile("par0.1.in"));   
    gen.addTest(fromOldFile("par0.2.in"));
    gen.addTest(fromOldFile("par0.3.in"));
    gen.addTest(fromOldFile("par0.4.in"));
    gen.endGroup();
    
    gen.beginGroup(); //2
    gen.addTest(fromOldFile("par1.0.in"));
    gen.addTest(fromOldFile("par1.1.in"));   
    gen.addTest(fromOldFile("par1.2.in"));
    gen.addTest(fromOldFile("par1.3.in"));
    gen.addTest(fromOldFile("par1.4.in"));
    
    gen.endGroup();
    
    gen.beginGroup(); //3
    gen.addTest(fromOldFile("par2.0.in"));
    gen.addTest(fromOldFile("par2.1.in"));   
    gen.addTest(fromOldFile("par2.2.in"));
    gen.addTest(fromOldFile("par2.3.in"));
    gen.addTest(fromOldFile("par2.4.in"));
    Generator::setSeed(51951);
    gen.addTest(randomTest(1000));
    gen.endGroup();
    
    gen.beginGroup(); //4
    gen.addTest(fromOldFile("par3.0.in"));
    gen.addTest(fromOldFile("par3.1.in"));   
    gen.addTest(fromOldFile("par3.2.in"));
    gen.addTest(fromOldFile("par3.3.in"));
    gen.addTest(fromOldFile("par3.4.in"));
    Generator::setSeed(58358365);
    gen.addTest(randomTest(10000));
    Generator::setSeed(8735853);
    gen.addTest(longCycle(10000, 500));
    gen.endGroup();
    
    gen.beginGroup(); //5
    gen.addTest(fromOldFile("par4.0.in"));
    gen.addTest(fromOldFile("par4.1.in"));   
    gen.addTest(fromOldFile("par4.2.in"));
    gen.addTest(fromOldFile("par4.3.in"));
    gen.addTest(fromOldFile("par4.4.in"));
    Generator::setSeed(742724);
    gen.addTest(randomTest(50000));
    Generator::setSeed(7672752);
    gen.addTest(longCycle(50000, 30000));
    gen.endGroup();
    
    gen.beginGroup(); //6
    gen.addTest(fromOldFile("par5.0.in"));
    gen.addTest(fromOldFile("par5.1.in"));   
    gen.addTest(fromOldFile("par5.2.in"));
    gen.addTest(fromOldFile("par5.3.in"));
    gen.addTest(fromOldFile("par5.4.in"));
    Generator::setSeed(867242);
    gen.addTest(randomTest(100000));
    Generator::setSeed(97576272);
    gen.addTest(longCycle(100000, 70000));
    gen.endGroup();
    
    gen.beginGroup(); //7
    gen.addTest(fromOldFile("par6.0.in"));
    gen.addTest(fromOldFile("par6.1.in"));   
    gen.addTest(fromOldFile("par6.2.in"));
    gen.addTest(fromOldFile("par6.3.in"));
    gen.addTest(fromOldFile("par6.4.in"));
    Generator::setSeed(8268624);
    gen.addTest(randomTest(200000));
    Generator::setSeed(97277642);
    gen.addTest(longCycle(200000, 100000));
    gen.endGroup();
    
    gen.beginGroup(); //8
    gen.addTest(fromOldFile("par7.0.in"));
    gen.addTest(fromOldFile("par7.1.in"));   
    gen.addTest(fromOldFile("par7.2.in"));
    gen.addTest(fromOldFile("par7.3.in"));
    gen.addTest(fromOldFile("par7.4.in"));
    Generator::setSeed(68262);
    gen.addTest(randomTest(400000));
    Generator::setSeed(185627);
    gen.addTest(longCycle(400000, 350000));
    gen.endGroup();
    
    gen.beginGroup(); //9
    gen.addTest(fromOldFile("par8.0.in"));
    gen.addTest(fromOldFile("par8.1.in"));   
    gen.addTest(fromOldFile("par8.2.in"));
    gen.addTest(fromOldFile("par8.3.in"));
    gen.addTest(fromOldFile("par8.4.in"));
    Generator::setSeed(756526);
    gen.addTest(randomTest(500000));
    Generator::setSeed(767228);
    gen.addTest(longCycle(500000, 400000));
    gen.endGroup();
    
    gen.beginGroup(); //10
    gen.addTest(fromOldFile("par9.0.in"));
    gen.addTest(fromOldFile("par9.1.in"));   
    gen.addTest(fromOldFile("par9.2.in"));
    gen.addTest(fromOldFile("par9.3.in"));
    gen.addTest(fromOldFile("par9.4.in"));
    Generator::setSeed(7624742);
    gen.addTest(randomTest(500000));
    Generator::setSeed(64262);
    gen.addTest(longCycle(500000, 350000));
    gen.endGroup();
    
    gen.generate();
}
int random(int a, int b);
Test exampleTest() {
    Test test;
    
    test.addLine(5);
    test.addLine(5, 2);
    test.addLine(3, 2);
    test.addLine(5, 1);
    test.addLine(2, 1);
    test.addLine(4, 2);
    
    return test;
}

Test randomTest(int n) {
    Test test;
    
    test.addLine(n);
    
    for (int i = 1; i <= n; i++) {
        int x;
        do {
            x = random(1, n);
        } while (x == i);
        test.addLine(x, random(1, 2));
    }
    
    return test;
}

Test longCycle(int n, int cycleLength) {
    Test test;
    assert(cycleLength <= n);
    test.addLine(n);
    
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            test.addLine(cycleLength, random(1, 2));
        if (1 < i && i <= cycleLength)
            test.addLine(i - 1, random(1, 2));
        if (cycleLength < i) {
            int sas = random(1, i - 1);
            test.addLine(sas, random(1, 2));
        }   
    }
    
    return test;
}

int random(int a, int b);
std::vector<int> randomQueries(int n, int k);

Test fromOldFile(const std::string &filename) {
    std::ifstream ifs("../test_old/" + filename);
    
    Test test;
    int n;
    ifs >> n;
    test.addLine(n);
    
    while (n--) {
        int a, b;
        ifs >> a >> b;
        test.addLine(a, b);
    }
    
    return test;
}

Test randomSequence(int n, int k, int minValue, int maxValue) {
    Test test;
    std::vector<int> sequence(n);
    test.addLine(n);
    
    for(int i = 0; i < n; i++) {
        sequence[i] = random(minValue, maxValue);
    }
    test.addLine(sequence);
    std::vector<int> q = randomQueries(n, k);
    test.addLine(k);
    for(int x: q) {
        test.addLine(x);
    }
    
    return test;
}

std::vector<int> randomQueries(int n, int k) {
    std::vector<int> ret;
    for(int i = 0; i < k; i++) {
        ret.push_back(random(1, n));
    }
    return ret;
}

int random(int a, int b) {
    return rand() % (b - a + 1) + a;
} 
