#include "generator.h"

#include <memory>

Test exampleTest();

Test randomTest(int size, int k, int lettersCount, int additional = 0);

int main() {
    Generator gen("uni");

    gen.addTest(exampleTest());

    // 1
    gen.beginGroup();
    {
        int size = 10;
        
        Generator::setSeed(194506);
        gen.addTest(randomTest(size, 2, 4));
        
        Generator::setSeed(287146);
        gen.addTest(randomTest(size, 1, 2));
        
    }
    gen.endGroup();
    
    // 2
    gen.beginGroup();
    {
        int size = 100;
        
        Generator::setSeed(8702615);
        gen.addTest(randomTest(size, 3, 20));
        
        Generator::setSeed(82736);
        gen.addTest(randomTest(size, 3, 7));
    }
    gen.endGroup();
    
    // 3
    gen.beginGroup();
    {
        int size = 1000;
        
        Generator::setSeed(237964);
        gen.addTest(randomTest(size, 2, 26));
        
        Generator::setSeed(817263);
        gen.addTest(randomTest(size, 15, 15, 20));
    }
    gen.endGroup();
    
    // 4
    gen.beginGroup();
    {
        int size = 50 * 1000;
        
        Generator::setSeed(2783146);
        gen.addTest(randomTest(size, 20, 20, 5));
        
        Generator::setSeed(5817923);
        gen.addTest(randomTest(size, 5, 8));
    }
    gen.endGroup();
    
    // 5
    gen.beginGroup();
    {
        int size = 250 * 1000;
        
        Generator::setSeed(123704);
        gen.addTest(randomTest(size, 1, 2));
        
        Generator::setSeed(912806);
        gen.addTest(randomTest(size, 26, 26));
    }
    gen.endGroup();
    
    // 6
    gen.beginGroup();
    {
        int size = 1000 * 1000;
        
        Generator::setSeed(1230476);
        gen.addTest(randomTest(size, 1, 1, 10));
        
        Generator::setSeed(2980134);
        gen.addTest(randomTest(size, 8, 8, 10000));
    }
    gen.endGroup();
    
    gen.generate();
}

Test exampleTest() {
    Test test;
    test.addLine(12, 2);
    test.addLine("auucuaccuauc");
    return test;
}

Test randomTest(int size, int k, int lettersCount, int additional) {
    Test test;
    test.addLine(size, k);
    
    std::vector<char> mapping;
    for (auto c = 'a'; c <= 'z'; c++) {
        mapping.push_back(c);
    }
    std::shuffle(mapping.begin(), mapping.end(), Generator::getGen());
    
    std::vector<char> seq;
    std::generate_n(std::back_inserter(seq), size, [&]() {
        return mapping[Generator::random() % lettersCount];
    });
    
    while (additional--) {
        seq[Generator::random() % seq.size()] = mapping[lettersCount];
    }
    
    test.setSeparator("");
    test.addLine(seq);
    
    return test;
}