#include "generator.h"

#include <memory>

const char RED = 'C';
const char WHITE = 'B';

Test exampleTest();
Test randomTest(int count, int red);
Test segments(int count, int minSize, int maxSize);

int main() {
    Generator gen("kul");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        int size = 10;
        Generator::setSeed(1029856);
        gen.addTest(randomTest(size, 3));
        
        Generator::setSeed(74316);
        gen.addTest(segments(size, 1, 2));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        int size = 50;
        
        Generator::setSeed(-182735);
        gen.addTest(randomTest(size, size / 4));
        
        Generator::setSeed(2384097);
        gen.addTest(segments(size, size / 2, size / 2));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        int size = 100;
        
        Generator::setSeed(2103567);
        gen.addTest(randomTest(size, size - 20));
        
        Generator::setSeed(1920374);
        gen.addTest(segments(size, size / 5, size / 4));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        int size = 1000;
        
        Generator::setSeed(-89321);
        gen.addTest(randomTest(size, size / 2));
        
        Generator::setSeed(-218375);
        gen.addTest(segments(size, 10, 30));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        int size = 50 * 1000;
        
        Generator::setSeed(21387);
        gen.addTest(randomTest(size, size / 20));
        
        Generator::setSeed(921348);
        gen.addTest(randomTest(size, size));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        int size = 100 * 1000;
        
        Generator::setSeed(12839547);
        gen.addTest(randomTest(size, 1000));
        
        Generator::setSeed(12384);
        gen.addTest(segments(size, size / 200, size / 100));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        int size = 300 * 1000;
        
        Generator::setSeed(983261);
        gen.addTest(randomTest(size, size / 10));
        
        Generator::setSeed(512938);
        gen.addTest(randomTest(size, 0));
    }
    gen.endGroup();

    // 8
    gen.beginGroup();
    {
        int size = 600 * 1000;
        
        Generator::setSeed(281943);
        gen.addTest(randomTest(size, size - 10));
        
        Generator::setSeed(129306);
        gen.addTest(segments(size, 1, 5));
    }
    gen.endGroup();

    // 9
    gen.beginGroup();
    {
        int size = 1000 * 1000;
        
        Generator::setSeed(961725);
        gen.addTest(randomTest(size, size / 5));
        
        Generator::setSeed(82396);
        gen.addTest(segments(size, 1, 1000));
    }
    gen.endGroup();

    gen.generate();
}

Test exampleTest() {
    Test test;
    test.addLine(12);
    test.addLine("BBCCBCCBCCBB");
    return test;
}

Test randomTest(int count, int red) {
    std::vector<char> balls(count, WHITE);
    std::fill(balls.begin(), balls.begin() + red, RED);
    std::shuffle(balls.begin(), balls.end(), Generator::getGen());
    
    Test test;
    test.addLine(balls.size());
    test.setSeparator("");
    test.addLine(balls);
    return test;
}

int random(int a, int b);

Test segments(int count, int minSize, int maxSize) {
    std::vector<char> balls;
    char curColor = (Generator::random() % 2) ? RED : WHITE;
    while (balls.size() < count) {
        int size = random(minSize, maxSize);
        if (maxSize >= count - (int)balls.size()) {
            size = count - (int)balls.size();
        }
        std::fill_n(std::back_inserter(balls), size, curColor);
        curColor = (curColor == WHITE) ? RED : WHITE;
    }
    
    Test test;
    test.addLine(balls.size());
    test.setSeparator("");
    test.addLine(balls);
    return test;
}

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}
