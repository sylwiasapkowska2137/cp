#include "generator.h"

#include <memory>

using graph_t = std::vector<std::pair<int, int>>;

Test exampleTest();

Test deep(int nodesCount, int randomTreeSize = 0, int deepness = 3, bool shuffle = false);
Test shallow(int nodesCount, int randomTreeSize = 0, bool shuffle = false);
Test randomTest(int nodesCount, bool leafRoot = false);
Test binaryTree(int nodesCount);
Test star(int nodesCount);

int main() {
    Generator gen("pol");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        int size = 10;
        
        Generator::setSeed(422);
        gen.addTest(randomTest(size, true));
        
        Generator::setSeed(803);
        gen.addTest(shallow(size, 2));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        int size = 50;
        
        Generator::setSeed(106);
        gen.addTest(randomTest(size));
        
        Generator::setSeed(125);
        gen.addTest(binaryTree(size));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        int size = 500;
        
        Generator::setSeed(465);
        gen.addTest(randomTest(size, true));
        
        Generator::setSeed(347);
        gen.addTest(deep(size, 10, 3));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        int size = 1000;
        
        Generator::setSeed(1287965);
        gen.addTest(randomTest(size));
        
        Generator::setSeed(12349768);
        gen.addTest(deep(size, 40, 5));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        int size = 50 * 1000;
        
        Generator::setSeed(97813);
        gen.addTest(randomTest(size, true));
        
        Generator::setSeed(908654);
        gen.addTest(binaryTree(size));
        
        Generator::setSeed(98123);
        gen.addTest(star(size));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        int size = 80 * 1000;
        
        Generator::setSeed(7912684);
        gen.addTest(randomTest(size));
        
        Generator::setSeed(9812356);
        gen.addTest(shallow(size, 1000));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        int size = 100 * 1000;
        
        Generator::setSeed(982615);
        gen.addTest(randomTest(size, true));
        
        Generator::setSeed(87213);
        gen.addTest(deep(size, 1000, 3, true));
        
        Generator::setSeed(91236);
        gen.addTest(star(size));
    }
    gen.endGroup();

    // 8
    gen.beginGroup();
    {
        int size = 100 * 1000;
        
        Generator::setSeed(9014327);
        gen.addTest(randomTest(size));
        
        Generator::setSeed(2839014);
        gen.addTest(binaryTree(size));
        
        Generator::setSeed(2398471);
        gen.addTest(shallow(size, 1000, true));
    }
    gen.endGroup();

    gen.generate();
}

Test exampleTest() {
    Test test;

    test.addLine(8);
    test.addLine(1, 2);
    test.addLine(1, 3);
    test.addLine(1, 4);
    test.addLine(1, 6);
    test.addLine(1, 8);
    test.addLine(6, 7);
    test.addLine(4, 5);

    return test;
}

int random(int a, int b);
graph_t randomTree(int count);
void addNodes(graph_t &graph, int count, int maxBack);
void shuffleGraph(graph_t &graph);
Test graphToTest(const graph_t &graph);

Test deep(int nodesCount, int randomTreeSize, int deepness, bool shuffle) {
    graph_t graph;
    if (randomTreeSize) {
        graph = randomTree(randomTreeSize);
    }
    addNodes(graph, nodesCount - randomTreeSize - 1, deepness);
    if (shuffle) {
        shuffleGraph(graph);
    }
    return graphToTest(graph);
}

Test shallow(int nodesCount, int randomTreeSize, bool shuffle) {
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
    return graphToTest(graph);
}

Test randomTest(int nodesCount, bool leafRoot) {
    graph_t graph = randomTree(nodesCount - 1);
    shuffleGraph(graph);

    if (leafRoot) {
        std::vector<int> connections(nodesCount + 1, 0);
        for (const auto &edge : graph) {
            connections[edge.first]++;
            connections[edge.second]++;
        }
        
        int root = 1;
        for (int i = 1; i <= nodesCount; i++) {
            if (connections[i] == 1) {
                root = i;
            }
        }

        for (auto &edge : graph) {
            for (int *end : {&edge.first, &edge.second}) {
                if (*end == 1) {
                    *end = root;
                } else if (*end == root) {
                    *end = 1;
                }
            }
        }
    }

    return graphToTest(graph);
}

Test binaryTree(int nodesCount) {
    graph_t graph;
    for (int i = 2; i <= nodesCount; i++) {
        graph.push_back({i, i / 2});
    }
    return graphToTest(graph);
}

Test star(int nodesCount) {
    graph_t graph;
    for (int i = 2; i <= nodesCount; i++) {
        graph.push_back({1, i});
    }
    return graphToTest(graph);
}

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test graphToTest(const graph_t &graph) {
    Test test;
    test.addLine(graph.size() + 1);
    for (const auto &edge : graph) {
        test.addLine(edge.first, edge.second);
    }
    return test;
}

graph_t randomTree(int count) {
    graph_t graph;
    addNodes(graph, count, 10e7);
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