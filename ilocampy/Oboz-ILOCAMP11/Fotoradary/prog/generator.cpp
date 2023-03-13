#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;

Test exampleTest();

Test single();
Test tiny1();
Test tiny2();

Test deep(int nodesCount, int randomTreeSize = 0, bool shuffle = false, int k = 0);
Test shallow(int nodesCount, int randomTreeSize = 0, bool shuffle = false, int k = 0);
Test randomTest(int nodesCount, int k);
Test star(int n, int k);

int main() {
    Generator gen("fot");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        gen.addTest(single());
        gen.addTest(tiny1());
        gen.addTest(tiny2());

        Generator::setSeed(982751);
        gen.addTest(deep(10, 6, false, 3));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        int size = 20;

        Generator::setSeed(13314242);
        gen.addTest(randomTest(size, 5));

        Generator::setSeed(9805123);
        gen.addTest(randomTest(size, 3));

        Generator::setSeed(2391074);
        gen.addTest(deep(size, 7, false, 4));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        int size = 100;

        Generator::setSeed(135523);
        gen.addTest(randomTest(size, 15));

        Generator::setSeed(4312904);
        gen.addTest(randomTest(size, 30));

        Generator::setSeed(32910857);
        gen.addTest(shallow(size, 20, false, 5));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        int size = 500;

        Generator::setSeed(15364123);
        gen.addTest(randomTest(size, 20));

        Generator::setSeed(129304);
        gen.addTest(randomTest(size, 300));

        Generator::setSeed(1239874);
        gen.addTest(deep(size, 50, true, 7));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        int size = 50 * 1000;

        Generator::setSeed(12542324);
        gen.addTest(randomTest(size, 61));

        Generator::setSeed(237135);
        gen.addTest(randomTest(size, 10000));

        Generator::setSeed(1258379);
        gen.addTest(shallow(size, 1000, true, 500));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        int size = 80 * 1000;

        Generator::setSeed(13251225);
        gen.addTest(randomTest(size, 511));

        Generator::setSeed(9138473);
        gen.addTest(randomTest(size, 50000));

        Generator::setSeed(23195723);
        gen.addTest(shallow(size, 1000, false, 20000));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        int size = 150 * 1000;

        Generator::setSeed(584656);
        gen.addTest(randomTest(size, 10));

        Generator::setSeed(130498327);
        gen.addTest(randomTest(size, 10000));

        Generator::setSeed(23149083);
        gen.addTest(deep(size, 1000, true, 100000));
    }
    gen.endGroup();

    // 8
    gen.beginGroup();
    {
        int size = 500 * 1000;

        Generator::setSeed(25234523);
        gen.addTest(randomTest(size, 62));

        Generator::setSeed(21891032);
        gen.addTest(randomTest(size, 6422));

        Generator::setSeed(3129846);
        gen.addTest(deep(size, 10 * 1000, false, 62469));
    }
    gen.endGroup();

    // 9
    gen.beginGroup();
    {
        int size = 900 * 1000;

        Generator::setSeed(24365472);
        gen.addTest(randomTest(size, 1000));

        Generator::setSeed(2301483);
        gen.addTest(randomTest(size, 10000));

        Generator::setSeed(21357923);
        gen.addTest(shallow(size, 10 * 1000, true, 500000));
        
        Generator::setSeed(7175722);
        gen.addTest(star(size, 100000));
    }
    gen.endGroup();

    // 10
    gen.beginGroup();
    {
        int size = 1000 * 1000;

        Generator::setSeed(254752235);
        gen.addTest(randomTest(size, 10));

        Generator::setSeed(13284732);
        gen.addTest(randomTest(size, 5251));

        Generator::setSeed(189456);
        gen.addTest(shallow(size, 500, false, 66666));
        
        Generator::setSeed(518111);
        gen.addTest(star(1000000, 400000));
    }
    gen.endGroup();

    gen.generate();
}

int random(int a, int b);
graph_t randomTree(int count);
void addNodes(graph_t &graph, int count, int maxBack);
void shuffleGraph(graph_t &graph);
Test graphToTest(const graph_t &graph, int k);

Test star(int n, int k) {
    Test test;
    
    test.addLine(n, k);
    int x = random(1, n);
    for(int i = 1; i <= n; i++) {
        if(i != x) {
            test.addLine(x, i);
        }
    }
    
    return test;
}

Test exampleTest() {
    Test test;
    
    test.addLine(10, 2);
    test.addLine(6, 2);
    test.addLine(2, 1);
    test.addLine(1, 8);
    test.addLine(3, 5);
    test.addLine(8, 3);
    test.addLine(1, 7);
    test.addLine(7, 9);
    test.addLine(7, 4);
    
    return test;
}

Test single() {
    Test test;
    test.addLine(1, 1);
    return test;
}

Test tiny1() {
    Test test;
    test.addLine(8, 1);
    test.addLine(1, 2);
    test.addLine(1, 3);
    test.addLine(1, 4);
    test.addLine(3, 5);
    test.addLine(3, 6);
    test.addLine(3, 7);
    test.addLine(4, 8);

    return test;
}

Test tiny2() {
    Test test;

    test.addLine(15, 3);
    test.addLine(2, 1);
    test.addLine(3, 2);
    test.addLine(4, 3);
    test.addLine(5, 3);
    test.addLine(6, 3);
    test.addLine(7, 4);
    test.addLine(8, 4);
    test.addLine(9, 4);
    test.addLine(10, 5);
    test.addLine(11, 5);
    test.addLine(12, 6);
    test.addLine(13, 6);
    test.addLine(14, 6);
    test.addLine(15, 6);

    return test;
}

Test deep(int nodesCount, int randomTreeSize, bool shuffle, int k) {
    graph_t graph;
    if (randomTreeSize) {
        graph = randomTree(randomTreeSize);
    }
    addNodes(graph, nodesCount - randomTreeSize - 1, random(1, 4));
    if (shuffle) {
        shuffleGraph(graph);
    }
    return graphToTest(graph, k);
}

Test shallow(int nodesCount, int randomTreeSize, bool shuffle, int k) {
    graph_t graph;
    graph = randomTree(randomTreeSize);

    nodesCount -= randomTreeSize + 1;
    while (nodesCount--) {
        int parent = Generator::random() % randomTreeSize + 1;
        graph.push_back({(int)graph.size() + 2, parent});
    }

    if (shuffle) {
        shuffleGraph(graph);
    }
    return graphToTest(graph, k);
}

Test randomTest(int nodesCount, int k) {
    graph_t graph = randomTree(nodesCount);
    shuffleGraph(graph);
    return graphToTest(graph, k);
}

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test graphToTest(const graph_t &graph, int k) {
    Test test;
    test.addLine(graph.size() + 1, k);
    for (const auto &edge : graph) {
        test.addLine(edge.first, edge.second);
    }
    return test;
}

graph_t randomTree(int count) {
    graph_t graph;
    addNodes(graph, count - 1, 10e7);
    return graph;
}

void addNodes(graph_t &graph, int count, int maxBack) {
    int curNode = (int)graph.size() + 1;
    while (count--) {
        curNode++;
        graph.push_back({curNode, random(std::max(1, curNode - maxBack), curNode - 1)});
    }
}

void shuffleGraph(graph_t &graph) {
    std::vector<int> mapping(graph.size() + 1);
    std::iota(mapping.begin(), mapping.end(), 1);
    std::shuffle(mapping.begin(), mapping.end(), Generator::getGen());
    for (auto &edge : graph) {
        edge.first = mapping[edge.first - 1];
        edge.second = mapping[edge.second - 1];
    }
}