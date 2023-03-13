#include "generator.h"

#include <memory>
#include <bits/stdc++.h>

using graph_t = std::vector<std::pair<int, int>>;

Test exampleTest();

Test single1();
Test single2();
Test tiny1();
Test tiny2();
Test path(int n, int m, int maxValue);
Test star(int n, int m, int maxValue);

Test deep(int nodesCount, int randomTreeSize = 0, bool shuffle = false);
Test shallow(int nodesCount, int randomTreeSize = 0, bool shuffle = false);
Test randomTest(int nodesCount, int m, int maxValue);
Test random_tree_from_prufer(int n, int m, int maxValue);
Test randomQueries(int n, int m, int maxValue);
int main() {
    Generator gen("kon");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    gen.beginGroup(); //1
    {
        gen.addTest(single1());
        gen.addTest(single2());
    }
    gen.endGroup();
    
    gen.beginGroup(); //2
    {
        gen.addTest(tiny1());
        gen.addTest(tiny2());
    }
    gen.endGroup();
    
    gen.beginGroup(); //3
    {
        Generator::setSeed(314141);
        gen.addTest(path(20, 20, 20));
        Generator::setSeed(859181);
        gen.addTest(path(20, 19, 10));
        Generator::setSeed(194911);
        gen.addTest(star(20, 20, 15));
        Generator::setSeed(95942);
        gen.addTest(star(20, 17, 16));
    }
    gen.endGroup();
    
    gen.beginGroup(); //4
    {
        Generator::setSeed(4151151);
        gen.addTest(randomTest(1000, 1200, 1000));
        Generator::setSeed(531511);
        gen.addTest(random_tree_from_prufer(1000, 1100, 10000));
        Generator::setSeed(53151);
        gen.addTest(randomTest(1000, 1000, 1000));
    }
    gen.endGroup();
    
    gen.beginGroup(); //5
    {
        Generator::setSeed(35151);
        gen.addTest(random_tree_from_prufer(50000, 80000, 1000));
        Generator::setSeed(531513);
        gen.addTest(randomTest(50000, 55000, 5000));
        Generator::setSeed(63151);
        gen.addTest(random_tree_from_prufer(50000, 100000, 1000));
    }
    gen.endGroup();
    
    gen.beginGroup(); //6
    {
        Generator::setSeed(51351);
        gen.addTest(randomTest(400000, 1000000, 1000));
        Generator::setSeed(7928235);
        gen.addTest(random_tree_from_prufer(750000, 1000000, 500));
        Generator::setSeed(68281385);
        gen.addTest(random_tree_from_prufer(999950, 1000000, 400));
    }
    gen.endGroup();
    
    gen.beginGroup(); //7
    {
        Generator::setSeed(65462);
        gen.addTest(random_tree_from_prufer(30000, 1000000, 300));
        Generator::setSeed(85848);
        gen.addTest(randomQueries(1000000, 1000000, 300));
        Generator::setSeed(518181);
    }
    gen.endGroup();
    
    gen.generate();
}

int random(int a, int b);
graph_t randomTree(int count);
void addNodes(graph_t &graph, int count, int maxBack);
void shuffleGraph(graph_t &graph);
Test graphToTest(const graph_t &graph);;
graph_t pruferTree(int n);

Test exampleTest() {
    Test test;
    
    test.addLine(4, 4);
    test.addLine(1, 3, 9);
    test.addLine(2, 4, 6);
    test.addLine(2, 3, 4);
    test.addLine(3, 4, 3);
    
    return test;
}

Test single1() {
    Test test;
    
    test.addLine(1, 0);
    
    return test;
}

Test single2() {
    Test test;
    
    test.addLine(1, 1);
    test.addLine(1, 1, 5);
    
    return test;
}

Test tiny1() {
    Test test;
    
    test.addLine(7, 7);
    test.addLine(1, 4, 18);
    test.addLine(2, 3, 6);
    test.addLine(2, 5, 14);
    test.addLine(3, 4, 9);
    test.addLine(5, 7, 9);
    test.addLine(4, 7, 13);
    test.addLine(6, 7, 5);

    return test;
}

Test tiny2() {
    Test test;

    test.addLine(6, 8);
    test.addLine(1, 1, 6);
    test.addLine(1, 2, 7);
    test.addLine(1, 3, 10);
    test.addLine(1, 4, 14);
    test.addLine(2, 2, 1);
    test.addLine(2, 3, 4);
    test.addLine(2, 4, 8);
    test.addLine(4, 6, 11);
    
    return test;
}



Test path(int n, int m, int maxValue) {
   assert(m <= n);
   Test test;
   
   test.addLine(n, m);
   for(int i = 1; i <= m; i++) {
       test.addLine(i, i, random(0, maxValue));
   }
   
   return test;
}

Test star(int n, int m, int maxValue) {
    int tab[n + 5];
    assert(m <= n);
    Test test;
    
    test.addLine(n, m);
    
    tab[0] = 0;
    for(int i = 1; i <= n; i++) {
        tab[i] = tab[i - 1] + random(1, maxValue);
    }
    
    for(int i = 1; i <= m; i++) {
        test.addLine(1, i, tab[i]);
    }
    
    return test;
}

Test random_tree_from_prufer(int n, int m, int maxValue) {
    graph_t graph = pruferTree(n);
    int values[n + 5];
    values[0] = 0;
    for(int i = 1; i <= n; i++) {
        values[i] = values[i - 1] + random(1, maxValue);
    }
    for(int i = 1; i <= m - n; i++) {
        int b = random(2, n + 1);
        int a = random(1, b - 1);
        graph.push_back({a, b});
    }
    std::shuffle(graph.begin(), graph.end(), Generator::getGen());
    Test test;
    test.addLine(n, m);
    for(int i = 0; i < graph.size(); i++) {
        if(graph[i].first > graph[i].second) {
            std::swap(graph[i].first, graph[i].second);
        }
        test.addLine(graph[i].first, graph[i].second - 1, values[graph[i].second - 1] - values[graph[i].first - 1]);
    }
    return test;
}


Test randomQueries(int n, int m, int maxValue) {
    Test test;
    
    int values[n + 5];
    values[0] = 0;
    for(int i = 1; i <= n; i++) {
        values[i] = values[i - 1] + random(0, maxValue);
    }
    test.addLine(n, m);
    for(int i = 1; i <= m; i++) {
        int a = random(1, n);
        int b = random(1, n);
        if(a > b) {
            std::swap(a, b);
        }
        test.addLine(a, b, values[b] - values[a - 1]);
    }
    
    return test;
}

Test randomTest(int nodesCount, int m, int maxValue) {
    graph_t graph = randomTree(nodesCount + 1);
    Test test;
    int values[nodesCount + 5];
    values[0] = 0;
    
    for(int i = 1; i <= nodesCount; i++) {
        values[i] = values[i - 1] + random(0, maxValue);
    }
    
    for(int i = 1; i <= m - nodesCount; i++) {
        int b = random(2, nodesCount + 1);
        int a = random(1, b - 1);
        
        graph.push_back({a, b});
    }
    test.addLine(nodesCount, m);
    for(int i = 0; i < graph.size(); i++) {
        int a = graph[i].first;
        int b = graph[i].second;
        if(a > b) {
            std::swap(a, b);
        }
        test.addLine(a, b - 1, values[b - 1] - values[a - 1]);
    }
    
    return test;
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

graph_t pruferTree(int n) {
    graph_t ret;
    std::priority_queue<int> q;
    int sequence[n + 5];
    int cnt[n + 5];
    for(int i = 1; i <= n + 1; i++) {
        cnt[i] = 0;
    }
    
    for(int i = 1; i <= n - 1; i++) {
        sequence[i] = random(1, n + 1);
        cnt[sequence[i]] += 1;
    }
    
    for(int i = 1; i <= n + 1; i++) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }
    
    for(int posInSeq = 1; posInSeq <= n - 1; posInSeq++) {
        int w = q.top();
        q.pop();
        int parent = sequence[posInSeq];
        
        ret.push_back({parent, w});
        cnt[parent]--;
        if(cnt[parent] == 0) {
            q.push(parent);
        }
    }
    int a = q.top();
    q.pop();
    int b = q.top();
    q.pop();
    ret.push_back({a, b});
    return ret;
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