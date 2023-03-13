#include "generator.h"

#include <memory>

Test exampleTest();
Test basicTest(int count, int k, int uniques, int rest, int maxMapping);

int main() {
    Generator gen("szt");

    gen.addTest(exampleTest());

    // 1
    gen.beginGroup();
    {
        int size = 10;

        Generator::setSeed(7821965);
        gen.addTest(basicTest(size, 3, 5, 2, 10));

        Generator::setSeed(120897);
        gen.addTest(basicTest(size, 3, 8, 1, 10));

        Generator::setSeed(1890457);
        gen.addTest(basicTest(size, 3, 0, 2, 10));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        int size = 40;

        Generator::setSeed(9120536);
        gen.addTest(basicTest(size, 5, 30, 1, 50));

        Generator::setSeed(824765);
        gen.addTest(basicTest(size, size, size, 0, 100));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        int size = 150;

        Generator::setSeed(127348);
        gen.addTest(basicTest(size, 3, 30, 30, 500));

        Generator::setSeed(5467);
        gen.addTest(basicTest(size, 50, 60, size - 60 - 5, 500));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        int size = 1000;

        Generator::setSeed(289304);
        gen.addTest(basicTest(size, 15, 200, 600, 1e6));

        Generator::setSeed(213695);
        gen.addTest(basicTest(size, 10, 30, 50, 5000));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        int size = 50 * 1000;

        Generator::setSeed(984120);
        gen.addTest(basicTest(size, 100, 150, 10 * 1000, 1e6));

        Generator::setSeed(1925478);
        gen.addTest(basicTest(size, 30, 1000, 3, 1e6));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        int size = 100 * 1000;

        Generator::setSeed(1289034);
        gen.addTest(basicTest(size, 3, 5, 5000, 5e5));

        Generator::setSeed(2134657);
        gen.addTest(basicTest(size, 10 * 1000, size / 2, size / 3, 5e5));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        int size = 250 * 1000;

        Generator::setSeed(12894);
        gen.addTest(basicTest(size, 100, 600, 20, 1e6));
        
        Generator::setSeed(172346);
        gen.addTest(basicTest(size, 3, 4, 1, 100));
    }
    gen.endGroup();

    // 8
    gen.beginGroup();
    {
        int size = 400 * 1000;

        Generator::setSeed(87);
        gen.addTest(basicTest(size, 100, 600, 20, 1e6));
        
        Generator::setSeed(14376);
        gen.addTest(basicTest(size, 3, 3, 1, 100));
    }
    gen.endGroup();
    
    // 9
    gen.beginGroup();
    {
        int size = 800 * 1000;

        Generator::setSeed(2157);
        gen.addTest(basicTest(size, 2, size / 2, 10, 1e6));
        
        Generator::setSeed(45298);
        gen.addTest(basicTest(size, size / 10, size / 9, 2, 1e6));
    }
    gen.endGroup();
    
    // 10
    gen.beginGroup();
    {
        int size = 1000 * 1000;

        Generator::setSeed(18254);
        gen.addTest(basicTest(size, 10, size / 100, 1000, 1e6));
        
        Generator::setSeed(12938);
        gen.addTest(basicTest(size, 10 * 1000, 15 * 1000, 20 * 1000, 1e6));
    }
    gen.endGroup();

    gen.generate();
}

Test exampleTest() {
    Test test;

    test.addLine(12, 2);
    test.addLine(2, 1, 3, 1, 3, 3, 3, 2, 1, 1, 2, 3);

    return test;
}

void applyMapping(std::vector<int> &vec, int maxMapping);

Test basicTest(int count, int k, int uniques, int rest, int maxMapping) {
    Test test;

    test.addLine(count, k);

    std::vector<int> seq;
    for (int i = 1; i <= uniques; i++) {
        seq.push_back(i);
    }
    while (seq.size() < count) {
        seq.push_back(uniques + 1 + Generator::random() % rest);
    }
    std::shuffle(seq.begin(), seq.end(), Generator::getGen());
    applyMapping(seq, maxMapping);
    test.addLine(seq);

    return test;
}

void applyMapping(std::vector<int> &vec, int maxMapping) {
    std::vector<int> mapping(maxMapping);
    std::iota(mapping.begin(), mapping.end(), 1);

    for (auto &x : vec) {
        x = mapping[x - 1];
    }
}
