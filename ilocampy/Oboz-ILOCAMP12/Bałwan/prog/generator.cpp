#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;

using namespace std;

Test randomTest(int n, int minValue, int maxValue);
Test exampleTest();
Test single1();
Test smallTest1();
Test smallTest2();
Test smallTest3();
Test smallTest4();
Test smallTest5();
Test smallTest6();
Test smallTest7();
Test smallTest8();
Test smallTest9();
Test smallTest10();
Test smallTest11();

Test mediumTest1();
Test mediumTest2();
Test mediumTest3();
Test mediumTest4();
Test mediumTest5();

Test begendTest(int n, int minValue, int maxValue);

int main() {
    Generator gen("bal");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
    // 1
    gen.beginGroup();
    {
        gen.addTest(single1());
        gen.addTest(smallTest1());
        gen.addTest(smallTest2());
        gen.addTest(smallTest3());
        gen.addTest(smallTest4());
        gen.addTest(smallTest6());
        gen.addTest(smallTest8());
        gen.addTest(smallTest10());
    }
    gen.endGroup();
    // 2
    gen.beginGroup();
    {
        Generator::setSeed(31531431);
        gen.addTest(randomTest(20, 1, 10));
        gen.addTest(randomTest(10, 1, 5));
        gen.addTest(smallTest5());
        gen.addTest(smallTest7());
        gen.addTest(smallTest9());
        gen.addTest(smallTest11());
        gen.addTest(randomTest(20, 1, 5));
        gen.addTest(begendTest(20, 1, 5));
    }
    gen.endGroup();
//     return 0;
    // 3
    gen.beginGroup();
    {
        Generator::setSeed(48141341);
        gen.addTest(randomTest(1000, 1, 1000));
        gen.addTest(randomTest(1000, 20, 100));
        gen.addTest(randomTest(1000, 1, 3));
        gen.addTest(mediumTest5());
        gen.addTest(begendTest(1000, 1, 20));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        Generator::setSeed(513859131);
        gen.addTest(mediumTest1());
        gen.addTest(mediumTest2());
        gen.addTest(randomTest(50000, 1, 50000));
        gen.addTest(mediumTest4());
        gen.addTest(randomTest(50000, 1, 1000000));
        gen.addTest(begendTest(50000, 1, 200));
    }
    gen.endGroup();
    
    // 5
    gen.beginGroup();
    {
        Generator::setSeed(5315131);
        gen.addTest(randomTest(100000, 1, 100000));
        gen.addTest(randomTest(100000, 1, 10000));
        gen.addTest(mediumTest3());
        gen.addTest(randomTest(100000, 1, 1000000));
        gen.addTest(begendTest(100000, 1, 200));
        gen.addTest(randomTest(100000, 1, 100));
    }
    gen.endGroup();
    
    // 6
    gen.beginGroup();
    {
        Generator::setSeed(31395310);
        gen.addTest(randomTest(100000, 1, 1000000000));
        gen.addTest(randomTest(100000, 1, 10000000));
        gen.addTest(randomTest(100000, 1, 100000000));
        gen.addTest(begendTest(100000, 1, 300));
        gen.addTest(randomTest(100000, 1, 100));
    }
    gen.endGroup();
    
    
    gen.beginGroup();
    {
        Generator::setSeed(31395310);
        gen.addTest(randomTest(100000, 1, 1000000000));
        gen.addTest(randomTest(100000, 1, 10000));
        gen.addTest(randomTest(100000, 1, 100));
        gen.addTest(begendTest(100000, 1, 300));
    }
    gen.endGroup();
 
    gen.generate();
}

int random(int a, int b);
graph_t randomTree(int count);
void addNodes(graph_t &graph, int count, int maxBack);
void shuffleGraph(graph_t &graph);
Test graphToTest(const graph_t &graph);

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test exampleTest() {
    Test test;
    test.addLine(7);
    test.addLine(2, 5, 3, 7, 6, 2, 9);
    return test;
}

Test single1() {
    Test test;
    test.addLine(1);
    test.addLine(1);
    return test;
}

Test smallTest1() {
    Test test;
    test.addLine(8);
    test.addLine(5, 4, 7, 6, 3, 9, 7, 6);
    return test;
}

Test smallTest2() {
    Test test;
    test.addLine(3);
    test.addLine(6, 4, 6);
    return test;
}

Test smallTest3() {
    Test test;
    test.addLine(5);
    test.addLine(5, 2, 7, 1, 6);
    return test;
}

Test smallTest4() {
    Test test;
    test.addLine(4);
    test.addLine(2, 5, 10, 2);
    return test;
}

Test smallTest5() {
    Test test;
    test.addLine(6);
    test.addLine(2, 4, 8, 10, 5, 4);
    return test;
}

Test smallTest6() {
    Test test;
    test.addLine(8);
    test.addLine(4, 1, 10, 1, 1, 6, 4, 7);
    return test;
}

Test smallTest7() {
    Test test;
    test.addLine(10);
    test.addLine(1, 1, 7, 7, 4, 6, 1, 4, 5, 6);
    return test;
}

Test smallTest8() {
    Test test;
    test.addLine(10);
    test.addLine(9, 8, 5, 8, 1, 9, 4, 9, 5, 8);
    return test;
}

Test smallTest9() {
    Test test;
    test.addLine(10);
    test.addLine(2, 4, 4, 4, 1, 2, 5, 2, 2, 6);
    return test;
}

Test smallTest10() {
    Test test;
    test.addLine(10);
    test.addLine(4, 9, 4, 3, 6, 2, 1, 4, 2, 5);
    return test;
}

Test smallTest11() {
    Test test;
    test.addLine(5);
    test.addLine(10, 5, 2, 1, 9);
    return test;
}

Test mediumTest1() {
    Test test;
    test.addLine(51);
    test.addLine(6, 9, 3, 6, 6, 8, 2, 4, 4, 9, 9, 2, 9, 6, 1, 7, 9, 8, 3, 3, 3, 10, 10, 5, 7, 4, 9, 1, 2, 3, 2, 9, 1, 6, 4, 8, 5, 7, 2, 10, 7, 10, 4, 5, 7, 4, 4, 5, 3, 6, 9);
    return test;
}


Test mediumTest2() {
    Test test;
    test.addLine(77);
    test.addLine(9, 7, 7, 9, 8, 6, 2, 3, 10, 6, 5, 3, 1, 8, 10, 6, 8, 10, 3, 5, 9, 9, 4, 3, 9, 9, 5, 2, 1, 7, 9, 9, 4, 7, 9, 3, 3, 10, 7, 4, 5, 2, 7, 8, 1, 6, 3, 10, 6, 7, 6, 6, 8, 2, 10, 6, 10, 4, 8, 10, 3, 8, 10, 8, 4, 9, 2, 8, 10, 8, 2, 7, 1, 8, 4, 4, 5);
    return test;
}

Test mediumTest3() {
    Test test;
    test.addLine(91);
    test.addLine(8, 1, 9, 2, 6, 3, 9, 9, 4, 7, 2, 9, 6, 4, 7, 5, 8, 5, 9, 7, 9, 5, 3, 1, 10, 2, 1, 10, 6, 3, 10, 3, 5, 8, 4, 2, 2, 4, 2, 5, 2, 4, 3, 7, 7, 1, 3, 6, 6, 2, 2, 4, 8, 6, 6, 7, 8, 9, 6, 3, 1, 7, 7, 7, 4, 1, 9, 7, 6, 10, 2, 8, 3, 6, 6, 9, 7, 9, 6, 4, 2, 7, 9, 9, 5, 4, 5, 2, 4, 3, 4);
    return test;
}

Test mediumTest4() {
    Test test;
    test.addLine(800);
    test.addLine(79, 59, 31, 80, 59, 66, 15, 84, 66, 45, 17, 15, 61, 99, 60, 38, 61, 27, 7, 99, 72, 81, 94, 15, 4, 12, 56, 2, 24, 1, 84, 2, 59, 14, 34, 17, 31, 48, 1, 48, 44, 69, 63, 56, 19, 74, 93, 79, 1, 99, 30, 24, 32, 75, 39, 35, 86, 46, 88, 9, 46, 71, 63, 5, 36, 96, 73, 66, 95, 25, 66, 38, 93, 28, 45, 12, 1, 37, 42, 53, 87, 23, 77, 18, 97, 67, 5, 34, 12, 92, 43, 10, 63, 57, 66, 50, 4, 38, 68, 98, 15, 33, 87, 7, 60, 31, 70, 12, 67, 64, 65, 5, 86, 41, 23, 35, 7, 27, 68, 70, 70, 62, 79, 84, 18, 44, 34, 21, 34, 1, 18, 48, 33, 4, 6, 44, 86, 28, 55, 4, 43, 19, 9, 80, 11, 31, 14, 69, 9, 82, 91, 78, 43, 21, 62, 61, 17, 47, 33, 50, 47, 3, 49, 31, 58, 6, 74, 44, 33, 28, 47, 75, 99, 55, 7, 61, 37, 20, 82, 45, 1, 72, 75, 96, 92, 88, 8, 8, 34, 40, 9, 32, 42, 9, 62, 100, 15, 87, 43, 99, 66, 41, 26, 16, 96, 32, 77, 84, 51, 10, 29, 4, 81, 55, 99, 24, 42, 58, 32, 27, 97, 92, 10, 91, 1, 71, 90, 15, 9, 84, 13, 74, 76, 38, 90, 23, 69, 18, 7, 72, 27, 87, 75, 59, 41, 25, 82, 34, 82, 65, 12, 30, 57, 21, 20, 57, 91, 61, 23, 99, 96, 87, 24, 72, 77, 13, 94, 97, 82, 100, 68, 8, 38, 94, 66, 78, 18, 48, 63, 99, 64, 74, 29, 20, 94, 100, 28, 36, 61, 2, 86, 56, 89, 10, 79, 65, 74, 25, 61, 56, 24, 81, 63, 14, 74, 81, 91, 92, 80, 6, 42, 43, 79, 22, 63, 25, 22, 42, 60, 34, 44, 46, 41, 32, 7, 20, 48, 80, 44, 8, 35, 19, 40, 50, 32, 14, 82, 75, 5, 61, 80, 98, 3, 10, 20, 17, 34, 93, 59, 94, 26, 2, 91, 18, 85, 97, 37, 32, 76, 32, 91, 63, 3, 31, 64, 34, 44, 45, 60, 100, 5, 91, 97, 59, 1, 68, 76, 34, 60, 34, 79, 37, 87, 69, 55, 71, 17, 43, 54, 45, 27, 96, 59, 29, 26, 22, 14, 21, 18, 74, 72, 74, 64, 21, 32, 16, 88, 7, 2, 100, 40, 80, 88, 26, 1, 94, 48, 17, 89, 1, 13, 15, 97, 71, 43, 74, 92, 8, 47, 61, 81, 70, 34, 97, 90, 66, 64, 30, 72, 65, 81, 64, 97, 68, 41, 49, 14, 41, 17, 2, 41, 30, 16, 89, 100, 10, 15, 44, 17, 13, 4, 50, 82, 38, 98, 72, 55, 13, 1, 26, 30, 33, 41, 26, 100, 34, 74, 65, 74, 42, 66, 66, 71, 33, 7, 71, 42, 21, 66, 11, 33, 69, 12, 14, 58, 61, 37, 12, 73, 89, 90, 2, 21, 82, 27, 73, 15, 52, 37, 40, 94, 3, 6, 16, 87, 12, 38, 29, 32, 3, 91, 16, 24, 2, 81, 81, 62, 18, 45, 86, 6, 86, 88, 79, 67, 66, 51, 34, 18, 87, 73, 63, 41, 78, 78, 80, 41, 68, 8, 24, 70, 50, 39, 93, 3, 20, 26, 64, 89, 22, 49, 46, 7, 88, 24, 25, 54, 74, 58, 23, 13, 31, 85, 5, 60, 14, 84, 53, 81, 43, 76, 3, 92, 67, 47, 94, 38, 24, 9, 26, 45, 10, 71, 51, 49, 95, 76, 2, 20, 85, 24, 32, 67, 60, 89, 79, 26, 72, 31, 58, 67, 58, 60, 10, 24, 59, 56, 61, 82, 64, 86, 27, 25, 9, 29, 74, 55, 56, 27, 74, 41, 51, 58, 59, 62, 46, 37, 87, 69, 19, 45, 35, 77, 56, 45, 100, 66, 100, 61, 48, 15, 98, 74, 92, 58, 54, 17, 12, 10, 43, 86, 2, 93, 95, 60, 7, 92, 49, 93, 60, 67, 89, 47, 43, 97, 43, 43, 62, 42, 55, 9, 8, 52, 34, 51, 62, 88, 67, 73, 97, 10, 10, 98, 54, 4, 9, 60, 95, 57, 5, 7, 24, 93, 5, 66, 89, 47, 60, 51, 40, 14, 11, 47, 18, 45, 98, 79, 32, 16, 3, 80, 25, 13, 29, 31, 68, 89, 90, 15, 46, 94, 73, 21, 39, 77, 38, 27, 23, 98, 29, 62, 63, 92, 60, 80, 36, 9, 10, 19, 25, 13, 50, 49, 77, 30, 79, 96, 18, 21, 10, 63, 66, 82, 35, 4, 58, 73, 83, 32, 70, 63, 45, 32, 54, 5, 64, 89, 13, 25, 59, 37, 89, 8, 38, 65, 37, 68, 61, 7, 40, 22, 69, 6, 4, 56, 9, 13, 28, 91, 97);
    return test;
}

Test mediumTest5() {
    Test test;
    test.addLine(800);
    test.addLine(30, 81, 65, 2, 52, 37, 84, 73, 9, 18, 69, 11, 99, 42, 93, 74, 62, 11, 91, 91, 85, 79, 77, 99, 17, 57, 91, 61, 66, 47, 47, 95, 79, 63, 49, 30, 51, 84, 55, 11, 1, 23, 22, 99, 17, 66, 24, 30, 76, 66, 20, 60, 45, 48, 59, 13, 4, 1, 73, 22, 47, 71, 16, 77, 85, 16, 7, 35, 99, 61, 98, 51, 35, 19, 2, 51, 36, 77, 80, 11, 43, 51, 23, 87, 50, 33, 51, 6, 85, 23, 27, 83, 45, 94, 59, 29, 62, 65, 15, 12, 77, 64, 63, 12, 82, 16, 14, 17, 92, 46, 80, 34, 48, 54, 72, 98, 86, 74, 55, 70, 96, 33, 52, 92, 26, 10, 72, 39, 27, 39, 51, 55, 2, 65, 18, 36, 80, 32, 4, 71, 29, 83, 57, 76, 88, 80, 25, 73, 54, 31, 94, 1, 63, 97, 45, 41, 59, 16, 79, 37, 54, 81, 91, 56, 45, 61, 43, 24, 44, 46, 47, 72, 81, 55, 99, 68, 86, 76, 41, 91, 6, 86, 92, 69, 83, 88, 61, 93, 3, 91, 29, 9, 72, 71, 16, 16, 31, 58, 92, 74, 3, 90, 97, 83, 44, 96, 51, 81, 71, 43, 72, 76, 80, 15, 96, 62, 2, 8, 6, 4, 99, 86, 64, 22, 57, 79, 37, 39, 36, 80, 13, 39, 69, 61, 73, 64, 56, 23, 97, 78, 17, 68, 6, 97, 82, 53, 10, 35, 61, 16, 90, 11, 1, 54, 32, 9, 32, 20, 48, 68, 52, 12, 58, 20, 72, 30, 36, 80, 5, 32, 57, 21, 51, 62, 17, 84, 67, 27, 18, 27, 94, 7, 89, 46, 60, 20, 55, 44, 91, 54, 11, 42, 65, 68, 14, 36, 49, 1, 15, 53, 84, 24, 74, 34, 37, 42, 17, 3, 20, 86, 81, 13, 92, 21, 11, 4, 92, 65, 47, 83, 18, 9, 76, 34, 28, 41, 21, 76, 41, 36, 81, 76, 11, 6, 9, 47, 47, 77, 2, 67, 62, 34, 31, 6, 55, 41, 61, 46, 57, 59, 80, 26, 19, 56, 11, 46, 96, 32, 73, 89, 19, 53, 64, 29, 58, 25, 27, 57, 1, 80, 75, 15, 14, 5, 72, 68, 98, 32, 65, 6, 42, 45, 84, 60, 52, 94, 57, 99, 25, 29, 87, 43, 34, 3, 23, 43, 27, 50, 99, 79, 29, 73, 93, 94, 30, 16, 13, 79, 99, 78, 36, 40, 74, 19, 51, 25, 13, 7, 23, 89, 88, 62, 84, 73, 16, 6, 15, 42, 55, 66, 72, 36, 90, 65, 29, 71, 32, 42, 49, 31, 71, 37, 70, 44, 55, 73, 20, 19, 79, 94, 60, 18, 55, 43, 90, 70, 48, 57, 63, 55, 74, 35, 90, 63, 51, 70, 86, 82, 11, 34, 12, 33, 22, 34, 76, 77, 6, 95, 47, 36, 41, 6, 54, 47, 48, 95, 69, 96, 51, 31, 50, 24, 17, 91, 39, 67, 60, 24, 1, 23, 9, 64, 55, 31, 97, 31, 7, 54, 77, 53, 90, 69, 11, 95, 16, 58, 89, 84, 5, 40, 14, 54, 15, 83, 96, 53, 49, 56, 76, 1, 78, 37, 65, 84, 67, 13, 14, 25, 67, 43, 29, 8, 11, 39, 54, 78, 49, 42, 61, 53, 33, 27, 59, 48, 9, 54, 52, 9, 9, 80, 10, 38, 16, 74, 22, 34, 38, 87, 58, 4, 81, 38, 63, 44, 77, 16, 21, 25, 10, 34, 77, 42, 60, 87, 41, 68, 41, 93, 76, 1, 24, 37, 91, 39, 62, 12, 24, 100, 50, 33, 55, 83, 70, 18, 26, 98, 85, 98, 22, 94, 31, 51, 36, 90, 37, 76, 9, 29, 20, 37, 30, 43, 73, 20, 33, 35, 83, 8, 34, 32, 40, 88, 14, 10, 57, 91, 7, 42, 89, 81, 35, 71, 83, 22, 13, 71, 50, 21, 100, 69, 57, 81, 64, 82, 100, 48, 16, 34, 56, 1, 17, 95, 40, 83, 56, 97, 73, 63, 90, 13, 95, 76, 84, 77, 98, 96, 47, 47, 68, 98, 67, 25, 78, 82, 6, 29, 30, 73, 62, 37, 25, 79, 83, 64, 13, 39, 12, 37, 53, 1, 50, 99, 77, 85, 75, 26, 32, 73, 72, 51, 71, 38, 27, 48, 72, 84, 29, 1, 56, 90, 89, 80, 20, 71, 96, 32, 61, 7, 69, 65, 8, 70, 63, 36, 6, 37, 61, 89, 10, 84, 39, 32, 73, 66, 31, 44, 49, 59, 44, 5, 1, 32, 36, 20, 55, 31, 4, 15, 38, 24, 80, 97, 45, 94, 84, 50, 31, 44, 38, 92, 27, 28, 23, 51, 93, 5, 95, 42, 64, 90, 98, 64, 74, 33, 35, 28, 16, 90, 94, 53, 65, 25, 1, 9, 19, 84, 10, 49, 79, 99);
    return test;
}

vector<int> randomSequence(int size, int minValue, int maxValue) {
    vector<int> ret(size);
    for (int i = 0; i < size; i++) {
        ret[i] = random(minValue, maxValue);
    }
    return ret;
}

Test randomTest(int n, int minValue, int maxValue) {
    Test test;
    test.addLine(n);
    test.addLine(randomSequence(n, minValue, maxValue));
    return test;
}

Test begendTest(int n, int minValue, int maxValue) {
    Test test;
    test.addLine(n);
    vector<int> ret;
    ret.push_back(minValue);
    for (int i = 2; i < n; i++) {
        ret.push_back(random(minValue + 1, maxValue - 1));
    }
    ret.push_back(maxValue);
    test.addLine(ret);
    return test;
}