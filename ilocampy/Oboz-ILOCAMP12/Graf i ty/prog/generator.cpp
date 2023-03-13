#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;

using namespace std;

Test randomTest(int n, int m);
Test exampleTest();
Test single();
Test wolneNWD(int x);

int main() {
    Generator gen("git");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
    // 1
    gen.beginGroup();
    {
        gen.addTest(single());
    }
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(randomTest(20, 20));
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(randomTest(300, 1000));
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(randomTest(1000, 2000));
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(randomTest(50000, 50000));
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(randomTest(200000, 200000));
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(randomTest(1000, 1000000));
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(randomTest(1000000, 1000000));
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(randomTest(1000000, 1000000));
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(randomTest(1000000, 1000000));
    gen.endGroup();
    
    gen.beginGroup();
    gen.addTest(wolneNWD(1));
    gen.addTest(wolneNWD(0));
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
    test.addLine(10, 3);
    test.addLine(2, 3);
    test.addLine(4, 8);
    test.addLine(5, 5);
    return test;
}

Test single() {
    Test test;
    test.addLine(1, 1);
    test.addLine(1, 1);
    return test;
}

Test smallTest() {
    Test test;
    test.addLine(10, 5);
    test.addLine(1, 10);
    test.addLine(3, 7);
    test.addLine(4, 6);
    test.addLine(6, 4);
    test.addLine(8, 7);
    return test;
}

Test randomTest(int n, int m) {
    Test test;
    test.addLine(n, m);
    for (int i = 1; i <= m; i++) {
        test.addLine(random(1, n), random(1, n));
    }
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

Test wolneNWD(int x) {
    Test test;
    int n = 1000000;
    test.addLine(n, n);
    for (int i = 1; i <= n; i++) {
        test.addLine(x?n:1, x?1:n);
    }
    return test;
}
